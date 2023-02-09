#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vec;
vector<int> vec_tmp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vec.resize(N);

    int num;
    for (int i = 0; i < N; i++)
        cin >> vec[i];

    vec_tmp = vec;
    sort(vec_tmp.begin(), vec_tmp.end());
    vec_tmp.erase(unique(vec_tmp.begin(), vec_tmp.end()), vec_tmp.end());

    for (int a : vec) {
        int idx = lower_bound(vec_tmp.begin(), vec_tmp.end(), a) - vec_tmp.begin();
        cout << idx << " ";
    }
}