#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    while (N--) {
        string name;
        cin >> name;

        for (char c : name) {
            if (c < 'a')
                cout << (c += 'a' - 'A');
            else cout << c;
        }
        cout << "\n";
    }
}