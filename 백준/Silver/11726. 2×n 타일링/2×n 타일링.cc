#include <iostream>
#include <vector>
using namespace std;

#define MAX 1000
#define MOD 10007

vector<int> vec(MAX + 1);

int dp(const int &N) {
    /*
    f(1) = 1
    f(2) = 2
    f(3) = 3
    f(4) = 5
    */

    vec[1] = 1;
    vec[2] = 2;

    for (int i = 3; i <= N; i++)
        vec[i] = (vec[i - 1] + vec[i - 2]) % MOD;

    return vec[N];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    cout << dp(N);
}