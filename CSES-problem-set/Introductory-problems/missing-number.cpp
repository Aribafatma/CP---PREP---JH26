#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<bool> vis(n+1);
    for(int i= 0; i<n-1; i++){
        int x;
        cin >> x;
        vis[x] = true;
    }
    for(int x = 1; x <=n; x++){
        if(!vis[x]){
            cout << x << "\n";
            return 0;
        }
    }
}