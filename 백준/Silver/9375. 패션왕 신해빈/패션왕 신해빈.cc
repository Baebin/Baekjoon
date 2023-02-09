#include <iostream>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    int N;
    string clothes, type;
    while (T--) {
        cin >> N;

        map<string, int> map;
        while (N--) {
            cin >> clothes >> type;

            map[type]++;
        }

        int sum = 1;
        for (auto data : map)
            sum *= (data.second + 1);
        cout << --sum << "\n";
    }
}