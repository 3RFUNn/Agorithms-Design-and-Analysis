#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, h;
	cin >> n >> h;
	vector<long long int > v(n);
	for(auto &x : v)
		cin >> x;
		
	set<long long int> my_set;
    my_set.insert(0LL);
 
    long long int ans = -1e18, sum = 0;

    for (int i = 0; i < n; i++) {
 
        sum += v[i];
        set<long long int>::iterator sit;
        sit = my_set.lower_bound(sum - h);
        if(my_set.lower_bound(sum - h) != my_set.end()){
        	ans = max(ans, sum - *sit);
		}   
        my_set.insert(sum);
    }
    
    cout << ans;
 	return 0; 
}
