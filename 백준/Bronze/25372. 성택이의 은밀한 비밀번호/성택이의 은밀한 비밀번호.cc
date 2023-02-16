#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops") 

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    string str;
    
    cin >> N;
    while (N--) {
        cin >> str;
        int len = str.length();
        if (len >= 6 && len <= 9)
            cout << "yes" << "\n";
        else cout << "no" << "\n";
    }
}