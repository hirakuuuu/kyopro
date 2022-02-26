#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;


int main(){
    int q; cin >> q;
    multiset<ll> ms;
    while(q--){
        int s; cin >> s;
        ll x; cin >> x;
        if(s == 1){
            ms.insert(x);
        }else if(s == 2){
            int k; cin >> k;
            k--;
            auto itr = ms.upper_bound(x);
            if(itr == ms.begin()){
                cout << -1 << endl;
                continue;
            }
            --itr;
            while(true){
                if(k and itr == ms.begin()){
                    cout << -1 << endl;
                    break;
                }else{
                    if(k == 0){
                        cout << *itr << endl;
                        break;
                    }
                    --itr;
                    k--;
                }
            }
        }else{
            int k; cin >> k;
            k--;
            auto itr = ms.lower_bound(x);
            while(true){
                if(k >= 0 and itr == ms.end()){
                    cout << -1 << endl;
                    break;
                }else{
                    if(k == 0){
                        cout << *itr << endl;
                        break;
                    }
                    ++itr;
                    k--;
                }
            }
        }
    }
}