#include <iostream>
using namespace std;

int main() {
    int A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;
    
    int S = A + B + C + D + max(E, F);
    S -= min(min(min(A, B), C), D);
    cout << S;
}