# include <bits/stdc++.h>
# define INF ULLONG_MAX

using namespace std;
typedef unsigned long long	LL;

class Graph{
		int V; 
		list< pair<LL, LL> > *way;
	public:
		Graph(int v);
		void add(int s, int e, int w);
		vector<LL> f(int s);
};


int main(){
	int n , m ,k;
	cin>>n>>m>>k;
	Graph g(n);
	
	int s , e , w;//start 	end  weight
	
	for(int i=0 ; i<m ; i++){
		cin>>s>>e>>w;
		g.add(s-1,e-1,w);
	}

	vector<LL> a;
	a=g.f(0);
	
	sort(a.begin(), a.end());
	
	if(a[k-1] != INF)
		cout<<a[k-1];
	else
		cout<<-1;
	
	return 0;
}


Graph::Graph(int v){
	V = v;
	way = new list< pair<LL, LL> > [V];
}

void Graph::add(int s, int e, int w){
	way[s].push_back(make_pair(e, w));
	way[e].push_back(make_pair(s, w));
}

vector<LL> Graph::f(int start){

	priority_queue < pair<LL, LL> , vector< pair<LL, LL> > ,  greater<pair<LL, LL> > > Q;
	
	vector<LL> a(V, INF);
	
		
	Q.push(make_pair(0, start));
	
	a[start] = 0;
	int up,w,v;
	while (!Q.empty()){
		up = Q.top().second;
		Q.pop();
		list< pair<LL, LL> > :: iterator I;
		for (I=way[up].begin() ; I!=way[up].end() ; I++)

			if (a[(*I).first] > a[up] + (*I).second){
				v=(*I).first;
				a[v] = a[up] + (*I).second;
				Q.push(make_pair(a[v], v));
			}
	}
	
	return a;
}
