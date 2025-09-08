#include<iostream>
using namespace std;

class Tollbooth {
private:
    unsigned int total_cars;
    double total_amt;

public:
    Tollbooth() {
        total_cars = 0;
        total_amt = 0.0;
    }

    void payingCar() {
        total_cars++;
        total_amt += 0.50;
    }

    void nopayCar() {
        total_cars++;
    }

    void printOnConsole() {
        int paying_cars = total_amt / 0.50;
        int non_paying_cars = total_cars - paying_cars;

        cout << "The total paid cars : " << paying_cars << endl;
        cout << "The total non paid cars : " << non_paying_cars << endl;
        cout << "Total cars : " << total_cars
             << " || Total amount : $" << total_amt << endl;
    }
};

int main() {
    Tollbooth t1;
    int x, count;

    do {
        cout<<"_____________menu_____________"<<endl;
        cout<<"0 : exit"<<endl;
        cout<<"1 : enter non paying cars"<<endl;
        cout<<"2 : enter paying cars"<<endl;
        cout<<"3 : display totals"<<endl;
        cout<<"Enter your choice: ";
        cin>>x;

        switch (x) {
            case 0:
                cout<<"Exit"<<endl;
                break;
            case 1:
                cout<<"How many non paying cars? ";
                cin>>count;
                for(int i=0;i<count;i++) t1.nopayCar();
                break;
            case 2:
                cout<<"How many paying cars? ";
                cin>>count;
                for(int i=0;i<count;i++) t1.payingCar();
                break;
            case 3:
                t1.printOnConsole();
                break;
            default:
                cout<<"Invalid option!"<<endl;
        }
    } while (x!=0);

    return 0;
}
