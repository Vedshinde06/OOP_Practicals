#include <iostream>
using namespace std;

// Base Class: Publication
class publication {
public:
    string title;
    float price;

    void getdata() {
        cout << "Enter Name of Publication: ";
        cin.ignore(); // To handle multi-word titles
        getline(cin, title);
        cout << "Enter Price of Publication: ";
        cin >> price;
    }

    void putdata() {
        cout << "Publication Title: " << title << endl;
        cout << "Publication Price: " << price << endl;
    }
};

// Derived Class: Book
class book : public publication {
public:
    int pagecount;

    void getdata() {
        publication::getdata();
        cout << "Enter Book Page Count: ";
        cin >> pagecount;
    }

    void putdata() {
        publication::putdata();
        cout << "Book Page Count: " << pagecount << " pages" << endl;
    }
};

// Derived Class: Tape
class tape : public publication {
public:
    float ptime;

    void getdata() {
        publication::getdata();
        cout << "Enter Tape Playing Time (Minutes): ";
        cin >> ptime;
    }

    void putdata() {
        publication::putdata();
        cout << "Tape Playing Time: " << ptime << " minutes" << endl;
    }
};

int main() {
    book b;
    tape t;

    cout << "\n--- Enter Book Details ---\n";
    b.getdata();

    cout << "\n--- Enter Tape Details ---\n";
    t.getdata();

    cout << "\n--- Displaying Book Details ---\n";
    b.putdata();

    cout << "\n--- Displaying Tape Details ---\n";
    t.putdata();

    return 0;
}
