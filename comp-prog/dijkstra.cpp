#include <bits/stdc++.h>

using namespace std;

void dijkstra(int s, vector<vector<pair<int,int>>> &adj, vector<int> &dists){

    int n = adj.size();
    dists = vector<int> (n, INT_MAX);
    dists[s] = 0;

    priority_queue< pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, s});

    while(!pq.empty()){
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(dist != dists[node])
            continue;

        for(auto edge : adj[node]){
            int to = edge.first;
            int weight = edge.second;

            if(dists[node] + weight < dists[to]){
                dists[to] = dists[node] + weight;
                pq.push({dists[to], to});
            }
        }
    }
}

int main()
{
    freopen("ateleport.in","r",stdin);
    freopen("ateleport.out","w",stdout);

    int n, m, p , l, k;
    cin >> n >> m >> p >> l >> k;

    //node -> neighbour, weight (edge)
    vector<vector<pair<int,int>>> adj (n + 1);

    int x, y, t;
    for(int i = 0; i < m; i++){
        cin >> x >> y >> t;
        adj[x].push_back({y, t});
        adj[y].push_back({x, t});
    }

    //computes an array of distances from node 1 to all other nodes on the shortest routes
    vector<int> dists;
    if(k == 0){
        dijkstra(1, adj, dists);
        cout << dists[n];
    }

    return 0;
}