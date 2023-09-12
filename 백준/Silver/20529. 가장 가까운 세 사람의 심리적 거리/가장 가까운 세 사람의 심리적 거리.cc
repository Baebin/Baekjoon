#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
using namespace std;

#define MBTI_SIZE 16

class MBTI {
public:
    void cin() {
        std::cin >> this->mbti;
    }
    vector<int> toInt() {
        // My MBTI ^~^
        return { mbti[0] == 'E', mbti[1] == 'N', mbti[2] == 'F', mbti[3] == 'J' };
    }
    int getDistance(MBTI& m) {
        vector<int> m1 = m.toInt();
        vector<int> m2 = this->toInt();
        
        int distance = 0;
        for (register int i = 0; i < 4; i++)
            distance += m1[i] ^ m2[i];
        return distance;
    }
private:
    string mbti;
};

int find(vector<MBTI>& mbtis) {
    const int& size = mbtis.size();
    // Pigeonhole Principle
    if (size > MBTI_SIZE * 2)
        return 0;
    // Brute Force
    int distance = MBTI_SIZE;
    for (register int i = 0; i < size; i++)
        for (register int j = i + 1; j < size; j++)
            for (register int k = j + 1; k < size; k++)
                distance = min(
                        distance,
                        mbtis[i].getDistance(mbtis[j])
                        + mbtis[j].getDistance(mbtis[k])
                        + mbtis[i].getDistance(mbtis[k]));
    return distance;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<MBTI> mbtis(N);
        for (register int i = 0; i < N; i++)
            mbtis[i].cin();
        cout << find(mbtis) << "\n";
    }
}