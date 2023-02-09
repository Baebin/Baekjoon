#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
using namespace std;

// Declare
#define INF 2e9

// Row, Chicken Pick
int N, M;

// Strucutre
struct Location {
    int x, y;

    int getDistance(const Location& a) {
        return abs(x - a.x) + abs(y - a.y);
    }
};

// Locations
int chickens;
vector<Location> house;
vector<Location> chicken;

// DFS Validate
vector<bool> visit;

int getCost() {
    int sum = 0;

    for (Location loc : house) {
        int distance = INF;
        for (int i = 0; i < chickens; i++)
            if (visit[i])
                distance = min(distance, loc.getDistance(chicken[i]));
        sum += distance;
    }
    return sum;
}

int cost = INF;
void search(const int& idx, const int& depth) {
    if (depth == M) {
        cost = min(cost, getCost());
        return;
    }
    for (int i = idx; i < chickens; i++) {
        if (visit[i])
            continue;
        visit[i] = true;
        search(i, depth + 1);
        visit[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int num;
            cin >> num;

            if (num == 1)
                house.push_back({ i, j });
            else if (num == 2)
                chicken.push_back({ i, j });
        }
    }
    chickens = chicken.size();
    visit.resize(chickens);

    // Start Point: 0, Depth: 0
    search(0, 0);

    cout << cost;
}