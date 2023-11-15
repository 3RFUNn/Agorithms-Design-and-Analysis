#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<long int> rocks;
    long int adad,meghdar,a,b;
    cin>>adad;
    for(long int i = 0 ; i<adad ; i++)
    {
        cin>>meghdar;
        rocks.push_back(meghdar);
    }
    make_heap(rocks.begin(),rocks.end());


    while(rocks.size()>1)
    {
        a = rocks.front();
        pop_heap(rocks.begin(), rocks.end());
        rocks.pop_back();
        b = rocks.front();
        pop_heap(rocks.begin(), rocks.end());
        rocks.pop_back();
        b = abs(a-b);
        rocks.push_back(b);
        push_heap(rocks.begin(), rocks.end());

    }
    cout<<rocks.front();







    return 0;
}
