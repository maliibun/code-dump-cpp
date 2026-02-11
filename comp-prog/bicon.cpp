#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj, bicon;
vector<int> v, nma, level, art;
stack<int> st;
int bicount = 0, artcnt = 0, rootkid = 0;
vector<pair<int,int>> critic;


void dfs(int nod, int t){

    v[nod] = 1;
    st.push(nod);
 level[nod] = level[t] + 1;
    nma[nod] = level[nod];

    for(auto k : adj[nod]){

        if(k == t)
            continue;

        if(v[k]){
            //no dfs
            nma[nod] = min(nma[nod], level[k]);
        } else {
            if(nod == 1)
                rootkid++;

            dfs(k, nod);

            nma[nod] = min(nma[nod], nma[k]);

            if (level[nod] <= nma[k]){
                //articulation point
                if(nod != 1 && !art[nod]){
                    artcnt++;
                    art[nod] = true;
                }

                int ld1 = level[nod];
                int ld2 = nma[k];

                //critic edge
                if (level[nod] < nma[k])
                    critic.push_back({nod, k});

                //biconex part
                vector<int> part;
                while(st.top() != k){
                    part.push_back(st.top());
                    st.pop();
                }

                st.pop(); //remove k as well
                part.push_back(k);
                part.push_back(nod);

                bicount++;
                bicon.push_back(part);

            }
        }
    }

    if(rootkid > 1 && !art[1]){
        art[1] = true;
        artcnt++;
    }
}

int main()
{
    freopen("bicon.in","r",stdin);
    freopen("bicon.out","w",stdout);

    int p, n, m;
    cin >> p >> n >> m;

    adj = vector<vector<int>> (n + 1);
    nma = art = v = level = vector<int> (n + 1, 0);

    int a,b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1,0);

    switch(p){
    case 1:
        cout << bicount << endl;
        for(int i = 0; i < bicon.size(); i++){
            cout << bicon[i].size() << ' ';
            for(int j = 0; j < bicon[i].size(); j++){
                cout << bicon[i][j] <<' ';
            }
            cout << endl;
        }
        break;
    case 2:
        cout << artcnt << endl;
        for(int i = 1; i <= n; i++){
            if(art[i])
                cout << i << ' ';
        }
        break;
    case 3:
        cout << critic.size() << endl;
        for(int i = 0; i < critic.size(); i++){
            cout << critic[i].first << ' ' << critic[i].second << endl;
        }
        break;
    }

    return 0;
}