#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> pos;
    vector<int> vec(N + 1);
    for (int i = 0; i <= N; i++) {
        cin >> vec[i];
        if (vec[i] == 1)
            pos.push_back(i);
    }

    int X;
    cin >> X;

    if (pos.size() > 2)
        cout << "NO";
    else if (pos.size() == 2) {
        int start = pos.front();
        int end = pos.back();

        if (start + X == end)
            cout << "YES\n" << start << " " << end;
        else cout << "NO";
    }
    else if (pos.size() == 1) {
        int end = pos.front();
        if (end - X >= 0 && (vec[end - X] == 1 || vec[end - X] >= 3))
            cout << "YES\n" << end - X << " " << end;
        else if (end + X <= N && vec[end + X] >= 1)
            cout << "YES\n" << end << " " << end + X;
        else cout << "NO";
    }
    else {
        for (int i = 0; i <= N - X; i++) {
            if (vec[i] > 2 && vec[i + X] >= 1) {
                cout << "YES\n" << i << " " << i + X;
                return 0;
            }
        }
        cout << "NO";
    }
}