#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Declare
#define INF 2e9

class Location {
public:
    int x, y;
};

int N, M, S;
vector<string> graph;

vector<int> cnt(26);
vector<vector<Location>> cnts(26);

int C = INF;
string name;
string L = "";

void move(Location& current, const Location& next) {
    int x = next.x - current.x;
    int y = next.y - current.y;

    const string dy = (y < 0 ? "U" : "D");
    const string dx = (x < 0 ? "L" : "R");

    x = abs(x), y = abs(y);
    for (int i = 0; i < x; i++)
        L += dx;
    for (int i = 0; i < y; i++)
        L += dy;
    current = next;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> S;
    graph.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> graph[i];
        for (int j = 0 ; j < M; j++)
            cnts[graph[i][j] - 'a'].emplace_back(Location{j, i});
    }
    cin >> name;
    for (int i = 0; i < S; i++)
        cnt[name[i] - 'a']++;
    for (int i = 0; i < S; i++) {
        int idx = name[i] - 'a';
        C = min(C, (int)(cnts[idx].size() / cnt[idx]));
    }

    Location cloc = { 0, 0 };
    for (int i = 0; i < C; i++) {
        for (int j = 0; j < S; j++) {
            const int &idx = (name[j] - 'a');
            Location loc = cnts[idx].back();
            cnts[idx].pop_back();
            move(cloc, loc);
            L += "P";
        }
    }
    move(cloc, Location{ M - 1, N - 1 });
    cout << C << " " << L.size() << "\n" << L;
}