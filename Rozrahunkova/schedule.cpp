//Schedule.cpp

#include "schedule.h"


//3 types of constructor
Schedule::Schedule()
{
    std::cout<<"- Schedule::Schedule())"<<std::endl;
}

Schedule::Schedule(const int& h,const int& m,const int& s,const std::string& d,const int& p)
{
    std::cout<<"- Schedule::Schedule(const int& h,const int& m,const int& s,const std::string& d,const int& p)"<<std::endl;
    nTrainSchedule.push_back(Train(h,m,s,d,p));
}

Schedule::Schedule(const Train &tr)
{
    std::cout<<"- Schedule::Schedule(const Train &tr)"<<std::endl;
    nTrainSchedule.push_back(tr);
}

Schedule::Schedule(std::vector<Train>&tr)
{
    std::cout<<"- Schedule::Schedule(std::vector<Train>&tr)"<<std::endl;
    nTrainSchedule = tr;
}

Schedule::~Schedule()
{

}

//Data output
void Schedule::show()
{
    std::cout<<"- Schedule::show()"<<std::endl;
    std::cout<<std::setw(9)
             <<"Hours"<<std::setw(12)
             <<"Minutes"<<std::setw(8)
             <<"Seconds"<<std::setw(12)
             <<"Destination"<<std::setw(9)
             <<"Platform"<<std::endl;
    for(auto it=nTrainSchedule.begin();it!=nTrainSchedule.end();++it)
    {
        nTrainSchedule[it - nTrainSchedule.begin()].show();
    }
}

//Setting of Data
void Schedule::set_data(const int& h,const int& m,const int& s,const std::string& d,const int& p)
{
    std::cout<<"- Schedule::set_data()"<<std::endl;
    nTrainSchedule.push_back(Train(h,m,s,d,p));
}

void Schedule::set_data(const Train &tr)
{
    std::cout<<"- Schedule::set_data(const Train &tr)"<<std::endl;
    nTrainSchedule.push_back(tr);
}

//Function,which set current time of system
void Schedule::real_time()
{
    t = time(0);   // get time now
    now = localtime( & t );
    nRealTime.set_data(now->tm_hour,now->tm_min,now->tm_sec);
}

//Use it to find next train to choosed station
void Schedule::next_train()
{
    bool isInitialized=false;
    std::string station;
    int next_train_hours,next_train_minutes,next_train_seconds;
    std::cout<<"Please,enter station:";
    std::cin>>station;
    for(auto it=nTrainSchedule.begin();it!=nTrainSchedule.end();++it)
    {

        if(nTrainSchedule[it-nTrainSchedule.begin()].get_destination()==station)
        {
            if(!isInitialized)
            {
                next_train_hours=nTrainSchedule[it-nTrainSchedule.begin()].get_hours();
                next_train_minutes= nTrainSchedule[it-nTrainSchedule.begin()].get_minutes();
                next_train_seconds=nTrainSchedule[it-nTrainSchedule.begin()].get_seconds();
                isInitialized=true;
            }
            else
            {
                if(next_train_hours<nRealTime.get_hours())
                {
                    if(nTrainSchedule[it-nTrainSchedule.begin()].get_hours()>nRealTime.get_hours())
                        {
                            next_train_hours=nTrainSchedule[it-nTrainSchedule.begin()].get_hours();
                            next_train_minutes= nTrainSchedule[it-nTrainSchedule.begin()].get_minutes();
                            next_train_seconds=nTrainSchedule[it-nTrainSchedule.begin()].get_seconds();
                        }
                }
                else if(next_train_hours>=nRealTime.get_hours())
                {
                    if(nTrainSchedule[it-nTrainSchedule.begin()].get_hours()>nRealTime.get_hours() &&
                            nTrainSchedule[it-nTrainSchedule.begin()].get_hours()<next_train_hours )
                        {
                            next_train_hours=nTrainSchedule[it-nTrainSchedule.begin()].get_hours();
                            next_train_minutes= nTrainSchedule[it-nTrainSchedule.begin()].get_minutes();
                            next_train_seconds=nTrainSchedule[it-nTrainSchedule.begin()].get_seconds();
                        }
                    else if(nTrainSchedule[it-nTrainSchedule.begin()].get_hours()==next_train_hours)
                        {
                            if( nTrainSchedule[it-nTrainSchedule.begin()].get_minutes()<next_train_minutes)
                            {
                                next_train_hours=nTrainSchedule[it-nTrainSchedule.begin()].get_hours();
                                next_train_minutes= nTrainSchedule[it-nTrainSchedule.begin()].get_minutes();
                                next_train_seconds=nTrainSchedule[it-nTrainSchedule.begin()].get_seconds();
                            }
                            else if(nTrainSchedule[it-nTrainSchedule.begin()].get_minutes()==next_train_minutes)
                            {
                                if( nTrainSchedule[it-nTrainSchedule.begin()].get_seconds()<next_train_seconds)
                                {
                                    next_train_hours=nTrainSchedule[it-nTrainSchedule.begin()].get_hours();
                                    next_train_minutes= nTrainSchedule[it-nTrainSchedule.begin()].get_minutes();
                                    next_train_seconds=nTrainSchedule[it-nTrainSchedule.begin()].get_seconds();
                                }

                            }
                       }

                }
            }
       }
    }
    if(!isInitialized)
    {
        std::cout<<"No trains from this station"<<std::endl;
    }
    else
    {
        std::cout<<"Next train for today:";
        std::cout<<next_train_hours<<':'<<next_train_minutes<<':'<<next_train_seconds<<std::endl;
    }
}
