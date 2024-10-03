#include<bits/stdc++.h>
#define mod 10e-8
using namespace std;
double p, q, r, s, t, u;
double low = 0, high = 1;
double ansByX(double );
double myFunc(double , double );
int main()
{
	cin >> p >> q >> r >> s >> t >> u;
    if(ansByX(low) * ansByX(high) > 0){
        return cout << "No solution", 0;
    }
    cout << fixed << setprecision(4) << myFunc(low, high);
	return 0;
}
double ansByX(double x){
    return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}
double myFunc(double low, double high)
{
	double mid;
	while((high - low) > mod)
    {
        mid = (low + high) / 2;
        if(ansByX(low) * ansByX(mid) <= 0)
			high = mid;
		else
			 low = mid;
    }
    return mid;
}
