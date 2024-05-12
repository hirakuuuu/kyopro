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
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

/*
trie木というデータ構造で、根付き木でたどったパス上の文字を連結して得られる文字列についての値を保持するみたいなことができる
各頂点に、その時点で見た文字列で、その文字列を接頭辞に持つものの個数を管理しておけばよい
今回は、部分文字列が高々 3*10^5 程度しか出てこないので、その個数分の頂点からなる木で、分岐も 26 個しかないので、十分間に合う
*/


int main(){
    int n; cin >> n;
    vector<string> s(n);
    rep(i, 0, n) cin >> s[i];
    ll ans = 0;
    vector<ll> cnt(300005);
    int idx = 1;
    vector<vector<int>> pos(300005, vector<int>(26, -1));
    rep(i, 0, n){
        int cur = 0;
        rep(j, 0, s[i].size()){
            if(pos[cur][s[i][j]-'a'] == -1){
                pos[cur][s[i][j]-'a'] = idx++;
            }
            cur = pos[cur][s[i][j]-'a'];
            ans += cnt[cur]++;
        }
    }
    cout << ans << endl;
    

    
    return 0;
}