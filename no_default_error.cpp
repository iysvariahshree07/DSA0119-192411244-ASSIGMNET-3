class Book {
public:
    Book(int copies) {}
};
int main() {
    Book shelf[3]; // Expected compile error: no default constructor.
}
