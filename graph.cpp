#include<bits/stdc++.h>

using namespace std;
#define int long long int
#define ld long double
#define MOD 1000000007
#define endl "\n"
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(var) (var).begin(), (var).end()
#define MAXX 9000000000000000000
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int> >
#define vpi vector<pair<int,int> >
#define vvpi vector<vector<pair<int,int> > >
vi ordering(5);

void addEdge(vector<int> adj[], int v, int u) {

    adj[v].push_back(u);
//    adj[u].pb(v);// comment when using directed graph
}

void addEdge(vector<pair<int, int>> adj[], int v, int u, int weight) {
    //method for weighted edges;
    adj[v].pb(mp(u, weight));
//    adj[u].pb(mp(v, weight));
}

void printGraph(vector<int> adj[], int v) {
    for (int i = 0; i < v; ++i) {
        cout << "adjacency list:" << i << "head\n";
        for (auto x: adj[i]) {
            cout << x << " ";
            /* code */
        }
        cout << endl;
        /* code */
    }
}

void SolveBFS(vi adj[], int n, int start) {
    queue<int> q;
    q.push(start);
    vector<bool> visited(n);
    for (int i = 0; i < n; i++)
        visited[i] = false;
    visited[start] = true;
    cout << start << "->";
    vi prev(n);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto i : adj[node]) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = true;
                cout << i << "->";
                prev[i] = node;

            }
        }
    }

}

void BFS_reconstructPath(vi adj[], int n, int start, int end) {
    queue<int> q;
    q.push(start);
    vector<bool> visited(n);
    for (int i = 0; i < n; i++)
        visited[i] = false;
    visited[start] = true;
    cout << "\n" << start << "->";
    vi prev(n);
    for (int i = 0; i < n; ++i) {
        prev[i] = -1;
    }
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto i : adj[node]) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = true;
                cout << i << "->";
                prev[i] = node;

            }
        }
    }

    //recondtructPath
    vi path;

    cout << endl;
    int i = end;
    while (-1 != i) {
        path.pb(i);
        i = prev[i];
    }
    reverse(all(path));
    cout << "\npath:";
    if (path[0] == start)
        for (auto x:path)
            cout << x << "->";
    else
        cout << "No path\n";

}

void DFS(int at, vi adj[], int n, bool visited[]) {
    if (visited[at])
        return;
    visited[at] = true;
    cout << at << "->";

    for (auto i : adj[at]) {
        DFS(i, adj, n, visited);
    }


}

int DFSforTopoSort(int i, int at, bool V[], vi adj[], int n) {
    V[at] = true;
    for (auto x: adj[at]) {
        if (!V[x])
            i = DFSforTopoSort(i, x, V, adj, n);
    }
    ordering[i] = at;
    return i - 1;
}

void topologicalSort(vi adj[], int n) {

    bool V[n];
    for (int i = 0; i < n; ++i) {
        V[i] = false;
        ordering[i] = 0;
    }

    int i = n - 1;
    for (int at = 0; at < n; ++at) {
        if (!V[at])
            i = DFSforTopoSort(i, at, V, adj, n);
    }
    for (auto x:ordering)
        cout << x << " ";

}

void ShortestPathOnDAG(vi adj[], int n) {
    //o(v+E);

}

void dijkstraSSSP(vector<pair<int, int>> adj[], int n, int start) {
    //o(E*log(v))
    //lazy approach
    bool visited[n];
    int newDist;
    memset(visited, false, sizeof(visited));
    vi dist(n, INT_MAX);

    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push(mp(0, start));
    while (!pq.empty()) {
        pair<int, int> p = pq.top();
        pq.pop();
        visited[p.second] = true;
        for (auto edge: adj[p.second]) {
            if (visited[edge.first])
                continue;
            newDist = dist[p.second] + edge.second;
            if (newDist < dist[edge.first]) {
                dist[edge.first] = newDist;
                pq.push(mp(newDist, edge.first));
            }

        }


    }
    cout << "shortest distance:" << endl;
    for (auto x:dist) {
        cout << x << " ";
    }


}

void bellmanFordSSSP(vector<pair<int, int>> adj[], int n, int start) {
//O(EV)

    vi D(n, INT_MAX);
    D[start] = 0;
    for (int i = 0; i <= n - 1; ++i) {
        for (auto edge:adj[i]) {
            if (D[i] + edge.second < D[edge.first])
                D[edge.first] = D[i] + edge.second;
        }

    }
    for (int i = 0; i <= n - 1; ++i) {
        for (auto edge:adj[i]) {
            if (D[i] + edge.second < D[edge.first])
                D[edge.first] = -INT_MAX;

        }

    }
    for (auto x:D)
        cout << x << " ";
}


void floydWarshallASSP(int adj[], int n) {
    ;
}

void TarjansStronglyConnectedComponents(int adj[], int n) {

}

void TSP_Dp(int adj[], int n) {
    ;
}

bool graphHasEulerianPath(vector<pair<int, int>> adj[], int n, vi in, vi out) {
    int start = 0, end = 0;
    for (int i = 0; i < n; ++i) {
        if (out[i] - in[i] > 1 || in[i] - out[i] > 1)
            return false;
        else if (out[i] - in[i] == 1)
            start++;
        else if (out[i] - in[i] == -1)
            end++;
        return (end == 0 && start == 0) || (end == 1 && start == 1);

    }

}

int findStartNode(vector<pair<int, int>> adj[], int n, vi in, vi out) {
    int start = 0;
    for (int i = 0; i < n; ++i) {
        if (out[i] - in[i] == 1)
            return i;
        if (out[i] > 0)
            start = i;
    }
    return start;

}

void dfsEulerPath(int at, vector<pair<int, int>> adj[], int n, vi in, vi out, vi &path) {
    while (out[at] != 0) {
        pair<int, int> next_edge = adj[at][--out[at]];
        dfsEulerPath(next_edge.first, adj, n, in, out, path);
    }
    path.push_back(at);
//    cout << at << " ";

}

void EulerPath(vector<pair<int, int>> adj[], int n, int m) {
//    O(E)
    vi in(n, 0);
    vi out(n, 0);
    vi path;
//countInOutDegrees();
    for (int i = 0; i < n; i++)
        for (auto edge:adj[i]) {
            out[i]++;
            in[edge.first]++;

        }

    if (!graphHasEulerianPath(adj, n, in, out)) {

        cout << "No euler path" << endl;

    } else
        dfsEulerPath(findStartNode(adj, n, in, out), adj, n, in, out, path);
    reverse(all(path));
    for (auto x:path)
        cout << x << "->";
    if (path.size() == m + 1)
    {
        cout<<"yeet\n";
        for (auto x:path)
            cout << x << "->";
    }

    else
        cout << "\nNO path";
}

priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>
addEdgeMST(vector<pair<int, int>> adj[], int nodeIndex, bool visited[],
           priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq) {
    visited[nodeIndex] = true;
    for (auto edge: adj[nodeIndex]) {
        if (!visited[edge.first])
            pq.push(mp(edge.second, mp(nodeIndex, edge.first)));
    }
    return pq;
}

void primsMST(vector<pair<int, int>> adj[], int n, int start = 0) {
//    structure of pq-> pair{edge weight, pair{start node,end node}}
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    bool visited[n];
    memset(visited, false, sizeof(visited));
    int m = n - 1; //total number of edges in MST;
    int edgeCount = 0, mstCost = 0;
    vector<pair<int, pair<int, int>>> mstEdges(m);
    visited[start] = true;
    for (auto edge: adj[start]) {
        if (!visited[edge.first])
            pq.push(mp(edge.second, mp(start, edge.first)));
    }

    while (!pq.empty() && edgeCount != m) {
        pair<int, pair<int, int>> edge = pq.top();
        pq.pop();

        int nodeIndex = edge.second.second;
        if (visited[nodeIndex])
            continue;
        mstEdges[edgeCount++] = edge;
        mstCost += edge.first;
        visited[nodeIndex] = true;
        for (auto edge: adj[nodeIndex]) {
            if (!visited[edge.first])
                pq.push(mp(edge.second, mp(nodeIndex, edge.first)));
        }

    }
    if (edgeCount != m) {
        cout << "\nNO MINIMUM SPANNING TREE \n:" << mstCost;

    } else {
        cout << "MST cost:" << mstCost << endl;
        for (auto edge:mstEdges) {
            cout << edge.second.first << "->" << edge.second.second << "weight:" << edge.first << endl;

        }
    }

}

void KruskalsMST(int adj[], int n) {
    ;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int V = 5; //no of vertexx;
    vi adj[V];
    vector<pair<int, int>> weightedGraph[7];
//    addEdge(adj, 0, 1);
//    addEdge(adj, 0, 2);
//    addEdge(adj, 1, 4);
//    addEdge(adj, 2, 3);
//
//    printGraph(adj, V);
//    bool visited[V];
//    for (int i = 0; i < V; ++i) {
//        visited[i] = false;
//    }
//    cout << "DFS" << endl;
//    DFS(0, adj, V, visited);
//    cout << "\nBFS" << endl;
//    SolveBFS(adj, V, 0);
//    cout << "\nreconstruct path btw 1 & 3";
//    BFS_reconstructPath(adj, V, 1, 3);
//    cout << "Topological Sort:\n";
//    topologicalSort(adj, V);
    addEdge(weightedGraph, 1, 2, 0);
    addEdge(weightedGraph, 1, 3, 8);

    addEdge(weightedGraph, 2, 2, 2);
    addEdge(weightedGraph, 2, 4, 6);
    addEdge(weightedGraph, 2, 4, 4);

    addEdge(weightedGraph, 3, 5, 5);
    addEdge(weightedGraph, 3, 1, 1);
    addEdge(weightedGraph, 3, 2, 1);

    addEdge(weightedGraph, 4, 6, 2);
    addEdge(weightedGraph, 4, 3, 3);

    addEdge(weightedGraph, 5, 6, 5);
    addEdge(weightedGraph, 6, 3, 1);


    V = 6;
//    cout << "dijkstra's:\n";
//    dijkstraSSSP(weightedGraph, V, 0);
//    cout << "\nBellman Ford\n";
//    bellmanFordSSSP(weightedGraph, V, 0);
//    primsMST(weightedGraph, V, 1);
    cout << "Eulerian Path:\n";
    EulerPath(weightedGraph, 7, 12);
    return 0;
}
