#include <iostream>

using namespace std;

int const MAX = 1e5;

int v[MAX], sums[MAX];

int main()
{
    freopen("complet.in","r",stdin);
    freopen("complet.out","w",stdout);

    int n, m;
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> v[i];
        sums[i/2] += v[i];
    }

    cin >> m;
    int x, c;

    for(int i = 1; i <= m; i++){
        cin >> c >> x;
        if(c == 1)
            cout << v[x / 2] << endl; //parent of node x
        else
            cout << sums[x] << endl; //sum of nodes whose parent is x
    }

    return 0;
}