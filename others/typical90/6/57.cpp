#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

/*
複数のスイッチを組み合わせて押すように組み替えても、答えは変わらない
掃き出し法によって、特定の位置を切り替えられるスイッチを1つに絞る
押すか押さないかはその時点でのｓに依存する
（これは掃き出し法で上三角行列を作るイメージ）
最終的に残った0行の数だけ選択肢がある
*/

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    rep(i, 0, n){
        int t; cin >> t;
        rep(j, 0, t){
            int A; cin >> A;
            a[i][A-1] = 1;
        }
    }
    vector<int> s(m);
    rep(i, 0, m) cin >> s[i];

    int l = 0;
    rep(i, 0, m){
        bool ok = false;
        rep(j, l, n){
            if(a[j][i] == 1){
                swap(a[l], a[j]);
                ok = true;
                break;
            }
        }
        if(ok){
            rep(j, 0, n){
                if(j != l && a[j][i] == 1){
                    rep(k, 0, m){
                        a[j][k] ^= a[l][k];
                    }
                }
            }
            if(s[i] == 1){
                rep(j, 0, m){
                    s[j] ^= a[l][j];
                }
            }
            l++;
        }
    }

    if(s == vector<int>(m, 0)){
        mint ans = 1;
        rep(i, l, n) ans *= 2;
        cout << ans.val() << endl;
    }else{
        cout << 0 << endl;
    }

    return 0;
}