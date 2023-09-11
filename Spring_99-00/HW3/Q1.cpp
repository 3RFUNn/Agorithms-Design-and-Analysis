#include <iostream>
#include <vector>
using namespace std;
vector<int> parent;
vector<int> andaze;
   void DS_maker(int n)
{
    andaze.resize(n);
    parent.resize(n);
    for (int i = 0; i < n; i++)
    {
        andaze[i]=1;
        parent[i] = i;

    }
}
int find(int y)
{
    if (parent[y] != y)
    {
        parent[y]=find(parent[y]);
    }
    return parent[y];
}
void merge(int x, int y)
{

    int x_node = find(x);
    int y_node = find(y);

    if (x_node == y_node)
        return;

    if (andaze[x_node] < andaze[y_node])
    {
        parent[x_node] = y_node;
        andaze[y_node]+=andaze[x_node];
        andaze[x_node]=andaze[parent[x_node]];
    }
    else if (andaze[x_node] > andaze[y_node])
    {
        parent[y_node] = x_node;
        andaze[x_node]+=andaze[y_node];
        andaze[y_node]=andaze[parent[y_node]];
    }


    else
    {
        parent[x_node] = y_node;
        andaze[y_node]+=andaze[x_node];
        andaze[x_node]=andaze[y_node];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, first, second, third;
    cin >> n >> m;
    DS_maker(n+1);
    for (int k = 0; k < m; k++)
    {
        cin >> first;
        if (first == 1)
        {
            cin >> second >> third;
            if (second == third)
                continue;
            merge(second, third);
        }
        else
        {
            cin >> second;
            cout<< andaze[find(second)]<<"\n";
        }
    }

    return 0;
}
