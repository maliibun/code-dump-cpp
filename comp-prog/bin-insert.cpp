#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

int v[50];
int main(){
    //Uses binary search to find the first position where the target could be inserted without breaking the order

        int n;
        cin >> n;

        for(int i = 0; i < n; i++)
          cin >> v[i];

        int x;
        cin >> x;

        int l = 0, h = n - 1, mid = 0;
        while(l <= h){
            mid = (l + h) / 2;
            if(v[mid] >= x)
                h = mid - 1;
            else
                l = mid + 1;
        }

        cout << l;

    return 0;
}