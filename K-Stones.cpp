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
const int N = 10001;
 
 
 
 
int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        bool dp[k + 1] = {false};
        for (int i = 1; i <= k; i++) {
            for (int j = 0; j < n; j++) {
                if (i - a[j] < 0)
                    break;
                else {
                    if (dp[i - a[j]] == false)
                        dp[i] = true;
                }
            }
        }
        if (dp[k])
            cout << "First" << endl;
        else
            cout << "Second" << endl;
    }
    return 0;
 
}
