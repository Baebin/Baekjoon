#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Structure
typedef pair<long long, long long> Location;
typedef pair<Location, Location> Line;

class LineChecker {
public:
    void setLine(const Line& l1) { this->l1 = l1; }
    int CCW(const Location& l1, const Location& l2, const Location& l3) {
        // 신발끈 공식 (-> Cross Product)
        long long weight_plus
            = (l2.first - l1.first) * (l3.second - l1.second);
        long long weight_minus
            = (l2.second - l1.second) * (l3.first - l1.first);

        // Overflow 방지
        if (weight_plus - weight_minus == 0)
            return 0;
        return (weight_plus > weight_minus ? 1 : -1);
    }
    bool checkLine(Line l2) {
        // p1, p2, p3
        int c1 = CCW(l1.first, l1.second, l2.first);
        // p1, p2, p4
        int c2 = CCW(l1.first, l1.second, l2.second);

        // p3, p4, p1
        int c3 = CCW(l2.first, l2.second, l1.first);
        // p3, p4, p2
        int c4 = CCW(l2.first, l2.second, l1.second);

        // 일직선상
        if (c1 * c2 == 0 && c3 * c4 == 0) {
            if (l1.first > l1.second)
                swap(l1.first, l1.second);
            if (l2.first > l2.second)
                swap(l2.first, l2.second);
            // A <= D && B >= C
            if (l1.first <= l2.second && l1.second >= l2.first)
                return true;
            return false;
        }
        if (c1 * c2 <= 0 && c3 * c4 <= 0)
            return true;
        return false;
    }
private:
    Line l1;
};

class Union {
public:
    Union(const int& N) {
        parent.resize(N);
        graph.resize(N, vector<int>());
        for (int i = 0; i < N; i++)
            parent[i] = i;
    }
    int find(const int& node) {
        if (parent[node] == node)
            return node;
        return parent[node] = find(parent[node]);
    }
    void merge(const int& x, const int& y) {
        int root_x = find(x);
        int root_y = find(y);

        // is Union
        if (root_x == root_y)
            return;
        // Merge
        parent[root_y] = root_x;

        // graph
        graph[root_x].push_back(root_y);
        graph[root_y].push_back(root_x);
    }
    pair<int, int> getGroupInfo() {
        int N = parent.size();
        vector<bool> visit(N);

        int cnt_group = 0, cnt_node = 0;
        for (int i = 0; i < N; i++)
            if (!visit[i]) {
                cnt_group++;
                cnt_node = max(cnt_node, BFS(i, visit));
            }
        return { cnt_group , cnt_node };
    }
    int BFS(int vertex, vector<bool>& visit) {
        queue<int> que;

        // Start Point
        que.push(vertex);
        visit[vertex] = true;

        // Line Count
        int cnt = 1;
        while (!que.empty()) {
            vertex = que.front();
            que.pop();

            for (int node: graph[vertex]) {
                // Validate
                if (visit[node])
                    continue;
                visit[node] = true;
                que.push(node);

                cnt++;
            }
        }
        return cnt;
    }
private:
    vector<int> parent;
    vector<vector<int>> graph;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    Union u(N);
    vector<Line> line(N);

    for (int i = 0; i < N; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        line[i] = { {x1, y1}, {x2, y2} };
    }

    LineChecker checker;
    for (int i = 0; i < N; i++) {
        checker.setLine(line[i]);
        for (int j = i + 1; j < N; j++)
            if (checker.checkLine(line[j]))
                u.merge(i, j);
    }

    auto info = u.getGroupInfo();
    cout << info.first << "\n" << info.second;
}