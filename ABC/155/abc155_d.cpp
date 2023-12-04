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
// https://atcoder.jp/contests/abc155/tasks/abc155_d

int main(){
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    vector<ll> minus, zero, plus;
    rep(i, 0, n){
        cin >> a[i];
        if(a[i] > 0) plus.push_back(a[i]);
        if(a[i] == 0) zero.push_back(a[i]);
        if(a[i] < 0) minus.push_back(abs(a[i]));
    }
    sort(plus.begin(), plus.end());
    sort(minus.begin(), minus.end());

    if(k <= minus.size()*plus.size()){
        // 答えがマイナス
        ll ok = 9e18, ng = 0;
        while(ok-ng > 1){
            ll m = (ok+ng)/2;
            ll cnt = 0;
            rep(i, 0, plus.size()){
                ll q = m/plus[i];
                cnt += minus.end() - upper_bound(minus.begin(), minus.end(), q);
            }
            rep(i, 0, minus.size()){
                ll q = m/minus[i];
                cnt += plus.end() - upper_bound(plus.begin(), plus.end(), q);
            }

            if(cnt/2 >= k) ng = m;
            else ok = m;
        }
        cout << -ok << endl;
    }else if(k <= minus.size()*plus.size()+zero.size()*(minus.size()+plus.size())+zero.size()*(zero.size()-1)/2){
        // 答えがゼロ
        cout << 0 << endl;
    }else{
        // 答えがプラス
        ll ok = 9e18, ng = 0;
        while(ok-ng > 1){
            ll m = (ok+ng)/2;
            ll cnt = 0;
            rep(i, 0, plus.size()){
                ll q = m/plus[i];
                cnt += plus.end() - upper_bound(plus.begin()+i+1, plus.end(), q);
            }
            rep(i, 0, minus.size()){
                ll q = m/minus[i];
                cnt += minus.end() - upper_bound(minus.begin()+i+1, minus.end(), q);
            }

            if(cnt > n*(n-1)/2-k) ng = m;
            else ok = m;
        }
        cout << ok << endl;
    }
    
    return 0;
}