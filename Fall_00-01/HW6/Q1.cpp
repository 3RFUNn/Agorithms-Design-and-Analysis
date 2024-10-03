#include <bits/stdc++.h>
using namespace std;

#define max 800*1000+1

struct box{
	int x;
	int y;
	int w;
};

int f(vector <box> &a , int x , int y , int sum_x , int sum_y , int k , int total_x , int total_y , int money , int &min);

int main(){
 int c;
 cin>>c;
 
 for(int t=0 ; t<c ; t++){
 	int x,y;
 	cin>>x>>y;
 	
 	int n;
 	cin>>n;
 	
 	vector<box> B(n);
 	
 	int total_x , total_y;
 	total_x = total_y = 0;
 	
 	for(int i=0 ; i<n ; i++){
 		cin>> B[i].x >> B[i].y >> B[i].w;
 		
 		total_x += B[i].x;
 		total_y += B[i].y;
 		
	 }
 		
 	int M=max;
 	cout<< f(B,x,y,0,0,0,total_x , total_y,0,M)<<"\n";
 }
 	
 return 0;
}


int f(vector <box> &a , int x , int y , int sum_x , int sum_y , int k, int total_x , int total_y , int money , int &M){
	
	if(x<=sum_x && y<=sum_y){
		M = min(money,M);
		return M;
	}
	
	else if(k == a.size() || sum_x+total_x < x || sum_y+total_y < y || money>M)
		return max;
	
	
	
	int T = f(a,x,y, sum_x+a[k].x	 , sum_y+a[k].y , k+1 , total_x-a[k].x , total_y-a[k].y , money+a[k].w  , M );
	int D = f(a,x,y, sum_x			 , sum_y		, k+1 , total_x-a[k].x , total_y-a[k].y , money			, M );
	
	return min(T,D);
}





