#include <iostream>
#include <map>
using namespace std;

map<string, string> search;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    string site, pw;
    while (N--) {
        cin >> site >> pw;
        search[site] = pw;
    }

    while (M--) {
        cin >> site;
        cout << search[site] << "\n";
    }
}