#include<iostream>
#include<fstream>
using namespace std;

class employee {
    char name[20];
    int ID;
    double salary;

public:
    void accept() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter ID: ";
        cin >> ID;
        cout << "Enter salary: ";
        cin >> salary;
        cout<<endl;
    }

    void display() {
        cout << "Name: " << name <<endl;
        cout << "ID: " << ID <<endl;
        cout << "Salary: " << salary << endl;
        cout<<endl;
    }
};

int main() {
    employee o[5];
    fstream f;
    int i, n;

    cout << "How many employee information do you need to store? ";
    cin >> n;

    f.open("employee.txt", ios::out | ios::binary);

    cout << "Enter information of Employees:" << endl;
    for(i = 0; i < n; i++) {
        cout << "Enter information of Employee " << (i + 1) << ":" << endl;
        o[i].accept();
        f.write((char*)&o[i], sizeof(o[i]));
    }
    f.close();

    f.open("employee.txt", ios::in | ios::binary);

    cout << "Information of employees is as follows:" << endl;
    for(i = 0; i < n; i++) {
        f.read((char*)&o[i], sizeof(o[i]));
        o[i].display();
    }
    f.close();

    return 0;
}