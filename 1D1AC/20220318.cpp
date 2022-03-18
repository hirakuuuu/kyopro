#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// https://atcoder.jp/contests/abc099/tasks/abc099_d
// int main(){
//     int n, c; cin >> n >> c;
//     vector<vector<int>> d(c, vector<int>(c));
//     rep(i, 0, c){
//         rep(j, 0, c) cin >> d[i][j];
//     }
//     vector<vector<int>> C(3, vector<int>(30));
    
//     rep(i, 0, n){
//         rep(j, 0, n){
//             int cc; cin >> cc;
//             C[(i+j)%3][cc-1]++;
//         }
//     }

//     vector<int> jun(c);
//     rep(i, 0, c){
//         if(i < 3) jun[i] = 3-i;
//         else jun[i] = 0;
//     }
//     reverse(jun.begin(), jun.end());
//     int ans = 1000000007;

//     do{
//         vector<int> selected(3);
//         rep(i, 0, c){
//             if(jun[i]) selected[jun[i]-1] = i;
//         }
//         int cost = 0;
//         rep(i, 0, 3){
//             rep(j, 0, c){
//                 if(selected[i] != j) cost += d[j][selected[i]]*C[i][j];
//             }
//         }
//         ans = min(ans, cost);
//     }while(next_permutation(jun.begin(), jun.end()));

//     cout << ans << endl;
// }

vector<ll> func(100005), inv(100005), func_inv(100005);

void func_init(){
    func[0] = func[1] = 1;
    inv[1] = 1;
    func_inv[0] = func_inv[1] = 1;
    rep(i, 2, 100004){
        func[i] = func[i-1]*i %MOD;
        inv[i] = MOD - inv[MOD%i]*(MOD/i)%MOD;
        func_inv[i] = func_inv[i-1]*inv[i]%MOD;
    }
}

ll nck(int n, int k){
    return func[n]*(func_inv[n-k]*func_inv[k]%MOD)%MOD;
}

int main(){
    int n, k; cin >> n >> k;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    sort(a.begin(), a.end());
    ll ans = 0;
    int M = k-1, m = n-k;
    func_init();
    rep(i, 0, n-k+1){
        ans = (ans+(a[M]-a[m])*nck(k-1+i, k-1))%MOD;
        M++;
        m--;
    }
    cout << ans << endl;

}