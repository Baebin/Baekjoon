#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    int cnt = 0;
    for (int i = 0; i < 5; i++) {
        int C;
        cin >> C;
        
        if (C % 10 == N)
            cnt++;
    }
    cout << cnt;
}