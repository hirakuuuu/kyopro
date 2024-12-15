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


// 座標圧縮
void comp(vector<ll>&a){
  set<int>s(a.begin(),a.end());
  map<int,int>d;
  int cnt=0;
  for(auto x:s)d[x]=cnt++;
  for(auto&x:a)x=d[x];
}

int main(){
    int n; cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    vector<ll> acc(n+1);
    rep(i, 0, n) acc[i+1] = acc[i]+a[i];

    map<pair<int, int>, ll> memo;
    vector<int> mini(n), maxi(n);
    iota(mini.begin(), mini.end(), 0);
    iota(maxi.begin(), maxi.end(), 1);
    int mid = -1;
    auto f = [&](auto self, int l, int r) -> ll {
        l = mini[l], r = maxi[r-1];
        chmin(mini[mid], l), chmax(maxi[mid], r);
        if(memo.find({l, r}) != memo.end()) return memo[{l, r}];
        ll sum = acc[r]-acc[l];
        if(l != 0 && sum > a[l-1]) return memo[{l, r}] = self(self, l-1, r);
        if(r != n && sum > a[r]) return memo[{l, r}] = self(self, l, r+1);
        return memo[{l, r}] = sum;
    };

    vector<ll> id = a;
    comp(id);
    int m = (*max_element(id.begin(), id.end()))+1;
    vector<vector<int>> pos(m);
    rep(i, 0, n) pos[id[i]].push_back(i);

    set<int> s;
    s.insert(-1), s.insert(n);
    vector<ll> ans(n);

    rrep(i, m-1, 0){
        for(auto pp: pos[i]){
            s.insert(pp);
        }
        for(auto pp: pos[i]){
            auto itr = s.find(pp);
            auto l = *prev(itr);
            auto r = *next(itr);
            mid = pp;
            ans[pp] = f(f, l+1, r);
        }
    }

    rep(i, 0, n){
        cout << ans[i] << ' ';
    }
    cout << endl;




    return 0;
}