#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define edge pair<int, int>
class Graph
{
private:
    vector<pair<int, edge> > G;  // graph
    vector<pair<int, edge> > T;  // mst
    int *parent;
    int V;
public:
    Graph(int V);
    void AddWeightedEdge(int u, int v, int w);
    int find_set(int i);
    void union_set(int u, int v);
    void kruskal();
    void kruskal2();
    void print();
};
Graph::Graph(int V)
{
    parent = new int[V];
    for (int i = 0; i < V; i++)
        parent[i] = i;

    G.clear();
    T.clear();
    T.resize(V);
}
void Graph::AddWeightedEdge(int u, int v, int w)
{
    G.push_back(make_pair(w, edge(u, v)));
}
int Graph::find_set(int i)
{
    if (i == parent[i])
        return i;
    else
        return find_set(parent[i]);
}

void Graph::union_set(int u, int v)
{
    parent[u] = parent[v];
}
void Graph::kruskal()
{
    int i, uRep, vRep;
    sort(G.begin(), G.end());
    for (i = 0; i < G.size(); i++)
    {
        uRep = find_set(G[i].second.first);
        vRep = find_set(G[i].second.second);
        if (uRep != vRep)
        {
            T[i]=G[i];
            union_set(uRep, vRep);
        }
    }
}
void Graph::kruskal2()
{
    int i, uRep, vRep;
    sort(G.begin(), G.end());
    reverse(G.begin(), G.end());
    for (i = 0; i < G.size(); i++)
    {
        uRep = find_set(G[i].second.first);
        vRep = find_set(G[i].second.second);
        if (uRep != vRep)
        {
            T[i]=G[i];
            union_set(uRep, vRep);
        }
    }
}
void Graph::print()
{
    int m=0;
    for (int i = 0; i < T.size(); i++)
    {
        m+=T[i].first;
    }
    cout<<m<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,u,v,w;
    cin>>n;
    Graph g(n+1);
    Graph m(n+1);
    for(int i=0; i<n; i++)
    {
        cin>>u>>v>>w;
        g.AddWeightedEdge(u,v,w);
        m.AddWeightedEdge(u,v,w);
    }
    m.kruskal2();
    m.print();
    g.kruskal();
    g.print();


    return 0;
}
