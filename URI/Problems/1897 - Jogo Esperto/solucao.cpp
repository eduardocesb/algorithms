#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 100000010
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
#define MAXN 101010
#define MAXL 23
#define endl '\n'

using namespace std;

int N, M;

int solve()
{
    unordered_map<int, int> dist;

    queue<int> fila;

    fila.push(N);
    dist[N] = 0;

    while (!fila.empty())
    {
        int current = fila.front();
        fila.pop();

        if(current == M) return dist[current];

        if (!dist.count(2 * current))
        {
            dist[2 * current] = dist[current] + 1;
            fila.push(2 * current);
        }

        if (!dist.count(current / 2))
        {
            dist[current / 2] = dist[current] + 1;
            fila.push(current / 2);
        }

        if (!dist.count(3 * current))
        {
            dist[3 * current] = dist[current] + 1;
            fila.push(3 * current);
        }

        if (!dist.count(current / 3))
        {
            dist[current / 3] = dist[current] + 1;
            fila.push(current / 3);
        }

        if (!dist.count(current + 7))
        {
            dist[current + 7] = dist[current] + 1;
            fila.push(current + 7);
        }

        if (!dist.count(current - 7))
        {
            dist[current - 7] = dist[current] + 1;
            fila.push(current - 7);
        }
    }

    return INF;
}

int main(int argc, char** argv)
{
	optimize;

    cin >> N >> M;

    cout << solve() << endl;

	return 0;
}