#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 2000000020LL
#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define REP(i, a, b) for(int i = (a); i <= (b); i++)
#define POS(n, x) (lower_bound(ALL(n), x) - (n).begin())
#define ll long long
#define ld long double
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define PB push_back
#define EB emplace_back
#define MOD 1000000007
#define PRIME 101 
#define MAXN 200020
#define MAXL 23
#define endl '\n'

using namespace std;

// (1 + sqrt(5)) / 2
const ld GOLDEN_RATIO = 1.6180339887498949025257388711906969547271728515625;
const ld PI = acos(-1.0);
const int BLOCK = 333;

ll nums[MAXN];

int main(int argc, char const *argv[])
{
	optimize;
	
    int N;

    cin >> N;

    for(int i = 0; i < N; i++)
        cin >> nums[i];

    if(N % 2 == 0)
    {
        cout << "1 1" << endl;
        cout << -nums[0] << endl;

        nums[0] = 0;

        cout << "2 " << N << endl;

        ll tam = N - 1;

        for(int i = 1; i < N; i++)
        {
            ll resto = nums[i] % N;

            cout << (tam * resto) << " ";

            nums[i] += tam * resto;
        }

        cout << endl;

        cout << "1 " << N << endl;

        for(int i = 0; i < N; i++)
            cout << -nums[i] << " ";
        cout << endl;
    }
    else
    {
        if(N == 1)
        {
            cout << "1 1" << endl;
            cout << 0 << endl;
            cout << "1 1" << endl;
            cout << 0 << endl;
            cout << "1 1" << endl;
            cout << -nums[0] << endl;
        }
        else
        {
            ll tam = N;

            cout << 1 << " " << N << endl;

            for(int i = 0; i < N; i++)
            {
                ll resto = (N - 1) - (nums[i] % (N - 1));

                nums[i] += (resto * tam);

                cout << (resto * tam) << " ";
            }

            cout << endl;

            cout << 2 << " " << N << endl;

            for(int i = 1; i < N; i++) 
                cout << -nums[i] << " ";

            cout << endl;

            cout << "1 1" << endl;
            cout << -nums[0] << endl;
        }
        
    }
    

	return 0;
}