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
        ll cnt = 1, num = 2, tmp = N;
        for (; num * num <= N; num++) {
            if (tmp % num)
                continue;
            ll pk = num;
            while ((tmp /= num) % num == 0)
                pk *= num;
            cnt *= pk - (pk / num);
        }
        return cnt * (tmp > 1 ? tmp - 1 : 1);
    }
private:
    ll N;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll N;
    cin >> N;
    cout << EulerPhi(N).get();
}