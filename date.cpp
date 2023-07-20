//===========================================================
string Date:: toString()
{
    // string year;
    // string month;
    // string day;
    // //first find the length of the year
    // int s=year;int i=0;
    // while((s/=10) != 0)
    //     i++;
    // i++;
        
}
//===========================================================
Date& Date::operator-(int n)
{
    if(n<day)
    {
        day= day-n;
    }
    else 
    {
        n=  n-day;
        
        if(month!=1)
                month--;
        else
        {
            year--;
            month=12;
        }
        
        
        int month_days;
        if(month==4||month==6||month==9||month==11)
            month_days=30;
        else if(month==2)
        {
            if(isLeapYear()==1)
                month_days=29;
            else
                month_days=28;
        }
        else
            month_days=31;
          
        while (n>=month_days)
        {
            n= n-month_days;
            if(month!=1)
                month--;
            else
            {
                year--;
                month=12;
            }
            //finding month days again 
            if(month==4||month==6||month==9||month==11)
                month_days=30;
            else if(month==2)
            {
                if(isLeapYear()==1)
                    month_days=29;
                else
                    month_days=28;          //eg dates was 2023/5/16 and n= 50   n=19 month=4 so now while conditon is 19>=30
            }                               //exits loop
            else
                month_days=31;
            
        }
        day= month_days-n;
        
        
    }
        return *this;
    
}
//===========================================================
Date& Date:: operator+(int n)       
{
    //jan, mar, may, july, aug, oct, dec have 31 days 
    // others have 30 days with exception of feb 
    //if it is a leap year feb has 29 days else 28
    int days_left;
    int month_days;
    if(month != 02)
    {
        if(month==8 || month==3 || month==5 || month==7 || month==10 || month==12 || month == 1)
        {    days_left=31-day;month_days=31;}
        else
        {    days_left=30-day;month_days=30;}
    }
    else 
    {
        if(isLeapYear()==1)
        {    days_left=29-day;month_days=29;}
        else
        {   days_left=28-day;month_days=28;}
    }
    
    if(n<days_left)
    {
        day+=n;
    }
    else//n=4 days left 30-day  n=n-days
    {
        n=n - days_left;
        month+=1;
        if(month != 2)
        {
            if(month==8 || month==3 || month==5 || month==7 || month==10 || month==12 || month == 1)
                month_days=31;
            else
                month_days=30;
        }
        else
        {
            if(isLeapYear()==1)
                month_days=29;
            else
                month_days=28;
        }
        // cout<<n<<endl;
        //  cout<<month_days<<endl;
        //  cout<<"Month: "<<month<<endl;
        while(n>=month_days)
        {
            n= n-month_days;
            // cout<<n<<endl;
            if(month>=12)
            {
                year+=1;
                month=1;
            }
            else
            {
                month+=1;
            }
            if(month != 2)
            {
                if(month==8 || month==3 || month==5 || month==7 || month==10 || month==12 || month == 1)
                    month_days=31;
                else
                    month_days=30;
            }
            else
            {
                if(isLeapYear()==1)
                    month_days=29;
                else
                    month_days=28;
            }
            day = n;
        }
         
    }
    return *this;
    
}
//===========================================================
bool Date :: operator>=(Date& a)
{
    if(year>=a.year)
        return 1;
    else if(year==a.year)
    {
        if(month>=a.month)
            return 1;
    }
    else if(year==a.year && month==a.month)
    {
        if(day>=a.day)
            return 1;
    }
    return 0;
}
//===========================================================
bool Date :: operator>(Date& a)
{
    if(year>a.year)
        return 1;
    else if(year==a.year)
    {
        if(month>a.month)
            return 1;
    }
    else if(year==a.year && month==a.month)
    {
        if(day>a.day)
            return 1;
    }
    return 0;
}
//===========================================================
bool Date:: operator<=(Date& a)
{
    if(year<=a.year)
        return 1;
    else if(year==a.year)
    {
        if(month<=a.month)
            return 1;
    }
    else if(year==a.year && month==a.month)
    {
        if(day<=a.day)
            return 1;
    }
    return 0;
}
//===========================================================
bool Date:: operator<(Date& a)
{
    if(year<a.year)
        return 1;
    else if(year==a.year)
    {
        if(month<a.month)
            return 1;
    }
    else if(year==a.year && month==a.month)
    {
        if(day<a.day)
            return 1;
    }
    return 0;
}
//===========================================================

bool Date:: operator!=(Date& a)
{
    if(year==a.year && month==a.month && day==a.day)
        return 0;
    return 1;
}
//===========================================================

bool Date:: operator==(Date& a)
{
    if(year==a.year && month==a.month && day==a.day)
        return 1;
    return 0;
}
//===========================================================
int Date::getYear()
{
    return year;
}
int Date::getMonth()
{
        return month;
}
int Date::getDay()
{
    return day;
}
//===========================================================
bool Date:: isLeapYear()
{
    //leap year is multipleof 4 
    if(year %400==0)
       return 1;
    else if(year % 100==0)
        return 0;
    else if(year % 4==0)
        return 1;
    else
        return 0;
}
//===========================================================
void Date:: operator=(Date& d)
{
    year=d.year;
    month=d.month;
    day=d.day;
    
}
//===========================================================
Date :: Date()
{
    day=0;
    month=0;
    year=0;
}
//===========================================================
Date :: Date(int y, int m ,int d)
{
    day=d;
    year=y;
    month=m;
    
}
//===========================================================
ostream& operator<<(ostream& out, Date& d)
{
    out<<d.year<<"/"<<d.month<<"/"<<d.day<<endl;
    return out;
}
//===========================================================
Date& Date:: operator+(Date& a)
{
    int new_month;
    int new_year;
    int new_day;
    //first we add years
    new_year= year + a.year;
    year=new_year;
    //adding months
    if((month+a.month)>12)
    {
        new_year+=1;
        year=new_year;
        new_month=(month+a.month)-12;
        month=new_month;
        cout<<"HEHE "<<new_month<<endl;
    }
    else
    {    
        new_month=month+a.month;
        month=new_month;
    }
        
    //adding days
    if(new_month==1||new_month==3||new_month==5||new_month==7||new_month==8||new_month==10||new_month==12)
    {
        if((day+a.day)<=31)
        {    
            new_day=day+a.day;
            day=new_day;
        }
        else //assuming both days add up to >31
        {
            Date new_d(new_year,new_month,day);
            new_d= new_d+a.day;
            cout<<"THE NEW DATE IS: "<<new_d<<endl;
            year=new_d.year;
            month=new_d.month;
            day=new_d.day;
        }
    }
    else
    {
        if((day+a.day)<=30)
        {    
            new_day=day+a.day;
            day=new_day;
        }
        else //assuming both days add up to >30
        {
            Date new_d(new_year,new_month,day);
            new_d= new_d+a.day;
            cout<<"THE NEW DATE is: "<<new_d<<endl;
            year=new_d.year;
            month=new_d.month;
            day=new_d.day;
        }
    }
    
    
    return *this;
}
//===========================================================
Date& Date:: operator-(Date& a)
{
    int new_month;
    int new_year;
    int new_day;
    //finding the new year
    if(year>a.year)
    {
        new_year=year-a.year;
        year=new_year;
    }
    else if(a.year>year)
    {
        new_year=a.year-year;
        year=new_year;
    }
    else //if the years are same 
        new_year=year;
        
        
    //finding the new month
    if(month>a.month)
    {
        new_month=month-a.month;
        month=new_month;
    }
    else if(a.month>month)
    {
        new_month=a.month-month;
        month=new_month;
    }
    else//is the months are same 2002/12/1 and 2023/12/1
    {
       new_month=month; 
    }

    //now find the days 
    if(day>a.day)
    {
        new_day=day-a.day;
    }
    else if(a.day>day)
    {
        new_day=a.day-day;
    }
    else 
        new_day=day;
    int month_days;
    
    //now we checck 
    if(new_month==4||new_month==6||new_month==9||new_month==11)
        month_days=30;
    else if(new_month==2)
    {
        if(isLeapYear()==1)
            month_days=29;
        else
            month_days=28;
    }
    else
        month_days=30;
        
    if(new_day>month_days)
    {
        new_day= new_day - month_days;
        if(new_month<12)
            new_month+=1;
        else
        {
            new_month=1;
            new_year+=1;
        }
    }
    
    day=new_day;
    month=new_month;
    year=new_year;
    
    return *this;
}
