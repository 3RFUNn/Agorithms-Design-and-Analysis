#include <bits/stdc++.h>
using namespace std;
const int maxn = 10;
int n, m, a, b, mn = 1;
bool isAble(bool [][maxn] , int );
bool getUtil(bool [][maxn] , int , int [] , int );
bool isValid(int , int, bool [][maxn] , int [] );
void solve(bool [][maxn] );

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	bool gf[n][maxn];
	memset(gf, 0, sizeof(gf));
	for(; m--; )
	{
		cin >> a >> b;
		a--, b--;
		gf[a][b] = gf[b][a] = 1;
	}
	solve(gf);
	return 0;
}

bool isValid(int v, int c, bool gf[][maxn], int color[])
{
	int res = 1;
	for(int i = 0; i < n; i++)
	{
		if (gf[v][i] && c == color[i])
		{
			res = 0;
			break;
		}
	}		
	return res;
}
bool getUtil(bool gf[][maxn], int m, int color[], int v)
{
	if (v == n)
		return 1;

	for(int c = 1; c <= m; c++)
	{
		if (isValid(v, c, gf, color))
		{
			color[v] = c;
			if (getUtil(gf, m, color, v + 1))
				return true;
			color[v] = 0;
		}
	}
	return false;
}
bool isAble(bool gf[][maxn], int m)
{
	int color[n];
	return (getUtil(gf, m, color, 0));
}
void solve(bool gf[][maxn]){
	while(!isAble(gf, mn))
		mn++;
	cout << mn;
}

