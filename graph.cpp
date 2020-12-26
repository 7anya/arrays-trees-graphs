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

void bellmanFordSSSP(vector<pair<int, int>> adj[], int n,int start) {
//O(EV)

vi D(n,INT_MAX);
D[start]=0;
    for (int i = 0; i <= n-1; ++i) {
        for(auto edge:adj[i])
        {
            if(D[i]+edge.second<D[edge.first])
                D[edge.first]=D[i]+edge.second;
        }

    }
    for (int i = 0; i <= n-1; ++i) {
        for(auto edge:adj[i])
        {
            if(D[i]+edge.second<D[edge.first])
                D[edge.first]=-INT_MAX;

        }

    }
    for(auto x:D)
        cout<<x<<" ";
}


void floydWarshallASSP(int adj[], int n) {
    ;
}

void TarjansStronglyConnectedComponents(int adj[], int n) {

}

void TSP_Dp(int adj[], int n) {
    ;
}

void EulerPath(int adj[], int n) {
    ;
}

void primsMST(int adj[], int n) {
    ;
}

void KruskalsMST(int adj[], int n) {
    ;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int V = 5; //no of vertexx;
    vi adj[V];
    vector<pair<int, int>> weightedGraph[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);

    printGraph(adj, V);
    bool visited[V];
    for (int i = 0; i < V; ++i) {
        visited[i] = false;
    }
    cout << "DFS" << endl;
    DFS(0, adj, V, visited);
    cout << "\nBFS" << endl;
    SolveBFS(adj, V, 0);
    cout << "\nreconstruct path btw 1 & 3";
    BFS_reconstructPath(adj, V, 1, 3);
    cout << "Topological Sort:\n";
    topologicalSort(adj, V);
    int a=0,b=1,c=2,d=3,e=4;
    addEdge(weightedGraph, a, b, -1);
    addEdge(weightedGraph, a, c, 4);
    addEdge(weightedGraph, b, c, 3);
    addEdge(weightedGraph, b, d, 2);
    addEdge(weightedGraph, b, e, 2);
    addEdge(weightedGraph, d, c, 5);
    addEdge(weightedGraph, d, b, 1);
    addEdge(weightedGraph, e, d, -3);

    cout << "dijkstra's:\n";
    dijkstraSSSP(weightedGraph, V, 0);
    cout<<"\nBellman Ford\n";
    bellmanFordSSSP(weightedGraph,V,0);

    return 0;
}
