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

int main(){
    int n, m; cin >> n >> m;
    vector<int> t(m), p(m);
    vector<vector<pair<int, int>>> in(n);
    rep(i, 0, m){
        cin >> t[i] >> p[i]; p[i]--;
        if(in[p[i]].empty() || in[p[i]].back().second != -1){
            in[p[i]].emplace_back(t[i], -1);
        }else{
            in[p[i]].back().second = t[i];
        }
    }

    vector<vector<ll>> ans_for_big(n);
    int thle = 500;
    rep(i, 0, n){
        if(in[i].size() < thle) continue;
        ans_for_big[i].assign(n, 0);

        int sz = (int)in[i].size();
        vector<ll> acc(sz+1);
        rep(j, 0, sz){
            acc[j+1] += acc[j]+(in[i][j].second-in[i][j].first);
        }

        rep(j, 0, n){
            if(i == j) continue;
            ll tmp = 0;
            for(auto [l, r]: in[j]){
                auto itr_l = upper_bound(in[i].begin(), in[i].end(), make_pair(l, 0));
                if(itr_l != in[i].begin()){
                    tmp += max(0LL, (ll)(*prev(itr_l)).second-l);
                }
                auto itr_r = upper_bound(in[i].begin(), in[i].end(), make_pair(r, 0));

                tmp += acc[itr_r-in[i].begin()]-acc[itr_l-in[i].begin()];
                if(itr_r != in[i].begin() && r < (*prev(itr_r)).second){
                    tmp -= (*prev(itr_r)).second-r;
                }
            }
            ans_for_big[i][j] = tmp;
        }
    }

    int q; cin >> q;
    while(q--){
        int a, b; cin >> a >> b; a--, b--;
        if(in[a].size() >= thle){
            cout << ans_for_big[a][b] << endl;
        }else if(in[b].size() >= thle){
            cout << ans_for_big[b][a] << endl;
        }else{
            ll ans = 0;
            int pa = 0, pb = 0;
            int sz_a = (int)in[a].size();
            int sz_b = (int)in[b].size();
            while(pa < sz_a && pb < sz_b){
                if(in[a][pa].second < in[b][pb].first){
                    pa++;
                }else if(in[b][pb].second < in[a][pa].first){
                    pb++;
                }else if(in[a][pa].first < in[b][pb].first){
                    if(in[a][pa].second < in[b][pb].second){
                        ans += (ll)in[a][pa].second-in[b][pb].first;
                        pa++;
                    }else{
                        ans += (ll)in[b][pb].second-in[b][pb].first;
                        pb++;
                    }
                }else{
                    if(in[b][pb].second < in[a][pa].second){
                        ans += (ll)in[b][pb].second-in[a][pa].first;
                        pb++;
                    }else{
                        ans += (ll)in[a][pa].second-in[a][pa].first;
                        pa++;
                    }
                }
                // cout << pa << ' ' << pb << ' ' << ans << endl;
            }
            cout << ans << endl;
        }
    }
    
    return 0;
}