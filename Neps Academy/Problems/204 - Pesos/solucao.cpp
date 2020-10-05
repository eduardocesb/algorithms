#include <bits/stdc++.h>
#define INF 2000000020LL
#define ALL(x) x.begin(), x.end()
#define ll long long
#define ld long double
#define PB push_back
#define EB emplace_back
#define MAXN 2000020

using namespace std;

int pesos [100005];
int n;

bool elevador (int num) {
    
    if (num >= (n-1)) return true;
    else {
        if (pesos[num+1] - pesos[num] <= 8) return elevador (num+1);
        else return false;
    }
}

int main(int argc, char const *argv[]){
    
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> pesos[i];
    }

    if (pesos[0] > 8) {
        cout << 'N' << endl; 
        return 0;
    }

    if (elevador(0)) cout << 'S' << endl;
    else cout << 'N' << endl; 
    
    return 0;
}