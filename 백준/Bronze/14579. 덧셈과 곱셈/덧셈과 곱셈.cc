#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int A, B;
    cin >> A >> B;

    int ans = 1;
    int tmp = (A  * (A + 1))/2;
    for (int i = A; i <= B; i++)
        ans = (ans * tmp) % 14579, tmp = (tmp + (i + 1)) % 14579;
    cout << ans % 14579;
}