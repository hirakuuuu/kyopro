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
    int n, m; cin >> n >> m;
    vector<string> s(n);
    rep(i, 0, n){
        cin >> s[i];
    }
    
    vector<int> score(n);
    rep(i, 0, m){
        int cnt0 = 0;
        rep(j, 0, n){
            if(s[j][i] == '0') cnt0++;
        }
        if((n+1)/2 > cnt0){
            rep(j, 0, n){
                if(s[j][i] == '0') score[j]++;
            }
        }else{
            rep(j, 0, n){
                if(s[j][i] == '1') score[j]++;
            }
        }
    }

    int mx = 0;
    rep(i, 0, n) chmax(mx, score[i]);
    rep(i, 0, n){
        if(score[i] == mx){
            cout << i+1 << ' ';
        }
    }
    cout << endl;
    return 0;
}