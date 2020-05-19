//Radhe Radhe
#include<bits/stdc++.h>
//#include<boost/multiprecision/cpp_int.hpp>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//using namespace boost::multiprecision;
//#include<boost/math/common_factor.hpp>
#include <ext/numeric>
using namespace __gnu_cxx;
using namespace std;
#define int long long
#define endl "\n"
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define array(a,n) int a[n]; for(int i=0;i<n;i++) cin>>a[i];
#define loop(i,a,b,x) for(int i=a;i<b;i+=x)
const int MOD = 1000000007;

vector<int> tree[100001];
int dp[100001][2];

int solve(int u, bool constraint, int pr)
{
    if (dp[u][constraint] != -1)
        return dp[u][constraint];
    int ans = 0;
    int w1 = 1;
    for (int child : tree[u])
    {
        if (child != pr)
            w1 = (w1 * solve(child, 0, u)) % MOD;
    }
    ans += w1;
    if (!constraint)
    {
        int w2 = 1;
        for (int child : tree[u])
        {
            if (child != pr)
                w2 = (w2 * solve(child, 1, u)) % MOD;
        }
        ans = (ans + w2) % MOD;
    }
    return dp[u][constraint] = ans;
}


int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    //cin >> t;
    while (t--) {
        int n;
        cin >> n;
        memset(dp, -1, sizeof dp);
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        cout << solve(1, 0, -1);
    }
    return 0;

}

