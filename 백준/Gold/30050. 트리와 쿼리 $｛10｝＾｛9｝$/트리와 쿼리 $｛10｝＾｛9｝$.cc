#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    map<int, int> e;

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i)
    {
        int q;
        cin >> q;
        if (q == 1)
        {
            int a, b;
            cin >> a >> b;
            e[b] = a;
        }
        else
        {
            int c, d;
            cin >> c >> d;

            ll ans = c + d;
            int c_h = log2(c), d_h = log2(d);
            while (c != d)
            {
                if (c_h >= d_h)
                {
                    if (e.find(c) == e.end())
                    {
                        c /= 2;
                        c_h--;
                    }
                    else
                    {
                        c = e[c];
                        c_h = log2(c);
                    }

                    ans += c;
                }
                else
                {
                    if (e.find(d) == e.end())
                    {
                        d /= 2;
                        d_h--;
                    }
                    else
                    {
                        d = e[d];
                        d_h = log2(d);
                    }

                    ans += d;
                }
            }

            ans -= c;
            cout << ans << '\n';
        }
    }

}