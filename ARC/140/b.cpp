#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/arc140/tasks/arc140_b

int main(){
    int n; cin >> n;
    string s; cin >> s;

    multiset<int> r;
    rep(i, 0, n){
        if(s[i] == 'R'){
            int a = i-1, c = i+1;
            while(0 <= a and s[a] == 'A') a--;
            while(c < n and s[c] == 'C') c++;
            int cnt = min((i-1)-a, c-(i+1));
            if(cnt > 0) r.insert(cnt);
        }
    }

    int ans = 0, i = 1;
    while(true){
        if(r.size() == 0) break;
        if(i%2){
            auto itr = r.end();
            --itr;
            int num = *itr;
            num--;
            r.erase(itr);
            if(num) r.insert(num);
        }else{
            r.erase(r.begin());
        }
        ans++;
        i++;
    }
    cout << ans << endl;
    
    return 0;
}