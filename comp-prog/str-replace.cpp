#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;


int main(){
    //Finds words made of * characters and replaces each with a previously read word of the same length
    int n;
    int f[100];
    char v[100][11], s[100];
    for(int i = 0; i < 100; i++)
        f[i] = -1;

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
        f[strlen(v[i])] = i;
    }
    cin.ignore();
    cin.getline(s, 100);

    char *p = strtok(s, " ");
    while(p != NULL)
    {
        if(p[0] == '*' && f[strlen(p)] != -1)
            cout << v[f[strlen(p)]] << ' ';
        else
            cout << p << ' ';
        p = strtok(NULL, " ");
    }

    return 0;
}