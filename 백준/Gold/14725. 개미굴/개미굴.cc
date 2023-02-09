#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Trie {
public:
    void insert(const vector<string>& rooms, const int& idx) {
        if (rooms.size() == idx)
            return;
        if (child.find(rooms[idx]) == child.end())
            child[rooms[idx]] = new Trie();
        child[rooms[idx]]->insert(rooms, idx + 1);
    }
    void find(const int& depth) {
        for (pair<string, Trie*> trie : child) {
            for (int i = 1; i <= depth; i++)
                cout << "--";
            cout << trie.first << "\n";
            trie.second->find(depth + 1);
        }
    }
private:
    map<string, Trie*> child;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    Trie trie;
    while (N--) {
        int K;
        cin >> K;

        string room;
        vector<string> rooms;
        while (K--) {
            cin >> room;
            rooms.push_back(room);
        }
        trie.insert(rooms, 0);
    }
    trie.find(0);
}