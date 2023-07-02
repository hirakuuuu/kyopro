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
// https://atcoder.jp/contests/abc308/tasks/abc308_c

int main(){
    int n; cin >> n;
    vector<ll> a(n), b(n);
    rep(i, 0, n) cin >> a[i] >> b[i];

    vector<int> p(n);
    iota(p.begin(), p.end(), 0);

    sort(p.begin(), p.end(), [&](int i, int j) {
        if(a[i]*b[j] > a[j]*b[i] || (a[i]*b[j] == a[j]*b[i] && i < j)){
            return true;
        }
        return false;
    });
    rep(i, 0, n){
        cout << p[i]+1 << ' ';
    }
    cout << endl;
    return 0;
}