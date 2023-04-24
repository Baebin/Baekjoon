#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int D, N;
    cin >> D >> N;

    vector<int> oven(D + 1);
    for (register int depth = 1; depth <= D; depth++) {
        cin >> oven[depth];
        if (depth != 1 && oven[depth - 1] < oven[depth])
            oven[depth] = oven[depth - 1];
    }

    int depth_max = D + 1;
    while (N--) {
        int length;
        cin >> length;

        int temp = 0;
        for (register int depth = depth_max - 1; depth >= 1; depth--) {
            if (oven[depth] < length)
                continue;
            temp = depth;
            break;
        }
        depth_max = temp;
    }
    cout << depth_max;
}