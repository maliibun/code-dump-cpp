//same time complexity

#include <bits/stdc++.h>

using namespace std;


//write a program that given an n x n grid of 0s and 1s, finds a path for a pawn from the top row to the bottom row 
//that collects the maximum number of 1s, moving only down and on diagonals if there is a 1 on it
//outputs max value and then path

int m[51][51], n;
vector<vector<int>> cp(51, vector<int>(51, 0));

int dfs(int i, int j){
    //this one goes from bottom to top
    if(i >= n || j >= n || i < 0 || j < 0)
        return 0;

    if(m[i][j] == 0)
        cp[i][j] = dfs(i-1, j);
    else
        cp[i][j] = max(dfs(i-1,j-1), dfs(i-1, j+1)) + 1;

    return cp[i][j];
}

void drum(int i, int j){

    if(i == 0){
        cout << i + 1 << ' ' << j + 1<< endl;
        return;
    }

    if(m[i][j] == 0)
        drum(i - 1, j);
    else if (cp[i-1][j+1] + 1 == cp[i][j])
        drum(i - 1, j + 1);
    else
        drum(i - 1, j - 1);

    cout << i + 1<< ' ' << j + 1 << endl;
}

int main()
{
    freopen("pionr.in","r",stdin);
    freopen("pionr.out","w",stdout);

    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> m[i][j];
        }
    }

    for(int i = 0; i < n; i++)
        dfs(n - 1, i);

    int maxval = 0, jm = 0;
    for(int i = 0; i < n; i++)
        if(maxval < cp[n-1][i]){
            jm = i;
            maxval = cp[n-1][i];
        }

    cout << maxval << endl;

    drum(n - 1, jm);

    return 0;
}