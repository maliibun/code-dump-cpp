#include <bits/stdc++.h>

using namespace std;

int a[200];

int main()
{
    freopen("cartesian.in","r",stdin);
    freopen("cartesian.out","w",stdout);

    //making a cartesian tree

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<int> parents(n+1, -1);

    stack<int> st;

    for(int i = 0; i < n; i++){
        int last = -1;

        while(!st.empty() && a[st.top()] >= a[i]){
            //bigger than node, put last under it
            last = st.top();
            st.pop();
        }
        //smaller than node, put it under biggest
        if(!st.empty())
            parents[i] = st.top();

        if(last >= 0){
            parents[last] = i;
        }

        st.push(i);
    }

    for(int i = 0; i < n; i++)
        cout << parents[i] <<' ';

    return 0;
}