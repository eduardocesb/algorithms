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
#define MAXN 2000020
#define MAXL 23
#define endl '\n'

using namespace std;

const ld PI = acos(-1.0);
const int BLOCK = 333;

int freq[3];

int main(int argc, char const *argv[])
{
	optimize;

    int N, P, M, x;

    cin >> N;
	
    for(int i = 0; i < N; i++)
    {
        cin >> x;

        freq[x]++;
    }

    cin >> P >> M;

    cout << (P >= freq[1] && M >= freq[2] ? 'S' : 'N') << endl;

	return 0;
}