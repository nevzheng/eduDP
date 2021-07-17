/**
 * A Frog 1
 * This problem is a good example of push DP
 * We use use our current value to compute future values.
 * A naive, simple approach is to allocate and fill an entire array
 * However, we can rewrite the occurrence from a pair of
 * dp[i+1] = min(dp[i+1], dp[i] + abs(cost[i] -costs[i+1]);
 * dp[i+2] = min(dp[i+2], dp[i] + abs(cost[i] -costs[i+2]);
 * to
 * dp[i] = min(dp[i-1] + abs(cost[i] - cost[i-1], dp[i-2] + abs(cost[i] - cost[i-2]));
 * Rewriting the recurrence highlights that we only need to remember the last two values
 * Meaning we only need constant memory
 * However, linear memory is accepted, but you can keep that memory optimization in mind
 * for future problems
 *
 * https://atcoder.jp/contests/dp/tasks/dp_a
 */
#include <bits/stdc++.h>
using namespace std;

/**
 * Print a vector
 * @tparam T
 * @param t
 */
template<typename T>
void printVector(const T &t) {
    std::copy(t.cbegin(), t.cend(), std::ostream_iterator<typename T::value_type>(std::cout, ", "));
}

/**
 * Print a 2d vector
 * @tparam T
 * @param t
 */
template<typename T>
void printVectorInVector(const T &t) {
    std::for_each(t.cbegin(), t.cend(), printVector<typename T::value_type>);
}

// Naive O(N)time, O(N) space
int frog1(int n, const vector<int> &costs) {
    vector dp(n, std::numeric_limits<int>::max());
    dp[0] = 0;// No Cost incurred on first stone
    dp[1] = abs(costs[0] - costs[1]);
//    for (auto i = 0; i < n; i++) {
//        if (i + 1 < n) dp[i + 1] = min(dp[i + 1], dp[i] + abs(costs[i] - costs[i + 1]));
//        if (i + 2 < n) dp[i + 2] = min(dp[i + 2], dp[i] + abs(costs[i] - costs[i + 2]));
//    }
    // Or as pull dp
    for(auto i=2; i<n; i++){
        dp[i] = min(dp[i-1] + abs(costs[i] - costs[i-1]), dp[i-2] + abs(costs[i] - costs[i-2]));
    }

    return dp.back();
}

int main() {
    int N;
    cin >> N;
    vector<int> costs(N, 0);
    for (auto &x : costs) cin >> x;
    cout << frog1(N, costs) << '\n';
    return 0;
}