#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/arc150/tasks/arc150_a

int main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        string s; cin >> s;
        int l = -1, r = -1;
        rep(i, 0, n){
            if(s[i] == '1' and l < 0) l = i;
            if(s[i] == '1') r = i; 
        }

        bool f = true;

        if(l >= 0){
            bool f1 = true;
            rep(j, l, r+1){
                if(s[j] == '0'){
                    f1 = false;
                }
            }
            bool f2 = true;
            if(r-l+1 < k){                
                int L = l, R = r;
                while(L-1 >= 0 and s[L-1] == '?') L--;
                while(R+1 < n and s[R+1] == '?') R++;
                f2 = (R-L+1 == k) or (R-L+1 > k and (l==L or R==r));
            }else if(r-l+1 > k){
                f2 = false;
            }
            f = f1 and f2;
        }else{
            int cnt = 0, num = 0;
            rep(i, 0, n){
                cnt = 0;
                if(s[i] == '?'){
                    cnt++;
                    while(i+1 < n and (s[i+1] == '?')){
                        cnt++;
                        i++;
                    }
                }
                if(cnt > k)  num += 2;
                else if(cnt == k) num++;
            }
            f = (num==1);
        }

        if(f) cout << "Yes" << "\n";
        else cout << "No" << "\n";

    }
    
    return 0;
}