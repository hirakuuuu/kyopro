#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

/*
構築系はサンプルの小さい例をベースにするといいことがあるかも
n が奇数の場合，2個ずつ増やしていくのは 1 とくっつければいいからOK
n が偶数の場合，n-1 まで上のやつでやって，あとは 1 とくっついてる 2~n-1 であって，xor が n+1 になるものとくっつければOK
*/

int main(){
    int n; cin >> n;
    if(__popcount(n) == 1){
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
    rep(i, 1, 3){
        cout << i << ' ' << i+1 << endl;
        cout << n+i << ' ' << n+i+1 << endl;
    }
    cout << 3 << ' ' << n+1 << endl;

    for(int i = 4; i+1 <= n; i += 2){
        cout << n+1 << ' ' << i << endl;
        cout << i << ' ' << n+i+1 << endl;
        cout << n+1 << ' ' << i+1 << endl;
        cout << i+1 << ' ' << n+i << endl;
    }

    if(n%2 == 0){
        int x = n+1;
        int j = 0;
        while((x>>j) != 1) j++;
        int y = (1<<j), z = x-y;
        assert(inr(2, y, n) && inr(2, z, n));
        if(y == 2) cout << n+2 << ' ' << n << endl;
        else cout << y << ' ' << n << endl;

        if(z == 2) cout << n+2 << ' ' << 2*n << endl;
        else cout << z << ' ' << 2*n << endl;
    }
    
    return 0;
}