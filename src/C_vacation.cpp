//
// Created by Nevin Zheng on 7/15/21.
//
#include <bits/stdc++.h>
using namespace std;


// O(N) time and O(N) memory
// Can optimize to O(1) memory since you only need to remember the values for the last day
// A more general problem is if there are k possible activites. then you would need to write a for loop
// There's probably log(N) solution that involves matrix exponentiation, but i'm not going to apply that
int vacation(vector<vector<int>> S, int N) {
    // dp[i][j] represents the max fun on day i, ending in activity j
    // N Days, and 3 activities on each day
    vector<vector<int>> dp(N, vector(3, std::numeric_limits<int>::min()));
    dp[0] = S[0];
    for (auto i = 1; i < N; i++) {
        // Could write in a for loop, but its easier unrolled
        // Add the benefit of doing a,b, or c on to the ith day from the best from the previous day
        dp[i][0] = S[i][0] + max(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = S[i][1] + max(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = S[i][2] + max(dp[i - 1][0], dp[i - 1][1]);
    }
    // Global Answer is the max over the last day
    return *max_element(begin(dp.back()), end(dp.back()));
}
int main() {
    int N;
    cin >> N;
    vector<vector<int>> S(N, vector(3, 0));
    for (auto &x : S) {
        cin >> x[0] >> x[1] >> x[2];
    }
    cout << vacation(S, N) << endl;
}