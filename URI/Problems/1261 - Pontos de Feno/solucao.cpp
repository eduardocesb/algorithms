#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'

using namespace std;

int main()
{
    optimize;

    int N, M;

    cin >> N >> M;

    string palavra;

    map<string, int> valor;

    for (int i = 0, v; i < N; i++)
    {
        cin >> palavra >> v;

        valor[palavra] = v;
    }
  
    while (M--)
    {
        int ans = 0;
        
        while ((cin >> palavra) && palavra != ".")
            ans += valor[palavra];

        cout << ans << endl;
    }

    return 0;
}