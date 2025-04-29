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
    int QCOUNT = 2*n;
    map<pair<int, int>, ll> memo;
    auto query = [&](int s, int t) -> ll {
        if(memo.count({s, t})) return memo[{s, t}];
        assert(QCOUNT >= 1);
        QCOUNT--;
        cout << "? " << s << ' ' << t << endl;
        ll res; cin >> res;
        return memo[{s, t}] = memo[{t, s}] = res;
    };

    // (1, 2) を聞く
    // 2(n-2) 回，(1, i) と (2, i) を聞く (i >= 3)
    // この結果から p が特定できる
    ll thl = query(1, 2);
    vector<int> left;
    vector<int> mid;
    vector<int> right;
    rep(i, 3, n+1){
        ll ans1 = query(1, i);
        ll ans2 = query(2, i);
        if(max(ans1, ans2) < thl){
            mid.push_back(i);
        }else if(ans1 > ans2){
            right.push_back(i);
        }else{
            left.push_back(i);
        }
    }
    sort(left.begin(), left.end(), [&](auto i, auto j){
        return memo[{1, i}] > memo[{1, j}] ;
    });
    sort(mid.begin(), mid.end(), [&](auto i, auto j){
        return memo[{1, i}] < memo[{1, j}] ;
    });
    sort(right.begin(), right.end(), [&](auto i, auto j){
        return memo[{1, i}] < memo[{1, j}] ;
    });
    vector<int> rev;
    for(auto l: left) rev.push_back(l);
    rev.push_back(1);
    for(auto m: mid) rev.push_back(m);
    rev.push_back(2);
    for(auto r: right) rev.push_back(r);

    vector<int> p(n+1);
    rep(i, 0, n) p[rev[i]] = i+1;


    
    map<pair<int, int>, ll> real;
    for(auto [key, val]: memo){
        auto [s, t] = key;
        real[{p[s], p[t]}] = real[{p[t], p[s]}] = val;
    }
    swap(real, memo);

    // rep(i, 1, n+1) rep(j, 1, n+1){
    //     cout << i << ' ' << j << ' ' << memo[{i, j}] << endl;
    // }
    vector<ll> a(n+1);
    if(p[1] >= 3) a[1] = memo[{1, p[1]}]-memo[{2, p[1]}];
    else if(p[2] >= 3) a[1] = memo[{1, p[2]}]-memo[{2, p[2]}];
    else a[1] = memo[{1, 3}]-memo[{2, 3}];
    ll acc = a[1];
    rep(i, 2, n+1){
        ll tmp = 0;
        if(p[1] == i){
            tmp = memo[{1, p[1]}];
        }else if(p[1] == i+1){
            tmp = memo[{1, p[2]}]-thl;
        }else if(p[1] < i){
            tmp = memo[{1, p[2]}]-thl+memo[{p[1], i}];
        }else{
            tmp = memo[{1, p[1]}]-memo[{p[1], i+1}];
        }

        a[i] = tmp-acc;
        acc += a[i];
    }

    cout << "! ";
    rep(i, 1, n+1) cout << p[i] << ' ';
    rep(i, 1, n+1) cout << a[i] << ' ';
    cout << endl;    
    
    return 0;
}

