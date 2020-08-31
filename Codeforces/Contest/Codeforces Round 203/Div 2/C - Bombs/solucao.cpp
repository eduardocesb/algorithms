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

bool cmp(pii &a, pii &b)
{
    return (abs(a.first) + abs(a.second)) < (abs(b.first) + abs(b.second));
}

int main(int argc, char const *argv[])
{
	optimize;

    int N;

    cin >> N;

    vii nums(N);

    for(auto &x : nums)
        cin >> x.first >> x.second;

    sort(ALL(nums), cmp);

    vector<pair<int, pair<int, char>>> ans;

    for(auto &x : nums)
    {
        if(x.first == 0)
        {
            ans.EB(make_pair(1, make_pair(abs(x.second), x.second > 0 ? 'U' : 'D')));
            ans.EB(make_pair(2, make_pair(-1, '*')));
            ans.EB(make_pair(1, make_pair(abs(x.second), x.second > 0 ? 'D' : 'U')));
            ans.EB(make_pair(3, make_pair(-1, '*')));
        }
        else if(x.second == 0)
        {
            ans.EB(make_pair(1, make_pair(abs(x.first), x.first > 0 ? 'R' : 'L')));
            ans.EB(make_pair(2, make_pair(-1, '*')));
            ans.EB(make_pair(1, make_pair(abs(x.first), x.first > 0 ? 'L' : 'R')));
            ans.EB(make_pair(3, make_pair(-1, '*')));
        }
        else
        {
            ans.EB(make_pair(1, make_pair(abs(x.second), x.second > 0 ? 'U' : 'D')));
            ans.EB(make_pair(1, make_pair(abs(x.first), x.first > 0 ? 'R' : 'L')));
            ans.EB(make_pair(2, make_pair(-1, '*')));
            ans.EB(make_pair(1, make_pair(abs(x.second), x.second > 0 ? 'D' : 'U')));
            ans.EB(make_pair(1, make_pair(abs(x.first), x.first > 0 ? 'L' : 'R')));
            ans.EB(make_pair(3, make_pair(-1, '*')));
        }
        
    }

    cout << (int)ans.size() << endl;

    for(auto &x: ans)
        if(x.first == 1)
            cout << x.first << " " << x.second.first << " " << x.second.second << endl;
        else 
            cout << x.first << endl;

	return 0;
}