#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string A, B;
    cin >> A >> B;

    long long sum = 0;
    for (const char& a : A)
        for (const char& b : B)
            sum += ((a - '0') * (b - '0'));
    cout << sum;
}