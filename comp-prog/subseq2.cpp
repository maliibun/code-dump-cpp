#include <bits/stdc++.h>

using namespace std;

int main()
{
    //Finds the longest subsequence containing at most three distinct values (traditional method)
    freopen("3secv.in","r",stdin);
    freopen("3secv.out","w",stdout);

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        if(n <= 3){
            cout << n;
            continue;
        }

        int a[n + 1], res = 0;
        a[n] = -1;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        int i = 0, j = 0, k = 3;

        while(i <= j){
            bool distinct = true;

            while(j < n - 1 && a[j] == a[j+1])
                j++;

            int p = i;
            while(p <= j && j < n){
                if(a[p] == a[j + 1])
                    j++;
                else if(k > 1){
                    j++;
                    k--;
                }
                else{
                    p++;
                    for(int pk = i + 1; pk <= j; pk++){
                        if(a[i] == a[pk])
                            distinct = false;
                    }

                    if(i != p && distinct){
                        k++;
                        i++;
                    }
                }
            }

            res = max(res, j - i + 1);
            i++;
        }

        cout << res << endl;
    }

    return 0;
}