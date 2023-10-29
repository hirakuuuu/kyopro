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
// https://atcoder.jp/contests/abc326/tasks/abc326_f

int main(){
    ll n, x, y; cin >> n >> x >> y;
    vector<ll> a(80);
    rep(i, 0, n) cin >> a[i];

    vector<pair<ll, ll>> cx, cy, dx, dy;
    rep(i, 0, (1<<20)){
        ll tmp_x = 0, tmp_y = 0;
        rep(j, 0, 20){
            if((i&(1<<j)) > 0){
                tmp_x += a[j*2+1];
                tmp_y += a[j*2];
            }else{
                tmp_x += -a[j*2+1];
                tmp_y += -a[j*2];
            }
        }
        cx.push_back({tmp_x, i});
        cy.push_back({tmp_y, i});
    }
    rep(i, 0, (1<<20)){
        ll tmp_x = x, tmp_y = y;
        rep(j, 0, 20){
            if((i&(1<<j)) > 0){
                tmp_x += a[(39-j)*2+1];
                tmp_y += a[(39-j)*2];
            }else{
                tmp_x += -a[(39-j)*2+1];
                tmp_y += -a[(39-j)*2];
            }
        }
        dx.push_back({tmp_x, i});
        dy.push_back({tmp_y, i});
    }

    sort(cx.begin(), cx.end());
    sort(dx.begin(), dx.end());
    sort(cy.begin(), cy.end());
    sort(dy.begin(), dy.end());



    bool fx = false, fy = false;
    ll root_x, root_y, root_rx, root_ry;
    rep(i, 0, cx.size()){
        auto itr = lower_bound(dx.begin(), dx.end(), make_pair(cx[i].first, 0LL));
        if(itr == dx.end()) continue;
        if((*itr).first == cx[i].first){
            fx = true;
            root_x = cx[i].second;
            root_rx = (*itr).second;
            break;
        }
    }
    rep(i, 0, cy.size()){
        auto itr = lower_bound(dy.begin(), dy.end(), make_pair(cy[i].first, 0LL));
        if(itr == dy.end()) continue;
        if((*itr).first == cy[i].first){
            fy = true;
            root_y = cy[i].second;
            root_ry = (*itr).second;
            break;
        }
    }


    if(fx && fy){
        cout << "Yes" << endl;
        // rep(i, 0, 20){
        //     cout << ((root_rx&1<<i) > 0 ? 1 : 0);
        // }
        // cout << endl;
        // rep(i, 0, 20){
        //     cout << ((root_ry&1<<i) > 0 ? 1 : 0);
        // }
        // cout << endl;
        vector<char> ans(80);
        int ex = 1, ey = 1;
        rep(i, 0, 20){
            if(((root_y&(1<<i)) > 0)^(ex == 1)){
                ans[2*i] = 'R';
                ey = 1-ex;
            }else{
                ans[2*i] = 'L';
                ey = ex;
            }
            if(((root_x&(1<<i)) > 0)^(ey == 1)){
                ans[2*i+1] = 'L';
                ex = 1-ey;
            }else{
                ans[2*i+1] = 'R';
                ex = ey;
            }
        }
        rep(i, 0, 20){
            if(((root_ry&(1<<(19-i))) == 0)^(ex == 1)){
                ans[2*(20+i)] = 'R';
                ey = 1-ex;
            }else{
                ans[2*(20+i)] = 'L';
                ey = ex;
            }
            if(((root_rx&(1<<(19-i))) == 0)^(ey == 1)){
                ans[2*(20+i)+1] = 'L';
                ex = 1-ey;
            }else{
                ans[2*(20+i)+1] = 'R';
                ex = ey;
            }
        }
        rep(i, 0, n){
            cout << ans[i];
        }
        cout << endl;
    }else{
        cout << "No" << endl;
    }
    
    return 0;
}