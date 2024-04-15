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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

ll power(ll a, ll b, ll m=MOD){
    ll res = 1;
    while(b > 0){
        if(b%2 == 1) res = res*a%m;
        a = a*a%m;
        b /= 2;
    }
    return res;
}

int main(){
    vector<vector<ll>> a(3, vector<ll>(3));
    rep(i, 0, 3){
        rep(j, 0, 3){
            cin >> a[i][j];
        }
    }

    vector<vector<int>> b(3, vector<int>(3, -1));
    auto judge = [&]() -> int{
        rep(i, 0, 3){
            set<int> s;
            rep(j, 0, 3){
                s.insert(b[i][j]);
            }
            if(s.size() == 1 && *s.begin() != -1) return *s.begin();
        }
        rep(i, 0, 3){
            set<int> s;
            rep(j, 0, 3){
                s.insert(b[j][i]);
            }
            if(s.size() == 1 && *s.begin() != -1) return *s.begin();
        }
        set<int> s;
        rep(i, 0, 3){
            s.insert(b[i][i]);
        }
        if(s.size() == 1 && *s.begin() != -1) return *s.begin();
        s.clear();
        rep(i, 0, 3){
            s.insert(b[2-i][i]);
        }
        if(s.size() == 1 && *s.begin() != -1) return *s.begin();
        return -1;
    };
    auto f = [&](auto self, int cnt) -> int {
        if(cnt == 9){
            ll st = 0, sa = 0;
            rep(i, 0, 3){
                rep(j, 0, 3){
                    if(b[i][j] == 0) st += a[i][j];
                    else sa += a[i][j];
                }
            }
            if(st > sa) return 0;
            return 1;
        }
        bool ff = false;
        bool ft = false, fa = false;
        rep(i, 0, 3){
            rep(j, 0, 3){
                if(b[i][j] == -1){
                    b[i][j] = cnt%2;
                    if(judge() == cnt%2){
                        ff = true;
                    }else{
                        int tmp = self(self, cnt+1);
                        if(tmp == cnt%2){
                            if(cnt%2 == 0) ft = true;
                            else fa = true;
                        }
                    }
                    b[i][j] = -1;
                }
            }
        }
        if(ff) return cnt%2;
        if(cnt%2 == 0 && ft) return 0;
        if(cnt%2 == 1 && fa) return 1;
        return 1-cnt%2;

    };  

    if(f(f, 0) == 0) cout << "Takahashi" << endl;
    else cout << "Aoki" << endl;
    
    return 0;
}