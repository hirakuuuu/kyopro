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
    vector<int> a(n), b(n);
    vector<ll> c(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];
    rep(i, 0, n) cin >> c[i];

    vecotr<int> ind(n);
    iota(ind.begin(), ind.end(), 0);
    sort(ind.begin(), ind.end(), [&](auto i, auto j){
        return c[i] < c[j];
    });

    ll lsum = 0, rsum = 0;
    vector<
    rep(i, 0, n){
        if(a[i] == 1 && b[i] == 1){
            lsum += c[ind[i]];
        }else if(a[i] == 1 && b[i] == 0){
            lsum += c[ind[i]];
        }else if(a[i] == 0 && b[i] == 1){
            rsum += c[ind[i]];
        }
    }
    
    vector<vector<int>> pos(4);
    rep(i, 0, n){
        if(a[i] == 1 && b[i] == 1){
            pos[3].push_back(i);
        }else if(a[i] == 1 && b[i] == 0){
            pos[1].push_back(i);
        }else if(a[i] == 0 && b[i] == 1){
            pos[2].push_back(i);
        }
    }
    ll ans = 0, len = 0;
    vector<ll> sum(4);
    sort(pos[1].begin(), pos[1].end(), [&](auto i, auto j){
        return c[i] > c[j];
    });
    rep(i, 0, (int)pos[1].size()){
        sum[1] += c[pos[1][i]];
        len++;
        ans += c[pos[1][i]]*i;
    }

    sort(pos[2].begin(), pos[2].end(), [&](auto i, auto j){
        return c[i] < c[j];
    });
    rep(i, 0, (int)pos[2].size()){
        sum[2] += c[pos[2][i]];
        len++;
        ans += c[pos[2][i]]*((int)pos[2].size()-i);
    }


    sort(pos[3].begin(), pos[3].end(), [&](auto i, auto j){
        return c[i] > c[j];
    });
    rep(i, 0, (int)pos[3].size()){
        sum[3] += c[pos[3][i]];
    }
    // cout << ans << endl;
    int pl = 0, pr = (int)pos[2].size()-1;
    rep(i, 0, (int)pos[3].size()){
        // cout << c[pos[3][i]] << endl;
        // sum を更新
        while(pl < (int)pos[1].size() && c[pos[1][pl]] >= c[pos[3][i]]){
            // cout << "###" << c[pos[1][pl]] << endl;

            sum[1] -= c[pos[1][pl]];
            pl++;
        }
        while(pr >= 0 && c[pos[2][pr]] >= c[pos[3][i]]){
            sum[2] -= c[pos[2][pr]];
            pr--;
        }
        // cout << sum[1] << ' ' << sum[2] << ' ' << sum[3] << endl;
        // cout << pl << ' ' << (int)pos[2].size()-pr << endl;

        // cout << c[pos[3][i]]*len  << ' ' <<   (sum[1]+sum[2]+sum[3])+c[pos[3][i]]*pl+c[pos[3][i]]*((int)pos[2].size()-pr-1) << endl;
        if(c[pos[3][i]]*len >= (sum[1]+sum[2])+(sum[3]-c[pos[3][i]])*2+c[pos[3][i]]*pl+c[pos[3][i]]*((int)pos[2].size()-pr)){
            ans += (sum[1]+sum[2])+(sum[3]-c[pos[3][i]])*2+c[pos[3][i]]*pl+c[pos[3][i]]*((int)pos[2].size()-pr);
            sum[3] -= c[pos[3][i]];
            len += 2;
            // cout << ans << endl;
        }else{
            ans += c[pos[3][i]]*len;
            // cout << len << endl;
            // cout << ans << endl;
        }
    }
    cout << ans << endl;
    return 0;
}