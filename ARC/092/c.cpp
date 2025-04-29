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
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    
    // a の最大値にするのは可能
    ll mx = -INF, mxi = 0;
    rep(i, 0, n){
        if(mx < a[i]){
            mx = a[i];
            mxi = i;
        }
    }
    ll ans = mx;
    vector<int> ans_op;
    rep(i, 0, mxi) ans_op.push_back(0);
    rep(i, 0, n-mxi-1) ans_op.push_back(n-mxi-1-i);
    

    // index の偶奇が等しいところしかまとめられない
    // 負の値は足さないようにできる？
    rep(f, 0, 2){
        vector<ll> b = a;
        int tmp = f;
        vector<int> op;

        while(b.size() >= 3){
            ll mi = INF, mii = -1;
            rep(i, 0, b.size()){
                if(i%2 != tmp) continue;
                if(mi > b[i]){
                    mi = b[i];
                    mii = i;
                }
            }

            if(mi > 0){
                break;
            }
            if(mii == 0){
                b.erase(b.begin()+mii);
                tmp ^= 1;
            }else if(mii == (int)b.size()-1){
                b.erase(b.begin()+mii);
            }else{
                b[mii-1] += b[mii+1];
                b.erase(b.begin()+mii);
                b.erase(b.begin()+mii);
            }
            op.push_back(mii);
        }

        if(tmp == 1){
            b.erase(b.begin());
            op.push_back(0);
        }
        while(b.size() >= 3){
            b[0] += b[2];
            b.erase(b.begin()+1);
            b.erase(b.begin()+1);
            op.push_back(1);
        }
        if(b.size() >= 2){
            b.erase(b.begin()+1);
            op.push_back(1);
        }

        if(ans < b[0]){
            swap(ans, b[0]);
            swap(ans_op, op);
        }
    }

    cout << ans << endl;
    cout << ans_op.size() << endl;
    for(auto aa: ans_op){
        cout << aa+1 << endl;
    }
    return 0;
}