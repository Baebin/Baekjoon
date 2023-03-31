#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
using namespace std;

// Declare
#define MAX 2000001
#define endl "\n"

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> vec(MAX);

    int N;
    cin >> N;
    while (N--) {
        int A;
        cin >> A;
        vec[A + 1000000]++;
    }

    for (int i = 0; i < MAX; i++)
        while (vec[i]--)
            cout << (i - 1000000) << endl;
}