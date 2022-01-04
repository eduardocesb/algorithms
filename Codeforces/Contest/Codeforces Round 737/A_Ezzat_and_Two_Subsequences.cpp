#include <bits/stdc++.h>
#define int long long
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

#define MOD         1000000007
#define nline       '\n'        
#define pb          push_back
#define mp          make_pair
#define fi          first
#define se          second
#define yes         cout<<"YES\n"
#define no          cout<<"NO\n"
#define vi          vector<int>
#define pii         pair<int,int>
#define sz(v)       v.size()
#define lcm(a,b)    (a*b)/(__gcd(a,b))
#define deb(x)      cout<<#x<<" = "<<x<<endl;
#define deb2(x,y)   cout<<#x<<" = "<<x<<' '<<#y<<" = "<<y<<endl;
#define deb3(x,y,z) cout<<#x<<" = "<<x<<' '<<#y<<" = "<<y<<' '<<#z<<" = "<<z<<endl;
#define PR(a,n)     cout<<#a<<" = ";for(int _=0;_<n;_++)cout<<a[_]<<' ';cout<<endl;
#define all(v)      v.begin(),v.end()
#define sortv(v)    sort(all(v));
#define sortrev(v)  sort(all(v),greater<int>())
#define maxHeap     priority_queue<int>
#define minHeap     priority_queue<int, vector<int>, greater<int>>

inline void solve()
{
    int n;
    cin>>n;
    vi a(n);
    double sum = 0;
    int mx = INT_MIN;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
        mx=max(mx,a[i]);
    }
    sum-=mx;
    double ans = mx + sum/(n-1);
    cout<<fixed<<setprecision(10)<<ans<<nline;
    return;
}

signed main()
{
    boost;
    int t=1;
    cin>>t;
    for(int tt=1;tt<=t;tt++)
    {
        // cout<<"Case #"<<tt<<": ";
        solve();
    }
    return 0;
}
