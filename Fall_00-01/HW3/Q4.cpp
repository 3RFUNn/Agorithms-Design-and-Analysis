#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> g(100010);
vector<int> group(100010);
void dfs(int v, int gr, int pr) {
	group[v] = gr;
	for (auto adj: g[v]) {
		if (adj != pr) {
			dfs(adj, gr, v);
		}
	}
}

int main() {
	//ios_base::sync_with_stdio(false);
	int n, m, c; cin >> n >> m >> c;
	int u, v, w;
	long long res = 0LL;
	vector<pair<int, pair<int, int>>> graph(m);

	for (int i = 0; i < m; ++i) {
		cin >> u >> v >> w;
		--u; --v;
		graph[i].first = w;
		graph[i].second = make_pair(u, v);
	}
	sort(graph.rbegin(), graph.rend());
	
	
	for (int i = 0; i < n; ++i)
		group[i] = i;
	int E = 0;
	for (auto ver: graph) {
		u = ver.second.first;
		v = ver.second.second;
		if (group[u] != group[v]) {
			dfs(v, group[u], -1);
			g[u].push_back(v);
			g[v].push_back(u);
			E++;
			res+= (long long) ver.first;
		}
		else {
			// delete
		}
		if (E == n - 1) {
			cout << res << "\n";
			return 0;
		}
	}
	if ((n == 1 && m == 0) || n == 0) {cout << "0\n"; return 0;}
	cout << "-1\n";
	return 0;
}
