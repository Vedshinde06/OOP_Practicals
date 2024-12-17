#include <iostream>
using namespace std;

class complex {
    float realp, imagp;

public:
    complex() {
        realp = 0;
        imagp = 0;
    }

    complex(float x, float y) {
        realp = x;
        imagp = y;
    }

    complex operator+(complex &);
    complex operator*(complex &);

    friend istream &operator>>(istream &, complex &);
    friend ostream &operator<<(ostream &, const complex &);
};

istream &operator>>(istream &din, complex &c) {
    cout << "Enter real part of complex number: ";
    din >> c.realp;
    cout << "Enter imaginary part of complex number: ";
    din >> c.imagp;
    return din;
}

ostream &operator<<(ostream &dout, const complex &c) {
    dout << c.realp << " + " << c.imagp << "i";
    return dout;
}

complex complex::operator+(complex &c) {
    complex temp;
    temp.realp = realp + c.realp;
    temp.imagp = imagp + c.imagp;
    return temp;
}

complex complex::operator*(complex &c) {
    complex mul;
    mul.realp = (realp * c.realp) - (imagp * c.imagp);
    mul.imagp = (imagp * c.realp) + (realp * c.imagp);
    return mul;
}

int main() {
    complex c1, c2, c3;

    cout << "Enter complex number 1" << endl;
    cin >> c1;

    cout << "Enter complex number 2" << endl;
    cin >> c2;

    c3 = c1 + c2;
    cout << "Addition of two complex numbers is: " << c3 << endl;

    c3 = c1 * c2;
    cout << "Multiplication of two complex numbers is: " << c3 << endl;

    return 0;
}