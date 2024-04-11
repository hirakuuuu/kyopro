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

int main(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];
    vector<int> l(n+1), r(n+1);
    set<int> s;
    map<int, int> lb;
    rep(i, 0, n){
        lb[a[i]] = IINF;
    }
    rrep(i, n-1, 0){
        lb[b[i]] = i;
    }
    rep(i, 1, n+1){
        if(s.find(a[i-1]) == s.end()){
            s.insert(a[i-1]);
            l[i] = max(l[i-1], lb[a[i-1]]);
            r[i] = r[i-1];
            while(r[i] != n && s.find(b[r[i]]) != s.end()) r[i]++;
        }else{
            l[i] = l[i-1];
            r[i] = r[i-1];
        }
    }

    int q; cin >> q;
    while(q--){
        int x, y; cin >> x >> y;
        y--;
        if(l[x] <= y && y < r[x]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
    return 0;
}