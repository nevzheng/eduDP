#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

template<typename T>
void printVector(const T &t) {
    std::copy(t.cbegin(), t.cend(), std::ostream_iterator<typename T::value_type>(std::cout, ", "));
}

template<typename T>
void printVectorInVector(const T &t) {
    std::for_each(t.cbegin(), t.cend(), printVector<typename T::value_type>);
}

long knapsack1(const vector<long> &val, const vector<long> &wgt, int N, int W) {
    // dp[i] Max total value of items with total weight exactlt
    vector<long> dp(W + 1);
    for (auto i = 1; i <= N; i++) {
        // shift down to handle offset form 0 col and row
        auto [v, wt] = std::tie(val[i - 1], wgt[i - 1]);
        for (int w = W; w >= wt; w--) {
            dp[w] = max(dp[w], dp[w - wt] + v);
        }
        //        for (auto w = 1; w <= W; w++) {
        //            if (wt <= w) {
        //                dp[i][w] = max(dp[i - 1][w], v + dp[i - 1][w - wt]);
        //            } else {// Exceed limit, exclude
        //                dp[i][w] = dp[i - 1][w];
        //            }
        //        }
    }
    return *max_element(begin(dp), end(dp));
}

int main() {
    int N, W;
    cin >> N >> W;
    vector<long> val(N, 0);
    vector<long> wt(N, 0);
    for (auto i = 0; i < N; i++) {
        cin >> wt[i] >> val[i];
    }
    cout << knapsack1(val, wt, N, W) << endl;
}