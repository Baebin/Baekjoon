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
        isSCC.resize(V);
        serial.resize(V);
        serial_scc.resize(V);
    }
    void find() {
        for (int node = 0; node < V; node++)
            // Visit Check
            if (serial[node] == 0)
                DFS(node);
    }
    int getCnt() { return cnt_scc; }
    auto getSerial() { return serial_scc; }
    auto getSCC() { return scc; }
    auto getGraph() { return graph; }
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

                // SCC Number
                serial_scc[vertex] = cnt_scc;

                // SCC Check
                isSCC[vertex] = true;
                if (vertex == node)
                    break;
            }
            // SCC Count
            cnt_scc++;

            // Push the SCC
            this->scc.push_back(scc);

        }
        return root;
    }
private:
    int V;
    int cnt_scc;
    int serial_id;

    stack<int> st;
    vector<int> serial;
    vector<int> serial_scc;
    vector<bool> isSCC;

    vector<vector<int>> scc;
    vector<vector<int>> graph;
};

void find(SCC& scc) {
    vector<int> inDegree(scc.getCnt());

    vector<int> serial = scc.getSerial();
    vector<vector<int>> graph = scc.getGraph();

    int graph_size = graph.size();
    for (int vertex = 0; vertex < graph_size; vertex++)
        for (int node : graph[vertex])
            if (serial[vertex] != serial[node])
                inDegree[serial[node]]++;

    int cnt = 0, idx = 0;
    for (int i = 0; i < scc.getCnt(); i++) {
        if (inDegree[i] == 0) {
            idx = i;
            cnt++;
        }
    }

    if (cnt != 1) {
        cout << "Confused\n";
        return;
    }
    vector<int> sccs = scc.getSCC()[idx];
    sort(sccs.begin(), sccs.end());
    for (int vertex : sccs)
        cout << vertex << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int N, E;
        cin >> N >> E;

        vector<vector<int>> graph(N);
        while (E--) {
            int u, v;
            cin >> u >> v;

            // Directed Graph
            graph[u].push_back(v);
        }
        SCC scc(N, graph);
        scc.find();

        find(scc);
        cout << "\n";
    }
}