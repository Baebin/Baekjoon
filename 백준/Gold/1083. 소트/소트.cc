#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("urnoll-loops")

#include <iostream>
#include <vector>
using namespace std;

void sort(vector<int> &vec, const int &limit) {
    int size = vec.size();
    int stack_swap = 0;
    for (int i = 0; i < size; i++) {
        int max_idx = i;
        for (int j = i + 1; j < size; j++)
            if (vec[max_idx] < vec[j] && (j - i) <= (limit - stack_swap))
                max_idx = j;
        if (max_idx == i)
            continue;
        for (int j = max_idx; j > i; j--)
            swap(vec[j], vec[j - 1]);
        if ((stack_swap += (max_idx - i)) == limit)
            return;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, S;
    cin >> N;

    vector<int> vec(N);
    for (int i = 0; i < N; i++)
        cin >> vec[i];

    cin >> S;
    sort(vec, S);
    for (int element : vec)
        cout << element << " ";
}