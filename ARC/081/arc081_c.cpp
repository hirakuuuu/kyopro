#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    string s; cin >> s;
    int n = (int)s.size();
    vector<vector<int>> pos(26);
    rep(i, 0, n){
        pos[s[i]-'a'].push_back(i);
    }
    int ok = 0, ng = n+1;
    while(ng-ok > 1){
        int mid = (ok+ng)/2;
        int tmp = -1;
        bool f = true;
        rep(i, 0, mid){
            int mx = 0;
            rep(j, 0, 26){
                auto itr = upper_bound(pos[j].begin(), pos[j].end(), tmp);
                if(itr == pos[j].end()){
                    f = false;
                    break;
                }
                chmax(mx, *itr);
            }
            if(!f) break;
            tmp = mx;
        }
        if(f) ok = mid;
        else ng = mid;
    }
    // 長さは ng 
    // cout << ng << endl;
    reverse(s.begin(), s.end());
    vector<vector<int>> rev(26);
    rep(i, 0, n){
        rev[s[i]-'a'].push_back(i);
    }
    vector<int> r;
    int tmp = -1;
    rep(i, 1, ng){
        int mx = 0;
        rep(j, 0, 26){
            auto itr = upper_bound(rev[j].begin(), rev[j].end(), tmp);
            chmax(mx, *itr);
        }
        tmp = mx;
        // cout << tmp << endl;
        r.push_back(n-1-tmp);
    }
    r.push_back(n);
    reverse(s.begin(), s.end());
    vector<vector<int>> cnt(n+1, vector<int>(26));
    rep(i, 0, n){
        cnt[i+1] = cnt[i];
        cnt[i+1][s[i]-'a']++;
    }
    sort(r.begin(), r.end());
    int l = -1;
    string ans;
    rep(i, 0, ng){
        // cout << l << ' ' << r[i] << endl;
        rep(j, 0, 26){
            if(cnt[r[i]][j]-cnt[l+1][j] == 0){
                ans += 'a'+j;
                auto itr = upper_bound(pos[j].begin(), pos[j].end(), l);
                if(itr == pos[j].end()) l = n;
                else l = *itr;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}