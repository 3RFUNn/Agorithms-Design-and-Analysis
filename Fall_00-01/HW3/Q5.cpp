#include "iostream"
using namespace std;

int main()
{
  bool flag = false;
  int x, n, m,i=0,j=0,sum=0;
  cin >> x >> n >> m;
  while ((n*i) + (m*j) <= x)
  {
    while ((n*i) + (m*j) <= x)
    {
      sum = (n*i) + (m*j);
      if (sum == x) { cout << i << " " << j ;flag=true; break; }
      i++;
    }
    if (flag) { break; }
    i = 0;
    j++;
  }
  if (flag == false) { cout << -1 ; }
    return 0;
}