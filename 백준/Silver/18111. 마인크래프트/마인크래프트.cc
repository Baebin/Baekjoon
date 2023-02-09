#include <iostream>
#include <vector>
using namespace std;

#define INF 2e9

#define TIME_PLACE 1
#define TIME_REMOVE 2

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, B;
    cin >> N >> M >> B;

    int max_y = 0;
    vector<vector<int>> dirts(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> dirts[i][j];
            if (dirts[i][j] > max_y)
                max_y = dirts[i][j];
        }
    }

    int result_y = 0, min_time = INF;
    for (int y = 0; y <= max_y; y++) {
        int place = 0;
        int inventory = 0;

        for (vector<int> row : dirts) {
            for (int dirt : row) {
                if (dirt > y)
                    inventory += dirt - y;
                else if (dirt < y)
                    place += y - dirt;
            }
        }

        if (inventory + B < place) continue;

        int time = place * TIME_PLACE + inventory * TIME_REMOVE;
        if (time <= min_time) {
            result_y = y;
            min_time = time;
        }
    }

    cout << min_time << " " << result_y;
}