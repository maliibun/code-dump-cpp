#include <bits/stdc++.h>

using namespace std;

vector<int> parents, ranks, ancestor, visited;

vector<vector<int>> adj;

int findP(int p){
    if(p == parents[p])
        return p;
    return parents[p] = findP(parents[p]);
}

void doUnion(int x, int y){

    int xp = findP(x);
    int yp = findP(y);

    if(xp == yp)
        return;

    if(ranks[yp] > ranks[xp])
        swap(xp, yp);
    parents[yp] = xp;
    if(ranks[xp] == ranks[yp])
        ranks[xp]++;

}

void dfs(int v){

    visited[v] = 1;
    ancestor[v] = v;
    for(auto u : adj[v]){
        if(!visited[u]){
            dfs(u);
            doUnion(v, u);
            ancestor[findP(v)] = v;
        }
    }
    //will always return lowest node of the two, need to implement queries
    for(auto other_node : adj[v]){
        if(visited[other_node]){
            cout << "LCA of " << v << " and " << other_node
                 << " is " << ancestor[findP(other_node)] << endl;
        }
    }

}

int main()
{
    //lowest common ancestor - tarjan

    freopen("tarjan.in","r",stdin);
    freopen("tarjan.out","w",stdout);

    int n, m;
    cin >> n >> m;

    parents = ranks = ancestor = visited = vector<int> (n + 1, 0);
    adj = vector<vector<int>> (n + 1);

    for(int i = 0; i <= n; i++)
        parents[i] = i;

    int from, to;
    for(int i = 0; i < m; i++){
        cin >> from >> to;
        adj[from].push_back(to);
    }

    dfs(3);

    return 0;
}