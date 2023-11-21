#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    while (N--) {
        string name;
        cin >> name;

        for (const char& c : name) {
            if (c != 'S')
                continue;
            cout << name;
            break;
        }
    }
}