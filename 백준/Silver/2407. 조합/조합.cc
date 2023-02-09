#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Declare
#define MAX 100

// Memorization
vector<vector<string>> factorial(MAX + 1, vector<string>(MAX + 1));

class BigNumber {
public:
    BigNumber(string a) {
        this->a = a;
    }
    string add(string b) {
        int digit = 0;

        stack<char> st;
        while (digit || !a.empty() || !b.empty()) {
            if (!a.empty()) {
                digit += a.back() - '0';
                a.pop_back();
            }
            if (!b.empty()) {
                digit += b.back() - '0';
                b.pop_back();
            }

            st.push((digit % 10) + '0');
            digit /= 10;
        }

        string num;
        while (!st.empty()) {
            num += st.top();
            st.pop();
        }

        return num;
    }
private:
    string a;
};

string nCm(int n, int r) {
    // n-1Cr-1 + n-1Cr = nCr

    if (n == r || !r)
        return "1";

    if (!factorial[n][r].empty())
        return factorial[n][r];
    return (factorial[n][r] = BigNumber(nCm(n - 1, r - 1)).add(nCm(n - 1, r)));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    cout << nCm(N, M);
}