#include <iostream>
#include <vector>
using namespace std;

vector<int> vec(301);
vector<int> point(301);

int dp(const int& N) {
    // Init
    point[1] = vec[1];
    point[2] = vec[1] + vec[2];
    point[3] = max(vec[1] + vec[3], vec[2] + vec[3]);

    for (int floor = 4; floor <= N; floor++)
        point[floor] = max(vec[floor] + point[floor - 2], vec[floor] + vec[floor - 1] + point[floor - 3]);

    return point[N];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> vec[i];

    cout << dp(N);
}