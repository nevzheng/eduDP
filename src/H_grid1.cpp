//
// Created by Nevin Zheng on 7/17/21.
//
#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<uint64_t>> IntGrid;
typedef vector<vector<bool>> BoolGrid;

const uint64_t MOD = 1'000'000'007;

BoolGrid readGrid(int H, int W);
uint64_t grid1(const BoolGrid &G, int H, int W);

int main() {
    int H, W;
    cin >> H >> W;
    auto grid = readGrid(H, W);
    cout << grid1(grid, H, W) << endl;
}

BoolGrid readGrid(int H, int W) {
    BoolGrid grid(H, vector(W, false));
    char x;
    for (auto i = 0; i < H; i++) {
        for (auto j = 0; j < W; j++) {
            cin >> x;
            grid[i][j] = x == '.';// True if Reachable '.', False if Wall '#';
        }
    }
    return grid;
}

// We Can traverse the grid in O(N^2) time and O(N^2) space
uint64_t grid1(const BoolGrid &G, int H, int W) {
    IntGrid dp(H, vector<uint64_t>(W, 0));
    // The 0th row and column are zeros
    for (auto i = 0; i < H; i++) {
        for (auto j = 0; j < W; j++) {
            uint64_t fromLeft, fromAbove;
            if (i == 0 and j == 0) {
                dp[i][j] = 1;// 1 Way to start and end at (0,0)
            } else if (i == 0) {
                fromLeft = G[i][j - 1] ? dp[i][j - 1] : 0;// Can add component from left
                dp[i][j] = fromLeft % MOD;
            } else if (j == 0) {                           // First Column Nothing to Left
                fromAbove = G[i - 1][j] ? dp[i - 1][j] : 0;// Can add component from above
                dp[i][j] = fromAbove % MOD;
            } else {
                fromLeft = G[i][j - 1] ? dp[i][j - 1] : 0; // Can add component from left
                fromAbove = G[i - 1][j] ? dp[i - 1][j] : 0;// Can add component from above
                dp[i][j] = (fromLeft + fromAbove) % MOD;   // Add the components
            }
        }
    }
    return dp.back().back();// Our Answer is the last element
}
