#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define pii pair<int,int>
#define INF 2000000020
#define MAXN 2000020

using namespace std;

template <class T, class C = std::less<T>>
struct MaxQueue {
  MaxQueue() {
    clear();
  }

  void clear() {
    id = 0;
    q.clear();
  }

  void push(T x) {
    std::pair<int, T> nxt(1, x);
    while(q.size() > id && cmp(q.back().second, x)) {
      nxt.first += q.back().first;
      q.pop_back();
    }
    q.push_back(nxt);
  }

  T qry() {
    return q[id].second;
  }

  void pop() {
    q[id].first--;
    if(q[id].first == 0) {
      id++;
    }
  }
private:
  std::vector<std::pair<int, T>> q;
  int id;
  C cmp;
};

ll nums[MAXN], sum[MAXN], blocos[MAXN], N, P;
int D;

ll query(int i, int j)
{
	return sum[j] - sum[i - 1];
}

MaxQueue<ll> fila;

bool ok(int i, int j)
{
	return (query(i, j) - (ll)fila.qry()) <= P;
}

void add(ll x)
{
	fila.push(x);
}

void remove()
{
	fila.pop();
}

int main(int argc, char const *argv[])
{
	optimize;

	cin >> N >> P >> D;

	int ans = D;

	for(int i = 1; i <= N; i++)
	{
		cin >> nums[i];

		sum[i] = sum[i - 1] + nums[i];
	}

	int i = 1, j = D;

	add(query(1,  D));

	while(j <= N)
	{
		if(ok(i, j))
		{
			// cout << "OK: " << i << " " << j << endl;
			// cout << query(i , j) << " -- " << fila.qry() << endl;
			ans = max(ans, (j - i) + 1);
			j++;
			add(query(j - D + 1, j));
		}
		else
		{
			// cout << "REMOVE: " << i << " " << j << endl;
			remove();
			i++;
		}
	}

	cout << ans << endl;

	return 0;
}