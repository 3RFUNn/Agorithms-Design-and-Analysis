#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k, res = 0;
    int a[6][1001], dp[10002], pos[6][1001];

    cin >> n >> k;
    for(int i = 1; i <= k; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
            pos[i][a[i][j]] = j;
        }
    }
     
    int i;
   for(int j1 = 0; j1 <= n; j1++) {
     for(int j = 1; j <= n; j++) {
        for(i = 1; i <= k; i++) {
          if(pos[i][a[1][j]] <= pos[i][a[1][j1]]) 
            break;  
        } 
        if(i > k) 
            dp[j] = max(dp[j], dp[j1] + 1);

     }

   }

   for(int i = 1; i <= n; i++)
     res = max(res, dp[i]);
   cout << res << "\n";
   return 0;
}
