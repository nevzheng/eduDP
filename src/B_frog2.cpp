//
// Created by Nevin Zheng on 7/14/21.
//
#include <bits/stdc++.h>
using namespace std;

template<typename T>
void printVector(const T &t) {
    std::copy(t.cbegin(), t.cend(), std::ostream_iterator<typename T::value_type>(std::cout, ", "));
}

template<typename T>
void printVectorInVector(const T &t) {
    std::for_each(t.cbegin(), t.cend(), printVector<typename T::value_type>);
}

// Complexity O(KN) Time, O(N) space
int frog2(const vector<int> &H, int N, int K) {
    vector<int> dp(N, std::numeric_limits<int>::max());
    dp[0] = 0;
    for (auto i = 0; i < N; i++) {
        for (auto j = 1; j <= K; j++) {
            if (i + j >= N) break;
            dp[i + j] = min(dp[i + j], dp[i] + abs(H[i] - H[i+j]));
        }
    }
//    printVector(dp);
//    cout << '\n';
    return dp.back();
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> H(N);
    for (auto &x : H) cin >> x;
    cout << frog2(H, N, K) << endl;
}