#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long tedad,kam,ziyad;
    long sharj_shode=0,current=1;
    vector<long> cellphones;
    cin>>tedad>>kam>>ziyad;
    cellphones.resize(tedad);
    for(long i=0; i<tedad; i++)
    {
        long vorudi;
        cin>>vorudi;
        cellphones[i]=vorudi;
    }
    sort(cellphones.begin(),cellphones.end());
    while(true)
    {
        if(cellphones[0]<0)
            break;
        if(sharj_shode==tedad-1)
            break;
        if(current>tedad-1)
            break;

        if(cellphones[current]<100)
        {
            cellphones[0]-=kam;
            cellphones[current]+=ziyad;
        }
        else
        {
            sharj_shode++;
            current++;
        }
    }
    if(sharj_shode==tedad-1)
        cout<<"YES";
    else cout<<"NO";

    return 0;
}
