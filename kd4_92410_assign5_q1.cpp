

#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class Date{
    private :
    int day;
    int month;
    int year;
    public:
    Date(void):day(0),month(0),year(0){}
    Date(int day,int month,int year):day(day),month(month),year(year){ }
    void setDate(void){
        cout<<"Enter the day :"<<endl;
        cin>>day;
        cout<<"Enter the month :"<<endl;
        cin>>month;
        cout<<"Enter the year :"<<endl;
        cin>>year;
    }
    void getDate(void){
        cout<<"The date is :"<<day<<"/"<<month<<"/"<<year<<endl;
    }
};

class person{
    string name;
    string address;
    Date *dob;

    //tight coupling
    public:
    person(void):name(" "),address(" "),dob(NULL)
    { }
    person(string name,string address):name(name),address(address){
        dob=NULL;
    }
    person(string name,string address,int day,int month,int year):person(name,address){
        dob=new Date(day,month,year);
    }
    void acceptDetailsOfPerson(void){
        
        cout<<"Loose coupling example(aggregation) :"<<endl;
        cout<<"Name :"<<endl;
        cin.ignore();
        getline(cin,name);
        cout<<"address:"<<endl;
        getline(cin,address);
        this->setDatePtr( );
    }
    void setDatePtr(void){
        if (dob!=NULL){
            delete dob;
            dob=NULL;
        }
        dob=new Date();
        dob->setDate();
    }
    void showDetailsofPerson(void){
        
        cout<<"-----presenting details----"<<endl;
        cout<<"name :"<<name<<endl;
        cout<<"address :"<<address<<endl;
        if(dob!=NULL){
            dob->getDate( );
        }
    }
    ~person(){
        if(dob!=NULL){
            delete dob;
            dob=NULL;
        }
    }
};

class Student{
    private:
    int id;
    int marks;
    string course;
    Date start_date;
    Date end_date;
    public:
    Student(void):id(0),marks(0),course(" "),start_date(),end_date(){}
    Student(int id,int marks,string course,Date start_date,Date end_date):id(id),marks(marks),course(course),start_date(start_date),end_date(end_date){}
    Student(int id,int marks,string course,int sday,int smonth,int syear,int eday,int emonth,int eyear):id(id),marks(marks),course(course),start_date(sday,smonth,syear),end_date(eday,emonth,eyear){}
    void setStudent(void){
        cout<<"Enter the id :"<<endl;
        cin>>id;
        cout<<"Enter the marks :"<<endl;
        cin>>marks;
        cout<<"Enter the course :"<<endl;
        cin>>course;
        cout<<"Enter the start date :"<<endl;
        start_date.setDate();
        cout<<"Enter the end date :"<<endl;
        end_date.setDate();
    }
    void getStudent(void){
        cout<<"id :"<<id<<endl;
        cout<<"marks :"<<marks<<endl;
        cout<<"course :"<<course<<endl;
        cout<<"Start course ->";
        start_date.getDate();
        cout<<"end course -> ";
        end_date.getDate();
    }
};



int main(){
    cout<<"deafult date parameter :"<<endl;
    Date d1;
    cout<<"------------------------"<<endl;
    d1.getDate();
    cout<<"paramterized date"<<endl;
    cout<<"------------------------"<<endl;
    Date d2={10,12,2023};
    d2.getDate();
    cout<<"------------------------"<<endl;
    cout<<"input date "<<endl;
    Date d3;
    d3.setDate();
    d3.getDate(); 
    cout<<"------------------------"<<endl;
    cout<<"student paramteried :"<<endl;
    Student s1(23,23,"wndlish",{23,01,2022},{23,11,2022});
    s1.getStudent();
    cout<<"------------------------"<<endl;
    cout<<"student paramterized"<<endl;
    Student s2(23,23,"wndlish",23,01,2022,23,11,2022);
    cout<<"------------------------"<<endl;
    cout<<"user input from student"<<endl;
    s2.setStudent();
    s2.getStudent();
    cout<<"------------------------"<<endl;

    person p1;
    p1.acceptDetailsOfPerson();
    p1.showDetailsofPerson();


    return 0;
}