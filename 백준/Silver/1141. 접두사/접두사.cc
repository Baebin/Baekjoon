#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

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

    vector<string> words;    
    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;

        words.emplace_back(word);
    }
    sort(words.begin(), words.end());

    int cnt = N;
    for (int i = 1; i < N; i++)
        if (words[i].find(words[i - 1]) == 0)
            cnt--;
    cout << cnt << '\n';
}