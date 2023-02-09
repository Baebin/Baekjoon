#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int x, y, w, h;
	cin >> x >> y >> w >> h;

	cout << min(
			min(abs(x - w), abs(y - h)), min(x, y));
}