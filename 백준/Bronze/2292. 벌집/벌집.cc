#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int room = 1, distance = 1;
	while (N > room)
		room += 6 * (distance++);

	cout << distance;
}