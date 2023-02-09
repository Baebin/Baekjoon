#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string a, string b) {
	if (a.length() == b.length())
		return a < b;
	return (a.length() < b.length());
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	string word;
	vector<string> vec_word;
	for (int i = 0; i < N; i++) {
		cin >> word;
		if (find(vec_word.begin(), vec_word.end(), word) == vec_word.end())
			vec_word.push_back(word);
	}

	sort(vec_word.begin(), vec_word.end(), cmp);

	for (string str : vec_word)
		cout << str << "\n";
}