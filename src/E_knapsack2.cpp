//
// Created by Nevin Zheng on 7/15/21.
//

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

long knapsack2(const vector<long>& val, const vector<long>& wgt, long N, long W) { return 0; }

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