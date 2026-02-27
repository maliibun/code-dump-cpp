#include <iostream>

using namespace std;

#define MOD 666013
typedef long long ll;
void prod(ll P[][2], ll A[][2], ll B[][2]){
    P[0][0] = (A[0][0] * B[0][0] + A[0][1] * B[1][0]) % MOD;
    P[0][1] = (A[0][0] * B[0][1] + A[0][1] * B[1][1]) % MOD;
    P[1][0] = (A[1][0] * B[0][0] + A[1][1] * B[1][0]) % MOD;
    P[1][1] = (A[1][0] * B[0][1] + A[1][1] * B[1][1]) % MOD;
}

void cop(ll A[][2], ll B[][2]){
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            A[i][j] = B[i][j];
}

int main()
{
    int n;
    cin >> n;

    ll A[2][2] = {{1, 1}, {1, 0}};
    ll P[2][2] = {{1, 0}, {0, 1}};
    ll B[2][2];

    while(n > 0){

        if(n % 2 == 1){
            prod(B, A, P);
            cop(P, B);
        }
        prod(B, A, A);
        cop(A, B);
        n /= 2;
    }

    cout << P[0][1];

    return 0;
}