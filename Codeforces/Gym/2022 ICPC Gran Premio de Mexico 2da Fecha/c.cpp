#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define os_type int
#define PB push_back
#define EB emplace_back
#define MOD 1000000007
#define PRIME 101 
#define MAXN 101010
#define MAXL 23
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>

int N, M;

map<int, unordered_set<int>> requested;

int main(int argc, char** argv)
{
    optimize;

    cin >> N >> M;

    for (int i = 0, id, cnt; i < N; i++)
    {
        cin >> id >> cnt;

        for (int j = 0, disciplina; j < cnt; j++)
        {
            cin >> disciplina;

            requested[id].insert(disciplina);
        }
    }

    int X = 0, Y = 0, Z = 0;

    map<int, vi> ans;

    set<int> xx;

    for (int i = 0, id, cnt; i < M; i++)
    {
        cin >> id >> cnt;

        for (int j = 0, disciplina; j < cnt; j++)
        {
            cin >> disciplina;

            if (requested[id].count(disciplina) == 0)
            {
                xx.insert(id);

                Y++;

                ans[id].PB(-disciplina);
            }
            else
            {
                requested[id].erase(disciplina);
            }
        }
    }

    for (auto id : requested)
        for (auto dis : id.second)
        {
            xx.insert(id.first);
            ans[id.first].PB(dis);
            Z++;
        }


    X = xx.size();

    if (X == 0)
    {
        cout << "GREAT WORK! NO MISTAKES FOUND!" << endl;
    }
    else
    {
        for (auto x : ans)
        {
            cout << x.first << " ";

            sort(ALL(x.second), [&](const int &a, const int &b) { return abs(a) < abs(b);});

            for (auto y : x.second)
                cout << (y > 0 ? "+" : "") << y << " ";
            cout << endl;
        }
        
        cout << "MISTAKES IN " << X << " STUDENTS: " << Y << " NOT REQUESTED, " << Z << " MISSED" << endl;
    }


    return 0;
}