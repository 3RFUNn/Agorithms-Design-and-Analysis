#include<bits/stdc++.h>
using namespace std;

vector<int> egg(30010, 0);
const int sq = 30000;
int arr[sq+1][600];
int res = 0;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, j, u; cin >> n >> j;
    for (int i = 0; i < n; ++i) {
        cin >> u;
        egg[u]+= 1;
    }
    memset(arr, -1, sizeof arr);
    arr[j][250] = egg[j];
    int idx;
    for (int i = j; i <= sq; i++) {
        for (int k = 0; k <= 500; k++) {
            if (arr[i][k] == -1) continue;
            idx = i+k+j-250;
            for (int w = -1; w < 2; w++) {
                if (idx + w <= sq && idx + w > i) {
                    arr[idx + w][k + w] = max(arr[idx + w][k + w], arr[i][k]+egg[idx + w]);
                }
            }
            res = max(res, arr[i][k]);
        }
    }

    cout << res << "\n";

}

