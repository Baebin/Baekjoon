#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

	for (register int i = 1; i <= N; i++)
	{
		for (register int j = 1; j <= i; j++) cout << "*";
		for (register int j = 1; j <= 2 * (N - i); j++) cout << " ";
		for (register int j = 1; j <= i; j++) cout << "*";
		cout << "\n";
	}
	for (int i = 1; i < N; i++)
	{
		for (register int j = i; j < N; j++) cout << "*";
		for (register int j = 1; j <= 2 * i; j++) cout << " ";
		for (register int j = i; j < N; j++) cout << "*";
		cout << "\n";
	}
}