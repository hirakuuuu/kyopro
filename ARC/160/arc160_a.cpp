#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/arc160/tasks/arc160_a

int main(){
    int n, k; cin >> n >> k; 
    int a[n];
    rep(i, 0, n) cin >> a[i];

    int s = 1, t = n*(n+1)/2;
    rep(i, 0, n){
        vector<int> large, small;
        rep(j, i+1, n){
            if(a[i] < a[j]) large.push_back(a[j]);
            if(a[i] > a[j]) small.push_back(a[j]);
        }
        int x = 0;
        if(k-s < small.size()){
            sort(small.begin(), small.end());
            x = small[k-s];
        }
        if(t-k < large.size()){
            sort(large.begin(), large.end());
            reverse(large.begin(), large.end());
            x = large[t-k];
        }

        if(x){
            int pos = 0;
            rep(j, 0, n){
                if(a[j] == x){
                    pos = j;
                    break;
                }
            }
            reverse(a+i, a+pos+1);
            break;
        }
        s += small.size();
        t -= large.size();
    }

    rep(i, 0, n) cout << a[i] << ' ';
    cout << endl;
    
    return 0;
}