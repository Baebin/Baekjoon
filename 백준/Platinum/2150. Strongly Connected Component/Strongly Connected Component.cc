#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class SCC {
public:
    SCC(const int& V, const vector<vector<int>>& graph) {
        this->V = V;
        this->graph = graph;

        // Init
        cnt_scc = 0;
        serial_id = 0;

        // Memory Allocation
        isSCC.resize(V + 1);
        serial.resize(V + 1);
    }
    auto find() {
        for (int node = 1; node <= V; node++)
            // Visit Check
            if (serial[node] == 0)
                DFS(node);
        sort(scc.begin(), scc.end());
        return this;
    }
    int getCnt() { return cnt_scc; }
    auto getSCC() { return scc; }
protected:
    int DFS(const int& node) {
        // Assign Serial Number
        serial[node] = ++serial_id;
        st.push(node);

        int root = serial[node];
        for (int vertex : graph[node]) {
            // not Visited
            if (serial[vertex] == 0)
                root = min(root, DFS(vertex));
            // Visited && isn't SCC
            else if (!isSCC[vertex])
                root = min(root, serial[vertex]);
        }

        // Check SCC
        if (root == serial[node]) {
            vector<int> scc;
            while (!st.empty()) {
                // Insert the SCC
                int vertex = st.top();
                scc.push_back(vertex);
                st.pop();

                // SCC Check
                isSCC[vertex] = true;
                if (vertex == node)
                    break;
            }
            // ASC
            sort(scc.begin(), scc.end());
            this->scc.push_back(scc);

            // SCC Count
            cnt_scc++;
        }
        return root;
    }
private:
    int V;
    int cnt_scc;
    int serial_id;

    stack<int> st;
    vector<int> serial;
    vector<bool> isSCC;

    vector<vector<int>> scc;
    vector<vector<int>> graph;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V, E;
    cin >> V >> E;

    vector<vector<int>> graph(V + 1);
    while (E--) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    SCC scc(V, graph);
    vector<vector<int>> vec = scc.find()->getSCC();

    cout << scc.getCnt() << "\n";
    for (vector<int> sccs : vec) {
        for (int vertex : sccs)
            cout << vertex << " ";
        cout << -1 << "\n";
    }
}