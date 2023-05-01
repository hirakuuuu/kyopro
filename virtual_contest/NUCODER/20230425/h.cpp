#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n; cin >> n;
    vector<int> x(n), c(n);
    rep(i, 0, n) cin >> x[i] >> c[i];

    vector<set<pii>> cnt_1(n+1), cnt_2(n+1);
    rep(i, 0, n) cnt_1[c[i]-1].insert({x[i], i});
    rep(i, 0, n) cnt_2[n-c[i]-1].insert({x[i], i});
    cnt_1[n].insert({0, n});
    cnt_2[0].insert({0, n});

    vector<ll> ans_1(n+1);
    vector<ll> ans_2(n+1);

    int pos = 0;
    ll ans = 0;
    rep(i, 0, n+1){
        while(cnt_1[i].size()){
            auto r = cnt_1[i].upper_bound({pos, 0});
            if(r != cnt_1[i].begin()){
                auto l = r;
                l--;
                if(r == cnt_1[i].end() or abs(pos-(*l).first) < abs(pos-(*r).first)) swap(l, r);
            }
            ans += abs(pos-(*r).first);
            ans_1[(*r).second] = ans;
            pos = (*r).second;
            cnt_1[i].erase(r);
        }
    }
    pos = 0;
    ans = 0;
    rep(i, 0, n+1){
        while(cnt_2[i].size()){
            auto r = cnt_2[i].upper_bound({pos, 0});
            if(r != cnt_2[i].begin()){
                auto l = r;
                l--;
                if(r == cnt_2[i].end() or abs(pos-(*l).first) < abs(pos-(*r).first)) swap(l, r);
            }
            ans += abs(pos-(*r).first);
            ans_2[(*r).second] = ans;
            pos = (*r).second;
            cnt_2[i].erase(r);
        }
    }
    ll min_ans = 1LL<<60;
    rep(i, 0, n+1) chmin(min_ans, ans_1[i]+ans_2[i]);
    cout << min_ans << endl;

    
    return 0;
}