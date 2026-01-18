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
    int a, b; cin >> a >> b;
    string s; cin >> s;
    vector<int> pa, pb;
    rep(i, 0, n){
        if(s[i] == 'a') pa.push_back(i);
        else pb.push_back(i);
    }
    int id_a = 0, id_b = 0;
    ll ans = 0;
    rep(i, 0, n){
        if(id_a+a-1 < pa.size()){
            if(id_b+b-1 >= pb.size()){
                ans += n-pa[id_a+a-1];
            }else{
                ans += max(0LL, (ll)pb[id_b+b-1]-pa[id_a+a-1]);
            }
        }
        if(s[i] == 'a'){
            id_a++;
        }else{
            id_b++;
        }
    }
    cout << ans << endl;
    
    return 0;
}