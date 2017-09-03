//times.cpp

#include "times.h"
#include <random>

//3 types of constructor
Time::Time()
{
    std::cout<<"- Time::Time()"<<std::endl;
    nHours = 0;
    nMinutes = 0;
    nSeconds = 0;
}
Time::Time(const int& h,const int &m,const int &s)
{
    std::cout<<"- Time::Time(const int& h,const int &m,const int &s)"<<std::endl;
    check_data(h,m,s);
    nHours=h;nMinutes=m;nSeconds=s;
}
Time::Time(const Time &time)
{
    std::cout<<"- Time::Time(const Time &time)"<<std::endl;
    check_data(time.nHours,time.nMinutes,time.nSeconds);
    nHours=time.nHours;
    nMinutes=time.nMinutes;
    nSeconds=time.nSeconds;

}
Time::Time(Time &&time)
{
    check_data(time.nHours,time.nMinutes,time.nSeconds);
    nHours=time.nHours;
    nMinutes=time.nMinutes;
    nSeconds=time.nSeconds;

}
//destructor
Time::~Time()
{}
//3 type of get functions for different values
int& Time::get_hours()
{
    return nHours;
}
int& Time::get_minutes()
{
    return nMinutes;
}
int& Time::get_seconds()
{
    return nSeconds;
}
//Setting data
void Time::set_data(int h,int m,int s)
{
    check_data(h,m,s);
    nHours=h;
    nMinutes=m;
    nSeconds=s;

}
//Output data
void Time::show() const
{
    std::cout<<nHours<<std::setw(12)
            <<nMinutes<<std::setw(6)
            <<nSeconds<<std::setw(8)
            <<std::endl;

}
//Checking of correct data input
void Time::check_data(int h, int m, int s)
{
    try{
        if(h>23)throw 1;
        if(m>59)throw 1.1;
        if(s>59)throw "1";
    }
    catch(int ){
        std::cout<<"Wrong data,number of hours should be less than 24";
        exit(1);
    }
    catch(double){
        std::cout<<"Wrong data,number of minutes should be less than 60";
        exit(1);
    }
    catch(char const*){
        std::cout<<"Wrong data,number of hours should be less than 24";
        exit(1);
    }

}
//overloaded operator=
Time &Time::operator=(const Time &time)
{
    if(this==&time)
        return *this;
    nHours=time.nHours;
    nMinutes=time.nMinutes;
    nSeconds=time.nSeconds;
    return *this;
}
 //overloaded operators+=,growind up data on choosed value
 Time &operator+=(Time &left,Time &right)
 {
     left.nHours+=right.nHours;
     return left;
 }
 Time &operator+=(Time &left,int right)
 {
     left.nHours+=right;
     return left;
 }
  //overloaded operators-=,reducing data on choosed value
 Time &operator-=(Time &left,Time &right)
 {
     left.nHours-=right.nHours;
     return left;
 }
 Time &operator-=(Time &left,int right)
 {
     left.nHours-=right;
     return left;
 }
 //overloaded operators << & >>,using for input and output of data
std::ostream& operator<<(std::ostream& stream,const Time& obj)
{
    stream<<obj.nHours<<':'<<obj.nMinutes<<':'<<obj.nSeconds<<std::endl;
    return stream;

}
std::istream&operator>>(std::istream &stream,Time &obj)
{
    std::cout<<"Enter hours:";
    stream>>obj.nHours;
    std::cout<<"Enter minutes:";
    stream>>obj.nMinutes;
    std::cout<<"Enter seconds:";
    stream>>obj.nSeconds;
    return stream;
}
