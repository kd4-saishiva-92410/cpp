#include<iostream>
#include<typeinfo>
#include<string>
#include<vector>
using namespace std;

class Employee {
protected:
    int id;
    double salary;

public:
    Employee() : id(0), salary(0.0) {}
    Employee(int id, double salary) : id(id), salary(salary) {}

    virtual void accept() {
        cout << "Enter id: ";
        cin >> this->id;
        cout << "Enter salary: ";
        cin >> this->salary;
    }

    virtual void display() {
        cout << "Id: " << this->id << ", Salary: " << this->salary;
    }

    virtual ~Employee() {} // Virtual destructor
};

//---------------- Manager -----------------
class Manager : virtual public Employee {
protected:
    double bonus;

public:
    Manager() : Employee(), bonus(0) {}
    Manager(int id, double salary, double bonus) : Employee(id, salary), bonus(bonus) {}

    void accept() override {
        Employee::accept();
        cout << "Enter Manager bonus: ";
        cin >> this->bonus;
    }

    void display() override {
        cout << "[Manager] ";
        Employee::display();
        cout << ", Bonus: " << this->bonus << endl;
    }
};

//---------------- Salesman -----------------
class Salesman : virtual public Employee {
protected:
    double commission;

public:
    Salesman() : Employee(), commission(0) {}
    Salesman(int id, double salary, double commission) : Employee(id, salary), commission(commission) {}

    void accept() override {
        Employee::accept();
        cout << "Enter Salesman commission: ";
        cin >> this->commission;
    }

    void display() override {
        cout << "[Salesman] ";
        Employee::display();
        cout << ", Commission: " << this->commission << endl;
    }
};

//---------------- SalesManager -----------------
class SalesManager : public Manager, public Salesman {
public:
    SalesManager() : Manager(), Salesman() {}
    SalesManager(int id, double salary, double bonus, double commission)
        : Employee(id, salary), Manager(id, salary, bonus), Salesman(id, salary, commission) {}

    void accept() override {
        Employee::accept();
        cout << "Enter Manager bonus: ";
        cin >> this->bonus;
        cout << "Enter Salesman commission: ";
        cin >> this->commission;
    }

    void display() override {
        cout << "[SalesManager] ";
        Employee::display();
        cout << ", Bonus: " << this->bonus << ", Commission: " << this->commission << endl;
    }
};

//---------------- Menu Operations -----------------
void addManager(vector<Employee*> &employee_list) {
    Employee *emp = new Manager();
    emp->accept();
    employee_list.push_back(emp);
    cout << "Manager added.\n";
}

void addSalesman(vector<Employee*> &employee_list) {
    Employee *emp = new Salesman();
    emp->accept();
    employee_list.push_back(emp);
    cout << "Salesman added.\n";
}

void addSalesManager(vector<Employee*> &employee_list) {
    Employee *emp = new SalesManager();
    emp->accept();
    employee_list.push_back(emp);
    cout << "SalesManager added.\n";
}

void displayCount(vector<Employee*> &employee_list) {
    int m = 0, s = 0, sm = 0;
    for (auto e : employee_list) {
        if (typeid(*e) == typeid(Manager))
            m++;
        else if (typeid(*e) == typeid(Salesman))
            s++;
        else if (typeid(*e) == typeid(SalesManager))
            sm++;
    }
    cout << "Managers: " << m << ", Salesmen: " << s << ", SalesManagers: " << sm << endl;
}

void displayAllManagers(vector<Employee*> &employee_list) {
    bool found = false;
    for (auto e : employee_list) {
        if (typeid(*e) == typeid(Manager)) {
            e->display();
            found = true;
        }
    }
    if (!found) cout << "No Managers found.\n";
}

void displayAllSalesmen(vector<Employee*> &employee_list) {
    bool found = false;
    for (auto e : employee_list) {
        if (typeid(*e) == typeid(Salesman)) {
            e->display();
            found = true;
        }
    }
    if (!found) cout << "No Salesmen found.\n";
}

void displayAllSalesManagers(vector<Employee*> &employee_list) {
    bool found = false;
    for (auto e : employee_list) {
        if (typeid(*e) == typeid(SalesManager)) {
            e->display();
            found = true;
        }
    }
    if (!found) cout << "No SalesManagers found.\n";
}

//---------------- Menu -----------------
int menu() {
    int choice;
    cout << "\n0. Exit\n";
    cout << "1. Add Manager\n";
    cout << "2. Add Salesman\n";
    cout << "3. Add SalesManager\n";
    cout << "4. Display count of employees by designation\n";
    cout << "5. Display all Managers\n";
    cout << "6. Display all Salesmen\n";
    cout << "7. Display all SalesManagers\n";
    cout << "Enter choice: ";
    cin >> choice;
    return choice;
}

int main() {
    vector<Employee*> employee_list;
    int choice;
    while ((choice = menu()) != 0) {
        switch (choice) {
        case 1: addManager(employee_list); break;
        case 2: addSalesman(employee_list); break;
        case 3: addSalesManager(employee_list); break;
        case 4: displayCount(employee_list); break;
        case 5: displayAllManagers(employee_list); break;
        case 6: displayAllSalesmen(employee_list); break;
        case 7: displayAllSalesManagers(employee_list); break;
        default: cout << "Invalid choice!\n"; break;
        }
    }

    // Free memory
    for (auto e : employee_list) delete e;

    return 0;
}
