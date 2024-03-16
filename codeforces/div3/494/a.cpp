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


ll power(ll a, ll b, ll m=MOD){
    ll res = 1;
    while(b > 0){
        if(b%2 == 1) res = res*a%m;
        a = a*a%m;
        b /= 2;
    }
    return res;
}

int main(){
    int n; cin >> n;
    vector<string> w(n);
    rep(i, 0, n) cin >> w[i];

    vector<vector<ll>> hash(n+1, vector<ll>(n+1));
    string s = w[0];
    rep(i, 1, n){
        s += ' ';
        s += w[i];
    }
    vector<ll> acc(s.size()+1);
    rep(i, 1, s.size()+1){
        if(s[i-1] == ' '){
            acc[i] = (acc[i-1]*28+27)%MOD;
        }else{
            acc[i] = (acc[i-1]*28+(s[i-1]-'a'+1))%MOD;
        }
    }

    int ans = s.size(), l = 0;
    map<ll, pair<int, int>> exist;
    rep(i, 0, n){
        int r = l+w[i].size();
        rep(j, i, n){
            // hash[i:j] の計算
            hash[i][j] = (acc[r]-acc[l]*power(28, r-l)%MOD+MOD)%MOD;
            // cout << i << ' ' << j  << ' ' << l << ' ' << r << ' ' << hash[i][j] << endl;
            if(exist.find(hash[i][j]) != exist.end()){
                int len = s.size(), cnt = exist[hash[i][j]].first+1;
                len -= cnt*(r-l);
                len += cnt*(j-i+1);
                chmin(ans, len);
            }
            if(j < n-1) r += w[j+1].size()+1;
        }
        // [j, i] 
        rep(j, 0, i+1){
            if(exist.find(hash[j][i]) != exist.end()){
                if(exist[hash[j][i]].second < j){
                    exist[hash[j][i]].first++;
                    exist[hash[j][i]].second = i;
                }
            }else{
                exist[hash[j][i]] = {1, i};
            }
        }
        l += w[i].size()+1;
    }
    cout << ans << endl;



    return 0;
}