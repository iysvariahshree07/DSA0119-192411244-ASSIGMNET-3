#include <iostream>
using namespace std;

// INTENTIONALLY UNSAFE demonstration. Do not use this design in a real program.
class BadPrescription {
    int* data;
public:
    BadPrescription() : data(new int[2]{10, 20}) {}
    // Compiler-generated copy copies only the pointer (shallow copy).
    ~BadPrescription() { delete[] data; }
    int get(int i) const { return data[i]; }
};
int main() {
    BadPrescription a;
    BadPrescription b = a; // Both objects point to the same allocation.
    cout << a.get(0) << " " << b.get(0) << '\n';
} // Undefined behaviour: both destructors try to delete the same array.
