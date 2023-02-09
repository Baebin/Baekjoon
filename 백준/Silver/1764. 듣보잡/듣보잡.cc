#include <iostream>
#include <set>
#include <map>
using namespace std;

set<string> result;
map<string, bool> people;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    string person;
    while (N--) {
        cin >> person;
        people[person] = true;
    }

    while (M--) {
        cin >> person;
        if (people[person])
            result.insert(person);
    }

    cout << result.size() << "\n";
    for (string name : result)
        cout << name << "\n";
}