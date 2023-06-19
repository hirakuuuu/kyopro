#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/arc162/tasks/arc162_b

int main(){
    int n; cin >> n;
    vector<int> p(n);
    rep(i, 0, n){
        cin >> p[i];
        p[i]--;
    }

    vector<pii> ans;
    rep(i, 0, n-2){
        if(i == p[i]) continue;

        int pos = -1;
        rep(j, i+1, n){
            if(p[j] == i){
                pos = j;
                break;
            }
        }
        if(pos == n-1){
            ans.push_back({n-2, n-2});
            swap(p[n-3], p[n-1]);
            swap(p[n-2], p[n-1]);
            pos = n-3;
        }
        ans.push_back({pos+1, i});
        int p1 = p[pos], p2 = p[pos+1];
        vector<int> q = p;
        rep(j, i, pos){
            p[j+2] = q[j];
        }
        p[i] = p1;
        p[i+1] = p2;
    }

    bool f = true;
    rep(i, 0, n){
        f &= (p[i] == i);
    }

    if(f){
        cout << "Yes" << endl;
        cout << ans.size() << endl;
        for(auto a: ans){
            cout << a.first << ' ' << a.second << endl;
        }
    }else{
        cout << "No" << endl;
    }


    
    return 0;
}