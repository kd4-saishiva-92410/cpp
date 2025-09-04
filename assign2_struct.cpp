#include<iostream>

using namespace std;
struct date{
    private:
        int day;
        int month;
        int year;

public:
void initDate(){
    day=23;
    month=9;
    year=2025;
    cout<<"The date is(via initlaize): "<<day<<'/'<<month<<'/'<<year<<endl;

}
void printDateOnConsole(){

        cout<<"The date is(via printDateOnConsole  ): "<<day<<'/'<<month<<'/'<<year<<endl;

}
void acceptDateOnConsole(){
    cout<<"Enter the day :"<<endl;
    cin>>day;

    cout<<"Enter the month :"<<endl;
    cin>>month;

    cout<<"Enter the year"<<endl;
    cin>>year;

    cout<<"Date accepted"<<endl;
    cout<<"The date is(via accept): "<<day<<'/'<<month<<'/'<<year<<endl;

}
void isLeapYear(){
    cout<<"The year is :"<<year<<endl;
    if((year%4==0 && year%100!=0)|| (year%400==0))
    {
        cout<<"Leap year"<<endl;
    }
    else{
        cout<<"not leap year"<<endl;
    }
    
}
};


int main(){
    int x;
    class date d1;

    cout<<"options for menu"<<endl;

    do
    {
        cout<<"--------------------------------"<<endl;
        cout<<"The value of x ->1:Initalize "<<endl;
        cout<<"The value of x ->2:print On cosole "<<endl;
        cout<<"The value of x ->3:accept date "<<endl;
        cout<<"The value of x->4:check leap year or not"<<endl;
        cout<<"Enter the value of x :"<<endl;
        cin>>x;

        switch (x)
        {
        case 1:
            cout<<"Entered option 1"<<endl;
            d1.initDate();
            break;
        case 2:
            cout<<"Entered option 2"<<endl;
            d1.printDateOnConsole();
            break;
        case 3:
            cout<<"Entered option 3"<<endl;
            d1.acceptDateOnConsole();
            break;
        case 4:
            cout<<"Entered option 4"<<endl;
            d1.isLeapYear();
            break;
        
        default:
            cout<<"Invalid option"<<endl;
            break;
        }
    } while (x!=0);
    
    return 0;
}
