#include <iostream>
#include <vector>
using namespace std;

int vec_size = 0;
vector<int> vec;
vector<vector<vector<int>>> dp;

int getCost(const int& X, const int& POS) {
    if (X == 0) return 2;
    if (X == POS) return 1;
    if ((X + 2) % 4 == POS % 4) return 4;
    return 3;
}

int DP(const int& L, const int& R, const int& IDX) {
    // Out Of Range?
    if (IDX == vec_size) return 0;
    // Memorization
    if (dp[L][R][IDX]) return dp[L][R][IDX];

    // Get Cost
    const int& LEFT = DP(vec[IDX], R, IDX + 1) + getCost(L, vec[IDX]);
    const int& RIGHT = DP(L, vec[IDX], IDX + 1) + getCost(R, vec[IDX]);

    return dp[L][R][IDX] = min(LEFT, RIGHT);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    while (cin >> N && N)
        vec.emplace_back(N);

    vec_size = vec.size();
    dp.resize(4 + 1, vector<vector<int>>(4 + 1, vector<int>(vec_size)));

    cout << DP(0, 0, 0);
}