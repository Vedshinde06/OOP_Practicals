#include <iostream>
using namespace std;

class publication {
public:
    string title;
    float prize;
    
    void getdata() {
        cout << "Enter Name of Publication: ";
        cin >> title;
        cout << "Enter Price of Publication: ";
        cin >> prize;
        cout << endl;
    }

    void putdata() {
        cout << "Publication Title: " << title << endl;
        cout << "Publication Price: " << prize << endl;
    }
};

class book : public publication {
public:
    int pagecount;

    void getdata() {
        publication::getdata();
        cout << "Enter Book Page Count: ";
        cin >> pagecount;
        cout << endl;
    }

    void putdata() {
        publication::putdata();
        cout << "Book Page Count: " << pagecount << endl;
        cout << endl;
    }
};

class tape : public publication {
private:
    float ptime;

public:
    void getdata() {
        publication::getdata();
        cout << "Enter Tape Playing Time (Minutes): ";
        cin >> ptime;
        cout << endl;
    }

    void putdata() {
        publication::putdata();
        cout << "Tape Playing Time: " << ptime << " min" << endl;
        cout << endl;
    }
};

int main() {
    book b;
    tape t;

    b.getdata();
    t.getdata();
    b.putdata();
    t.putdata();

    return 0;
}