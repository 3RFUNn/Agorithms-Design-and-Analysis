#include <bits/stdc++.h>

using namespace std;

static int team = 0;

void max_team(int n, vector<int> a){
    int max = 0, ind_max = 0;
    max = a[n - 1];
    ind_max = n - 1;
    team++;
    int numberOfEachTeam = 1;
    for(int i = 0; i < n-max;){
        if(numberOfEachTeam < a[i]){
            i++;
            numberOfEachTeam++;
        }
        else{
            team++;
            numberOfEachTeam = 1;
            i++;
        }
    }
    cout << team << endl;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr;
    arr.resize(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end());
    max_team(n, arr);
}

