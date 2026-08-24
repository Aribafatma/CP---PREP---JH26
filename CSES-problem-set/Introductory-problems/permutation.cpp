#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector <int> a;
    for(int i= 1; i<= n; i+= 2){
        a.push_back(i);
    }
    for(int i = 2; i<= n; i +=2){
        a.push_back(i);
    }
    if(n == 4){
        a = {3, 1 , 4, 2};
    }
    for(int i = 0; i< (int) a.size() - 1; i++){
        if(abs(a[i]- a[ i+1])== 1){
            cout << "NO SOLUTION\n";
            return 0;
        }
    }
    for(int x : a){
        cout << x<< " ";
    }
    cout << "\n";
}