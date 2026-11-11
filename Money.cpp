#include <iomanip>
#include <iostream>
using namespace std;

class Money {
    long long paise;

public:
    Money(long long rupees = 0, int p = 0) : paise(rupees * 100 + p) {}

    Money operator+(const Money& other) const {
        Money result;
        result.paise = paise + other.paise;
        return result;
    }
    Money operator-(const Money& other) const {
        Money result;
        result.paise = paise - other.paise;
        return result;
    }
    Money& operator+=(const Money& other) {
        paise += other.paise;
        return *this;
    }
    bool operator==(const Money& other) const { return paise == other.paise; }
    bool operator<(const Money& other) const { return paise < other.paise; }

    friend ostream& operator<<(ostream& out, const Money& m) {
        long long whole = m.paise / 100;
        long long fraction = m.paise % 100;
        if (fraction < 0) fraction = -fraction;
        out << "Rs " << whole << '.' << setw(2) << setfill('0') << fraction;
        return out;
    }

    friend istream& operator>>(istream& in, Money& m) {
        long long rupees;
        int p;
        if (in >> rupees >> p) m.paise = rupees * 100 + p;
        return in;
    }
};

int main() {
    Money a(120, 75), b(79, 25);
    Money c = a + b;
    cout << c << '\n' << boolalpha << (c == Money(200)) << '\n';

    Money x(0, 75), y(0, 50);
    cout << x + y << '\n'; // Rs 1.25

    Money difference = Money(5) - Money(8);
    cout << "Negative subtraction: " << difference << '\n';

    Money total(10);
    total += Money(2, 50);
    cout << "Updated total: " << total << '\n';
    return 0;
}
