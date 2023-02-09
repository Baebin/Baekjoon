#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, H, W, N;
	int floor, room;

	cin >> T;
	for (int i = 0; i < T; i++) {
		// floor, room, guest
		cin >> H >> W >> N;

		floor = (N % H);
		room = ((N - 1) / H) + 1;

		if (floor == 0) floor = H;

		printf("%d\n", floor * 100 + room);
	}
}