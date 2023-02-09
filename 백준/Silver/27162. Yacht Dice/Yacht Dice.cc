#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
using namespace std;

vector<bool> canUse(12 + 1);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;

    int len = str.length();
    for (int i = 1; i <= len; i++)
        if (str[i - 1] == 'Y')
            canUse[i] = true;

    int A, B, C;
    cin >> A >> B >> C;

    int point = 0;
    int result = 0;
    for (int i = 1; i <= 6; i++) {
        if (!canUse[i])
            continue;
        point = 0;
        if (A == i)
            point += i;
        if (B == i)
            point += i;
        if (C == i)
            point += i;

        result = max(result, point + i * 2);
    }

    if (canUse[7]) {
        vector<int> vec(6 + 1);

        vec[A]++;
        vec[B]++;
        vec[C]++;

        for (int i = 1; i <= 6; i++)
            if (vec[i] >= 2)
                result = max(result, i * 4);
    }

    if (canUse[8]) {
        vector<int> vec(6 + 1);

        vec[A]++;
        vec[B]++;
        vec[C]++;

        // A, A, A, D, D
        if (A == B && B == C)
            for (int i = 1; i <= 6; i++)
                if (vec[i] == 0)
                    result = max(result, A * 3 + i * 2);

        // A, A, C, C, C
        // A, A, C, C, A
        if (A == B && B != C) {
            result = max(result, A * 3 + C * 2);
            result = max(result, A * 2 + C * 3);
        }

        // A, B, B, A, A
        // A, B, B, B, A
        if (B == C && C != A) {
            result = max(result, A * 2 + B * 3);
            result = max(result, A * 3 + B * 2);
        }

        // A, B, A, A, B
        // A, B, A, B, B
        if (A == C && B != A) {
            result = max(result, A * 3 + B * 2);
            result = max(result, A * 2 + B * 3);
        }
    }

    if (canUse[9] || canUse[10]) {
        vector<int> vec(6 + 1);

        vec[A]++;
        vec[B]++;
        vec[C]++;

        if (canUse[9])
            if (vec[1] <= 1 && vec[2] <= 1 && vec[3] <= 1 && vec[4] <= 1 && vec[5] <= 1 && vec[6] == 0)
                result = max(result, 30);
        if (canUse[10])
            if (vec[1] == 0 && vec[2] <= 1 && vec[3] <= 1 && vec[4] <= 1 && vec[5] <= 1 && vec[6] <= 1)
                result = max(result, 30);
    }

    if (canUse[11])
        if (A == B && B == C)
            result = max(result, 50);
    if (canUse[12])
        result = max(result, A + B + C + 12);

    cout << result;
}