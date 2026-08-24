#include<bits/stdc++.h>
using namespace std;
void test_case() {
    int row, col;
    cin >> row >> col;
    int layer = max(row, col);
    if(layer % 2 == 1){
        swap(row, col);
    }
    if (col == layer){
        cout << (long long)(layer -1)*(layer -1)+1 + row -1 << "\n";
    }
    else{
        assert(row == layer);
        cout << (long long)layer * layer -(col-1)<< "\n";
    }
}
int main(){
    int T ;
    cin >> T;
    for (int rep = 0; rep <T; rep ++){
        test_case();
    }
}
