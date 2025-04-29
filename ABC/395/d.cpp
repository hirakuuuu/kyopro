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
各巣にラベル鳩がいると思うと考えやすい
各操作をラベル鳩を介して考えると，以下のようになる
1. 鳩 a を ラベル鳩 b がいる箱に移動
2. ラベル鳩 a と ラベル鳩 b を入れ替える
3. 鳩 a と同居しているラベル鳩の番号を出力
*/

int main(){
    int n; cin >> n;
    int q; cin >> q;
    
    vector<int> p2s(n), l2s(n), s2l(n);
    iota(p2s.begin(), p2s.end(), 0); 
    iota(l2s.begin(), l2s.end(), 0); 
    iota(s2l.begin(), s2l.end(), 0); 
    
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int a, b; cin >> a >> b; a--, b--;
            p2s[a] = l2s[b];
        }else if(t == 2){
            int a, b; cin >> a >> b; a--, b--;
            swap(l2s[a], l2s[b]);
            swap(s2l[l2s[a]], s2l[l2s[b]]);
        }else{
            int a; cin >> a; a--;
            cout << s2l[p2s[a]]+1 << endl;
        }
    }
    return 0;
}