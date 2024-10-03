#include <bits/stdc++.h>
using namespace std;

void f(int a[][2] , int n , int i , int &s , int &e , int &t);

int main(){
 int n,k;
 cin>>n>>k;
 
 int a[n][2];
 for(int i=0 ; i<n ; i++) 
 	a[i][0]=a[i][1]=0;
 
 int x,y;
 for(int i=0 ; i<k ; i++){
 	cin>>x>>y;
 	x--;
 	if(a[x][0]==0)
 		a[x][0]=a[x][1]=y;
 		
 	else if(y<a[x][0])
 		a[x][0]=y;
 			
	else if(a[x][1]<y)
 		a[x][1]=y;
	
 }
 
 int t=1;
 
 for(int i=0 ; i<n ; i++)
 	if(t<a[i][1]-a[i][0] + 1)
 		t=a[i][1]-a[i][0] + 1;
 
 
 int s=1;
 int e=n;
 
 for(int i=0 ; i<n ; i++){
 	f(a,n,i,s,e,t);
 	//cout<<i;
 }
 	
 
 cout<<t;
 
 return 0;
}

void f(int a[][2] , int n , int i , int &s , int &e , int &t){
	
	s = 2<s ? s-1 : 1;
	e = e<n ? e+1 : n;
	
	if(a[i][0]==0)
		return ;
		
	while(a[i][0]<s){
		s = 2<s ? s-1 : 1;
		e = e<n ? e+1 : n;
		t++;//cout<<11;
	}
	
	while(e<a[i][1]){
		
		s = 2<s ? s-1 : 1;
		e = e<n ? e+1 : n;
		t++;//cout<<11;
	}
	
	while(s+t-1 < a[i][1])
		s++;
	
	while(e-t+1 > a[i][0])
		e--;

		
	
}






















