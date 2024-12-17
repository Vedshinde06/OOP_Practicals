#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

class Student {
    int roll;
    char name[20];
    char Class[10];
    char Div[10];
    char dob[10];
    char bg[3];
    char contact[20];
    char phone[15];
    char license[12];

public:
    static int totalCount;  // Static variable to track object count

    // Static function to display object count
    static void showCount() {
        cout << "Total number of objects: " << totalCount << endl;
    }

    // Default Constructor
    Student() {
        roll = 0;
        strcpy(name, "Default");
        strcpy(Class, "X");
        strcpy(Div, "A");
        strcpy(dob, "01/01/2000");
        strcpy(bg, "O+");
        strcpy(contact, "Unknown");
        strcpy(phone, "0000000000");
        strcpy(license, "N/A");
        totalCount++;
    }

    // Copy Constructor
    Student(const Student& obj) {
        roll = obj.roll;
        strcpy(name, obj.name);
        strcpy(Class, obj.Class);
        strcpy(Div, obj.Div);
        strcpy(dob, obj.dob);
        strcpy(bg, obj.bg);
        strcpy(contact, obj.contact);
        strcpy(phone, obj.phone);
        strcpy(license, obj.license);
        totalCount++;
    }

    // Destructor
    ~Student() {
        cout << name << " (Object) destroyed!" << endl;
        totalCount--;
    }

    // Function to input student data
    void getData() {
        cout << "Enter Student Details:\n";
        cout << "Name: ";
        cin >> name;
        cout << "Roll Number: ";
        cin >> roll;
        cout << "Class: ";
        cin >> Class;
        cout << "Division: ";
        cin >> Div;
        cout << "Date of Birth (dd/mm/yyyy): ";
        cin >> dob;
        cout << "Blood Group: ";
        cin >> bg;
        cout << "Address: ";
        cin.ignore();
        cin.getline(contact, 20);
        cout << "Phone Number: ";
        cin >> phone;
        cout << "License Number: ";
        cin >> license;
    }

    // Friend function to display student details
    friend void display(const Student& s);
};

// Initialize static variable
int Student::totalCount = 0;

// Function to display student details
void display(const Student& s) {
    cout << setw(12) << s.name
         << setw(10) << s.roll
         << setw(8) << s.Class
         << setw(6) << s.Div
         << setw(12) << s.dob
         << setw(6) << s.bg
         << setw(20) << s.contact
         << setw(15) << s.phone
         << setw(12) << s.license << endl;
}

void displayHeader() {
    cout << setw(12) << "Name"
         << setw(10) << "Roll"
         << setw(8) << "Class"
         << setw(6) << "Div"
         << setw(12) << "DOB"
         << setw(6) << "BG"
         << setw(20) << "Address"
         << setw(15) << "Phone"
         << setw(12) << "License" << endl;
    cout << string(100, '-') << endl;
}

int main() {
    int n, choice, delIndex;
    Student* students[50] = {nullptr};  // Array of pointers for dynamic management
    int currentCount = 0;  // To keep track of valid students

    // Default Object
    Student defaultObj;
    cout << "\nDefault Object Details:\n";
    displayHeader();
    display(defaultObj);

    // Input number of students
    cout << "\nHow many students do you want to add?: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        students[i] = new Student();
        students[i]->getData();
        currentCount++;
    }

    do {
        cout << "\n** Menu **\n";
        cout << "1. Display All Students\n";
        cout << "2. Add New Student\n";
        cout << "3. Delete a Student\n";
        cout << "4. Show Total Count\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (currentCount > 0) {
                    cout << "\nStudent List:\n";
                    displayHeader();
                    for (int i = 0; i < currentCount; i++) {
                        if (students[i] != nullptr) {
                            display(*students[i]);
                        }
                    }
                } else {
                    cout << "\nNo students to display!\n";
                }
                break;

            case 2:
                if (currentCount < 50) {
                    students[currentCount] = new Student();
                    students[currentCount]->getData();
                    currentCount++;
                } else {
                    cout << "Student limit reached!\n";
                }
                break;

            case 3:
                cout << "Enter the index of the student to delete (0 to " << currentCount - 1 << "): ";
                cin >> delIndex;
                if (delIndex >= 0 && delIndex < currentCount && students[delIndex] != nullptr) {
                    delete students[delIndex];
                    students[delIndex] = nullptr;
                    cout << "Student deleted successfully!\n";
                } else {
                    cout << "Invalid index!\n";
                }
                break;

            case 4:
                Student::showCount();
                break;

            case 5:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    // Clean up remaining students
    for (int i = 0; i < currentCount; i++) {
        if (students[i] != nullptr) {
            delete students[i];
        }
    }

    return 0;
}
