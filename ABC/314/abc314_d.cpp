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
// https://atcoder.jp/contests/abc314/tasks/abc314_d

int main(){
    int n; cin >> n;
    string s; cin >> s;
    int q; cin >> q;


    vector<tuple<int, int, char>> queri(q);
    rep(i, 0, q){
        int t, x;
        char c;
        cin >> t >> x >> c;
        x--;
        queri[q-i-1] = {t, x, c};
    }

    string ans = s;
    vector<bool> seen(n);
    int tmp = 0;
    int pos = 0;
    rep(i, 0, q){
        const auto [t, x, c] = queri[pos];

        if(t == 1 && !seen[x]){
            ans[x] = c;
            seen[x] = true;
        }else if(t != 1){
            tmp = t;
            break;
        }
        pos = i;
    }

    rep(i, pos, q){
        const auto [t, x, c] = queri[i];

        if(t == 1 && !seen[x]){
            ans[x] = c;
            seen[x] = true;

            if(tmp == 2){
                if(ans[x]>='A'&&ans[x]<='Z') ans[x] += 32;
            }else if(tmp == 3){
                if(ans[x]>='a'&&ans[x]<='z') ans[x] -= 32;
            }
        }
    }

    rep(i, 0, n){
        if(!seen[i]){
            ans[i] = s[i];
            if(tmp == 2){
                if(ans[i]>=65&&ans[i]<=90) ans[i] += 32;
            }else if(tmp == 3){
                if(ans[i]>=97&&ans[i]<=122) ans[i] -= 32;
            }
        }
    }

    for(auto aa: ans){
        cout << aa;
    }
    cout << endl;





    
    return 0;
}