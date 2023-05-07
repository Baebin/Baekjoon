#include <iostream>
#include <string>
using namespace std;

int main() {
    int K, D, A;
    scanf("%d/%d/%d", &K, &D, &A);
    cout << (((K + A < D) || D == 0) ? "hasu" : "gosu" );
}