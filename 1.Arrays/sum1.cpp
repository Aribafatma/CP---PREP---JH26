#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main(){
    vector<int>nums = {2, 7, 11, 15};
    int target = 13;
    int n = nums.size();
    map<int , int> mp;
    for(int i =0; i<n; i++){
        int remaining = target - nums[i];
        if(mp.find(remaining)!= mp.end()){
            cout << mp[remaining]<< " " << i << endl;
            return 0;
        }
        mp[nums[i]]= i;
    }
    return 0;
}