#include <iostream>
#include <vector>
using namespace std;

#define MAX 10000000
vector<int> cards(MAX * 2 + 1);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		cards[tmp + MAX] += 1;
	}

	int M;
	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> tmp;
		cout << cards[tmp + MAX] << " ";
	}
}