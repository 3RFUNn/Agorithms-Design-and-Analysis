#include <bits/stdc++.h>

using namespace std;

const int max_n = 1000*100;

vector <int> graph[max_n];

bool visited[max_n];
int score[max_n];


int bfs(int start){
    int javab = 0;
    for(int i = 0 ; i < max_n ; i++){
        visited[i]=false;
    }

	queue<int> Q;
	Q.push(start);
    int level[1000*100];
    level[start]=0;
	while(!Q.empty()){
		int cur = Q.front();
		Q.pop();
		visited[cur]=true;

		for(auto v: graph[cur]){
			if(!visited[v]){
				Q.push(v);
				visited[v]=true;
				level[v]=level[cur]+1;
                javab += level[v];
			}


		}

	}

    return javab;
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);


	int n;
	cin>>n;

	int m;
	cin>>m;
    int mini;
    int node;
	for(int i=0; i<m; i++){
		int u; int v;
		cin>>u>>v;
		u --;
		v --;
		graph[u].push_back(v);
		graph[v].push_back(u);

	}



    mini = INT_MAX;
	 for(int i = 0; i < n; i++){
	 	if(mini > bfs(i) ){
            mini = bfs(i);
            node=i+1;
	 	}
	 	}
        cout<<node;

}
