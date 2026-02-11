#include <bits/stdc++.h>

using namespace std;

int v[1001];
int dp[1001][1001];
int mxval = 0;

int main()
{
    freopen("recyclebin.in","r",stdin);
    freopen("recyclebin.out","w",stdout);

    //find the maximum sum of a subsequence where you are allowed to jump backward by powers of two

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    dp[0][0] = v[0];
    mxval = max(mxval, v[0]);

    for(int i = 1; i < n; i++){
        for(int j = 0; j <= i; j++){
            dp[i][j] = v[i] + max(0, dp[i-1][j]);
            mxval = max(mxval, dp[i][j]);

            // if (j & p) - pairs of p summing up to j (if p is a possible pair / sequence)
            for(int p = 1; p <= i; p *= 2){
                if(j & p)
                    dp[i][j] = max(dp[i][j], dp[i-p][j - p]);
            }
        }
    }

    cout << mxval;

    return 0;
}