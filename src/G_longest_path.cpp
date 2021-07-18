//
// Created by Nevin Zheng on 7/17/21.
//
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

typedef vector<vector<int>> IntMatrix;
typedef vector<pair<int, int>> EdgeVec;
typedef vector<int> Ordering;

EdgeVec readEdges(int N) {
    EdgeVec edges(N);
    for (auto &e : edges) { cin >> e.first >> e.second; }
    return edges;
}

IntMatrix makeAdjacencyList(const EdgeVec &edges, int N) {
    IntMatrix adj(N, vector<int>());
    for (auto &e : edges) {
        auto [u, v] = e;
        adj[u - 1].push_back(v - 1);
    }
    return adj;
}

enum class Color {
    White,
    Gray,
    Black,
};

bool top_sort(const IntMatrix &G, const int V, int root, vector<int> &order, vector<Color> &colors) {
    if (colors[root] == Color::Black) return true;
    if (colors[root] == Color::Gray) return false;// Not a DAG, there was a back edge
    colors[root] = Color::Gray;                   // Mark Node as Gray
    for (auto &n : G[root]) {
        if (!top_sort(G, V, n, order, colors)) return false;
    }
    // Mark Node as Complete and Push onto ordering
    colors[root] = Color::Black;
    order.push_back(root);
    return true;
}

/**
 * Return a topological ordering of G in O(V+E) time
 * Uses a DFS based algorithm
 * @param G
 * @param N
 * @return
 */
Ordering topSort(const IntMatrix &G, int N) {
    Ordering order;
    vector<Color> colors(N, Color::White);
    // Explore All Components
    for (int u = 0; u < N; u++) {
        if (colors[u] == Color::White) {
            if (auto valid = top_sort(G, N, u, order, colors); !valid) return {};
        }
    }
    reverse(begin(order), end(order));// Reverse the ordering returned
    return order;
}

int longest_path(const IntMatrix &G, const Ordering &ordering, int V, int src) {
    vector<int> dist(V, std::numeric_limits<int>::min());
    dist[src] = 0;
    for (auto u : ordering) {
        if (dist[u] < 0) continue;
        for (auto v : G[u]) {
            auto newDist = dist[u] + 1;
            if (dist[v] < 0) {
                dist[v] = newDist;
            } else {
                dist[v] = max(dist[v], newDist);
            }
        }
    }
    return *max_element(begin(dist), end(dist));
}


int longestPath(const IntMatrix &G, int V, int augIndex) {
    auto ordering = topSort(G, V);
    if (ordering.empty()) return -1;                           // Graph was had a directed cycle
    auto aug = *find(begin(ordering), end(ordering), augIndex);// Look for the where our augmented node is in the ordering
    return longest_path(G, ordering, V, aug);
}

int main() {
    int N, M;
    cin >> N >> M;
    // We Need to augment our graph with an additional node and edge
    // This will greatly improve our time complexity as we don't have to guess which node the longest path starts at
    // we will just subtract 1 from our result
    N++;// Increment N for our augmented edge. The LAST index in the adj list will be the node we use to augment the graph
    EdgeVec edges = readEdges(M);
    for (auto i = 1; i < N; i++) {// Nodes numbered from 1 to N
        edges.emplace_back(N, i);
    }

    IntMatrix G = makeAdjacencyList(edges, N);
    cout << longestPath(G, N, N - 1) - 1;
}
