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
    vector<int> a(2*n);
    rep(i, 0, 2*n) cin >> a[i];

    vector<tuple<int, int, int>> x(n);
    rep(i, 0, n){
        x[i] = {a[i], a[i+n], i};
    }
    sort(x.begin(), x.end());
    vector<tuple<int, int, int>> mi = {x[0]};
    int l;
    {
        auto [x1, x2, id] = mi[0];
        l = id+1;
    }
    rep(i, 1, n){
        auto [x1, x2, id] = x[i];
        if(id < l) continue;
        l = id+1;
        mi.push_back(x[i]);
    }

    for(auto [x1, x2, id]: mi){
        cout << x1 <<' ' << x2 << ' ' << id << endl;;
    }

    vector<int> ans1, ans2;
    int f = 0;
    for(auto [x1, x2, _]: mi){
        if(ans1.empty()){
            ans1.push_back(x1);
            ans2.push_back(x2);
        }else{
        cout << x1 <<' ' << ans2[0] << endl;

            if(ans2[0] < x1){
                break;
            }else if(ans2[0] > x1){
                ans1.push_back(x1);
                if(f == 0 && ans2.back() > x2) f = 2;
                if(f == 0 && ans2.back() < x2) f = 1;
                ans2.push_back(x2);
            }else{
                if(f != 1) break;
                ans1.push_back(x1);
                ans1.push_back(x2);
            }
        }
    }

    for(auto a1: ans1) cout << a1 << ' ';
    for(auto a2: ans2) cout << a2 << ' ';
    cout << endl;
    
    return 0;
}