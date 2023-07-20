//header file for date class
class Date
{
    int day; 
    int month;
    int year;
    public:
    Date();
    Date(int y, int m, int d);
    void operator=(Date& d);
    bool isLeapYear();
    int getYear();
    int getMonth();
    int getDay();
    Date& operator+(int n);
    Date& operator-(int n);
    Date& operator+(Date& a);
    Date& operator-(Date& a);
    bool operator<(Date& a);
    bool operator<=(Date& a);
    bool operator>(Date & a);
    bool operator>=(Date & a);
    bool operator==(Date& a);
    bool operator!=(Date& a);
    string toString();
    friend ostream& operator<<(ostream& output,Date& d );
};
