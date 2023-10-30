#include <iostream>
#include <cmath>
#define PI 3.141592653589793238
using namespace std;

int main(){
    double A;
    cin >> A;

    cin.precision(10);
    cout << fixed << (2 * PI * sqrt(A/PI));
}