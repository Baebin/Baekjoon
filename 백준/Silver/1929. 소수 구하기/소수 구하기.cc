#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<bool> vec(M + 1);
    vec[0] = true, vec[1] = true;

    for (int i = 1; i <= M; i++) {
        if (vec[i]) continue;
        for (int j = i * 2; j <= M; j += i)
            vec[j] = true;
    }

    for (int i = N; i <= M; i++)
        if (!vec[i])
            cout << i << "\n";
}