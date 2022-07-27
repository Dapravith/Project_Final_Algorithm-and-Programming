#include<iostream>
#include<ctime>
using namespace std;

string month(int n){

     string month[12] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sept","Oct","Nov","Dec"};
     return month[n];
}

string day(int n){

  string day[7] = {"Sunday","Monday","Tuesday","Wednesday","Thurday","Friday","Saturday"};
  return day[n];

}


//main(){
//
//
//
//     time_t now = time(0);
//     tm*T = localtime(&now);
//
//     cout<<day(T->tm_wday)<<", "<<T->tm_mday<<"/ "<<month(T->tm_mon)<<"/ "<<1900+T->tm_year;
//
//
//     file<<"<"<<day(ltm->tm_wday)<<", "<<month(ltm->tm_mon)<<", "<<1900+ltm->tm_year<<" >";
//
//}
