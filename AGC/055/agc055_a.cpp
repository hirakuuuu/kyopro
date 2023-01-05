#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/agc055/tasks/agc055_a

int main(){
    int n; cin >> n;
    string s; cin >> s;

    vector<vector<int>> cnt(3, vector<int>(3));
    rep(i, 0, 3){
        rep(j, i*n, (i+1)*n){
            cnt[i][s[j]-'A']++;
        }
    }

    vector<int> ans(3*n);
    vector<int> len(6, n);
    vector<string> tmp = {"ABC", "ACB", "BAC", "BCA", "CAB", "CBA"};
    rep(i, 0, 6){
        rep(j, 0, 3){
            chmin(len[i], cnt[j][tmp[i][j]-'A']);
        }

        rep(j, 0, 3){
            int l = len[i], pos = j*n;
            while(pos < (j+1)*n and l > 0){
                if(ans[pos] == 0 and s[pos] == tmp[i][j]){
                    ans[pos] = i+1;
                    l--;
                }
                pos++;
            }
        }
        rep(j, 0, 3){
            cnt[j][tmp[i][j]-'A'] -= len[i];
        }
    }

    rep(i, 0, 3*n) cout << ans[i];
    cout << endl;
    
    return 0;
}