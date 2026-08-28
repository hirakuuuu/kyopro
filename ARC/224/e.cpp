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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int n = (int)s.size();
        vector<int> stc;
        int sz = 0;
        auto f = [&]() -> void {
            while(true){
                bool flag = false;
                if(sz >= 3 && stc[sz-1] == 'C' && stc[sz-2] == 'B' && stc[sz-3] == 'A'){
                    stc.pop_back();
                    stc.pop_back();
                    stc.pop_back();
                    sz -= 3;
                    flag = true;
                }else if(sz >= 3 && stc[sz-1] == 'B' && stc[sz-2] == 'B' && stc[sz-3] == 'A'){
                    char c = stc.back();
                    stc.pop_back();
                    stc.pop_back();
                    stc.pop_back();
                    stc.push_back(c);
                    sz -= 2;
                    flag = true;
                }else if(sz >= 2 && stc[sz-1] == 'C' && stc[sz-2] == 'A'){
                    char c = stc.back();
                    stc.pop_back();
                    stc.pop_back();
                    stc.push_back(c);
                    sz -= 1;
                    flag = true;
                }
                if(!flag) break;
            }
            return;
        };
        rep(i, 0, n){
            stc.push_back(s[i]);
            sz++;
            f();
        }

        string t;
        rep(i, 0, sz) t += stc[i];
        stc.clear();
        sz = 0;
        n = t.size();
        rep(i, 0, n){
            stc.push_back(t[i]);
            sz++;
            while(sz >= 2 && stc[sz-1] == 'B' && stc[sz-2] == 'A'){
                stc.pop_back();
                stc.pop_back();
                sz -= 2;
            }
        }

        int ans = 0;
        rep(i, 0, sz){
            if(stc[i] != 'A') ans++;
        }
        cout << ans << endl;

    }
    
    return 0;
}