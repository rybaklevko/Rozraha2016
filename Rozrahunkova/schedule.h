//Schedule.h
#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <vector>
#include <algorithm>
#include <ctime>
#include "train.h"
#include "times.h"

class Schedule
{
public:
    Schedule();
    Schedule(const int& h,const int& m,const int& s,const std::string& d,const int& p);
    Schedule(const Train&);
    Schedule(std::vector<Train>&);
    ~Schedule();

    void set_data(const int &, const int &, const int &, const std::string &, const int &);
    void set_data(const Train &);

    void show();
    void real_time();
    void next_train();

private:
    std::vector<Train>nTrainSchedule;
    Time nRealTime;
    struct tm * now;
    time_t t;
};

#endif // SCHEDULE_H
