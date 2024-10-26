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
    vector<string> a(3);
    rep(i, 0, 3) cin >> a[i];
    vector<int> sa(3);
    rep(i, 0, 3) sa[i] = (int)a[i].size();

    rep(i, 0, 3){
        int l = (i+1)%3, r = (i+2)%3;
        rep(_, 0, 2){
            vector<string> t;
            rep(j, 0, sa){
                // tmp := a[l][:j] + a[r] が作れるかを判定
                string tmp = a[l].substr(0, j)+a[r];
                bool ok = true;
                rep(k, j, sa){
                    if(a[k] != tmp[k]) {
                        if(tmp[k] == '?') tmp[k] = a[k];
                        else if(a[l][k] != '?') ok = false;
                    }
                }
                while(tmp.size() <)
                if(ok)
            }

            swap(a[l], a[r]);
        }

    }
    vector<string> ab;

    ab.push_back(a+b);
    
    return 0;
}