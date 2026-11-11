#include <iostream>
using namespace std;

class Demo {
    int first;
    int second;
public:
    // Members are initialized in declaration order: first, then second.
    // The list order below is intentionally wrong to demonstrate -Wreorder.
    Demo() : second(20), first(10) {}
    void show() const { cout << first << " " << second << '\n'; }
};

int main() {
    Demo d;
    d.show();
}
