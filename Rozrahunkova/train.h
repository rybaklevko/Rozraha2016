//train.h
#ifndef TRAIN_H
#define TRAIN_H

#include <string>
#include "times.h"

class Train:public Time
{
    friend class Schedule;
public:
    Train();
    Train(const int&,const int&,const int&,const std::string&,const int&);
    Train(const Train &);
    Train(Train &&);
    ~Train();

    Train &operator=(const Train &);

    void set_data(int,int,int,std::string,int);

    std::string& get_destination();
    int& get_hours();
    int& get_minutes();
    int& get_seconds();
    int& get_platform();

    void show() const;

private:
    std::string nDestination;
    int nPlatform;
};

#endif // TRAIN_H
