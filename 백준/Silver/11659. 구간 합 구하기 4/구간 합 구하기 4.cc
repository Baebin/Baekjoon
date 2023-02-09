#include <iostream>
#include <vector>
using namespace std;

vector<int> vec;
vector<int> sum;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >>  M;

    vec.resize(N + 1);
    sum.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> vec[i];
        sum[i] = sum[i - 1] + vec[i];
    }

    int i, j;
    while (M--) {
        cin >> i >> j;
        cout << sum[j] - sum[i - 1] << "\n";
    };
}