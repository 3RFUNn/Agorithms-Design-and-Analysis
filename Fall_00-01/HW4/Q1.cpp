#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    unsigned long long n, m, l, r, t;
    cin >> n >> m;
    vector<pair<unsigned long long, int>> open, close;
    vector<unsigned long long> cost, start;

    for(int i = 0; i < m; i++) {
        cin >> l >> r >> t;
        open.push_back({l, i});
        close.push_back({r, i});
        cost.push_back(t);
        start.push_back(l);
    }
    
    sort(open.begin(), open.end());
    sort(close.begin(), close.end());
    
    unsigned long long i = 0, j = 0;
    unsigned long long res = (unsigned long long)0;
    vector<pair<unsigned long long, unsigned long long>> close_list;
    unsigned long long len = (unsigned long long)0;

    while (i < m) {
        if (open[i].first <= close[j].first) {
            ++i;
        }
        else {
            l = start[close[j].second];
            for (int k = len - 1; k >= 0; --k) {
                if (l <= close_list[k].first) {
                    if (close_list[k].second >= cost[close[j].second]) {
                        cost[close[j].second] = (unsigned long long)0;
                        break;
                    }
                    else
                        cost[close[j].second]-= close_list[k].second;
                }
                else break;
            }
            if (cost[close[j].second] != (unsigned long long)0) {
                close_list.push_back({close[j].first, cost[close[j].second]});
                ++len;
                res+= cost[close[j].second];
            }
            ++j;
        }
    }
    while (j < m) {
        l = start[close[j].second];
        for (int k = len - 1; k >= 0; --k) {
            if (l <= close_list[k].first) {
                if (close_list[k].second >= cost[close[j].second]) {
                    cost[close[j].second] = (unsigned long long)0;
                    break;
                }
                else
                    cost[close[j].second]-= close_list[k].second;
            }
            else break;
        }
        if (cost[close[j].second] != (unsigned long long)0) {
            close_list.push_back({close[j].first, cost[close[j].second]});
            ++len;
            res+= cost[close[j].second];
        }
        ++j;
    }
    cout << res << "\n";
}
