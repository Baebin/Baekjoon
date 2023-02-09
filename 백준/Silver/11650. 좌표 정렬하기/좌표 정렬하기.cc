#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Location {
	int x, y;
};

bool cmp(Location a, Location b) {
	if (a.x == b.x)
		return a.y < b.y;
	return a.x < b.x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int x, y;
	vector<Location> locs(N);
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		locs[i] = { x, y };
	}
	sort(locs.begin(), locs.end(), cmp);

	for (Location loc : locs)
		cout << loc.x << " " << loc.y << "\n";
}