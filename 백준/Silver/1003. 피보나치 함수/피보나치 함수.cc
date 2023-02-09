#include <iostream>
#include <vector>
using namespace std;

#define MAX 41

vector<int> vec(MAX + 1, -1);

int fibonacci(int n) {
    if (vec[n] != -1) return vec[n];
    vec[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return vec[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vec[0] = 0;
    vec[1] = 1;

    int T;
    cin >> T;

    int tmp;
    for (int i = 0; i < T; i++) {
        cin >> tmp;

        if (tmp <= 1) {
            cout << 1 - tmp << " " << tmp << "\n";
            continue;
        }
        cout << fibonacci(tmp - 1) << " " << fibonacci(tmp) << "\n";
    }
}