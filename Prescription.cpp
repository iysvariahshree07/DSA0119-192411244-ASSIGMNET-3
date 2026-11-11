#include <iostream>
#include <string>
using namespace std;

class Prescription {
    int n;
    string* medicines;

public:
    explicit Prescription(int count)
        : n(count < 0 ? 0 : count), medicines(new string[n]) {}

    Prescription(const Prescription& other)
        : n(other.n), medicines(new string[other.n]) {
        for (int i = 0; i < n; ++i) medicines[i] = other.medicines[i];
        cout << "Copy constructor called\n";
    }

    Prescription& operator=(const Prescription& other) {
        if (this != &other) {
            string* temp = new string[other.n];
            for (int i = 0; i < other.n; ++i) temp[i] = other.medicines[i];
            delete[] medicines;
            medicines = temp;
            n = other.n;
        }
        return *this;
    }

    ~Prescription() { delete[] medicines; }

    void set(int i, const string& m) {
        if (i >= 0 && i < n) medicines[i] = m;
    }
    string get(int i) const {
        return (i >= 0 && i < n) ? medicines[i] : "";
    }
    int size() const { return n; }
};

void byValue(Prescription p) { cout << "Passed by value\n"; }
void byReference(const Prescription& p) { cout << "Passed by const reference\n"; }

int main() {
    Prescription p(2);
    p.set(0, "Paracetamol");
    p.set(1, "ORS");

    Prescription q = p;             // copy constructor
    q.set(1, "Cetirizine");

    Prescription r(1);
    r = p;                           // copy assignment
    p.set(0, "Ibuprofen");
    r = r;                           // self-assignment test

    cout << p.get(0) << ' ' << p.get(1) << " | "
         << q.get(0) << ' ' << q.get(1) << " | "
         << r.get(0) << ' ' << r.get(1) << '\n';

    byValue(p);
    byReference(p);
    return 0;
}
