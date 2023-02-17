#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class SCC {
public:
    explicit SCC(const int &V, const vector<vector<int>> &edge) { init(V, edge); }
    SCC* find() {
        for (int vertex = 0; vertex < V; vertex++)
            // Validate
            if (serial[vertex] == 0)
                DFS(vertex);
        return this;
    }
    const int &getCntScc() const { return cnt_scc; }
    const vector<int> &getSerialScc() const { return serial_scc; }
protected:
    void init(const int &V, const vector<vector<int>> &edge) {
        this->V = V;
        this->edge = edge;

        serial_id = 0;
        cnt_scc = 0;

        serial.resize(V);
        serial_scc.resize(V);

        is_scc.resize(V);
    }
    int DFS(const int &vertex) {
        // Assign Serial Number
        serial[vertex] = ++serial_id;
        st.push(vertex);

        int root = serial[vertex];
        for (int node: edge[vertex])
            if (serial[node] == 0)
                root = min(root, DFS(node));
            else if (!is_scc[node])
                root = min(root, serial[node]);

        // is SCC? (Cycle Check)
        if (root == serial[vertex]) {
            while (!st.empty()) {

                int node = st.top();
                st.pop();

                is_scc[node] = true;
                serial_scc[node] = cnt_scc;

                if (vertex == node)
                    break;
            }
            cnt_scc++;
        }
        return root;
    }
private:
    int V;

    int serial_id;
    int cnt_scc;

    stack<int> st;
    vector<int> serial;
    vector<int> serial_scc;

    vector<bool> is_scc;
    vector<vector<int>> edge;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> edge(N);
    while (M--) {
        int A, B;
        cin >> A >> B;
        edge[A].push_back(B);
    }

    // For Non Cycle Graph
    SCC scc = *SCC(N, edge).find();
    int scc_cnt = scc.getCntScc();
    auto serial = scc.getSerialScc();

    // Topological Sort
    vector<int> inDegree(scc_cnt);
    for (int vertex = 0; vertex < N; vertex++)
        for (int node: edge[vertex])
            if (serial[vertex] != serial[node])
                inDegree[serial[node]]++;

    int cnt = 0;
    for (int i = 0; i < scc_cnt; i++)
        if (inDegree[i] == 0)
            cnt++;
    cout << cnt;
}