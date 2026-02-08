#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

//A 4‑directional neighbor‑minimum scan that detects local depressions and accumulates the total fill needed.

int main(){

    int di[] = {-1, 1, 0, 0};
    int dj[] = {0, 0, -1, 1};

    int m, n, v[100][100];
    cin >> m >> n;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> v[i][j];

    int l, c, vm, cnt = 0;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            vm = 15;

            for(int k = 0; k < 4; k++){
                l = i + di[k];
                c = j + dj[k];
                if(l >= 0 && c >= 0 && l < m && c < n)
                    if(v[l][c] < vm)
                        vm = v[l][c];
            }

            if(v[i][j] < vm && vm != 15){
                cnt += vm - v[i][j];
                v[i][j] = vm;
            }
        }
    }

    cout << cnt;

    return 0;
}