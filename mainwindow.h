#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>

#include <cmath>
#include <string>
#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "XTFReader/logger.h"
#include "XTFReader/simulator.h"
#include "XTFReader/frame.h"
#include "eventlabel.h"
#include "labeldialog.h"

using namespace cv;
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void systemInit();
    ~MainWindow();

    /*flags*/
    int stop_flag = 0;
    int save_mode;

signals:
    void labelAdded(QString label);
    void labelDeleted(QString label);
    void labelCleared();

private slots:
    /*btn*/
    void on_btn_Start_clicked();
    void on_btn_Pause_clicked();
    void on_btn_Stop_clicked();
    void on_btn_Run_clicked();
    void on_btn_SpeedUp_clicked();
    void on_btn_SpeedDown_clicked();
    void on_speedSlider_sliderReleased();

    /*tool bar*/
    void openFile();
    void openDir();
    void saveAnnotation();
    void appQuit();
    void changeMode();
    void imageAutoSave();

    /*files*/
    void douleClickFile(QListWidgetItem *item);

    /*label*/
    void newLabel(QString label);
    void newLabelfromDialog(QString label);
    void deleteLabel(QString label);
    void labelMenu(const QPoint &pos);

    /*annotation*/
    void setLabel(QString label);
    void setRect(QList<int>);
    void setAnnotation();

private:
    Ui::MainWindow *ui;
    std::string file_path = "/home/kim/PCL-Works/side_scan_mosaic/data/NY_HudsonRiver/000_1400.xtf";
    QString dir_path;
    QStringList file_list;

    simulator *p_simulator;
    EventLabel *p_label = new EventLabel();
    LabelDialog *dialog = new LabelDialog();

    QString label_name;
    QList<int> current_rect;
    QString ping_number;
    QString num_sample;
    QString ping_direction;
    QString width;
    QString height;
    QString origin_x;
    QString origin_y;
    QString sonar_annotation;
    QString yolo_annotation;

    int current_pingNumber;
    int current_numSample;

    cv::Mat imageSaved;
    int curIdx=0;

    /* xtf solver*/
    void imageGain(cv::Mat& ssImage, int numSamples);
    void updateMat(cv::Mat* src);
    void copyToMat(unsigned char * src,unsigned char * dst,unsigned int len, int fBytesPerSample);
    void gray2Color(Mat& gray, Mat& color);
    void imageLoad();

    /* Manager */
    void setupLabelManager();
    void setupFileManager();
    void setupmainToolBar();
    void setupLabelDialog();
    void setupAnnotationManager();
};

#endif // MAINWINDOW_H
