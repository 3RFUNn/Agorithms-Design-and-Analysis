#include<iostream>
#include <bits/stdc++.h>
#include<vector>
using namespace std;
class NumMatrix
{
public:

    long sumRegion(long row1, long col1, long row2, long col2)
    {
        long up = (row1 - 1 >= 0)?farm[row1 - 1][col2]:0;
        long left = (col1 - 1 >= 0)?farm[row2][col1 - 1]:0;
        long leftup = (row1 - 1 >= 0 && col1 - 1 >= 0)?farm[row1 - 1][col1 - 1]:0;
        return farm[row2][col2] - up - left + leftup;
    }

    vector<vector<long>> farm;
    long m,n;
    NumMatrix(vector<vector<long>> matrix)
    {
        if(!matrix.empty())
        {
            m = matrix.size();
            farm.resize(m+1,vector<long>(m+1));
            for(long i = 0; i < m; ++i)
            {
                for(long j = 0; j < m; ++j)
                {
                    long up = (i - 1 < 0)?0:farm[i - 1][j];
                    long left = (j - 1 < 0)?0:farm[i][j - 1];
                    long leftup = (i - 1 >= 0 && j - 1 >= 0)?farm[i - 1][j - 1]:0;
                    farm[i][j] = up + left - leftup + matrix[i][j];
                }
            }
        }
    }


};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<vector<long>> zamin;
    long tool,soal;
    cin>>tool>>soal;
    zamin.resize(tool+1,vector<long>(tool+1));
    for(long i=0; i<tool; i++)
    {
        for(long j=0; j<tool; j++)
        {
            long sood;
            cin>>sood;
            zamin[i][j]=sood;
        }
    }
    NumMatrix keshavarz(zamin);
    for(long l=0; l<soal; l++)
    {
        long a,b,c,d;
        cin>>a>>b>>c>>d;
        cout<<keshavarz.sumRegion(a-1,b-1,c-1,d-1)<<"\n";
    }



    return 0;
}
