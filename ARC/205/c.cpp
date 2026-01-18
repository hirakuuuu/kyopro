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
    vector<int> s(n), t(n);
    vector<tuple<int, int, int, int>> e(n);
    rep(i, 0, n){
        cin >> s[i] >> t[i];
        if(s[i] < t[i]){
            e[i] = {s[i], t[i], 0, i};
        }else{
            e[i] = {t[i], s[i], 1, i};
        }
    }
    sort(e.begin(), e.end());
    int mx = 0;
    rep(i, 0, n){
        auto [l, r, _, __] = e[i];
        if(r < mx){
            cout << "No" << endl;
            return 0;
        }
        mx = r;
    }

    vector<int> p;
    int dir = -1;
    for(int i = 0; i < n;){
        auto [l, r, d, id] = e[i];
        dir = d;
        int j = i+1;
        vector<int> np = {id};
        while(j < n){
            auto [nl, nr, nd, nid] = e[j];
            if(r < nl) break; 
            if(nd != dir){
                cout << "No" << endl;
                return 0;
            }
            r = nr;
            np.push_back(nid);
            j++;
        }
        if(dir == 0) reverse(np.begin(), np.end());
        for(auto pp: np){
            p.push_back(pp);
        }
        i = j;
    }
    cout << "Yes" << endl;
    rep(i, 0, n){
        cout << p[i]+1 << ' ';
    }
    cout << endl;

    
    return 0;
}