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
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    ll n, a, b; cin >> n >> a >> b;
    string s; cin >> s;
    vector<int> cnt(2);
    rep(i, 0, 2*n){
        if(s[i] == '(') cnt[0]++;
        else cnt[1]++;
    }
    ll ans = 0;
    // 個数を合わせるためにabs(cnt[0]-cnt[1])回、操作２をやる必要がある
    // ( なら 左から、 ) なら右から
    int dif = abs(cnt[0]-cnt[1]);
    if(cnt[0] > cnt[1]){
        int id = 2*n-1;
        while(dif){
            if(s[id] == '('){
                s[id] = ')';
                ans += b;
                dif -= 2;
            }
            id--;
        }
    }else{
        int id = 0;
        while(dif){
            if(s[id] == ')'){
                s[id] = '(';
                ans += b;
                dif -= 2;
            }
            id++;
        }
    }
    // そのあとは操作１をコスト min(a, 2*b) でやる
    // 左と右から両方見て行って、正しいかっこ列になってないところを入れ替える
    int l = 0, r = 2*n;
    vector<int> acc_l(2*n+1), acc_r(2*n+1);
    while(l < r){
        while(l < 2*n && acc_l[l] >= 0){
            if(s[l] == '(') acc_l[l+1] = acc_l[l]+1;
            else acc_l[l+1] = acc_l[l]-1;
            l++;
        }
        while(r >= 1 && acc_r[r] >= 0){
            if(s[r-1] == ')') acc_r[r-1] = acc_r[r]+1;
            else acc_r[r-1] = acc_r[r]-1;
            r--;
        }
        if(l <= r){
            // cout << l << ' ' << r << endl;
            ans += min(a, 2*b);
            swap(s[l-1], s[r]);
            acc_l[l] += 2;
            acc_r[r] += 2;
        }else{
            break;
        }
    }
    cout << ans << endl;


    return 0;
}