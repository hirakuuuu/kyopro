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
    vector<ll> s(1<<n);
    rep(i, 0, 1<<n) cin >> s[i];
    sort(s.begin(), s.end());
    multiset<ll> ms;
    rep(i, 0, (1<<n)-1) ms.insert(-s[i]);
    multiset<ll> slime;
    slime.insert(-s[(1<<n)-1]);
    rep(i, 0, n){
        multiset<ll> slime_ = slime;
        for(auto sl: slime){
            auto itr = ms.upper_bound(sl);
            if(itr == ms.end()){
                cout << "No" << endl;
                return 0;
            }
            ll tmp = *itr;
            slime_.insert(tmp);
            ms.erase(itr);
        }
        swap(slime, slime_);
    }
    cout << "Yes" << endl;
    return 0;
}