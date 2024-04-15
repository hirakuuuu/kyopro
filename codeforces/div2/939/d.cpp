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
    int n; cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    int mx = -1, op = -1;
    rep(i, 0, 1<<n){
        // ビットが立っているところは操作する
        // ビットが連続している区間について、すべてが(区間の長さ)になるまで操作するのが最適
        int sum = 0;
        rep(j, 0, n){
            if((i>>j)&1){
                int l = j, r = j;
                while(r < n && (i>>r)&1) r++;
                sum += (r-l)*(r-l);
                j = r-1;
            }else{
                sum += a[j];
            }
        }
        if(sum > mx){
            mx = sum;
            op = i;
        }
    }
    // op に対する操作を考える
    vector<pair<int, int>> lr;
    auto dfs = [&](auto self, int l, int r) -> void{
        if(r-l == 1){
            if(a[l] != 0){
                lr.push_back({l, l});
                a[l] = 0;
            }
            return;
        }
        self(self, l, r-1);
        if(a[r-1] != r-l-1){
            lr.push_back({l, r-1});
            rep(i, l, r){
                a[i] = r-l-1;
            }
        }else{
            lr.push_back({l, r-2});
            rep(i, l, r-1){
                a[i] = r-l-1;
            }
        }
        self(self, l, r-1);
    };
    rep(i, 0, n){
        if((op>>i)&1){
            int l = i, r = i;
            while(r < n && (op>>r)&1) r++;
            // [l, r) に対して操作を行う
            // ハノイの塔みたいな感じ？
            // 再帰を使えば楽そう
            if(r-l == 1){
                if(a[l] == 0){
                    lr.push_back({l, l});
                }
            }else{
                dfs(dfs, l, r);
                lr.push_back({l, r-1});
                rep(j, l, r) a[j] = r-l;
            }
            i = r-1;
        }
    }
    cout << mx << ' ' << lr.size() << endl;
    for(auto [l, r]: lr){
        cout << l+1 << ' ' << r+1 << endl;
    }



    
    return 0;
}