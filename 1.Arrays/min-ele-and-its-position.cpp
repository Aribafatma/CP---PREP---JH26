#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0 ;i < n; i++){
        cin >>a[i];
    }
int ans =a[0],location = 1;
for(int i = 1; i< n;i++){
    if(a[i]< ans){
        ans = a[i];
    location= i+1;}
}

cout << ans << " " << location << endl;
return 0;}