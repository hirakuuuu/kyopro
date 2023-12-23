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
// https://atcoder.jp/contests/abc172/tasks/abc172_f

int main(){
    int n; cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    ll obj = 0;
    rep(i, 2, n) obj ^= a[i];
    rep(i, 0, 10){
        cout << ((a[0]-i)^(a[1]+i)) << endl;
    }
    if(a[0]+a[1] < obj){
        cout << -1 << endl;
    }else{
        if(a[0] > a[1]){
            if((((a[0]+a[1])/2)^((a[0]+a[1])/2+(a[0]+a[1])%2)) <= obj){
                ll ok = 0, ng = a[0]-a[1];
                while(ng-ok> 1){
                    ll mid = (ok+ng)/2;
                    ll a1 = a[0]-mid, a2 = a[1]+mid;
                    cout << mid << ' ' << (a1^a2) << endl;
                    if((a1^a2) <= obj) ok = mid;
                    else ng = mid;
                }
                if(((a[0]-ok)^(a[1]+ok)) == obj){
                    cout << ok << endl;
                    return 0;
                }
            }
        }
        // 単調増加性がある
        if((a[0]^a[1]) <= obj){
            ll ok = a[0]-1, ng = -1;
            while(ok-ng> 1){
                ll mid = (ok+ng)/2;
                ll a1 = a[0]-mid, a2 = a[1]+mid;
                cout << mid << ' ' << (a1^a2) << endl;
                if((a1^a2) < obj) ng = mid;
                else ok = mid;
            }
            if(((a[0]-ok)^(a[1]+ok)) == obj) cout << ok << endl;
            else cout << -1 << endl;
        }else{
            cout << -1 << endl;
        }
    }

    
    return 0;
}