#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QToolButton>
#include <QLabel>
#include <QDir>
#include <QDateTime>
#include <QTextStream>

#define WINDOW_H 1000
#define WINDOW_W 2400
#define COMPENSARION_VALUE 2

#define ALFA 1 // sonar parameters
#define GAMA 0.01f // sonar parameters

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupmainToolBar();
    setupFileManager();
    setupLabelManager();
    setupLabelDialog();
    setupAnnotationManager();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::systemInit()
{

}

/***********************************************************************************************
 *                                  set mainToolBar
 * *********************************************************************************************/
void MainWindow::setupmainToolBar()
{
    QObject::connect(ui->actionOpenFile, SIGNAL(triggered(bool)), this, SLOT(openFile()));
    QObject::connect(ui->actionOpenDir, SIGNAL(triggered(bool)), this, SLOT(openDir()));
    QObject::connect(ui->actionSave, SIGNAL(triggered(bool)), this, SLOT(saveAnnotation()));
    QObject::connect(ui->actionExit, SIGNAL(triggered(bool)), this, SLOT(appQuit()));
    QObject::connect(ui->actionOutput_YOLO_Pics, SIGNAL(triggered(bool)), this, SLOT(changeMode()));
    QObject::connect(ui->btn_Run, SIGNAL(clicked(bool)), this, SLOT(imageAutoSave()));
}

void MainWindow::openFile()
{
    QString str_path = QFileDialog::getOpenFileName(this, tr("select xtf file"));
    if (str_path != ""){
        file_path = str_path.toStdString();
    }
}

void MainWindow::openDir()
{
    dir_path = QFileDialog::getExistingDirectory(this, tr("select directory"));
    if (dir_path != ""){
        QDir dir(dir_path);
        QStringList nameFilters;
        nameFilters << "*.xtf" << "*.XTF";
        file_list = dir.entryList(nameFilters, QDir::Files|QDir::Readable, QDir::Name);
        if (file_list.empty())
        {
            QMessageBox::about(NULL, "ERROR", "No existed XTF files in the directory");
            return;
        }
        QString str_path = dir_path + "/" + file_list[0];
        file_path = str_path.toStdString();
        ui->Files_listWidget->addItems(file_list);
    }
}

void MainWindow::saveAnnotation()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("txt file"), QString("./annotation.txt"), tr("text Files(*.txt)"));
    if (fileName == "")
    {
        return;
    }
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        return;
    }
    else
    {
        QTextStream textStream(&file);
        textStream << QString::fromStdString(file_path) << "\n" << "\n" << "\n";
        textStream << "------------sonar annotaion------------" << "\n";
        for (int i = 0; i < ui->sonar_listWidget->count(); i++)
        {
            textStream << ui->sonar_listWidget->item(i)->text() + "\n";
        }
        textStream << "\n" << "\n" << "\n";
        textStream << "------------yolo annotaion------------" << "\n";
        for (int i = 0; i < ui->yolo_listWidget->count(); i++)
        {
            textStream << ui->yolo_listWidget->item(i)->text() + "\n";
        }
        QMessageBox::information(this, "Saved", "Successed Saving Annotation");
        file.close();
    }
    ui->sonar_listWidget->clear();
    ui->yolo_listWidget->clear();
    ui->actionSave->setEnabled(0);
}

void MainWindow::appQuit()
{
    p_simulator->pauseSimulator();
    if (!(QMessageBox::information(this,tr("Exit Warning"),tr("Do you really want exit ?"),tr("Yes"),tr("No"))))
    {
        qApp->quit();
    }
    p_simulator->unpauseSimulator();
}

void MainWindow::changeMode()
{
    if (ui->actionOutput_YOLO_Pics->iconText() == "red")
    {
        ui->actionOutput_YOLO_Pics->setIconText("green");
        ui->actionOutput_YOLO_Pics->setIcon(QIcon("://Images/resource/green-circle.png"));
        save_mode = 1;
    }
    else
    {
        ui->actionOutput_YOLO_Pics->setIconText("red");
        ui->actionOutput_YOLO_Pics->setIcon(QIcon("://Images/resource/red-circle.png"));
        save_mode = 0;
    }
}

void MainWindow::imageAutoSave()
{
    if (!current_rect.empty() && save_mode == 1)
    {
        QString path;
        QDir dir;
        QDateTime time = QDateTime::currentDateTime();
        path = dir.currentPath() + "/" + time.toString("yy-MM-dd hh:mm");

        QDir dir_file;
        QString path_file;
        if (!dir_file.exists(path))
        {
            dir_file.mkdir(path);
        }
        path_file = path + "/" + QString::number(curIdx) + ".jpg";
        imwrite(path_file.toStdString(), imageSaved);
        current_rect.clear();
        curIdx++;
    }
}

/***********************************************************************************************
 *                                        files box
 * *********************************************************************************************/
void MainWindow::setupFileManager()
{
    QObject::connect(ui->Files_listWidget, &QListWidget::itemDoubleClicked, this, &MainWindow::douleClickFile);
    QObject::connect(ui->Files_listWidget, &QListWidget::itemDoubleClicked, this, &MainWindow::on_btn_Start_clicked);
}

void MainWindow::douleClickFile(QListWidgetItem *item)
{
    file_path = (dir_path + "/" + item->text()).toStdString();
}

/***********************************************************************************************
 *                                        label box
 * *********************************************************************************************/
void MainWindow::setupLabelManager()
{
    ui->Label_listWidget->setProperty("contextMenuPolicy", Qt::CustomContextMenu);
    QObject::connect(ui->btn_AddLabel, &QPushButton::clicked, [this](){newLabel(ui->lineEdit_newLabel->text());});
    QObject::connect(ui->Label_listWidget, &QListWidget::customContextMenuRequested, this, &MainWindow::labelMenu);
    QObject::connect(dialog, SIGNAL(dialoglabelAdded(QString)), this, SLOT(newLabelfromDialog(QString)));

}

void MainWindow::newLabel(QString label)
{
    if (label == "")
    {
        return;
    }
    if (!ui->Label_listWidget->findItems(label, Qt::MatchExactly).empty())
    {
        QMessageBox::about(NULL, "ERROR", "Exist Label, Please reset the label name");
        return;
    }
    ui->Label_listWidget->addItem(label);
    ui->lineEdit_newLabel->setText("");
    emit labelAdded(label);

}

void MainWindow::newLabelfromDialog(QString label)
{
    if (ui->Label_listWidget->findItems(label, Qt::MatchExactly).empty())
    {
        ui->Label_listWidget->addItem(label);
        return;
    }
}

void MainWindow::deleteLabel(QString label)
{
    QListWidgetItem* item = ui->Label_listWidget->findItems(label, Qt::MatchExactly)[0];
    ui->Label_listWidget->removeItemWidget(item);
    delete item;
    emit labelDeleted(label);
}

void MainWindow::labelMenu(const QPoint &pos)
{
    QPoint globalPos = ui->Label_listWidget->mapToGlobal(pos);
    QModelIndex modelIndex = ui->Label_listWidget->indexAt(pos);
    if (!modelIndex.isValid())
    {
        return;
    }
    int row = modelIndex.row();
    auto item = ui->Label_listWidget->item(row);

    QMenu menu;
    menu.addAction("Delete");
    menu.addAction("Clear all");
    QAction* click = menu.exec(globalPos);
    if (click)
    {
        if (click->text().contains("Delete"))
        {
            deleteLabel(item->text());
        }
        else if (click->text().contains("Clear all"))
        {
            ui->Label_listWidget->clear();
            emit labelCleared();
        }
    }
}

/***********************************************************************************************
 *                                     annotation box
 * *********************************************************************************************/
void MainWindow::setupAnnotationManager()
{
    QObject::connect(dialog, SIGNAL(dialoglabelAdded(QString)), this, SLOT(setLabel(QString)));
    QObject::connect(ui->label_image, SIGNAL(rectLocationSet(QList<int>)), this, SLOT(setRect(QList<int>)));
    QObject::connect(dialog, SIGNAL(dialoglabelAdded(QString)), this, SLOT(setAnnotation()));
}

void MainWindow::setAnnotation()
{
    /* original poing */
    origin_x = QString::number(int((current_rect[0] + current_rect[1]) / 2));
    origin_y = QString::number(int((current_rect[2] + current_rect[3]) / 2));

    /* box size */
    width = QString::number(current_rect[1] - current_rect[0]);
    height = QString::number(current_rect[3] - current_rect[2]);

    /* number sample of origin */
    if (origin_x.toInt() < ui->label_image->width()/2)
    {
        num_sample = QString::number(current_numSample - int(current_numSample * origin_x.toInt() / (ui->label_image->width()/2)));
        ping_direction = "Left";
    }
    else
    {
        num_sample = QString::number(int(current_numSample * origin_x.toInt() / (ui->label_image->width()/2)) - current_numSample);
        ping_direction = "Right";
    }

    /* ping number of origin */
    ping_number = QString::number(current_pingNumber - origin_y.toInt());

    sonar_annotation = label_name + " " + ping_number + " " + num_sample +  " " + ping_direction + " " + width + " " + height;
    yolo_annotation = label_name + " " + "(" + origin_x + ", " + origin_y + ")" + " " + "(" + width + ", " + height + ")" + "  " + QString::number(curIdx) + ".jpg";
    ui->sonar_listWidget->addItem(sonar_annotation);
    ui->yolo_listWidget->addItem(yolo_annotation);
}

void MainWindow::setLabel(QString label)
{
    label_name = label;
}

void MainWindow::setRect(QList<int> rect)
{
    current_rect = rect;
}

/***********************************************************************************************
 *                                     label dialog
 * *********************************************************************************************/
void MainWindow::setupLabelDialog()
{
    QObject::connect(ui->btn_Run, SIGNAL(clicked(bool)), ui->label_image, SLOT(deleteRectlist()));
    QObject::connect(ui->label_image, SIGNAL(mouseReleaseSignal()), dialog, SLOT(dialogShow()));
    QObject::connect(this, SIGNAL(labelAdded(QString)), dialog, SLOT(getLabelFromManager(QString)));
    QObject::connect(this, SIGNAL(labelDeleted(QString)), dialog, SLOT(deleteLabelFromManager(QString)));
    QObject::connect(this, SIGNAL(labelCleared()), dialog, SLOT(clearLabelFromManager()));
    QObject::connect(dialog, SIGNAL(dialoglabelCanceled()), ui->label_image, SLOT(deleteLastRect()));
}

/***********************************************************************************************
 *                                  sonar image function
 * *********************************************************************************************/

void MainWindow::imageGain(Mat& ssImage, int numSamples)
{
    for (int i = 0; i < numSamples; i++)
    {
        if ((int)(ssImage.ptr<unsigned char>(WINDOW_H-1)[i] + ALFA * 10 * log10(numSamples-i) + GAMA * (numSamples-i)) > 255)
        {
            ssImage.ptr<unsigned char>(WINDOW_H-1)[i] = 255;
        }
        else
        {
            ssImage.ptr<unsigned char>(WINDOW_H-1)[i] = (int)(ssImage.ptr<unsigned char>(WINDOW_H-1)[i] + ALFA * 10 * log10(numSamples-i) + GAMA * (numSamples-i));
        }

        if ((int)((ssImage.ptr<unsigned char>(WINDOW_H-1)+numSamples)[i] + ALFA * 10 * log10(i) + GAMA * i) > 255)
        {
            (ssImage.ptr<unsigned char>(WINDOW_H-1)+numSamples)[i] = 255;
        }
        else
        {

            (ssImage.ptr<unsigned char>(WINDOW_H-1)+numSamples)[i] = (ssImage.ptr<unsigned char>(WINDOW_H-1)+numSamples)[i] + ALFA * 10 * log10(i) + GAMA * i;
        }
    }
}

void MainWindow::updateMat(cv::Mat* src){
    int ii,jj;
    unsigned char* ptr_dst;
    unsigned char* ptr_src;
    for(ii=src->rows-2; ii>0 || ii==0;ii--){
        ptr_dst=src->ptr<unsigned char>(ii+1);
        ptr_src=src->ptr<unsigned char>(ii);
        for(jj=0;jj<src->cols;jj++){
            *(ptr_dst+jj)=*(ptr_src+jj);
        }
    }
}

void MainWindow::copyToMat(unsigned char * src,unsigned char * dst,unsigned int len, int fBytesPerSample){
    unsigned int ii;
    for(ii=0; ii<len; ii++)
    {
        dst[ii] = src[fBytesPerSample*ii];
    }
}

void MainWindow::gray2Color(Mat& gray, Mat& color)
{
    for (int i = 0; i < gray.rows; i++)
    {
        uchar *ptr_gray = gray.ptr<uchar>(i);
        Vec3b *ptr_color = color.ptr<Vec3b>(i);
        for (int j = 0; j < gray.cols; j++)
        {
            ptr_color[j][0] = abs(0.10 * ptr_gray[j] + COMPENSARION_VALUE);
            ptr_color[j][1] = abs(0.50 * ptr_gray[j] + COMPENSARION_VALUE);
            ptr_color[j][2] = abs(0.90 * ptr_gray[j] + COMPENSARION_VALUE);
        }
    }
}

void MainWindow::imageLoad()
{
    active_logger = (std::unique_ptr<logger>) new logger(logger::log_level::debug);

    bool enableSSimage=true;
    Mat ssImage(WINDOW_H,WINDOW_W,CV_8UC1, cvScalar(0));
    Mat color_ssImage(WINDOW_H,WINDOW_W,CV_8UC3, cvScalar(0));
    Mat rgb;

    while(p_simulator->getSimState()!=simState::simStop)
    {
        if (stop_flag)
        {
            stop_flag=0;
            break;
        }
        Frame * p_frame;
        if(p_simulator->fetchFrame(p_frame))
        {
            if(p_frame->packetType==XTF_DATA_SIDESCAN)
            {
                pingFrame* p_ping=(pingFrame *)p_frame;
                current_numSample = p_ping->numSamples;
                current_pingNumber = p_ping->pingNumber;

                int window_w = 2 * p_ping->numSamples;
                ssImage.create(WINDOW_H,window_w,CV_8UC1);
                color_ssImage.create(ssImage.rows, ssImage.cols, CV_8UC3);

                LOG(info,"Time stamp: "+std::to_string(p_ping->timeStamp)+"No: "+std::to_string(p_ping->pingNumber));       
                if(enableSSimage)
                {
                    updateMat(&ssImage);
                    copyToMat((unsigned char*)p_ping->p_data[0],ssImage.ptr<unsigned char>(0),p_ping->numSamples, p_ping->bytesPerSample);
                    copyToMat((unsigned char*)p_ping->p_data[1],ssImage.ptr<unsigned char>(0)+p_ping->numSamples, p_ping->numSamples, p_ping->bytesPerSample);

                    imageGain(ssImage, p_ping->numSamples);
                    gray2Color(ssImage, color_ssImage);
                    cvtColor(color_ssImage, rgb, COLOR_BGR2RGB);
                }
            }
            QImage disImage= QImage((const uchar*)(rgb.data), rgb.cols, rgb.rows, rgb.cols*rgb.channels(), QImage::Format_RGB888);
            QPixmap pixmap = QPixmap::fromImage(disImage);
            pixmap.scaled(ui->label_image->width(), ui->label_image->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
            ui->label_image->setScaledContents(true);
            ui->label_image->setPixmap(pixmap);

            cv::waitKey(20);
        }
        QApplication::processEvents();
        imageSaved = color_ssImage.clone();
    }
}

/***********************************************************************************************
*                                  Button Function
************************************************************************************************/

void MainWindow::on_btn_Start_clicked()
{
    if (file_path.empty())
    {
        QMessageBox::about(NULL, "ERROR", "Please Select XTF files");
        return;
    }
    /* clear */
    if (ui->yolo_listWidget->count() != 0 )
    {
        if (QMessageBox::Yes == QMessageBox(QMessageBox::Information, "Tips", "Annotations are not saved. Are you sure you want to quit?", QMessageBox::Yes|QMessageBox::No).exec())
        {
            ui->yolo_listWidget->clear();
            ui->sonar_listWidget->clear();
            ui->Label_listWidget->clear();
        }
        else
        {
            return;
        }
    }
    /* button status */
    ui->btn_Pause->setEnabled(1);
    ui->btn_Stop->setEnabled(1);
    ui->btn_SpeedDown->setEnabled(1);
    ui->btn_SpeedUp->setEnabled(1);
    ui->btn_Start->setText("Restart");
    ui->speedSlider->setEnabled(1);
    ui->actionExit->setEnabled(0);

    p_simulator= new simulator(file_path);
    p_simulator->initializeSimulator();
    p_simulator->startSimulator();
    imageLoad();
}

void MainWindow::on_btn_Pause_clicked()
{
    /* button status */
    ui->btn_Run->setEnabled(1);
    ui->btn_Start->setEnabled(0);
    ui->btn_Stop->setEnabled(0);
    ui->btn_Pause->setEnabled(0);
    ui->btn_SpeedDown->setEnabled(0);
    ui->btn_SpeedUp->setEnabled(0);
    ui->speedSlider->setEnabled(0);

    p_simulator->pauseSimulator();
}

void MainWindow::on_btn_Stop_clicked()
{
    /* button status */
    ui->btn_Start->setEnabled(1);
    ui->btn_Pause->setEnabled(0);
    ui->btn_Stop->setEnabled(0);
    ui->btn_Run->setEnabled(0);
    ui->btn_SpeedDown->setEnabled(0);
    ui->btn_SpeedUp->setEnabled(0);
    ui->btn_Start->setText("Start");
    ui->speedSlider->setEnabled(0);
    ui->actionExit->setEnabled(1);

    stop_flag = 1;
    p_simulator->stopSimulator();

}

void MainWindow::on_btn_Run_clicked()
{
    /* button status */
    ui->btn_Run->setEnabled(0);
    ui->btn_Pause->setEnabled(1);
    ui->btn_Stop->setEnabled(1);
    ui->btn_SpeedDown->setEnabled(1);
    ui->btn_SpeedUp->setEnabled(1);
    ui->speedSlider->setEnabled(1);
    ui->actionSave->setEnabled(1);

    p_simulator->unpauseSimulator();
}

void MainWindow::on_btn_SpeedUp_clicked()
{
    if (p_simulator->getSpeed() < p_simulator->_MAX_SPEED)
    {
        QMessageBox::about(NULL, "ERROR", "Out of MAX Speed");
        return;
    }
    p_simulator->speedUp();
    ui->speedSlider->setValue(p_simulator->getSpeed());
}

void MainWindow::on_btn_SpeedDown_clicked()
{
    if (p_simulator->getSpeed() > p_simulator->_MIN_SPEED)
    {
        QMessageBox::about(NULL, "ERROR", "Out of MIN Speed");
        return;
    }
    p_simulator->speedDown();
    ui->speedSlider->setValue(p_simulator->getSpeed());
}

void MainWindow::on_speedSlider_sliderReleased()
{
    int speed = ui->speedSlider->value();
    p_simulator->setSpeed(speed);
}
