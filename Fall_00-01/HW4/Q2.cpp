#include<bits/stdc++.h>
using namespace std;

long long md = 1e9 + 7LL;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<long long> fib(1e5 + 1);
    fib[1] = 1LL;
    fib[2] = 1LL;
    for (int i = 3; i <= 1e5; ++i) {
        fib[i] = (fib[i - 1] % md + fib[i - 2] % md) % md;
    }


    long long q, n, d1, d2;
    cin >> q;
    for (;q--;) {
        cin >> d1 >> d2 >> n;
        // replacement d1 and d2
        if (n == 1) {
            cout << d1 << "\n";
        }
        else if (n == 2) {
            cout << d2 << "\n";   
        }
        else {
            cout << (fib[n - 2] * d1 % md + fib[n - 1] * d2 % md) % md << "\n";
        }
    }
}
