#include<iostream>
using namespace std;



class Tollbooth{
    private:
    unsigned int total_cars;
    unsigned int total_pay_cars;
    unsigned int total_nopay_cars;
    double total_amt;

    public:
    Tollbooth(void){
        this->total_cars=0;
        this->total_amt=0;
        this->total_pay_cars=0;
        this->total_nopay_cars=0;
    }
    int payingCar(){
        total_pay_cars=total_pay_cars+1;
        total_amt=total_amt+0.50;

    }
    int nopayCar(){
        total_nopay_cars=total_nopay_cars+1;

    }
    void printOnConsole(){
        cout<<"The total cars and total amount is"<<endl;
        total_cars=total_nopay_cars+total_pay_cars;
        cout<<"Total cars : "<<total_cars<< " ||Total amount : "<<total_amt<<endl;

    }
};

int main(){
    Tollbooth t1;
    int paying_cars;
    int non_paying_cars;
    cout<<"How many paying cars are passing :"<<endl;
    cin>>paying_cars;
    cout<<"How many non paying cars are passing :"<<endl;
    cin>>non_paying_cars;

    for(int i=1;i<=paying_cars;i++){
        t1.payingCar();
    }
    for(int i=1;i<=non_paying_cars;i++){
        t1.nopayCar();
    }

    cout<<"Total info"<<endl;
    t1.printOnConsole();


    return 0;
}