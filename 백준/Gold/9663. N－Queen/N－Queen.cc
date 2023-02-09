#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
using namespace std;

// <row, column>
vector<int> board;

bool canPut(const int& row) {
    for (int i = 0; i < row; i++)
        // Row Validate, Diagonal Validate
        if (board[row] == board[i] || (row - i) == abs(board[row] - board[i]))
            return false;
    return true;
}

// DFS
int cnt = 0;
void put(const int& N, const int& depth) {
    // Depth Limit
    if (depth == N) {
        cnt++;
        return;
    }

    for (int i = 0; i < N; i++) {
        board[depth] = i;
        if (!canPut(depth))
            continue;
        put(N, depth + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    board.resize(N);

    put(N, 0);
    cout << cnt;
}