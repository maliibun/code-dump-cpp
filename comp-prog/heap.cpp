#include <iostream>

#define MAXN 150001
using namespace std;

int v[MAXN];
//max-heap, binary tree

int main()
{
    freopen("heap.in","r",stdin);
    freopen("heap.out","w",stdout);

    int n;
    cin >> n;

    int c, x;

    int cnt = 0;
    for(int i = 1; i <= n; i++){
        cin >> c;
        if(c == 1){ //add to heap
            cin >> x;
            v[++cnt] = x;

            int k = cnt;
            while(k > 1) //percolates
                if(v[k] > v[k / 2]){
                    swap(v[k], v[k/2]);
                    k /= 2;
                } else break;
            continue;
        } //remove maximum
            cout << v[1] << '\n';

            v[1] = v[cnt];
            cnt--;

            int k = 1, f;
            while(k * 2 <= cnt){
                f = k * 2;
                if(f + 1 <= cnt && v[f + 1] > v[f])
                    f++;

                if(v[k] >= v[f])
                    break;
                else {
                    swap(v[k], v[f]);
                    k = f;
                }
            }
        }

    return 0;
}