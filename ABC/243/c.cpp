#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;


int main(){
    int n; cin >> n;
    map<int, int> hy;
    vector<vector<pii>> y;
    y.push_back({});
    int cnt = 1;
    rep(i, 0, n){
        int X, Y; cin >> X >> Y;
        if(hy[Y] == 0){
            hy[Y] = cnt;
            cnt++;
        }
        y.push_back({});
        y[hy[Y]].push_back(make_pair(X, i));
    }
    string s; cin >> s;
    bool f = false;
    rep(i, 1, cnt+1){
        if(y[i].size() == 1) continue;
        sort(y[i].begin(), y[i].end());
        bool f1 = false, f2 = false;
        rep(j, 0, y[i].size()){
            if(!f1 and s[y[i][j].second] == 'R') f1 = true;
            if(f1 and !f2 and s[y[i][j].second] == 'L') f2 = true;
        }
        if(f2) f = true;
    }
    if(f) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
