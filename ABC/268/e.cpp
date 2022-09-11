#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc268/tasks/abc268_e

int main(){
    ll n; cin >> n;
    vector<ll> p(n), pos(n);
    rep(i, 0, n){
        cin >> p[i];
        pos[p[i]] = i;
    }

    if(n%2 == 0){
        ll plus = 0, minus = 0, cnt = 0;
        vector<ll> change(n);
        rep(i, 0, n){
            if(0 <= (pos[i]-i+n)%n and (pos[i]-i+n)%n < n/2){
                cnt += (pos[i]-i+n)%n;
                plus++;
                change[n/2 - (pos[i]-i+n)%n]--;
                change[(n-(pos[i]-i+n)%n)%n]++;
            }else{
                cnt += n-(pos[i]-i+n)%n;
                minus++;
                change[n - (pos[i]-i+n)%n]++;
                change[(3*n/2-(pos[i]-i+n)%n)%n]--;
            }
        }

        ll ans = (1LL<<60);
        rep(i, 0, n){
            ans = min(cnt, ans);
            cnt += plus;
            cnt -= minus;
            plus += change[(i+1)%n];
            minus -= change[(i+1)%n];
        }

        cout << ans << endl;
    }else{
        ll plus = 0, minus = 0, cnt = 0;
        vector<ll> change_p(n), change_m(n);
        rep(i, 0, n){
            if(0 <= (pos[i]-i+n)%n and (pos[i]-i+n)%n < n/2){
                cnt += (pos[i]-i+n)%n;
                plus++;
                change_p[n/2 - (pos[i]-i+n)%n]--;
                change_m[(n/2-(pos[i]-i+n)%n+1)%n]++;
                change_m[(n-(pos[i]-i+n)%n)%n]--;
                change_p[(n-(pos[i]-i+n)%n)%n]++;
            }else if((pos[i]-i+n)%n == n/2){
                cnt += (pos[i]-i+n)%n;
                change_m[1]++;
                change_p[n/2+1]++;
                change_m[n/2+1]--;
                change_p[0]--;
            }else{
                cnt += n-(pos[i]-i+n)%n;
                minus++;
                change_p[n-(pos[i]-i+n)%n]++;
                change_m[n-(pos[i]-i+n)%n]--;
                change_p[((n-(pos[i]-i+n)%n)%n+n/2)%n]--;
                change_m[((n-(pos[i]-i+n)%n)%n+n/2+1)%n]++;
            }
        }

        ll ans = (1LL<<60);
        rep(i, 0, n){
            ans = min(cnt, ans);
            cnt += plus;
            cnt -= minus;
            plus += change_p[(i+1)%n];
            minus += change_m[(i+1)%n];
        }

        cout << ans << endl;

    }
    
    return 0;
}