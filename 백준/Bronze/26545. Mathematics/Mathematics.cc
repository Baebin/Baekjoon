#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    int sum = 0;
    while (N--) {
        int A;
        cin >> A;
        sum += A;
    }
    cout << sum;
}