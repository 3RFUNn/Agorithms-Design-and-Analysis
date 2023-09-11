#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pairs;
struct Graph
{
    int V, E;
    vector< pair<int, pairs> > edges;
    Graph(int V, int E)
    {
        this->V = V;
        this->E = E;
    }
    void addEdge(int u, int v, int w)
    {
        edges.push_back({w, {u, v}});
    }
    int kruskalMST(int& adade_niazi);
};
struct DisjointSets
{
    int *parent, *rnk;
    int n;
    DisjointSets(int n)
    {
        this->n = n;
        parent = new int[n+1];
        rnk = new int[n+1];
        for (int i = 0; i <= n; i++)
        {
            rnk[i] = 0;
            parent[i] = i;
        }
    }
    int find(int u)
    {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }
    void merge(int x, int y)
    {
        x = find(x), y = find(y);
        if (rnk[x] > rnk[y])
            parent[y] = x;
        else
            parent[x] = y;
        if (rnk[x] == rnk[y])
            rnk[y]++;
    }
};
int Graph::kruskalMST(int& adade_niazi)
{
    int moshtarak = 0;
    sort(edges.begin(), edges.end());
    reverse(edges.begin(), edges.end());
    DisjointSets ds(V);
    vector< pair<int, pairs> >::iterator it;
    for (it=edges.begin(); it!=edges.end(); it++)
    {
        int u = it->second.first;
        int v = it->second.second;
        int set_u = ds.find(u);
        int set_v = ds.find(v);
        if (set_u != set_v)
        {
            adade_niazi++;
            if(it->first==3)
             moshtarak += 1;
                      ds.merge(set_u, set_v);
        }
    }
    return moshtarak;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int V, E;
    int num1=0,num2=0;
    cin>>V>>E;
    Graph grinfindor(V, E);
    Graph estrilin(V , E);
    for(int i=0;i<E;i++){
        int a,b,c;
        cin>>a>>b>>c;
        if(c==3){
            estrilin.addEdge(a,b,c);
            grinfindor.addEdge(a,b,c);
        }
        else if (c==2){
            estrilin.addEdge(a,b,c);
        }else if (c==1){
            grinfindor.addEdge(a,b,c);
        }
    }
        int grif=grinfindor.kruskalMST(num1);
        int estr=estrilin.kruskalMST(num2);
        if(num1==(V-1) && num2==(V-1)){
            cout<< E - (estr + (2*V - 2 - estr - grif));
        }else cout<< -1;

    return 0;
}
