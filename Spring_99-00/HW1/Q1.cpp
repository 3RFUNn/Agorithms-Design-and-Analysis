#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int number, time,portion, sum = 0;
    cin >> number;
    cin>> time;
    priority_queue <int> pq;
    for (int i = 0; i < number; ++i) {
        cin >> portion;
        pq.push(portion);
    }
    for (int j = 0; j <time ; ++j) {
        sum+=pq.top()/2;
        pq.push(pq.top()/2);
        pq.pop();
    }
    printf("%d",sum);
    return 0;
}

