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
    int n = 6, m = 5;
    vector<double> a(n);
    double sum_a = 0;
    rep(i, 0, n){
        cin >> a[i];
        sum_a += a[i];
    }

    vector<vector<int>> cnt;
    vector<int> tmp;
    auto f = [&](auto self, int pos, int sum) -> void {
        if(pos == n){
            cnt.push_back(tmp);
            return;
        }
        rep(i, 0, m+1){
            if(sum+i > m) break;
            tmp.push_back(i);
            self(self, pos+1, sum+i);
            tmp.pop_back();
        }
    };
    f(f, 0, 0);

    int k = (int)cnt.size();
    vector<double> dp(k);
    rep(i, 0, k){
        int sum = 0;
        rep(j, 0, n){
            sum += cnt[i][j];
        }
        double rest = (double)(m-sum)/n;
        rep(x, 0, n){
            int cur = 0, cur2 = 0;
            rep(j, 0, n){
                if(a[j] == a[x]){
                    cur2++;
                    cur += cnt[i][j];
                }
            }
            chmax(dp[i], ((double)cur+rest*cur2)*a[x]);
        }
    }
    // cout << dp[0] << endl;

    rep(_, 0, 2){
        vector<double> dp2(k);
        rep(i, 0, k){
            vector<int> tmp2;
            rep(j, 0, k){
                int sum2 = 0;
                rep(l, 0, n){
                    sum2 += cnt[j][l];
                    if(cnt[i][l] <= cnt[j][l]) continue;
                    sum2 = -1;
                    break;
                }
                if(sum2 == m){
                    tmp2.push_back(j);
                    // rep(l, 0, n){
                    //     cout << cnt[j][l] << ' ';
                    // }
                    // cout << endl;
                }
            }
            int sz = (int)tmp2.size();
            cout << sz << endl;

            rep(j, 0, sz){
                double mx = 0;
                rep(l, 0, k){
                    bool ok = true;
                    rep(ii, 0, n){
                        if(cnt[i][ii] <= cnt[l][ii] && cnt[l][ii] <= cnt[tmp2[j]][ii]) continue;
                        ok = false;
                        break;
                    }
                    if(ok){
                        chmax(mx, dp[l]);
                    }
                }
                dp2[i] += mx;
            }
            dp2[i] /= (double)sz;
        }
        swap(dp2, dp);
    }
    cout << dp[0] << endl;



    return 0;
}