#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
using namespace std;

// Structure
typedef long long ll;

class EulerPhi {
public:
    EulerPhi(const ll& N) { this->N = N; }
    ll get() {
        ll cnt = 1, tmp = N;
        for (ll num = 2; num * num <= N; num++) {
            if (tmp % num)
                continue;
            ll pk = num;
            while ((tmp /= num) % num == 0)
                pk *= num;
            cnt *= pk - (pk / num);
        }
        if (tmp > 1)
            cnt *= (tmp - 1);
        return cnt;
    }
private:
    ll N;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll N;
    while (true) {
        cin >> N;
        if (N == 0)
            return 0;
        if (N == 1) cout << 0 << "\n";
        else cout << EulerPhi(N).get() << "\n";
    }
}