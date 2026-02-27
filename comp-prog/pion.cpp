#include <bits/stdc++.h>

using namespace std;

//write a program that given an n x n grid of 0s and 1s, finds a path for a pawn from the top row to the bottom row 
//that collects the maximum number of 1s, moving only down, down‑left, or down‑right
//outputs max value and then path

int m[51][51] , dp[51][51];

void dfs(int i, int j){

    if (i == 0){
        cout << i + 1 << ' ' << j + 1 << endl;
        return;
    }

    if(m[i][j] == 0){
        dfs(i - 1, j);
    } else if(dp[i-1][j+1] + 1 == dp[i][j])
        dfs(i - 1 ,j + 1);
    else
        dfs(i - 1, j - 1);
    cout << i + 1 << ' ' << j + 1 << endl;
}

int main()
{
    freopen("pion.in","r",stdin);
    freopen("pion.out","w",stdout);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> m[i][j];
        }
    }

    for(int i = 1; i < n; i++){
        for(int j = 0; j < n; j++){
            if(m[i][j] == 0)
                dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j + 1]) + 1;
        }
    }

    int maxval = 0, jm = 0;
    for(int i = 0; i < n; i++)
        if(maxval < dp[n - 1][i]){
            maxval = dp[n - 1][i];
            jm = i;
        }


    cout << maxval << endl;
    dfs(n - 1, jm);

    return 0;
}