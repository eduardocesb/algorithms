#include "bits/stdc++.h"
#define endl '\n'
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define present(c, x) (c.find(x) != c.end())
#define rep(i, a, b) for (int i = a; i < (b); ++i)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
mt19937 rng((ll)std::chrono::steady_clock::now().time_since_epoch().count());

struct pt;
using P = pt;
struct pt
{
    using T = double;

    T x, y;
    int id;
    explicit pt(T x = 0, T y = 0) : x(x), y(y) {}
    bool operator<(P p) const { return tie(x, y) < tie(p.x, p.y); }
    bool operator==(P p) const { return tie(x, y) == tie(p.x, p.y); }
    P operator-(P p) const { return P(x - p.x, y - p.y); }
    T cross(P p) const { return x * p.y - y * p.x; }
    T cross(P &a, P &b) const { return (a - *this).cross(b - *this); }
    T dist2() const { return x * x + y * y; }
};

vector<pt> convexHull(vector<pt> &pts)
{
    if (sz(pts) <= 1)
        return pts;
    sort(all(pts));
    vector<pt> h(2 * sz(pts) + 1);
    int s = 0, t = 0;
    for (int it = 2; it--; s = --t, reverse(all(pts)))
        for (pt p : pts)
        {
            while (t >= s + 2 && h[t - 2].cross(h[t - 1], p) <= 0)
                t--;
            h[t++] = p;
        }
    return {h.begin(), h.begin() + t - (t == 2 && h[0] == h[1])};
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    double timing = clock();

    int n;
    while (cin >> n)
    {
        vector<pt> pol(n);
        for (auto &p : pol)
            cin >> p.x >> p.y;

        auto ch = convexHull(pol);
        double ans = 0;
        auto area = [&](int i, int j, int k)
        {
            return fabs((ch[j] - ch[i]).cross(ch[k] - ch[j]));
        };

        n = sz(ch);
        for (int i = 0; i < n; ++i)
        {
            int mid = i + 1, j = mid + 1;
            while (j < n)
            {
                while (mid + 1 < j && area(i, mid, j) < area(i, mid + 1, j))
                {
                    mid++;
                }
                ans = max(ans, area(i, mid, j));
                j++;
            }
        }

        cout << fixed << setprecision(1);
        cout << ans / 2.0 << endl;
    }
    //--------------------------
    cerr << "\n\nREAL TIME: " << fixed << setprecision(4) << (clock() - timing) / CLOCKS_PER_SEC << endl;
}