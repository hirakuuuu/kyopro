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
    int h, w; cin >> h >> w;
    if(h == 1 && w == 1){
        cout << "! " << 1 << ' ' << 1 << endl;
        return 0;
    }

    cout << "? " << 1 << ' ' << 1 << endl;
    int d; cin >> d;
    set<pair<int, int>> s;
    {
        rep(i, 1, h+1) rep(j, 1, w+1){
            if((i-1)*(i-1)+(j-1)*(j-1) == d){
                s.insert({i, j});
            }
        }
            assert(!s.empty());
        if(s.size() == 1){
            cout << "! " << (*s.begin()).first << ' ' << (*s.begin()).second << endl;
            return 0;
        }
    }

    if(w > 1){
        cout << "? " << 1 << ' ' << w << endl;
        cin >> d;
        {
            set<pair<int, int>> s_;
            for(auto [i, j]: s){
                if((i-1)*(i-1)+(j-w)*(j-w) == d){
                    s_.insert({i, j});
                }
            }
            swap(s_, s);
            assert(!s.empty());
            if(s.size() == 1){
                cout << "! " << (*s.begin()).first << ' ' << (*s.begin()).second << endl;
                return 0;
            }
        }
    }


    if(h > 1){
        cout << "? " << h << ' ' << 1 << endl;
        cin >> d;
        {
            set<pair<int, int>> s_;
            for(auto [i, j]: s){
                if((i-h)*(i-h)+(j-1)*(j-1) == d){
                    s_.insert({i, j});
                }
            }
            swap(s_, s);
            assert(!s.empty());
            if(s.size() == 1){
                cout << "! " << (*s.begin()).first << ' ' << (*s.begin()).second << endl;
                return 0;
            }
        }
    }

    // // assert(s.size() == 2);
    // int i0 =  (*s.begin()).first, j0 = (*s.begin()).second;
    // s.erase(s.begin());
    // int i1 =  (*s.begin()).first, j1 = (*s.begin()).second;
    // cout << "? "  << i0 << ' ' << j0 << endl;
    // cin >> d;
    // if(d == 0){
    //     cout << "! " << i0 << ' ' << j0 << endl;
    // }else{
    //     cout << "! " << i1 << ' ' << j1 << endl;
    // }

    return 0;
}