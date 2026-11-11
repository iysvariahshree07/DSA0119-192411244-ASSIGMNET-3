#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

class Time {
    int seconds;
public:
    explicit Time(int s = 0) : seconds(s < 0 ? 0 : s) {}
    Time& operator++() { ++seconds; return *this; }       // prefix
    Time operator++(int) { Time old(*this); ++seconds; return old; } // postfix
    bool operator==(const Time& t) const { return seconds == t.seconds; }
    bool operator<(const Time& t) const { return seconds < t.seconds; }
    int value() const { return seconds; }
};

class Playlist {
    vector<string> tracks;
public:
    Playlist(initializer_list<string> list) : tracks(list) {}
    string& operator[](int i) {
        if (i < 0 || i >= static_cast<int>(tracks.size()))
            throw out_of_range("Playlist index out of range");
        return tracks[i];
    }
    const string& operator[](int i) const {
        if (i < 0 || i >= static_cast<int>(tracks.size()))
            throw out_of_range("Playlist index out of range");
        return tracks[i];
    }
    int size() const { return static_cast<int>(tracks.size()); }
};

int main() {
    Time t(5);
    Time a = t++;
    Time b = ++t;
    cout << a.value() << ' ' << b.value() << ' ' << t.value() << '\n';

    Playlist p{"Song A", "Song B", "Song C"};
    cout << p[0] << '\n';
    p[1] = "Updated Song B";
    cout << p[1] << '\n';

    try { cout << p[-1] << '\n'; }
    catch (const out_of_range& e) { cout << e.what() << '\n'; }

    try { cout << p[p.size()] << '\n'; }
    catch (const out_of_range& e) { cout << e.what() << '\n'; }

    // Seconds since midnight: 23:59:59 -> 00:00:00.
    Time last(86399);
    ++last;
    cout << "Rollover seconds: " << last.value() << '\n';
    return 0;
}
