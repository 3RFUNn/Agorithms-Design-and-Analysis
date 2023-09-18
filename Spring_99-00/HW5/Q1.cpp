#include<bits/stdc++.h>
using namespace std;
int worldwar(string word1, string word2)
{
    int dp[word2.size()+1][word1.size()+1];

    for (int i=0; i <=word2.size(); i++)
    {
        for (int j=0; j <= word1.size(); j++)
        {
            if (i == 0)
            {
                dp[i][j] = j;
            }
            else if (j == 0)
            {
                dp[i][j] = i;
            }
            else
            {

                if (word1[j-1] == word2[i-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = min(
                                   min(1+dp[i-1][j-1],
                                       1+dp[i-1][j]),
                                   1+dp[i][j-1]
                               );
                }
            }
        }
    }

    return dp[word2.size()][word1.size()];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string a,b;

    cin>>a>>b;

    cout<<worldwar(a,b);

    return 0;
}
