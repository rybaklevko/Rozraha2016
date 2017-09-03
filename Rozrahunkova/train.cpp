//train.cpp

#include "train.h"


//4 types of constructor
Train::Train()
    :Time(),
     nDestination(""),
     nPlatform(0)
{
    std::cout<<"- Train::Train"<<std::endl;
}
Train::Train(const int& h,const int& m,const int& s,const std::__cxx11::string& d,const int& p)
    :Time(h,m,s),
     nDestination(d),
     nPlatform(p)
{
    std::cout<<"- Train::Train(const int& h,const int& m,const int& s,const std::__cxx11::string& d,const int& p)"<<std::endl;

}

Train::Train(const Train &tr):
    Time(tr)
{
    std::cout<<"- Train::Train(const Train &tr)"<<std::endl;
    //Time(tr.nHours,tr.nMinutes,tr.nSeconds);
    //Time(Time(tr));
    nDestination=tr.nDestination;
    nPlatform=tr.nPlatform;
}

Train::Train(Train &&tr)
    :Time(tr)
{
    //Time(tr.nHours,tr.nMinutes,tr.nSeconds);
    nDestination=tr.nDestination;
    nPlatform=tr.nPlatform;
}

//destructor
Train::~Train()
{}

Train &Train::operator=(const Train &tr)
{
    if(this == &tr)
        return *this;
    //Time(tr.nHours,tr.nMinutes,tr.nSeconds);
    Time::operator =(tr);
    nDestination=tr.nDestination;
    nPlatform=tr.nPlatform;
    return *this;
}
//Setting of data
void Train::set_data(int h, int m, int s, std::__cxx11::string d, int p)
{
    Time::set_data(h,m,s);
    nDestination=d;
    nPlatform=p;

}
//5 types of get functions for different values
int& Train::get_hours()
{
    return nHours;
}
int& Train::get_minutes()
{
    return nMinutes;
}
int& Train::get_seconds()
{
    return nSeconds;
}
std::string& Train::get_destination()
{
    return nDestination;

}
int& Train::get_platform()
{
    return nPlatform;
}
//Output data,overloaded function
void Train::show() const
{
    std::cout<<std::setw(9)
             <<nHours<<std::setw(12)
             <<nMinutes<<std::setw(8)
             <<nSeconds<<std::setw(12)
             <<nDestination<<std::setw(9)
             <<nPlatform<<std::endl;

}
