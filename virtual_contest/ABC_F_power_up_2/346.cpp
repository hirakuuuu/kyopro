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

int main(){
    ll n; cin >> n;
    string s, t; cin >> s >> t;
    vector<vector<ll>> cnt(26, vector<ll>(s.size()+1));
    rep(i, 0, 26){
        rep(j, 0, (int)s.size()){
            cnt[i][j+1] = cnt[i][j];
            if(s[j]-'a' == i) cnt[i][j+1]++;
        }
    }
    auto calc = [&](char c, int pos, ll l) -> pair<ll, ll> {
        int tmp = c-'a';
        if(cnt[tmp][s.size()] == 0){
            return {n+1, 0};
        }
        pair<ll, ll> res = {0LL, 0LL};
        {
            ll ok = s.size()+1, ng = pos;
            while(ok-ng > 1){
                ll mid = (ok+ng)>>1;
                if(cnt[tmp][mid]-cnt[tmp][pos] >= l) ok = mid;
                else ng = mid;
            }
            if(ok <= s.size()){
                res.second = ok-1;
                return res;
            }
        }
        l -= cnt[tmp][s.size()]-cnt[tmp][pos];
        assert(l > 0);
        res.first++;
        if(l%cnt[tmp][s.size()] == 0){
            res.first += l/cnt[tmp][s.size()]-1;
            l -= (l/cnt[tmp][s.size()]-1)*cnt[tmp][s.size()];
        }else{
            res.first += l/cnt[tmp][s.size()];
            l -= (l/cnt[tmp][s.size()])*cnt[tmp][s.size()]; 
        }
        {
            assert(cnt[tmp][s.size()] >= l);
            ll ok = s.size(), ng = 0;
            while(ok-ng > 1){
                ll mid = (ok+ng)>>1;
                if(cnt[tmp][mid] >= l) ok = mid;
                else ng = mid;
            }
            res.second = ok-1;
            return res;
        }
    };
   
    

    ll ok = 0, ng = INF;
    while(ng-ok > 1){
        ll mid = (ok+ng)>>1;
        pair<ll, ll> tmp = {0, 0};
        rep(i, 0, t.size()){
            pair<ll, ll> now = calc(t[i], tmp.second, mid);
            tmp.first += now.first;
            tmp.second = now.second;
            if(tmp.first > n) break;
            if(tmp.second == (int)s.size()-1){
                tmp.first++;
                tmp.second = 0;
            }else{
                tmp.second++;
            }
            // cout << mid << ' ' << tmp.first << ' ' << tmp.second << endl;
        }
        if(tmp.first <= n-1 || (tmp.first == n && tmp.second == 0)){
            ok = mid;
        }else{
            ng = mid;
        }
    }
    cout << ok << endl;
    
    return 0;
}