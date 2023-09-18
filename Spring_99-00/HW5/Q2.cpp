#include <iostream>
using namespace std;

int findMin(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    bool dp[n+1][sum+1];
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }
    for (int i = 1; i <= sum; i++) {
        dp[0][i] = false;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            dp[i][j] = dp[i-1][j];
            if (arr[i-1] <= j) {
                dp[i][j] |= dp[i-1][j-arr[i-1]];
            }
        }
    }
    int diff = INT8_MAX;
    for (int j = sum/2; j >= 0; j--) {
        if (dp[n][j] == true) {
            diff = sum - 2*j;
            break;
        }
    }
    return diff;
}


int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for ( int i  = 0; i < n; i++ ) {
        cin >> arr[i];
    }
    cout <<findMin(arr, n);
    return 0;
}
