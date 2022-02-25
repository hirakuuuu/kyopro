#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

/*
区間スケジューリング　終了時刻の早いやつから順にこなしていくみたいな考え方
この問題では、右端がより左にあり、前回切った区間の右端より右にある区間から切るべき区間として追加していく
*/

int main(){
    int n, m; cin >> n >> m;
    vector<int> l(m), r(m);
    rep(i, 0, m){
        cin >> l[i] >> r[i];
    }

    // 区間の右端 r が小さい順に id を並び替える
    vector<int> ids(m);
    rep(i, 0, m) ids[i] = i;
    sort(ids.begin(), ids.end(), [&](int i, int j) {
        return r[i] < r[j];
    });

    int ans = 0;
    int last_r = 0;  // 前回の右端
    for (auto i: ids) {
        // 区間iの左端がlast_rの右側に含まれない場合はスキップ
        if (l[i] < last_r) continue;

        // 区間を採用
        ans++;
        last_r = r[i];
    }
    cout << ans << endl;
  
}