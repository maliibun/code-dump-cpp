#include <bits/stdc++.h>

using namespace std;

//Tarjan’s algorithm for biconnected components
//reads an undirected graph and identifies all its biconnected components
//a biconnected component contains no articulation points, at removing any vertices of the component it does not disconnect
//artculation point: a vertex whose removal disconnects the graph

stack<pair<int,int>> st;
vector<vector<int>> parts, adj;
vector<int> v, nma, nivel;

int totalparts = 0;

void dfs(int k, int t){

    v[k] = 1;
    nivel[k] = nivel[t] + 1;
    nma[k] = nivel[k];

    for(auto nod : adj[k]){

        if(nod == t)
            continue;

            if(v[nod] == 1){
                //no dfs
                //if(k != t)
                    nma[k] = min(nma[k], nivel[nod]);
            } else {
                st.push({k, nod});

                dfs(nod, k);
                nma[k] = min(nma[k], nma[nod]);

                if(nivel[k] <= nma[nod]){

                    vector<int> part;
                    int s, p;
                    do{
                        p = st.top().first;
                        s = st.top().second;
                        part.push_back(p);
                        part.push_back(s);
                        st.pop();
                    } while (!st.empty() && (p != k || s != nod));

                    totalparts++;
                    parts.push_back(part);
                }
            }
        }
}

int main()
{
    freopen("centrala.in","r",stdin);
    freopen("centrala.out","w",stdout);

    int n, m;

    cin >> n >> m;

    //st.push({-1, 1});
    v = nma = nivel = vector<int> (n + 1);
    adj = vector<vector<int>> (n +1 );

    int a, b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);

    cout << totalparts << endl;

    for(int i = 0; i < parts.size(); i++){

        sort(parts[i].begin(), parts[i].end());
        for(int j = 0; j < parts[i].size(); j++){
            if(j > 0 && (parts[i][j] == parts[i][j-1]))
                continue;
            cout << parts[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}