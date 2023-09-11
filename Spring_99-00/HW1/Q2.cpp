#include<bits/stdc++.h>

using namespace std;

vector<vector<int> > graph;
vector<int> d;
vector<bool> vis;

void bfs(int s) {
    int t;
    queue<int> q;
    q.push(s);
    d[s] = 0;
    vis[s] = true;
    while (!q.empty()) {
        t = q.front();
        q.pop();
        for (int i = 0; i < graph[t].size(); i++) {
            if (!vis[graph[t][i]]) {
                vis[graph[t][i]] = true;
                d[graph[t][i]] = d[t] + 1;
                q.push(graph[t][i]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, t, j, a, m, q, k, s;
    cin >> n >> m >> q >> k >> s;
    vis.resize(n + 1);
    graph.resize(n + 1);
    d.resize(n + 1);

    for (j = 0; j < m; j++) {
        cin >> a >> t;
        graph[a].push_back(t);
        graph[t].push_back(a);
    }
    fill_n(vis.begin(), n + 1, false);
    fill_n(d.begin(), n + 1, 0);
    bfs(q);
    for (int l = 0; l < n; ++l) {
        if(l==q){
            cout<<s<<endl;
            continue;
        }
        if(d[l]==0){
            cout<<0<<endl;
            continue;
        }
        if(s-10*d[l]<0){
            cout<<0<<endl;
            continue;
        }
        if(d[l]>k){
            cout<<0<<endl;
            continue;
        }
        if(d[l]<=k){
            cout<<(s-10*d[l])<<endl;
            continue;
        }
    }

    return 0;
}

