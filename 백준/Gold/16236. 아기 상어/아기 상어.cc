#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define UP loc.y - 1
#define DOWN loc.y + 1
#define LEFT loc.x - 1
#define RIGHT loc.x + 1

int stack = 0;
int N, baby_size = 2;

vector<int> fish(6 + 1, 0);
vector<vector<int>> graph;

struct Location {
    int x, y;
};

void move(Location* baby, const Location& loc) {
    fish[graph[loc.y][loc.x]]--;

    graph[(*baby).y][(*baby).x] = 0;
    graph[loc.y][loc.x] = 0;

    *baby = { loc.x, loc.y };

    if (++stack == baby_size) {
        stack = 0;
        baby_size++;
    }
}

bool isEmpty() {
    int min = 0;
    for (int i = 1; i <= 6; i++) {
        if (fish[i] != 0) {
            min = i;
            break;
        }
    }
    if (baby_size > min && min > 0)
        return false;
    return true;
}

bool canEat(const Location& loc) {
    if (graph[loc.y][loc.x] == 0) return false;
    return baby_size > graph[loc.y][loc.x];
}

bool canMove(const Location& loc) {
    return baby_size >= graph[loc.y][loc.x];
}

pair<Location, int> BFS(const Location& baby) {
    queue<pair<int, Location>> que;
    vector<vector<bool>> visit(N, vector<bool>(N));
    vector<vector<Location>> graph_cost(N, vector<Location>(N, { -1, -1 }));

    que.push({ 0, baby });
    visit[baby.y][baby.x] = true;

    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            if (!canMove({ x, y }))
                visit[y][x] = true;

    pair<int, Location> data;
    Location loc; int distance;

    int min = 0;

    while (!que.empty()) {
        data = que.front();
        distance = data.first;
        loc = data.second;

        que.pop();

        if (canEat(loc)) {
            if (min == 0)
                min = distance;
            else if (distance > min) continue;
            graph_cost[loc.y][loc.x] = loc;
            continue;
        }

        distance++;
        if (LEFT >= 0 && !visit[loc.y][LEFT]) {
            que.push({ distance, { LEFT, loc.y } });
            visit[loc.y][LEFT] = true;
        }
        if (UP >= 0 && !visit[UP][loc.x]) {
            que.push({ distance, { loc.x, UP } });
            visit[UP][loc.x] = true;
        }
        if (DOWN < N && !visit[DOWN][loc.x]) {
            que.push({ distance, { loc.x, DOWN } });
            visit[DOWN][loc.x] = true;
        }
        if (RIGHT < N && !visit[loc.y][RIGHT]) {
            que.push({ distance, { RIGHT, loc.y } });
            visit[loc.y][RIGHT] = true;
        }
    }

    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            if (graph_cost[y][x].x != -1)
                return { graph_cost[y][x], min };

    return { {}, 0 };
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    graph.resize(N, vector<int>(N));

    Location baby;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> graph[y][x];
            
            if (graph[y][x] == 0)
                continue;
            if (graph[y][x] == 9)
                baby = { x, y };
            else fish[graph[y][x]]++;
        }
    }

    int time = 0;
    pair<Location, int> fish;
    while (!isEmpty()) {
        fish = BFS(baby);

        if (fish.second == 0)
            break;

        time += fish.second;
        move(&baby, fish.first);
    }

    cout << time;
}