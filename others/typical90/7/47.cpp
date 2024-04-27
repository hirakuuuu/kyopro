#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

/*
小課題、全探索できる

ローリングハッシュは分かるけど、どう適用するかが分からない
斜め線が赤色になるパターンは、 RR, GB, BG
tの Gを B, B を G にすると、 RR, GG, BB に変換できる
よって、文字列一致判定に帰着される

*/

int main(){
    int n; cin >> n;
    string S, T; cin >> S >> T;
    map<char, int> rgb;
    rgb['R'] = 0, rgb['G'] = 1, rgb['B'] = 2;
    vector<int> s(n), t(n);
    rep(i, 0, n){
        s[i] = rgb[S[i]];
        t[i] = rgb[T[i]];
    }
    vector<ll> ten(n+1, 1);
    rep(i, 1, n+1) ten[i] = (ten[i-1]*10)%MOD;
    int ans = 0;
    rep(k, 0, 3){
        // tを変換する
        rep(i, 0, n){
            if(t[i] != k) t[i] = (6-k-t[i])%3;
        }

        // ハッシュテーブル構築
        vector<ll> hash_s(n+1), hash_t(n+1);
        rep(i, 1, n+1) hash_s[i] = (hash_s[i-1]*10+s[i-1])%MOD;
        rep(i, 1, n+1) hash_t[i] = (hash_t[i-1]*10+t[i-1])%MOD;

        rep(i, 0, n){
            ll hs = (hash_s[n]-hash_s[i]*ten[n-i])%MOD;
            if(hs < 0) hs += MOD;
            ll ht = hash_t[n-i];
            if(hs == ht) ans++;
        }
        rep(i, 1, n){
            ll ht = (hash_t[n]-hash_t[i]*ten[n-i])%MOD;
            if(ht < 0) ht += MOD;
            ll hs = hash_s[n-i];
            if(hs == ht) ans++;
        }
        // 元に戻す
        rep(i, 0, n){
            if(t[i] != k) t[i] = (6-k-t[i])%3;
        }
    }

    cout << ans << endl;
    
    return 0;
}

