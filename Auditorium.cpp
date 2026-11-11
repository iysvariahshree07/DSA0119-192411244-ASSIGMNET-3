#include <iostream>
#include <string>
using namespace std;

class Auditorium {
    int rows, seats;
    bool** booked;

public:
    Auditorium(int r, int s) : rows(r > 0 ? r : 0), seats(s > 0 ? s : 0), booked(nullptr) {
        if (rows > 0 && seats > 0) {
            booked = new bool*[rows];
            int made = 0;
            try {
                for (; made < rows; ++made) {
                    booked[made] = new bool[seats]{false};
                }
            } catch (...) {
                while (made > 0) delete[] booked[--made];
                delete[] booked;
                throw;
            }
        }
        cout << "Event created: " << rows << " rows, " << seats << " seats\n";
    }

    bool book(int r, int s) {
        if (!valid(r, s) || booked[r][s]) return false;
        booked[r][s] = true;
        return true;
    }

    bool cancel(int r, int s) {
        if (!valid(r, s) || !booked[r][s]) return false;
        booked[r][s] = false;
        return true;
    }

    bool valid(int r, int s) const {
        return booked && r >= 0 && r < rows && s >= 0 && s < seats;
    }

    ~Auditorium() {
        if (booked) {
            for (int r = 0; r < rows; ++r) delete[] booked[r];
            delete[] booked;
        }
        cout << "Event closed. Memory released.\n";
    }
};

int main() {
    cout << "Stack object:\n";
    Auditorium a(2, 3);
    cout << "Book (0,1): " << a.book(0, 1) << '\n';
    cout << "Cancel (0,1): " << a.cancel(0, 1) << '\n';

    cout << "Heap object:\n";
    Auditorium* p = new Auditorium(1, 2);
    p->book(0, 0);
    delete p;

    cout << "Block object:\n";
    {
        Auditorium b(1, 1);
    }

    cout << "Zero-row object:\n";
    Auditorium z(0, 5);
    return 0;
}
