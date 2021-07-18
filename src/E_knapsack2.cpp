//
// Created by Nevin Zheng on 7/15/21.
//

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int64_t knapsack2(const vector<long> &val, const vector<long> &wgt, long N, long W) {
    auto maxVal = accumulate(begin(val), end(val), 0L);
    vector<long> dp(maxVal + 1, 1e18L + 5);// dp[i] the minimum total weight of items with total value exactly i
    dp[0] = 0;
    for (auto item = 0; item < N; item++) {
        for (auto value_already = maxVal - val[item]; value_already >= 0; value_already--) {
            dp[value_already + val[item]] = min(dp[value_already + val[item]], dp[value_already] + wgt[item]);
        }
    }
    auto ans = 0L;
    for (auto i = 0l; i <= maxVal; i++) {
        if (dp[i] <= W) ans = max(ans, i);
    }
    return ans;
}

// TODO: Complete knapsack2
int main() {
    int N, W;
    cin >> N >> W;
    vector<long> val(N, 0);
    vector<long> wt(N, 0);
    for (auto i = 0; i < N; i++) {
        cin >> wt[i] >> val[i];
    }
    cout << knapsack2(val, wt, N, W) << endl;
}