#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    priority_queue<ll> pq;
    ll sum = 0;
    ll ans = -2e18; // very small number for max comparison
    
    for (int i = 0; i < n; i++) {
        if (pq.size() == m - 1) {
            ll score = m * a[i] - sum;
            ans = max(ans, score);
        }
        
        if (m - 1 > 0) {
            if (pq.size() < m - 1) {
                pq.push(a[i]);
                sum += a[i];
            } else if (a[i] < pq.top()) {
                sum -= pq.top();
                pq.pop();
                pq.push(a[i]);
                sum += a[i];
            }
        }
    }
    
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
