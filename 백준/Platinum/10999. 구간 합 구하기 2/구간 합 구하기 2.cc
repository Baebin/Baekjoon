#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
using namespace std;

// Structure
typedef long long ll;

class LazySegementTree {
public:
	LazySegementTree(const vector<ll>& container) {
		this->container = container;

		int N = container.size();
		tree.resize(N * 4);
		lazy.resize(N * 4);
		init(0, N - 1, 1);
	}
	ll sum(const int& start, const int& end, const int& node, const int& left, const int& right) {
		update_lazy(start, end, node);
		if (right < start || left > end)
			return 0;
		if (left <= start && end <= right)
			return tree[node];
		int mid = (start + end) / 2;
		return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
	}
	void update(const int& start, const int& end, const int& node, const int& left, const int& right, const ll& value) {
		update_lazy(start, end, node);
		if (right < start || left > end)
			return;
		if (left <= start && end <= right) {
			tree[node] += (end - start + 1) * value;
			if (start != end) {
				lazy[node * 2] += value;
				lazy[node * 2 + 1] += value;
			}
			return;
		}
		int mid = (start + end) / 2;
		update(start, mid, node * 2, left, right, value);
		update(mid + 1, end, node * 2 + 1, left, right, value);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
protected:
	ll init(const int& start, const int& end, const int& node) {
		if (start == end)
			return tree[node] = container[end];
		int mid = (start + end) / 2;
		return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
	}
	void update_lazy(const int& start, const int& end, const int& node) {
		if (lazy[node] == 0)
			return;
		tree[node] += (end - start + 1) * lazy[node];
		if (start != end) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
private:
	vector<ll> container;
	vector<ll> tree;
	vector<ll> lazy;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, K;
	cin >> N >> M >> K;

	vector<ll> container(N);
	for (int i = 0; i < N; i++)
		cin >> container[i];

	int A; ll B, C, D;
	LazySegementTree tree(container);

	for (int i = 0; i < M + K; i++) {
		cin >> A >> B >> C;

		// Update
		if (A == 1) {
			cin >> D;
			tree.update(0, N - 1, 1, B - 1, C - 1, D);
		}
		else cout << tree.sum(0, N - 1, 1, B - 1, C - 1) << "\n";
	}
}