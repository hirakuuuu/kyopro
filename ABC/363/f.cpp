#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    ll n; cin >> n;
    vector<ll> yakusu;
    for(ll i = 2; i*i <= n; i++){
        if(n%i == 0){
            string s = to_string(i);
            bool ok = true;
            for(auto ss: s) if(ss == '0') ok = false;
            if(ok) yakusu.push_back(i);
            if(n/i != i && n/i <= 1000000){
                s = to_string(n/i);
                ok = true;
                for(auto ss: s) if(ss == '0') ok = false;
                if(ok) yakusu.push_back(n/i);
            }
        }
    }
    sort(yakusu.begin(), yakusu.end());
    map<ll, int> p;
    for(auto yy: yakusu){
        string s = to_string(yy);
        reverse(s.begin(), s.end());
        p[yy] = stoi(s);
    }
    string ans;
    map<ll, bool> memo;
    auto is_pal = [&](ll num) -> bool {
        if(memo.find(num) != memo.end()) return memo[num];
        string s = to_string(num);
        string t = s;
        reverse(t.begin(), t.end());
        if(s != t) return memo[num] = false;
        for(auto ss: s) if(ss == '0') return memo[num] = false;
        return memo[num] = true;
    };
    // O(sqrt(n)) でおさまっている
    auto f = [&](auto self, ll tmp, int pos) -> void {
        // cout << tmp << ' ' << pos << endl;
        if(is_pal(tmp)){
            string rev = ans;
            reverse(ans.begin(), ans.end());
            cout << ans << tmp << rev << endl;
            exit(0);
        }

        string ans_ = ans;
        rep(i, pos, yakusu.size()){
            if(tmp%yakusu[i] == 0 && (tmp/yakusu[i])%p[yakusu[i]] == 0){
                ans += "*";
                ans += to_string(yakusu[i]);
                self(self, (tmp/(yakusu[i]))/p[yakusu[i]], i);
                ans = ans_;
            }
        }
    };
    f(f, n, 0);
    cout << -1 << endl;
    
    return 0;
}