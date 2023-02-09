#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
using namespace std;

class Liner {
public:
    void print(const int& cmd) {
        int segment = 3;
        while (segment--) {
            printSegment(cmd);
            if (cmd <= 1)
                return;
        }
    }
private:
    void printSegment(const int& cmd) {
        if (cmd == 1)
            printStraight();
        else if (cmd == 2)
            printLeft();
        else if (cmd == 3)
            printRight();
        else if (cmd == 4)
            printSide();
        else printEmpty();
    }
    void printEmpty() { cout << "\n"; }
    void printStraight() { cout << " * * *\n"; }
    void printLeft() { cout << "*\n"; }
    void printRight() { cout << "      *\n"; }
    void printSide() { cout << "*     *\n"; }
};

class NumberLiner : public Liner {
public:
    NumberLiner() { init(); }
    virtual void print(const int& num) {
        for (int cmd : vec[num])
            Liner::print(cmd);
    }
private:
    vector<vector<int>> vec;
    void init() {
        /*
        0. Empty
        1. Stright
        2. Left
        3. Right
        4. Side
        */
        vec.resize(10, vector<int>(5));

        vec = {
            { 1, 4, 0, 4, 1 },
            { 0, 3, 0, 3, 0 },
            { 1, 3, 1, 2, 1 },
            { 1, 3, 1, 3, 1 },
            { 0, 4, 1, 3, 0 },
            { 1, 2, 1, 3, 1 },
            { 1, 2, 1, 4, 1 },
            { 1, 3, 0, 3, 0 },
            { 1, 4, 1, 4, 1 },
            { 1, 4, 1, 3, 1 }
        };
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    NumberLiner liner;
    liner.print(N);
}