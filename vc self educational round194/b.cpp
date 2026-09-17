#include<iostream>
using namespace std;
void solve(){
    long long x, y,k;
    cin >> x >> y >> k;
    long long w = y-x;
    long long ans = 0;
    while(k--){
        ans+=(y%x);
        if(y%x==w) break;

    y++;
    x++;

    }
    if(k>0) ans+=(w*k);
    cout << ans << endl;
}
    int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    

return 0;
}
