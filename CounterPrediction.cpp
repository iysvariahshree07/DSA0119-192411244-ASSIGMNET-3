#include <iostream>
using namespace std;

struct Counter {
    int v;
    Counter& operator++() { ++v; return *this; }
    Counter operator++(int) { Counter old = *this; ++v; return old; }
};

int main() {
    Counter c{5};
    Counter a = c++;
    Counter b = ++c;
    cout << a.v << ' ' << b.v << ' ' << c.v << '\n';
}
