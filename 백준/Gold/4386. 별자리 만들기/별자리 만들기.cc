#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

// Structure
struct Location {
	double x, y;

	double getDistance(const Location& a) {
		double dx = x - a.x;
		double dy = y - a.y;
		return sqrt(dx * dx + dy * dy);
	}
};

struct Edge {
	int u, v;
	double weight;

	bool operator<(const Edge& edge) {
		return weight < edge.weight;
	}
};

class Union {
public:
	Union(const int& N) {
		parent.resize(N);
		for (int i = 0; i < N; i++)
			parent[i] = i;
	}
	int findParent(const int& node) {
		if (parent[node] == node)
			return node;
		return parent[node] = findParent(parent[node]);
	}
	bool merge(int x, int y) {
		x = findParent(x);
		y = findParent(y);

		if (x == y)
			return false;
		parent[y] = x;
		return true;
	}
protected:
	vector<int> parent;
};

class Kruskal : public Union {
public:
	Kruskal(const int& N) : Union(N) {}
	void push(const Edge& e) { edge.push_back(e); }
	double get() {
		sort(edge.begin(), edge.end());

		double cost = 0;
		for (Edge e : edge)
			if (Union::merge(e.u, e.v))
				cost += e.weight;
		return cost;
	}
private:
	vector<Edge> edge;
};

int main() {
	int N;
	cin >> N;

	Kruskal k(N);
	vector<Location> loc(N);

	for (int i = 0; i < N; i++) {
		cin >> loc[i].x >> loc[i].y;
		for (int j = 0; j < i; j++)
			k.push({ i, j, loc[i].getDistance(loc[j]) });
	}

	cout << fixed;
	cout.precision(2);
	cout << k.get();
}