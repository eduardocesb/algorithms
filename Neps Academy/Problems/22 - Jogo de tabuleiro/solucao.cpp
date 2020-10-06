#include <bits/stdc++.h>
#define INF 2000000020LL
#define ALL(x) x.begin(), x.end()
#define ll long long
#define ld long double
#define PB push_back
#define EB emplace_back
#define MAXN 2000020


using namespace std;

int main(int argc, char const *argv[]){
    int n;
    cin >> n;
    int tab [n+1][n+1];
    int b = 0, p = 0;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> tab[i][j];
        }
    }

    for (int i = 2; i <= n; i++){
        for (int j = 2; j <= n; j++){

            p = 0;
            b = 0;

            if (tab[i-1][j-1] == 1) p++;
            else b++;
            if (tab[i][j-1] == 1) p++;
            else b++;
            if (tab[i-1][j] == 1) p++;
            else b++;

            if (b < p) tab[i][j] = 0;
            else tab[i][j] = 1;
            
        }
    }

    cout << tab[n][n] << endl;

    return 0;
}