#include <bits/stdc++.h>

using namespace std;

int main()
{
    //Finds the longest subsequence containing at most three distinct values(unordered map)
    freopen("3secv.in","r",stdin);
    freopen("3secv.out","w",stdout);

    int t;
    cin >> t;

    while(t--){

        int n=0, res = 0;
        cin >> n;

        if(n <= 3){
            cout << n << endl;
            continue;
        }

        int a[n+1];
        a[n] = -1;

        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        int k = 2;
        unordered_map<int, int> mp;
        int i = 0, j = 0;
        mp[a[i]]++;
        while(i <= j && j < n){

            while(a[j] == a[j+1]){
                j++;
                mp[a[j]]++;
            }

            while(k > 0){
                j++;
                mp[a[j]]++;
                k--;
            }

            while(mp.find(a[j+1]) != mp.end() && mp[a[j+1]] > 0){
                j++;
                mp[a[j]]++;
            }

            res = max(res, j - i + 1);

            if(mp.find(a[i]) != mp.end()){
                if(mp[a[i]] == 1){
                    mp[a[i]]--;
                    k++;
                    i++;
                } else {
                    mp[a[i]]--;
                    i++;
                }
            }
        }

        cout << res << endl;
    }

    return 0;
}