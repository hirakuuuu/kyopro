#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    ll n; cin >> n;
    ll ord = 0, m = n;
    while(m){
        ord++;
        m /= 10;
    }  
    vector<int> a;
    auto is_shichigosan = [&]() -> int {
        set<int> s(a.begin(), a.end());
        ll tmp = 0;
        for(auto aa: a) tmp = (tmp*10)+(ll)aa;
        return (s.size() == 3 && tmp <= n);
    };
    
    auto f = [&](auto self, ll i) -> ll {
        ll res = 0;
        if(!a.empty()) res += is_shichigosan();
        
        if(i == ord) return res;

        for(int j = 3; j <= 7; j += 2){
            a.push_back(j);
            res += self(self, i+1);
            a.pop_back();
        }
        return res;
    };
    cout << f(f, 0LL) << endl;

    return 0;
}