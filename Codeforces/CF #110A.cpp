#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <unordered_map>
using namespace std;

// Macros for speed
#define fastio ios::sync_with_stdio(false); cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define ff first
#define ss second

// Type aliases
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

// Debugging (disable before submission)
#define debug(x) cerr << #x << " = " << x << '\n'

// Constants
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

// Solve function
void solve() {
    int n;
    cin>>n;

    while(n>0){
        int rem=n%10;
        if(rem!=4 || rem!=7){
            cout<<"NO";
        }
        n=n/10;
    }
    cout<<"YES";
}

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
