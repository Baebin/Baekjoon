#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Delare
#define INF 2e9

int i;
int N, M;

int start_city, end_city;
int tmp_start, tmp_end, tmp_pay;

int city;
int newCity;

int tmp_cost;

vector<int> cost;
vector<vector<pair<int, int>>> vec;

priority_queue<pair<int, int>> que;

// Search
void dijkstra() {
	cost[start_city] = 0;
	que.push({ 0, start_city });

	while (!que.empty()) {
		city = que.top().second;
		tmp_pay = -que.top().first;
		que.pop();

		if (cost[city] < tmp_pay) continue;

		for (i = 0; i < vec[city].size(); i++) {
			newCity = vec[city][i].second;
			tmp_cost = tmp_pay + vec[city][i].first;

			if (tmp_cost < cost[newCity]) {
				cost[newCity] = tmp_cost;
				que.push({ -tmp_cost, newCity });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	N, M;
	cin >> N >> M;

	// Init
	vec.resize(N + 1);
	cost.resize(N + 1, INF);

	for (i = 0; i < M; i++) {
		cin >> tmp_start >> tmp_end >> tmp_pay;
		vec[tmp_start].push_back({ tmp_pay, tmp_end });
	}
	cin >> start_city >> end_city;
	
	dijkstra();

	printf("%d", cost[end_city]);
}