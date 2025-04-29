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
- N が奇数でないとだめ
- (N-1)%K == 0 であればいける
- （嘘）(N-1)/2 本で (N-1)/2+1 頂点の木を作り，その頂点を +K した木が元の木と１頂点だけ被るようにすれば勝ち
- それができるかは {0, k, 2*k} を除いた頂点に対して，完全マッチングが作れるかでよい

- N が奇数なら必ず可能
- https://atcoder.jp/contests/arc152/editorial/5119
*/


int main(){
    int n, k; cin >> n >> k;
    if(n%2 == 0){
        cout << -1 << endl;
        return 0;
    }
    
    int g = gcd(n, k);
    vector<vector<int>> a(n/g);
    int pre = 0;
    rep(i, 0, n/g){
        a[i].push_back(pre);
        pre = (pre+k)%n;
    }
    rep(i, 0, n/g){
        rep(j, 0, g){
            a[i].push_back(a[i].back()+1);
        }
    }

    cout << (n-1)/2 << endl;
    // 縦線
    rep(i, 0, n/g-1){
        if(i%2 == 1) continue;
        rep(j, 0, g){
            if(j%2 == 1) continue;
            cout << a[i][j] << ' ' << a[i+1][j] << endl;
        }
    }
    // 横線
    rep(i, 0, n/g){
        if(i < n/g-2){
            if(i%2 == 1) continue;
            rep(j, 0, g-1){
                if(j%2 == 1) continue;
                cout << a[i][j] << ' ' << a[i][j+1] << endl;
            }
        }else if(i == n/g-2){
            rep(j, 0, g-1){
                if(j%2 == 0) continue;
                cout << a[i][j] << ' ' << a[i][j+1] << endl;
            }
        }
    }

    return 0;
}