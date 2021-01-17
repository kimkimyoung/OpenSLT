#include "frame.h"

float getTimeStamp(unsigned short year,
                    unsigned char month,
                    unsigned char day,
                    unsigned char hour,
                    unsigned char minute,
                    unsigned char second,
                    unsigned char hseconds){
    tm recordTime;
    time_t tt;
    recordTime.tm_year=year;
    recordTime.tm_mon=month;
    recordTime.tm_mday=day;
    recordTime.tm_hour=hour;
    recordTime.tm_min=minute;
    recordTime.tm_sec=second;
    recordTime.tm_isdst=0;
    recordTime.tm_gmtoff=0;
    tt=mktime(&recordTime);
    return float(tt)+float(hseconds)*0.01;
}
