#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string emoji;
	cin >> emoji;

	int colon = 0;
	int underbar = 0;

	for (char c : emoji)
		if (c == ':')
			colon++;
		else if (c == '_')
			underbar++;
	cout << (emoji.length() + colon + underbar * 5);
}