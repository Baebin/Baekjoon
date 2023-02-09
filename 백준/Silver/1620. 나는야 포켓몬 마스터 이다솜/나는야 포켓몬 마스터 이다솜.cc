#include <iostream>
#include <string>
#include <map>
using namespace std;

map<int, string> pokemons;
map<string, int> pokemons_idx;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    string pokemon;
    for (int i = 1; i <= N; i++) {
        cin >> pokemon;
        pokemons[i] = pokemon;
        pokemons_idx[pokemon] = i;
    }

    while (M--) {
        cin >> pokemon;
        if (pokemon[0] >= 'A' && pokemon[0] <= 'Z')
            cout << pokemons_idx[pokemon] << "\n";
        else cout << pokemons[stoi(pokemon)] << "\n";
    }
}