#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc269/tasks/abc269_e

int main(){
    int n; cin >> n;

    int x = 1, y = 1;

    int N = n;
    
    while(N){
        printf("? %d %d %d %d", x, x+(N-1)/2, 1, n);
        cout << endl;
        int t; cin >> t;
        if(t == (N-1)/2+1){
            x += (N-1)/2+1;
        }
        N /= 2;
    }
    
    N = n;
    while(N){
        printf("? %d %d %d %d", 1, n, y, y+(N-1)/2);
        cout << endl;
        int t; cin >> t;
        if(t == (N-1)/2+1){
            y += (N-1)/2+1;
        }
        N /= 2;
    }


    printf("! %d %d", x, y);
    cout << endl;


    
    return 0;
}