//main.cpp

#include <random>
#include <time.h>
#include <stdio.h>
#include "times.h"
#include "train.h"
#include "schedule.h"

int main()
{
   std::vector<Train>tr;//dynamical array of Train objects
   std::string AllStations[5]={"Kyiv","Lviv","Kharkiv","Odesa","Vinutsa"};
   std::string str;
   srand(time(NULL));

   for(int i(0);i<10;i++)
   {
       str=AllStations[rand()%5];

       int arg1=rand()%23,
           arg2=rand()%59,
           arg3=rand()%59,
           arg5=rand()%9+1;//random data to initialize of objects

       tr.push_back(Train(arg1,arg2,arg3,str,arg5));//initialize of objects
   }

   Schedule s(tr);
   char c;

   //interface to work with user
   bgn:
   std::cout<<"Choose one:"<<std::endl;
   std::cout<<"s-to see train schedule"<<std::endl;
   std::cout<<"n-to see next train to choosed station"<<std::endl;
   std::cout<<"b-to go back into menu "<<std::endl;
   std::cout<<"e-to exit from program"<<std::endl;
   while(c!='e')
   {
       std::cout<<"Write number:";
       std::cin>>c;
       switch(c)
       {
       case 's':s.show();break;
       case 'n':s.next_train();break;
       case 'b':system("cls");goto bgn;break;
       default:c='e';
       }
   }
    return 0;
}
