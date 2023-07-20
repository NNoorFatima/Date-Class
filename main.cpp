#include <iostream>
#include "date.cpp"
using namespace std;
int main()
{
   Date d1(3980,02,8);      ///making use of the constructor
   Date d2(2023,5,16);
   Date d3(2000,1,1);
   //assigning d2 to d3 using =
   d3=d2;
   //O/P of d3
   cout<<d3;
   //adding 5 days to d1 so the new date will be  13/02/3980
   d1=d1+5;
   cout<<d1;
   //subtracting 5 days from d1 so the new date will be 8/2/3980
   d1=d1-5;
   cout<<d1;
   //adding d1 and d2 and storing in d3
   d3=d1+d2;
   cout<<d3;
   //subtracting d3 and d2 which will be equal to initial value of d1 ie 8/2/3980
   cout<<d3-d2;
   //outputting all three d1,d2,d3 
    cout<<"D1 :"<<d1;
    cout<<"D2 :"<<d2;
    cout<<"D3 :"<<d3;
    //comparing the three dates 
    if(d1>d2)
        cout<<"D1 > D2\n";
    else
        cout<<"D2 > D1\n";
    //usage of <
    if(d1<d2)
        cout<<"D1 < D2\n";
    else
        cout<<"D2 < D1\n";
    //using !=
    if(d1!= d2)
        cout<<"d1!=d2\n";
    else
        cout<<"d1==d2\n";
    //assigning d1 to d2
    d2=d1;
    //using ==
    if(d1== d2)
        cout<<"d1==d2\n";
    else
        cout<<"d1!=d2\n";
        
    //creating d4
    Date d4(1956,6,12);
    cout<<"is d4 a leap year: "<<d4.isLeapYear();
   
    return 0;
}
