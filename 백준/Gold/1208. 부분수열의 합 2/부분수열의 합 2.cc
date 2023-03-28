#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Struct
typedef long long ll;

class SeqSumCounter {
public:
    SeqSumCounter(const vector<int> &num, const int &S) : num(num), S(S) {}
    ll get() {
        register ll cnt = 0;
        init(num.size(), cnt);
        // Empty Exception
        return (cnt - (S == 0));
    }
protected:
    void init(const int &N, register ll &cnt) {
        doLeftSearch(0, N / 2, 0);
        doRightSearch(N / 2, N, 0, cnt);
    }
    void doLeftSearch(const int &depth, const int &limit, const int &sum) {
        if (depth == limit) {
            cnts[sum] += 1;
            return;
        }
        doLeftSearch(depth + 1, limit, sum);
        doLeftSearch(depth + 1, limit, sum + num[depth]);
    };
    void doRightSearch(const int &depth, const int &limit, const int &sum, register ll &cnt) {
        if (depth == limit) {
            cnt += cnts[S - sum];
            return;
        }
        doRightSearch(depth + 1, limit, sum, cnt);
        doRightSearch(depth + 1, limit, sum + num[depth], cnt);
    };
private:
    int S;
    vector<int> num;
    map<int, int> cnts;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, S;
    cin >> N >> S;

    vector<int> num(N);
    while (N--)
        cin >> num[N];
    cout << SeqSumCounter(num, S).get();
}