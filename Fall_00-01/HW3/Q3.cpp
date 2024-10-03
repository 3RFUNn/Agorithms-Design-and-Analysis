#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long tedad;
    cin>>tedad;
    long gheymate_tablo[tedad+1];

    for(long i=1; i<=tedad; i++)
    {
        long arzesh;
        cin>>arzesh;
        gheymate_tablo[i]=arzesh;
    }

    long sum[tedad+1];
    long masir[tedad+1];
    masir[1]=-1;
    masir[2]=-1;
    sum[1]=gheymate_tablo[1];
    sum[2]=max(gheymate_tablo[1],gheymate_tablo[2]);

    for(long j=3; j<=tedad; j++)
    {
        if (sum[j - 2] + gheymate_tablo[j] > sum[j - 1])
        {
            masir[j] = j - 2;
            sum[j] = sum[j - 2] + gheymate_tablo[j];
        }
        else
        {
            masir[j] = j - 1;
            sum[j] = sum[j - 1];
        }

    }
    long path=tedad;
    if(sum[path]==sum[path-1])
        path--;
    stack<long> dozdide;
    int tedad_dozdide=0;
    while(true)
    {
        if(sum[path]==sum[path-1])
            path--;
        dozdide.push(path);
        path=masir[path];
        tedad_dozdide++;

        if(path==-1)
            break;


    }
    cout<<sum[tedad]<<"\n";
    cout<<tedad_dozdide<<"\n";
    while(!dozdide.empty())
    {
        cout<<dozdide.top()<<" ";
        dozdide.pop();
    }



    return 0;
}
