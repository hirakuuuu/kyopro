#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

int minus_(int i){
    if(i == 0) return 2;
    if(i == 1) return 1;
    return 0;
}

int plus_(int i, int j){
    if(i == 2 or j == 2) return 2;
    if(i == 1 or j == 1) return 1;
    return 0;
}

int multi(int i, int j){
    if(i == 0 or j == 0) return 0;
    if(i == 1 or j == 1) return 1;
    return 2;
}

int main(){
    vector<int> p = {0, 1, 2};
    vector<int> q = {0, 1, 2};
    vector<int> r = {0, 1, 2};
    map<char, int> mp;
    while(true){
        string s; cin >> s;
        if(s == ".") break;
        int cnt = 0;
        rep(i, 0, 3){
            rep(j, 0, 3){
                rep(k, 0, 3){
                    stack<char> stc_c;
                    stack<int> stc_i;
                    mp['P'] = p[i];
                    mp['Q'] = q[j];
                    mp['R'] = r[k];
                    rep(l, 0, s.size()){
                        if(s[l] == '*' or s[l] == '+' or s[l] == '('){
                            stc_c.push(s[l]);
                        }else if(s[l] == ')'){
                            char enzansi = stc_c.top(); stc_c.pop();
                            int n1 = stc_i.top(); stc_i.pop();
                            int n2 = stc_i.top(); stc_i.pop();
                            if(enzansi == '+'){
                                stc_i.push(plus_(n1, n2));
                            }else{
                                stc_i.push(multi(n1, n2));
                            }
                            stc_c.pop();
                            if(stc_c.size() and stc_c.top() == '-'){
                                int stc_i_top = stc_i.top(); stc_i.pop();
                                stc_i.push(minus_(stc_i_top));
                                stc_c.pop();
                            }
                        }else if(s[l] == '-'){
                            if(stc_c.size() and stc_c.top() == '-') stc_c.pop();
                            else stc_c.push('-');
                        }else{
                            int value = s[l]-'0';
                            if(value < 0 or 2 < value){
                                value = mp[s[l]];
                            }
                            if(stc_c.size() and stc_c.top() == '-'){
                                stc_c.pop();
                                value = minus_(value);
                            }
                            stc_i.push(value);
                        }
                    }
        
   
                    if(stc_i.top() == 2) cnt++;
                }
            }
        }
        cout << cnt << endl;
    }
    
    return 0;
}