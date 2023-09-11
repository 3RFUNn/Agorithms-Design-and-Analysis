#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a;
    cin>>a;
    double saf[a],sum,time[a];
    double temp;
    for(int i=0; i<a; i++)
    {
        cin>>temp;
        saf[i]=temp;
    }
    sort(saf,saf+a);
    sum+=saf[0];
    time[0]=saf[0];
    for(int j=1; j<a; j++)
    {
        time[j]=saf[j]+time[j-1];
        sum+=time[j];
    }
    printf("%.2f", sum/a);

    return 0;
}
