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
    int n; cin >> n;
    vector<int> a(n);
    rep(i, 0, n){
        cin >> a[i];
    }

    set<tuple<int, int, int>> s;
    for(int i = 0; i < n; ){
        int j = i;
        while(j < n && a[i] == a[j]){
            j++;
        }
        s.insert({i, j, a[i]});
        i = j;
    }

    int ans = n;
    {
        int pl = -n, pr = 0;
        for(auto [l, r, c]: s){
            if(c == 0){
                if(r-l == 1){
                    if(l != 0 && r != n) ans -= 2;
                }else{
                    ans -= r-l-2;
                }
            }else{
                if(l == 0){
                    if(r != n) ans -= r-l-1;
                }else if(l != 0 || r != n){
                    if(r == n && pr-pl == 1) ans -= max(r-l-2, 0);
                    else ans -= r-l-1;
                }
            }
            pl = l, pr = r;
        }
    }


    auto f = [&](int l, int r, int c) -> int {
        if(c == 0){
            if(r-l == 1){
                if(l != 0 && r != n) return 2;
            }else{
                return r-l-2;
            }
        }
        if(l == 0){
            if(r != n) return r-l-1;
            return 0;
        }
        auto itr = prev(s.find({l, r, c}));
        auto [pl, pr, _] = *itr;
        if(r == n && pr-pl == 1) return max(r-l-2, 0);
        return r-l-1;
    };

    int q; cin >> q;
    while(q--){
        int pos; cin >> pos; pos--;

        int p_l, p_r;

        // 区間の取得
        {
            auto itr = prev(s.lower_bound({pos+1, pos+1, -1}));
            auto [l, r, c] = *itr;
            p_l = l, p_r = r;
            // 区間を修正
            ans += f(l, r, c);
            if(itr != s.begin()){
                auto itr_l = prev(itr);
                auto [l_l, l_r, l_c] = *itr_l;
                if(pos == l_r) ans += f(l_l, l_r, l_c);
            }
            if(*itr != *s.rbegin()){
                auto itr_r = next(itr);
                auto [r_l, r_r, r_c] = *itr_r;
                if(pos+1 == r_l) ans += f(r_l, r_r, r_c);
            }
            s.erase(itr);

            if(l < pos) s.insert({l, pos, c});
            s.insert({pos, pos+1, 1-c});
            if(pos+1 < r) s.insert({pos+1, r, c});
        }
        {
            auto itr = prev(s.lower_bound({pos+1, pos+1, -1}));
            auto [l, r, c] = *itr;
            if(itr != s.begin()){
                auto itr_l = prev(itr);
                auto [l_l, l_r, l_c] = *itr_l;
                if(l_c == c){
                    s.erase(itr);
                    s.erase(itr_l);
                    s.insert({l_l, pos+1, c});
                }
            }
        }
        {
            auto itr = prev(s.lower_bound({pos+1, pos+1, -1}));
            auto [l, r, c] = *itr;
            if(*itr != *s.rbegin()){
                auto itr_r = next(itr);
                auto [r_l, r_r, r_c] = *itr_r;
                if(r_c == c){
                    s.erase(itr);
                    s.erase(itr_r);
                    s.insert({l, r_r, c});
                }
            }
        }
        auto itr = prev(s.lower_bound({pos+1, pos+1, -1}));
        auto [l, r, c] = *itr;
        ans -= f(l, r, c);
        if(itr != s.begin()){
            auto itr_l = prev(itr);
            auto [l_l, l_r, l_c] = *itr_l;
            if(p_l <= l_l && l_r <= p_r) ans -= f(l_l, l_r, l_c);
        }
        if(*itr != *s.rbegin()){
            auto itr_r = next(itr);
            auto [r_l, r_r, r_c] = *itr_r;
            if(p_l <= r_l && r_r <= p_r) ans -= f(r_l, r_r, r_c);
        }
        


        a[pos] = 1-a[pos];

        // cout << endl;
        // rep(i, 0, n){
        //     cout << a[i] << ' ';
        // }
        // cout << endl;
        // for(auto [l, r, c]: s){
        //     cout << l << ' ' << r << ' ' << c << ' ' << f(l, r, c) << endl;
        // }
        // cout << endl;

        cout << ans << endl;



    }
    
    return 0;
}