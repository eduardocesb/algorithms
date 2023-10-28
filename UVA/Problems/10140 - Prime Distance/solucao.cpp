#include "bits/stdc++.h"
#define f first
#define s second
#define pb push_back
#define sz(x) (int)(x).size()
#define ALL(x) x.begin(), x.end()
#define present(c, x) (c.find(x) != c.end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = sqrt(INT_MAX) + 69;
bool prime[N];
vector<int> all_primes;

void precal()
{
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;
    for (int i = 4; i < N; i += 2)
    {
        prime[i] = false;
    }

    int limit = sqrt(N) + 1;
    for (int i = 3; i <= limit; i += 2)
    {
        if (prime[i])
        {
            int count = (N - 1) / i;
            int product = count * i;
            for (; count >= i; --count, product -= i)
            {
                if (prime[count])
                    prime[product] = false;
            }
        }
    }

    all_primes.pb(2);
    for (int i = 3; i < N; i += 2)
        if (prime[i])
            all_primes.pb(i);
}

bool isPrime(int x)
{
    if (x < N)
        return prime[x];
    for (int i = 0; i < sz(all_primes) && all_primes[i] < x; ++i)
    {
        if (x % all_primes[i] == 0)
            return false;
    }
    return true;
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    precal();

    int l, r;
    while (cin >> l >> r)
    {
        int last = -1;
        array<ll, 2> a = {-1, 2000000}, b = {0, 0};

        for (ll i = l; i <= r; ++i)
        {
            if (isPrime(i))
            {
                if (last != -1)
                {
                    ll dist = i - last;
                    if (a[1] - a[0] > dist)
                    {
                        a = {last, i};
                    }
                    if (b[1] - b[0] < dist)
                    {
                        b = {last, i};
                    }
                }

                last = i;
            }
        }

        if (a[0] == -1)
        {
            cout << "There are no adjacent primes.\n";
        }
        else
        {
            cout << a[0] << "," << a[1] << " are closest, " << b[0] << "," << b[1] << " are most distant.\n";
        }
    }
}