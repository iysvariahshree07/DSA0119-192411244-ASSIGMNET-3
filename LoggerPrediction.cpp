#include <iostream>
#include <string>
using namespace std;

struct Logger {
    string n;
    Logger(const string& s) : n(s) { cout << '+' << n << ' '; }
    Logger(const Logger& o) : n(o.n + "c") { cout << "copy" << n << ' '; }
    ~Logger() { cout << '-' << n << ' '; }
};

void use(Logger) { cout << "use "; }

int main() {
    Logger a("A");
    {
        Logger b("B");
    }
    use(a);
    Logger* p = new Logger("P");
    delete p;
    cout << "end ";
}
