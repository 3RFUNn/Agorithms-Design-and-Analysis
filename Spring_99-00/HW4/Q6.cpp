#include<bits/stdc++.h>
using namespace std;
int main()
{
    bool tashkhis=true;
    double vorudi,kam,ziyad;
    cin>>vorudi>>kam>>ziyad;
    if(kam>ziyad)
    {
        swap(kam,ziyad);
    }
    vector<double> shabake;
    vector<double> radius;
    shabake.resize(vorudi);
    radius.resize(vorudi);
    for(long i=0; i<vorudi; i++)
    {
        double mokhtasat;
        cin>>mokhtasat;
        shabake[i]=mokhtasat;
        radius[i]=0;
    }
    sort(shabake.begin(),shabake.end());
    if(shabake[1]-shabake[0]>ziyad)
    {
        cout<<"-1";
        return 0;
    }
    else if(shabake[1]-shabake[0]>kam)
    {
        radius[0]=ziyad;
    }
    else
    {
        radius[0]=kam;
    }

    for(long j=0 ; j<vorudi-1 ; j++)
    {
        if(shabake[j+1]-shabake[j]>ziyad)
        {
            cout<<"-1";
            return 0;
        }
        if(shabake[j+1]-shabake[j]>kam)
        {
        radius[j]=ziyad;

        radius[j+1]=ziyad;
        }

        else
        {
            radius[j+1]=kam;
        }
    }
    long hazine=0;
    for(long m=0; m<vorudi; m++)
    {
        hazine+=radius[m];
    }
    cout<<hazine;



    return 0;
}
