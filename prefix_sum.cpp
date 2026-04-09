//前缀和
// 是一种预处理，用于快速计算数组或序列的子数组和
// 通过预先计算前缀和，可以在O(1)时间复杂度内快速求解任意子数组的和（查询）
// 前缀和数组通常用于解决区间查询问题，如求解子数组和、子数组最大值、子数组最小值等
#include <iostream>
#include <vector>
using namespace std;

//如何操作：
//对一个给定的数组arr，新建立一个数组prefix_sum,这个数组每个元素prefix_sum[i]表示从arr[0]到arr[i]的和
//当我要计算arr[i]到arr[j]的和，只需要计算prefix_sum[j]-prefix_sum[i-1]
int prefix_sum(vector<int>& arr,int i,int j){
    vector<int> prefix_sum(arr.size());
    int tmp_sum=0;
    for(int k=0;k<arr.size();k++){
        tmp_sum+=arr[k];
        prefix_sum[k]=tmp_sum;
    }//预处理，时间复杂度为O(n)
    return prefix_sum[j]-prefix_sum[i-1];//查询，时间复杂度为O(1)
}

class Solution{//找到数组中间位置，使得左右两边的和相等
public:
    int findMiddleIndex(vector<int>& nums) {
        vector<int> prefix_sum(nums.size());
        int tmp_sum=0;
        for(int k=0;k<nums.size();k++){
            tmp_sum+=nums[k];
            prefix_sum[k]=tmp_sum;
        }
        for(int i=0;i<nums.size();i++){
            if(prefix_sum[i]==prefix_sum[nums.size()-1]-prefix_sum[i]) return i;
        }
        return -1;
    }
};
