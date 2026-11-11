#include <iostream>
#include <string>
using namespace std;

class Book {
    string title;
    string author;
    int copies;

    static int validCopies(int c) {
        if (c < 0) {
            cout << "Invalid copies. Setting copies to 0.\n";
            return 0;
        }
        return c;
    }

public:
    Book() : Book("Unknown", "Unknown", 0) {}

    explicit Book(const string& t) : Book(t, "Unknown", 1) {}

    Book(const string& t, const string& a, int c)
        : title(t), author(a), copies(validCopies(c)) {}

    void display() const {
        cout << "Title: " << title << ", Author: " << author
             << ", Copies: " << copies << '\n';
    }
};

int main() {
    Book empty;
    Book donated("Wings of Fire");
    Book full("The Guide", "R. K. Narayan", 5);
    Book invalid("Test Book", "Author", -3);

    empty.display();
    donated.display();
    full.display();
    invalid.display();

    // explicit prevents: Book converted = "Atomic Habits";
    Book valid("Atomic Habits");
    valid.display();
    return 0;
}
