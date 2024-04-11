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

// 問題
// 

// 0ならば素数, 0でないなら最小の素因数
vector<int> erat(200005);
void init_e(){
    rep(i, 2, sqrt(200005)){
        if(erat[i] == 0){
            for(int j = (ll)i*i; j < 200005; j += i){
                if(erat[j] == 0) erat[j] = i;
            }
        }
    }
}

int main(){
    int n; cin >> n;
    vector<int> p(n+1);
    rep(i, 1, n+1){
        cin >> p[i];
    }
    init_e();
    ll ans = 0;
    // if(p[1] == 1) ans = n-1;
    // else ans = n-2;
    vector<ll> mu(n+1);
    vector<vector<int>> yakusu(n+1);
    rep(i, 2, n+1){
        int ii = i, tmp = 1, oe = 0;
        while(erat[ii]){
            int pp = erat[ii];
            tmp *= pp;
            oe++;
            while(ii%pp == 0){
                ii /= pp;
            }
        }
        if(ii > 1){
            tmp *= ii;
            oe++;
        }
        if(tmp < i) continue;

        if(oe%2) mu[i] = 1;
        else mu[i] = -1;
        for(int j = i; j <= n; j += i){
            yakusu[j].push_back(i);
        }
    }
    vector<ll> used(n+1), cnt(n+1);
    rep(i, 2, n+1){
        if(mu[i] == 0) continue;
        vector<int> c;
        for(int j = i; j <= n; j += i){
            for(int k = 0; k < yakusu[p[j]].size(); k++){
                cnt[yakusu[p[j]][k]]++;
                if(!used[yakusu[p[j]][k]]){
                    c.push_back(yakusu[p[j]][k]);
                    used[yakusu[p[j]][k]] = true;
                }
            }
        }
        for(auto cc: c){
            ans += mu[i]*mu[cc]*(cnt[cc]*(cnt[cc]+1)/2);
            cnt[cc] = 0;
            used[cc] = false;
        }
    }
    cout << ans << endl;
    
    return 0;
}