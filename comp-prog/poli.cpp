#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> s;
int n;

bool alt(vector<char> &s1, vector<char> &s2){
    for(int i = 0; i < n; i++){
        if(!(s1[i] ^ s2[i]))
            return false;
    }
    return true;
}

bool alt1(int col1, int col2){
    for(int i = 0; i < n; i++){
        if(!(s[i][col1] ^ s[i][col2]))
            return false;
    }
    return true;
}

bool comp(int col1, int col2){ //for collumns
    for(int i = 0; i < n; i++){
        if(s[i][col1] != s[i][col2])
            return false;
    }
    return true;
}

int main()
{
    //freopen("poli.in","r",stdin);
    //freopen("poli.out","w",stdout);


    //Checks whether the matrix’s rows and columns form valid alternating binary
    //patterns and computes the minimal swaps needed when required
    int p, t;

    cin >> p >> t;

    while(t--){
        cin >> n;
        s = vector<vector<char>> (n, vector<char>(n));
        vector<int> cl(n, 0);

        for(auto &el : s)
                for(auto &line : el)
                    cin >> line;

        if(p == 1){
            bool ok = true;

            int ln = 0;
            for(int i = 0; i < n; i++){
                   ln = 0;
                for(int j = 0; j < n; j++){
                    if(s[i][j] - '0')
                        ln++;
                    if(s[j][i] - '0')
                        cl[j]++;
                }
                if(ln != n / 2){
                    ok = false;
                    break;
                }
            }
            for(int i = 0; i < n && ok; i++)
                if(cl[i] != n / 2)
                    ok = false;

            if(!ok)
                cout << 0 << endl;
            else {
                //check if n/2 lines are the same as first and n/2 are different
                ok = true;

                int same = 1, diff = 0;
                for(int i = 1; i < n && ok; i++){
                    if(s[0] == s[i])
                        same++;
                    else if(alt(s[0], s[i]))
                        diff++;
                }

                int same1 = 1, diff1 = 0;

                for(int i = 1; i < n && ok; i++){
                    if(comp(0, i))
                        same1++;
                    if(alt1(0, i))
                        diff1++;
                }

                if((same == diff && diff == n / 2) && (same1 == diff1 && diff1 == n / 2))
                    cout << 1 << endl;
                else cout << 0 << endl;
            }

        } else if (p == 2){
            //we need to arrange 1st line and 1st col

            //lines
            int s1 = 0, s2 = 0;
            for(int i = 0; i < n; i++){
                if(s[0][i] == '1' && (i % 2)) //1010
                    s1++;

                if(s[0][i] == '0' && (i % 2)) //0101
                    s2++;
            }

            s1 = min(s1, s2);

            //cols
            int s3 = 0 , s4 = 0;
            for(int i = 0; i < n; i++){
                if(s[i][0] == '1' && (i % 2))
                    s3++;
                if(s[i][0] == '0' && (i % 2))
                    s4++;
            }

            s3 = min (s3, s4);
            cout << s1 + s3 << endl;

        }
    }

    return 0;
}