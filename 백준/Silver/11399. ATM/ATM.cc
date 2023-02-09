#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> time(N);
    for (int i = 0; i < N; i++)
        cin >> time[i];

    sort(time.begin(), time.end());

    int min = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j <= i; j++)
            min += time[j];

    cout << min;
}