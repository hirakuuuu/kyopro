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
    {
        string s = to_string(n);
        bool not_zero = true;
        for(auto ss: s){
            if(ss == '0') not_zero = false;
        }
        string t = to_string(n);
        reverse(t.begin(), t.end());
        if(not_zero && s == t){
            cout << s << endl;
            return 0;
        }
    }
    
    // 0を含まないかつ，反転しても約数となるような約数列挙
    vector<ll> yakusu;
    map<ll, ll> pal_num;
    for(ll i = 2; i*i <= n; i++){
        if(n%i == 0){
            // i について判定
            {
                string s = to_string(i);
                // 0 を含まないことの判定
                bool not_zero = true;
                {
                    for(auto ss: s){
                        if(ss == '0') not_zero = false;
                    }
                }
                // 反転して約数になるか
                string t = to_string(i);
                reverse(t.begin(), t.end());
                ll j = stol(t);
                if(not_zero && n%j == 0){
                    yakusu.push_back(i);
                    pal_num[i] = j;
                }
            }

            // n/i について判定
            if(n/i != i){
                string s = to_string(n/i);
                // 0 を含まないことの判定
                bool not_zero = true;
                {
                    for(auto ss: s){
                        if(ss == '0') not_zero = false;
                    }
                }
                // 反転して約数になるか
                string t = to_string(n/i);
                reverse(t.begin(), t.end());
                ll j = stol(t);
                if(not_zero && n%j == 0){
                    yakusu.push_back(n/i);
                    pal_num[n/i] = j;
                }
            }
        }
    }

    sort(yakusu.begin(), yakusu.end());
    // for(auto yy: yakusu){
    //     cout << yy << endl;
    // }
    int m = yakusu.size();

    // 文字列を再帰的に構成
    string ans;
    auto f = [&](auto self, int i=0, ll l=1, ll r=1, string tmp="1") -> void {
        if(i >= m) return;
        if(!ans.empty()) return;
        // cout << yakusu[i] << ' ' << tmp << endl;
        // cout << tmp << ' ' << i << ' ' << l << ' ' << r << endl;
        if(l*r == n){
            string rev = tmp;
            reverse(rev.begin(), rev.end());
            ans = tmp+"*"+rev;
            return;
        }
        {
            ll num = n/l/r;
            string s = to_string(num);
            bool not_zero = true;
            for(auto ss: s){
                if(ss == '0') not_zero = false;
            }
            string t = to_string(num);
            reverse(t.begin(), t.end());
            if(not_zero && s == t){
                string rev = tmp;
                reverse(rev.begin(), rev.end());
                ans = tmp+"*"+s+"*"+rev;
                return;
            }
        }

        self(self, i+1, l, r, tmp);

        if(((n/l)/r)%yakusu[i] == 0 && (((n/l)/r)/yakusu[i])%pal_num[yakusu[i]] == 0){
            tmp += "*"+to_string(yakusu[i]);
            l *= yakusu[i];
            r *= pal_num[yakusu[i]];
            self(self, i, l, r, tmp);
        }
        return;
    };

    f(f);
    if(ans.empty()) ans = "-1";
    cout << ans << endl;



    
    return 0;
}