#include <algorithm>
#include <iostream>
#include <vector>
#define int long long
using namespace std;
// vector<int> solve(int i, vector<int>& nums, int sum){
//     vector<int> res;
//     if(i >= nums.size() || sum<0) return {};
//     if(sum == 0) return res; 
    
//     res.push_back(nums[i]);
//     solve(i+1,nums,sum-nums[i]);
//     res.pop_back();
//     solve(i+1,nums,sum);
    
//     return res;
// }
// bool solve(int i, vector<int>& nums, int sum, vector<int>& res) {
//     if (sum == 0) return true;
//     if (i >= nums.size() || sum < 0) return false;
    
//     // Include nums[i]
//     res.push_back(nums[i]);
//     if (solve(i + 1, nums, sum - nums[i], res)) return true;
    
//     // Exclude nums[i]
//     res.pop_back();
//     if (solve(i + 1, nums, sum, res)) return true;
    
//     return false;
// }
int32_t main() {
    int N;
    cin >> N;
    // int sum=0;
    // vector<int> nums;
    // for(int i=1; i<=N; i++) {sum += i; nums.push_back(i);}
    // if(sum%2 == 1) {cout<<"NO"; return 0;}
    
    // sum = sum/2;
    // vector<int> fhalf;
    // bool flag = solve(0,nums,sum, fhalf);
    // cout<<"YES"<<endl;
    // cout<<fhalf.size()<<endl;
    // for(auto i: fhalf) cout<<i<<" ";
    // cout<<endl;
    // vector<int> shalf;
    // int o=0;
    // for(int i=0; i<nums.size(); i++){
    //     if(nums[i] == fhalf[o]) {o++; continue;}
    //     else shalf.push_back(nums[i]);
    // }
    // cout<<shalf.size()<<endl;
    // for(auto i: shalf) cout<<i<<" ";
    int sum = N*(N+1)/2;
    if(sum%2 == 1) {cout<<"NO"; return 0;}
    cout<<"YES"<<endl;
    sum = sum/2;
    vector<int> set1,set2;
    int curr = 0;
    for(int i=N; i>=1; i--){
        if(curr + i <= sum){
            set1.push_back(i);
            curr += i;
        }
        else set2.push_back(i);
    }
    cout<<set1.size()<<endl;
    for(auto i: set1) cout<<i<<" ";
    cout<<endl;
    cout<<set2.size()<<endl;
    for(auto i: set2) cout<<i<<" ";
    
    
    return 0;
}