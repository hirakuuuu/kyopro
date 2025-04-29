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
    ll n, m, a, b; cin >> n >> m >> a >> b;
    vector<ll> l(m), r(m);
    rep(i, 0, m){
        cin >> l[i] >> r[i];
    }

    if(m == 0){
        ll cnt = (n-1)/a;
        if(n-(1+cnt*a) <= cnt*(b-a)) cout << "Yes" << endl;
        else cout << "No" << endl;
        return 0; 
    }

    vector<pair<ll, ll>> good;
    good.push_back({1, l[0]-1});
    rep(i, 1, m){
        if(r[i-1]+1 <= l[i]-1){
            good.push_back({r[i-1]+1, l[i]-1});
        }
    }
    good.push_back({r[m-1]+1, n});

    vector<pair<ll, ll>> c;
    int num = (int)good.size();
    rep(i, 0, num){
        // 各区間の先頭20マスと後ろ20マス
        rep(j, 0, 20){
            if(good[i].second < good[i].first+j) break;
            c.push_back({good[i].first+j, i});
        }
        rep(j, 0, 20){
            if(good[i].second-j < good[i].first) break;
            c.push_back({good[i].second-j, i});
        }
    }
    sort(c.begin(), c.end());
    c.erase(unique(c.begin(), c.end()), c.end());
    
    num = (int)c.size();
    vector<vector<ll>> to(num);
    rep(i, 0, num){
        int j = i+1;
        while(j < num){
            if(c[j].second == c[i].second){
                // 同じ区間内の移動
                ll tmp = (c[j].first-c[i].first)/a;
                ll pos = c[i].first+a*tmp;
                if(c[j].first-pos <= tmp*(b-a)) to[i].push_back(j);
            }else{
                // 異なる区間の移動
                if(inr(a, c[j].first-c[i].first, b+1)) to[i].push_back(j);
                else if(b < c[j].first-c[i].first) break;
            }
            j++;
        }
    }

    vector<bool> ok(num);
    ok[0] = true;
    rep(i, 0, num){
        if(!ok[i]) continue;
        // cout << good[i].first << ' ' <<  good[i].second << endl;
        for(auto can: to[i]){
            ok[can] = true;
        }
    }
    if(ok[num-1]) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}