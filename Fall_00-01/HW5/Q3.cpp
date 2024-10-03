#include<bits/stdc++.h>
using namespace std;
string myFunc(string );
int main()
{
	string a, b;
	cin >> a >> b;
	int n = a.length();
	int m = b.length();
	if(n != m)
	{
		cout << "NO";
		return 0;
	}
	if(n % 2 == 1)
	{
		cout << (a == b ? "YES" : "NO");
		return 0;
	}
	cout << (myFunc(a) == myFunc(b) ? "YES" : "NO");
	return 0;
}
string myFunc(string inp)
{	
	if (inp.length() % 2 == 1) return inp;
	string left = myFunc(inp.substr(0, inp.length() / 2));
	string right = myFunc(inp.substr(inp.length() / 2));
//	cout << left << " " << right << "\t" << left + right << ", " << right + left << '\n';
	return (left + right < right + left ? left + right : right + left);
}

