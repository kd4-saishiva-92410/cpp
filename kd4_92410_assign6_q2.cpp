#include <iostream>
using namespace std;

class Employee {
protected:
    int id;
    double salary;

public:
    Employee() : id(0), salary(0.0) {}
    Employee(int id, double salary) : id(id), salary(salary) {}

    void setId(int id) {
        cout << "Enter an id: ";
        cin >> this->id;
    }

    void setSalary(double salary) {
        cout << "Enter the salary: ";
        cin >> this->salary;
    }

    double getSalary() {
        return this->salary;
    }

    virtual void accept() {
        cout << "Enter the id: ";
        cin >> this->id;
        cout << "Enter the salary: ";
        cin >> this->salary;
    }

    virtual void display() {
        cout << "id: " << this->id << ", salary: " << this->salary;
    }
};

class Manager : virtual public Employee {
protected:
    double bonus;

public:
    Manager() : Employee(), bonus(0) {}
    Manager(int id, double salary, double bonus) : Employee(id, salary), bonus(bonus) {}

    void setBonus(double bonus) {
        cout << "Enter the Manager bonus: ";
        cin >> this->bonus;
    }

    double getBonus() {
        return this->bonus;
    }

    void accept() override {
        cout << "Manager details:" << endl;
        Employee::accept();  
        acceptManager();
    }

    void acceptManager() {
       
        cout << "Enter the manager bonus: ";
        cin >> this->bonus;
    }

    void display() override {
        cout << "Manager details:" << endl;
        Employee::display();
        displayManager();
    }

    void displayManager() {
        cout << "Manager details:" << endl;
        cout << "Manager Bonus: " << this->bonus << endl;
    }
};

class Salesman : virtual public Employee {
protected:
    double commission;

public:
    Salesman() : Employee(), commission(0) {}
    Salesman(int id, double salary, double commission) : Employee(id, salary), commission(commission) {}

    void setCommission(double commission) {
        cout << "Enter the Salesman commission: ";
        cin >> this->commission;
    }

    double getCommission() {
        return this->commission;
    }

    void accept() override {
        cout << "Salesman details:" << endl;
        Employee::accept();  // id & salary
        acceptSalesman();
    }

    void acceptSalesman() {
        cout << "Enter the Salesman commission: ";
        cin >> this->commission;
    }

    void display() override {
        cout << "Salesman display:" << endl;
        Employee::display();
        displaySalesman();
    }

    void displaySalesman() {
        cout << ", Salesman Commission: " << this->commission << endl;
    }
};

class SalesManager : public Manager, public Salesman {
public:
    SalesManager() : Manager(), Salesman() {}
    SalesManager(int id, double salary, double bonus, double commission)
        : Manager(id, salary, bonus), Salesman(id, salary, commission) {}

    void accept() override {
        cout << "SalesManager details:" << endl;
        Employee::accept();  
        Manager::acceptManager();  
        Salesman::acceptSalesman(); 
    }

    void display() override {
        cout << "SalesManager details:" << endl;
        Employee::display();        
        Manager::displayManager(); 
        Salesman::displaySalesman(); 
    }
};

int main() {
    Manager m1;
    m1.accept();   
    m1.display();

    Salesman s1;
    s1.accept();  
    s1.display();


    SalesManager sm1; 
    sm1.accept();
    sm1.display();

    return 0;
}
