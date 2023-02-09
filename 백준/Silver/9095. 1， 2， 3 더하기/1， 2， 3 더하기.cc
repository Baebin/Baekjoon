#include <iostream>
#include <vector>
using namespace std;

vector<int> vec(11);

int dp(const int& N) {
    /*
    1: 1
    2: 2
    3: 4
    4: 7
    5: 13
    */

    for (int i = 4; i <= N; i++) {
        vec[i] = vec[i - 1] + vec[i - 2] + vec[i - 3];
    }

    return vec[N];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vec[1] = 1;
    vec[2] = 2;
    vec[3] = 4;

    int T;
    cin >> T;

    int N;
    while (T--) {
        cin >> N;
        cout << dp(N) << "\n";
    }
}