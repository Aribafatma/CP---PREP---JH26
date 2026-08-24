#include<bits/stdc++.h>
using namespace std;
int main(){
    int max_n;
    cin >> max_n;
    for(long long n =1 ; n <= max_n; n++){
        long long size = n*n;
        long long allWays  = size * (size -1) /2;
        long long badWays = 0;
        badWays += 8 * (n-4) * (n-4);
        badWays 
    }
}