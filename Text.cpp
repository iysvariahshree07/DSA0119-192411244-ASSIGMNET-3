#include <cstring>
#include <iostream>
using namespace std;

class Text {
    char* data;
public:
    Text(const char* s = "") {
        data = new char[strlen(s) + 1];
        strcpy(data, s);
    }

    Text(const Text& other) {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
    }

    Text& operator=(const Text& other) {
        if (this != &other) {
            char* temp = new char[strlen(other.data) + 1];
            strcpy(temp, other.data);
            delete[] data;
            data = temp;
        }
        return *this;
    }

    Text operator+(const Text& other) const {
        size_t n1 = strlen(data), n2 = strlen(other.data);
        char* temp = new char[n1 + n2 + 1];
        strcpy(temp, data);
        strcat(temp, other.data);
        Text result(temp);
        delete[] temp;
        return result;
    }

    bool operator==(const Text& other) const { return strcmp(data, other.data) == 0; }
    bool operator!=(const Text& other) const { return !(*this == other); }
    friend ostream& operator<<(ostream& out, const Text& t) { return out << t.data; }

    ~Text() { delete[] data; }
};

int main() {
    Text a("Hello "), b("World"), c("");
    Text message = a + b;
    cout << message << '\n';
    cout << boolalpha << (message != c) << '\n';

    Text longText("This is a longer SMS message for testing.");
    cout << longText << '\n';

    message = message; // self-assignment
    cout << "After self-assignment: " << message << '\n';

    Text combined = a + b + Text("!");
    cout << combined << '\n';
    return 0;
}
