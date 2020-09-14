#pragma once
/*
1192. Critical Connections in a Network
There are n servers numbered from 0 to n-1 connected by undirected server-to-server connections forming a network where connections[i] = [a, b] represents a connection between servers a and b. Any server can reach any other server directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some server unable to reach some other server.

Return all critical connections in the network in any order.



Example 1:



Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.


Constraints:

1 <= n <= 10^5
n-1 <= connections.length <= 10^5
connections[i][0] != connections[i][1]
There are no repeated connections.
*/
#include<vector>
#include<algorithm>

using namespace std;

void dfs(int cur, int pre, vector<vector<int>>& g, vector<vector<int>>& ret, vector<int>& dfn, vector<int>& low, int& timestamp) {
    // if the node is already visited then return
    if (dfn[cur] > 0)
        return;
    // increment the timestamp
    timestamp += 1;
    dfn[cur] = low[cur] = timestamp;


    for (int next : g[cur]) {
        // don't go back to its parent
        if (next == pre) {
            continue;
        }
        // dfs on neighbors
        dfs(next, cur, g, ret, dfn, low, timestamp);
        low[cur] = min(low[cur], low[next]);
        if (low[next] > dfn[cur]) {
            ret.push_back({ cur, next });
        }
    }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    vector<vector<int>> g, ret;
    vector<int> dfn, low;
    int timestamp = 0;
    dfn = vector<int>(n, -1);
    low = vector<int>(n, -1);
    g.resize(n);
    for (auto& c : connections) {
        int u = c[0], v = c[1];
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, -1, g, ret, dfn, low, timestamp);
    return ret;
}