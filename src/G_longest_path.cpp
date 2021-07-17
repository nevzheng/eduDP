//
// Created by Nevin Zheng on 7/17/21.
//
int main() {
    cin >> N >> M;
    vector<pair<int,int>> edges = readEdges(M);
    vector<vector<int>> G = makeAdjacencyMatrix(edges);
    cout << longest_path(G, N, M);
}