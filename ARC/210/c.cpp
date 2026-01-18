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
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector<ll> a(n);
        rep(i, 0, n) cin >> a[i];

        vector<ll> ans = {0};
        auto f = [&](auto self, int i, int k) -> int {
            int tmp = k;
            if(i < n) tmp += a[i];
            if(i >= n && tmp < m) return k;

            int change = tmp/10;
            int remain = self(self, i+1, change);
            tmp -= (change-remain)*10;

            int x = tmp/m;
            if(x){
                while(ans.size() <= i) ans.push_back(0);
                ans[i] += x;
            }
            return min(tmp-x*m, k);
        };
        f(f, 0, 0);
        string s;
        rep(i, 0, (int)ans.size()-1){
          s += (char)('0'+ans[i]%10);
          ans[i+1] += ans[i]/10;
        }
        while(ans.back()){
          s += (char)('0'+ans.back()%10);
          ans.back() /= 10;
        }
        while(s.size() > 1 && s.back() == '0') s.pop_back();
        if(s.empty()) s += '0';
        reverse(s.begin(), s.end());
        cout << s << endl;
    }


    return 0;
}