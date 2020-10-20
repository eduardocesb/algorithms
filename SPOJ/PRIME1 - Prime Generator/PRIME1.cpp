#include<bits/stdc++.h>
using namespace std;

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define ll long long
#define ld long double 

#define endl "\n"

#define MAXN 1000020

vector<ll>primos;
bool v[MAXN];

void crivo(ll n){
    n++;
    for(ll i=2;i<=n;i++){
        if(!v[i]){
            for(ll j=i*i;j<=n;j+=i){
                v[j] = true;
            }
            primos.push_back(i);
        }
    }
}

void imprimePrimos(ll l , ll r){

    l = max(2LL,l);
    for(ll i=l;i<=r;i++){
        bool composto = false;
        for(int j=0; primos[j]<=sqrt(i) ;j++){
            if( !(i%primos[j]) ){
                composto = true;
                break;
            }
        }
        if(!composto)
            cout << i << endl;
    }

}

int main(){

    v[0] = true;
    v[1] = true;
    v[2] = false;

    crivo(1000000LL);

    ll k;

    cin >> k;

    ll l,r;

    for(int i=0;i<k;i++){
        cin >> l >> r;

        imprimePrimos(l,r);

        if(i!=k-1)
            cout << endl;
    }

    return 0;
}