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
    set<pair<int, int>> s;
    s.insert({IINF, 1});
    s.insert({0, 0});
    int ans = 0;
    rep(i, 0, n){
        int h; cin >> h;
        int pre = 0;
        while((*s.begin()).first <= h){
            if(i%2 == 0){
                if((*s.begin()).second == 1){
                    ans += (*s.begin()).first-pre;
                }
            }else{
                if((*s.begin()).second == 0){
                    ans -= (*s.begin()).first-pre;
                }
            }

            pre = (*s.begin()).first;
            s.erase(s.begin());
        }
        if((*s.begin()).second != i%2){
            s.insert({h, i%2});
            if(i%2 == 0){
                ans += h-pre;
            }else{
                ans -= h-pre;
            }
        }
        cout << ans << endl;
        // for(auto [H, C]: s){
        //     cout << "{" << H << ", " << C << "}, ";
        // }
        // cout << endl;
    }
    // cout << ans << endl;


    
    return 0;
}