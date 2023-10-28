#include <bits/stdc++.h> //DSU
using namespace std;

const int N = 100010;
int qnt, t, n;
int lv[N], pai[N], friends[N];
map<string, int> id;

int find(int x)
{
    if (x == pai[x])
        return x;
    return pai[x] = find(pai[x]);
}

void join(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return;
    if (lv[x] < lv[y])
        pai[x] = y;
    else if (lv[x] > lv[y])
        pai[y] = x;
    else
    {
        pai[x] = y;
        lv[y]++;
    }

    friends[y] += friends[x];
    friends[x] = friends[y];
}

void go(string name)
{
    if (id.count(name))
        return;
    id[name] = qnt;
    qnt++;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    cin >> t;
    while (t--)
    {
        cin >> n;

        for (int i = 0; i <= n; ++i)
            pai[i] = i, lv[i] = friends[i] = 1;

        id.clear();
        qnt = 1;

        string a, b;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a >> b;
            go(a);
            go(b);
            join(id[a], id[b]);
            int A = find(id[a]), B = find(id[b]);
            cout << max(friends[A], friends[B]) << "\n";
        }
    }
}