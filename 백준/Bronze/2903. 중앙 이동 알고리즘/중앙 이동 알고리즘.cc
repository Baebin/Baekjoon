#include <iostream>
using namespace std;

int main(void)
{
    int N;
    cin >> N;

    int ans = 2;
    while (N--)
        ans += ans - 1;
    cout << ans * ans;
}