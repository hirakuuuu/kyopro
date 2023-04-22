#include <iostream>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

class A {
    public:
    A() {
        cout << "a";
    }
    ~A() {
        cout << "b";
    }

    void dosomething() {
        cout << "c";
    }
};

class B : public A {
public: 
    B() {}
    ~B() {}
    void dosomething() {
        cout << "d";
    }
};

void update(int a, int& b, int* c){
    a++; b++; (*c)++;
}

int main(){
    int a = 1, b = 1, c = 1;
    update(a, b, &c);

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    putchar(10);

    
    return 0;
}