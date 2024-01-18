#include <bits/stdc++.h>
using namespace std;

int main()
{   
    priority_queue<long long, vector<long long>, greater<long long>> q;
    long long n, k;
    cin >> n >> k;
    for (long long i = 0; i < n; ++i) {
        long long x;
        cin >> x; q.push(x);
    }
    bool have_ans = false;
    long long count = 0;
    while (q.size() > 0)
    {
        long long u = q.top();q.pop();
        if (u >= k) {
            have_ans = true;
            break;
        }
        if(q.empty()) {
            break;
        }
        long long v = q.top();q.pop();
        ++count;
        q.push(u + (2LL * v));
    }
    if (have_ans)
        cout << count << "\n";
    else
        cout << -1LL << "\n";
}
