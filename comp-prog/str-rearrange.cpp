#include <iostream>
#include <string.h>

using namespace std;

int main(){
    //Rearranges the characters of the first string based on the parity pattern given by the second string

    freopen("trash.in","r",stdin);
    freopen("trash.out","w",stdout);

    char s[100], c[100], r1[100], r2[100], r[100];
    cin >> s >> c;
    int n, m, cnt1 = 0, cnt2 = 0;
    n = strlen(s);
    m = strlen(c);

    if(n != m){
        cout << "incorrect code";
    } else {
        for (int i = 1; i < n; i++){
            if((c[i] - '0') % 2 == 0)
                r1[cnt1++]=s[i];
            else
                r2[cnt2++]=s[i];
        }
        r1[cnt1] = r2[cnt2] = NULL;
        int j = 0;
        for(int i = cnt1 - 1; i >= 0; i--)
            r[j++] = r1[i];
        r[cnt1] = s[0];
        j = 0;
        for(int i = cnt1 + 1; i < n; i++)
            r[i] = r2[j++];
        r[n] = NULL;
        cout << r;
    }

    return 0;
}