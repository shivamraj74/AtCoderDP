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

struct flower
{
    int hi;
    int bty;
};

int solve(vector<flower>& v, int n)
{
    vector<int> dp(n + 1);
    map<int, int> meaningful;
    dp[1] = v[1].bty;
    meaningful[v[1].hi] = dp[1];
    int ans = dp[1];

    for (int i = 2; i <= n; i++)
    {
        dp[i] = v[i].bty;
        auto it = meaningful.lower_bound(v[i].hi + 1);
        if (it != meaningful.begin())
        {
            it--;
            dp[i] += it->second;
        }
        meaningful[v[i].hi] = dp[i];
        it = meaningful.upper_bound(v[i].hi);
        while (it != meaningful.end() && it->second <= dp[i])
        {
            auto temp = it;
            temp++;
            meaningful.erase(it);
            it = temp;
        }
        ans = max(ans, dp[i]);
    }
    return ans;
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
        cin >> n ;
        vector<flower> v(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> v[i].hi;
        for (int i = 1; i <= n; i++)
            cin >> v[i].bty;
        cout << solve(v, n);

    }

    return 0;

}

