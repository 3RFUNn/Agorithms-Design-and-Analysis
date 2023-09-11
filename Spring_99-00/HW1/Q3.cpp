#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
map<int, vector<int> > Derakht;
map<int, int> peymayesh_shode;
bool right_permutation(vector<int> &nodes) {
    queue<set<int> > q;
    set<int> derakht;
    derakht.insert(1);
    int n = (int) nodes.size();
    q.push(derakht);
    int i = 0;
    while (!q.empty() && i < n) {
        if (peymayesh_shode.count(nodes[i])) {
            return true;
        }
        peymayesh_shode[nodes[i]] = 1;
        if (q.front().empty()) {
            q.pop();
        }
        if (q.front().find(nodes[i])
            == q.front().end()) {
            return true;
        }
        derakht.clear();
        for (auto j : Derakht[nodes[i]]) {
            if (peymayesh_shode.count(j)) {
                continue;
            }
            derakht.insert(j);
        }
        if (!derakht.empty()) {
            const set<int> &temp = derakht;
            q.push(temp);
        }
        derakht.clear();
        q.front().erase(nodes[i]);
        i++;
    }

    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        scanf("%d",&a);
        scanf("%d",&b);
        Derakht[a].push_back(b);
        Derakht[b].push_back(a);
    }
    vector<int> vorudi;
    for (int j = 0; j < n; ++j) {
        int entry;
        scanf("%d",&entry);
        vorudi.push_back(entry);
    }

    if (right_permutation(vorudi)) {
        printf("No");
    }
    else
        printf("Yes");

    return 0;
}

