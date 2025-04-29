#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

    void simplify() {
        int g = gcd(abs(numerator), abs(denominator));
        numerator /= g;
        denominator /= g;

        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

public:
8
    Fraction(int n = 0, int d = 1) {
        numerator = n;
        denominator = d;
        simplify();
    }

    void display() const {
        if (denominator == 1)
            cout << numerator;
        else
            cout << numerator << "/" << denominator;
    }

    Fraction operator+(const Fraction& other) const {
        int n = numerator * other.denominator + other.numerator * denominator;
        int d = denominator * other.denominator;
        return Fraction(n, d);
    }

    Fraction operator-(const Fraction& other) const {
        int n = numerator * other.denominator - other.numerator * denominator;
        int d = denominator * other.denominator;
        return Fraction(n, d);
    }

    Fraction operator*(const Fraction& other) const {
        int n = numerator * other.numerator;
        int d = denominator * other.denominator;
        return Fraction(n, d);
    }

    Fraction operator/(const Fraction& other) const {
        int n = numerator * other.denominator;
        int d = denominator * other.numerator;
        return Fraction(n, d);
    }
};

int main() {
    Fraction f1(3, 4);
    Fraction f2(5, 6);

    cout << "kasr 1: ";
    f1.display();
    cout << endl;

    cout << "kasr 2: ";
    f2.display();
    cout << endl;

    Fraction sum = f1 + f2;
    cout << "sum: ";
    sum.display();
    cout << endl;

    Fraction diff = f1 - f2;
    cout << "tafazol: ";
    diff.display();
    cout << endl;

    Fraction product = f1 * f2;
    cout << "zarb: ";
    product.display();
    cout << endl;

    Fraction quotient = f1 / f2;
    cout << "taghsim: ";
    quotient.display();
    cout << endl;

    return 0;
}
