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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

/*
エラトステネスの篩で N までの素数を O(NloglogN) 時間で列挙できる.
また, 自然数 n の素因数分解を O(logn) で実行できる
よって愚直に素因数分解するだけでも O(NlogN) であり, N <= 10^7 では十分高速
*/

// 0ならば素数, 0でないなら最小の素因数
vector<int> erat(10000005);
void init_e(){
    rep(i, 2, sqrt(10000005)){
        if(erat[i] == 0){
            for(int j = i*i; j <= 10000005; j += i){
                if(erat[j] == 0) erat[j] = i;
            }
        }
    }
}

int main(){
    init_e();
    int n, k; cin >> n >> k;
    int ans = 0;
    rep(i, 2, n+1){
        int cnt = 0, p = 0, j = i;
        while(erat[j]){
            if(p != erat[j]){
                cnt++;
                p = erat[j];
            }
            j /= erat[j];
        }
        if(j != 1 && j != p) cnt++; 
        if(k <= cnt) ans++;
    }
    cout << ans << endl;


    return 0;
}