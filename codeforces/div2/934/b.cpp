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


int main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<int> a(2*n);
        rep(i, 0, 2*n){
            cin >> a[i];
            a[i]--;
        }
        vector<int> cnt(n);
        rep(i, 0, n) cnt[a[i]]++;
        vector<int> l, r, c;
        rep(i, 0, n){
            if(cnt[i] == 2){
                l.push_back(i);
            }else if(cnt[i] == 0){
                r.push_back(i);
            }else{
                c.push_back(i);
            }
        }
        vector<int> L, R;
        int s = min(l.size(), r.size());
        rep(i, 0, min(k, s)){
            rep(_, 0, 2) L.push_back(l[i]);
            rep(_, 0, 2) R.push_back(r[i]);
        }
        rep(i, 0, 2*k){
            if(L.size() == 2*k) break;
            L.push_back(c[i]);
            R.push_back(c[i]);
        }
        rep(i, 0, 2*k) cout << L[i]+1 << ' ';
        cout << endl;
        rep(i, 0, 2*k) cout << R[i]+1 << ' ';
        cout << endl;

    }
 
    return 0;
}