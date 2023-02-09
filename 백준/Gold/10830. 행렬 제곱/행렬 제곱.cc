#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
using namespace std;

// Declare
#define MOD 1000

// Structure
typedef long long ll;

class Matrix {
public:
    Matrix(const int& N) {
        this->N = N;
        this->container.resize(N, vector<ll>(N));
    }
    Matrix operator*(Matrix& matrix) {
        Matrix res(N);
        for (int row = 0; row < N; row++) {
            for (int column = 0; column < N; column++) {
                for (int idx = 0; idx < N; idx++)
                    res.get()[row][column] += container[row][idx] * matrix.get()[idx][column];
                res.get()[row][column] %= MOD;
            }
        }
        return res;
    }
    vector<vector<ll>>& get() { return container; }
private:
    int N;
    vector<vector<ll>> container;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; ll B;
    cin >> N >> B;

    Matrix res(N), matrix(N);
    for (int row = 0; row < N; row++) {
        for (int column = 0; column < N; column++)
            cin >> matrix.get()[row][column];
        // 단위 행렬
        res.get()[row][row] = 1;
    }

    while (B > 0) {
        if (B % 2 == 1)
            res = res * matrix;
        B /= 2;
        matrix = matrix * matrix;
    }
    for (int row = 0; row < N; row++) {
        for (int column = 0; column < N; column++)
            cout << res.get()[row][column] << " ";
        cout << "\n";
    }
}