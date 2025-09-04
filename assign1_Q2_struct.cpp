#include<iostream>

using namespace std;
struct date{
    private:
        int day;
        int month;
        int year;

public:
void initDate(struct date *ptr){
    ptr->day=23;
    ptr->month=9;
    ptr->year=2025;
    cout<<"The date is(via initlaize): "<<ptr->day<<'/'<<ptr->month<<'/'<<ptr->year<<endl;

}
void printDateOnConsole(struct date *ptr){

        cout<<"The date is(via printDateOnConsole  ): "<<ptr->day<<'/'<<ptr->month<<'/'<<ptr->year<<endl;

}
void acceptDateOnConsole(struct date *ptr){
    cout<<"Enter the day :"<<endl;
    cin>>ptr->day;

    cout<<"Enter the month :"<<endl;
    cin>>ptr->month;

    cout<<"Enter the year"<<endl;
    cin>>ptr->year;

    cout<<"Date accepted"<<endl;
    cout<<"The date is(via accept): "<<ptr->day<<'/'<<ptr->month<<'/'<<ptr->year<<endl;

}
void isLeapYear(struct date *ptr){
    cout<<"The year is :"<<ptr->year<<endl;
    if((ptr->year%4==0 && ptr->year%100!=0)|| (ptr->year%400==0))
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
    struct date d1;

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
        case 1:{
            cout<<"Entered option 1"<<endl;
            d1.initDate(&d1);
            break;
        }
        case 2:{
            cout<<"Entered option 2"<<endl;
            d1.printDateOnConsole(&d1);
            break;
        }
        case 3:{
            cout<<"Entered option 3"<<endl;
            d1.acceptDateOnConsole(&d1);
            break;
        }
        case 4:{
            cout<<"Entered option 4"<<endl;
            d1.isLeapYear(&d1);
            break;
        }
        
        default:{
            cout<<"Invalid option"<<endl;
            break;
        }
    }
    } while (x!=0);
    
    return 0;
}
