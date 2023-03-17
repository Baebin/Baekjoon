#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long N, A, B;
	cin >> N;
    
    while (N--) {
        cin >> A >> B;
        cout << A + B << "\n";
    }
}