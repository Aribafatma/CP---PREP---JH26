#include <bits/stdc++.h>
using namespace std ;
int main(){
    string s;
    cin >> s;
    int n = s.length();
    int block = 0;
    int answer = 0;
    for(int i = 0; i<n; i++){
        if( i != 0 && s[i]== s[i-1]){
            block++;
        }
        else{
            answer = max(answer, block);
            block = 1;
        }
    }
    answer = max(answer, block);
    cout << answer << "\n";
}