#include <iostream>
#include <vector>
using namespace std;

#define INF 2e9

vector<int> dis;
vector<int> cost;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    dis.resize(N + 1);
    cost.resize(N + 1);

    for (int i = 1; i < N; i++)
        cin >> dis[i];

    for (int i = 1; i <= N; i++)
        cin >> cost[i];

    int min_oil = INF;
    int min_cost = 0;
    for (int i = 1; i < N; i++) {
        if (cost[i] < min_oil)
            min_oil = cost[i];
        min_cost += min_oil * dis[i];
    }

    cout << min_cost;
}