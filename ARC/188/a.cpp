#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}


int main(){

    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<int> qcnt(n+1);
    rep(i, 0, n){
        qcnt[i+1] = qcnt[i];
        if(s[i] == '?') qcnt[i+1]++;
    }
    if(k == 0){
        cout << mint(3).pow(qcnt[n]).val() << endl;
        return 0;
    }
    // 0: 0 or 7,  1: 1 or 6,  2: 2 or 5,  3: 3 or 4; 
    vector<vector<map<vector<int>, mint>>> dp(k, vector<map<vector<int>, mint>>(4));
    dp[0][0][{0, 0, 0}] = 1;
    mint ans = 0;
    rep(i, 0, n){
        vector<vector<map<vector<int>, mint>>> ndp(k, vector<map<vector<int>, mint>>(4));
        if(s[i] == 'A' || s[i] == '?'){
            rep(l, 0, k){
                rep(j, 0, 4){
                    for(auto [vec, val]: dp[l][j]){
                        if(val == 0) continue;
                        int same = 0;
                        if((j^1) == 0) same++;
                        vector<int> nvec = vec;
                        if(j != 2){
                            same += vec[(j^1)];
                            nvec[(j^1)]++;
                        }else same += i-(vec[0]+vec[1]+vec[2]);

                        if(l+same >= k) ans += val*mint(3).pow(qcnt[n]-qcnt[i+1]);
                        else ndp[l+same][j^1][nvec] += val;
                    }
                }
            }
        }

        if(s[i] == 'B' || s[i] == '?'){
            rep(l, 0, k){
                rep(j, 0, 4){
                    for(auto [vec, val]: dp[l][j]){
                        if(val == 0) continue;
                        int same = 0;
                        if((j^2) == 0) same++;
                        vector<int> nvec = vec;
                        if(j != 1){
                            same += vec[(j^2)];
                            nvec[(j^2)]++;
                        }else same += i-(vec[0]+vec[1]+vec[2]);
                        if(l+same >= k) ans += val*mint(3).pow(qcnt[n]-qcnt[i+1]);
                        else ndp[l+same][j^2][nvec] += val;
                    }
                }
            }
        }

        if(s[i] == 'C' || s[i] == '?'){
            rep(l, 0, k){
                rep(j, 0, 4){
                    for(auto [vec, val]: dp[l][j]){
                        if(val == 0) continue;
                        int same = 0;
                        if((j^3) == 0) same++;
                        vector<int> nvec = vec;
                        if(j != 0){
                            same += vec[(j^3)];
                            nvec[(j^3)]++;
                        }else same += i-(vec[0]+vec[1]+vec[2]);
                        if(l+same >= k) ans += val*mint(3).pow(qcnt[n]-qcnt[i+1]);
                        else ndp[l+same][j^3][nvec] += val;
                    }
                }
            }
        }

        swap(dp, ndp);
    }
    cout << ans.val() << endl;
    
    return 0;
}