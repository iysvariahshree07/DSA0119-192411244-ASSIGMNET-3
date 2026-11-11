#include <cmath>
#include <iostream>
#include <stdexcept>
using namespace std;

class Complex {
    double real, imag;
public:
    Complex() : real(0), imag(0) {}
    Complex(double r) : real(r), imag(0) {}
    Complex(double r, double i) : real(r), imag(i) {}

    Complex operator+(const Complex& z) const {
        return Complex(real + z.real, imag + z.imag);
    }
    Complex operator-(const Complex& z) const {
        return Complex(real - z.real, imag - z.imag);
    }
    Complex operator*(const Complex& z) const {
        return Complex(real*z.real - imag*z.imag,
                       real*z.imag + imag*z.real);
    }
    Complex operator/(const Complex& z) const {
        double denominator = z.real*z.real + z.imag*z.imag;
        if (denominator == 0.0) throw domain_error("Division by zero impedance");
        return Complex((real*z.real + imag*z.imag)/denominator,
                       (imag*z.real - real*z.imag)/denominator);
    }
    bool operator==(const Complex& z) const {
        const double eps = 1e-9;
        return fabs(real-z.real) < eps && fabs(imag-z.imag) < eps;
    }
    double magnitude() const { return sqrt(real*real + imag*imag); }

    friend ostream& operator<<(ostream& out, const Complex& z) {
        out << z.real;
        if (z.imag >= 0) out << " + j" << z.imag;
        else out << " - j" << -z.imag;
        return out;
    }
};

int main() {
    // Example impedances: resistor 10 ohm, inductor j5 ohm, capacitor -j2 ohm.
    Complex resistor(10, 0), inductor(0, 5), capacitor(0, -2);

    Complex series = resistor + inductor + capacitor;
    cout << "Series impedance: " << series << '\n';
    cout << "Series magnitude: " << series.magnitude() << '\n';

    Complex z1(10, 0), z2(0, 5);
    Complex parallel = (z1 * z2) / (z1 + z2);
    cout << "Parallel impedance: " << parallel << '\n';
    cout << "Parallel magnitude: " << parallel.magnitude() << '\n';

    try {
        Complex zero(0, 0);
        Complex invalid = z1 / zero;
        cout << invalid << '\n';
    } catch (const domain_error& e) {
        cout << "Error: " << e.what() << '\n';
    }
    return 0;
}
