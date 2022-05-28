#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to;
    int capacity;
    int flow;
    Edge *rev;
    int spare() { return capacity - flow; }
    void add_flow(int flow) {
        this->flow += flow;
        rev->flow -= flow;
    }
};

Edge edge_list[20004];
int list_cnt;
Edge *new_edge(int capacity, int to) {
    edge_list[list_cnt] = {to, capacity, 0, nullptr};
    return &edge_list[list_cnt++];
}

vector<Edge*> adj[402];
int par[402];
Edge *path[402];

int network_flow(int src, int sink) {
    int total_flow = 0;
    while (true) {
        memset(par, -1, sizeof(par));
        queue<int> q;
        q.push(src);
        while (!q.empty() && par[sink] == -1) {
            int cur = q.front(); q.pop();
            for (auto &e : adj[cur]) {
                int nxt = e->to;
                if (e->spare() > 0 && par[nxt] == -1) {
                    q.push(nxt);
                    par[nxt] = cur;
                    path[nxt] = e;
                    if (nxt == sink) break;
                }
            }
        }
        if (par[sink] == -1) break;
        int min_amount = 1e9;
        for (int i = sink; i != src; i = par[i]) {
            min_amount = min(min_amount, path[i]->spare());
        }
        for (int i = sink; i != src; i = par[i]) {
            path[i]->add_flow(min_amount);
        }
        total_flow += min_amount;
    }
    return total_flow;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, p; cin >> n >> p;
    for (int i = 0; i < p; i++) {
        int a, b; cin >> a >> b;
        Edge *e = new_edge(1, b);
        Edge *rev = new_edge(0, a);
        e->rev = rev;
        rev->rev = e;
        adj[a].push_back(e);
        adj[b].push_back(rev);
    }

    cout << network_flow(1, 2);
}