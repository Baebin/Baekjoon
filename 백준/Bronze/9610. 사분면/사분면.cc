#include <iostream>
using namespace std;

int main() {
    int A = 0, B = 0, C = 0, D = 0, E = 0;
    int N;
    cin >> N;
    while (N--) {
        int X, Y;
        cin >> X >> Y;

        if (X == 0 || Y == 0)
            E++;
        else if (X > 0 && Y > 0)
            A++;
        else if (X < 0 && Y > 0)
            B++;
        else if (X < 0 && Y < 0)
            C++;
        else D++;
    }
    cout << "Q1: " << A << '\n'
        << "Q2: " << B << '\n'
        << "Q3: " << C << '\n'
        << "Q4: " << D << '\n'
        << "AXIS: " << E;
}