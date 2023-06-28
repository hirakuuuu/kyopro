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
    int n, m; cin >> n >> m;
    vector<pii> t(m), a(m);
    rep(i, 0, m){
        int A, B; cin >> A >> B;
        A--; B--;
        t[i] = {A, B};
    }
    sort(t.begin(), t.end());
    rep(i, 0, m){
        int A, B; cin >> A >> B;
        A--; B--;
        a[i] = {A, B};
    }
    sort(a.begin(), a.end());

    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    do{
        vector<pii> t_(m);
        rep(i, 0, m){
            pii tt = t[i];
            if(p[tt.first] > p[tt.second]) swap(tt.first, tt.second);
            t_[i] = {p[tt.first], p[tt.second]};
        }
        sort(t_.begin(), t_.end());
        if(a == t_){
            cout << "Yes" << endl;
            return 0;
        }
    }while(next_permutation(p.begin(), p.end()));

    cout << "No" << endl;
    
    return 0;
}