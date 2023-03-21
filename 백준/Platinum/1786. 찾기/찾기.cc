#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
using namespace std;

// Declare
#define endl "\n"

class KMP {
public:
    vector<int> get(const string &STR, const string &PATTERN) {
        SIZE = STR.length();
        SIZE_PATTERN = PATTERN.length();
        init(PATTERN);

        vector<int> ans;
        int i = 0, j = 0;
        for (; i < SIZE; i++) {
            while (j > 0 && STR[i] != PATTERN[j])
                j = failure_func[j - 1];
            if (STR[i] == PATTERN[j]) {
                if (j + 1 == SIZE_PATTERN) {
                    ans.push_back((i - SIZE_PATTERN) + 2);
                    j = failure_func[j];
                    continue;
                }
                j++;
            }
        }

        return ans;
    }
protected:
    void init(const string &STR) {
        failure_func.resize(SIZE_PATTERN);

        int i = 1, j = 0;
        while (i < SIZE_PATTERN) {
            if (STR[i] == STR[j])
                failure_func[i++] = (++j);
            else if (j == 0)
                i++;
            else j = failure_func[j - 1];
        }
    }
private:
    int SIZE, SIZE_PATTERN;
    vector<int> failure_func;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string T, P;
    getline(cin, T);
    getline(cin, P);

    KMP kmp;
    auto ans = kmp.get(T, P);

    cout << ans.size() << endl;
    for (int begin : ans)
        cout << begin << " ";
}