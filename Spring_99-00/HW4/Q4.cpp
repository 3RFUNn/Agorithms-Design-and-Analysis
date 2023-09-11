#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<long> sahame_edalat;
    long tedade_saham;
    cin>>tedade_saham;
    sahame_edalat.resize(tedade_saham);
    for(long i=0; i<tedade_saham; i++)
    {
        int vorudi;
        cin>>vorudi;
        sahame_edalat[i]=vorudi;
    }
    long bishtarin_saham = sahame_edalat[0], payane_list = sahame_edalat[0];
    for(long i=1; i<tedade_saham; ++i)
    {
        payane_list = max(sahame_edalat[i], payane_list + sahame_edalat[i]);
        bishtarin_saham = max(bishtarin_saham, payane_list);
    }

    cout<<bishtarin_saham;



}
