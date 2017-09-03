//times.h
#ifndef TIME_H
#define TIME_H

#include <cstdlib>
#include <iostream>
#include <iomanip>

class Time
{
public:
    Time();
    Time(const int&,const int&,const int&);
    Time(const Time &);
    Time(Time &&);
    virtual ~Time();

    virtual int& get_hours();
    virtual int& get_minutes();
    virtual int& get_seconds();

    virtual void set_data(int,int,int);

    virtual void show() const;
    void check_data(int,int,int);

    Time &operator=(const Time &);
    friend  Time &operator+=(Time&,Time &);
    friend  Time &operator+=(Time&,int);
    friend  Time &operator-=(Time &,Time &);
    friend  Time &operator-=(Time &,int);

    friend  std::ostream &operator<<(std::ostream &stream,const Time &obj);
    friend  std::istream  &operator>>(std::istream &stream,Time &obj);
protected:
    int nHours;
    int nMinutes;
    int nSeconds;
};

#endif // TIME_H
