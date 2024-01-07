#include <bits/stdc++.h>
using namespace std;

void left(int node, vector<vector<int>>& adj) {
    int k = -1;
    auto it = find(adj[node].begin(), adj[node].end(), k);
    if (it != adj[node].end())
    {
        int index = it - adj[node].begin();
        left(index, adj);
        cout << node+1;

    }
    else {
        cout << node+1;
    }
}
void right(int node, vector<vector<int>>& adj) {
    int k = 1;
    auto it = find(adj[node].begin(), adj[node].end(), k);
    if (it != adj[node].end())
    {
        int index = it - adj[node].begin();
        if (node != 0) {
            cout << node+1;
        }
        right(index, adj);

    }
    else {
        cout << node+1;
    }
}

int main()
{
    int n;
    vector<vector<int>> adj;
    cin >> n;

    for (int i = 0; i < n; i++) {
        vector<int> tmp;
        for (int i = 0; i < n; i++) {
            tmp.push_back(0);
        }
        adj.push_back(tmp);
    }

    int first, secound;
    char child;
    for (int i = 0; i < n - 1; i++) {
        cin >> first >> secound >> child;
        if (child == 'L') {
            adj[secound-1][first-1] = -1;
        }
        else if (child == 'R') {
            adj[secound-1][first-1] = 1;
        }
    }

    left(0, adj);
    right(0, adj);

    return 0;
}
