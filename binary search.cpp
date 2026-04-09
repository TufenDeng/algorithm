//红绿灯标记法

//1.线性查找
//在有序数组中查找x，大于等于x的标记为绿，小于的标记为红，那么查找就变成了找到第一个绿色并返回下标

//2.二分查找
//定义两个虚拟空间，-1和n，定义两个游标，红色指向-1，绿色指向n，用黄色游标指向中间；
//将黄色变为中间对应的颜色，进行迭代，直到区间为2，返回绿色指标，想返回红色指标就减去1

#include <iostream>
#include <vector>
using namespace std;

bool isGreen(vector<int> arr,int mid,int target){
    return arr[mid]>=target;
}//可以通过修改这个函数解决各种问题

int findMinGreenIndex(vector<int> arr,int size,int target){
    int l=-1;
    int r=size;

    while(l+1<r){   
        int mid=(l+r)/2;
        if(isGreen(arr,mid,target)) r=mid;
        else l=mid;
    }
    return r;
}//二分模板

//套用模板，idx=findMinGreenIndex(...);当idx等于n，说明没有找到target;当idx不等于n，且arr[idx]不等于target

//最大最小下标：可能存在连续的target，返回下标区间；否则返回[-1,-1]
//在idx=findMinGreenIndex的基础上，增加idx_=findMinGreenIndex[...,target+1]，两个下标即为最小和最大

class Solution2{
public:
    int search(vector<int>& nums, int target) {
        int size=nums.size();
        int idx=0;
        idx=findMinGreenIndex(nums,size,target);
        if(idx==size) return -1;
        else{
            if(nums[idx]==target) return idx;
            else return -1;
        }
    }
};

class Solution3{
public:
    vector<int> searchIndexSpan(vector<int> nums,int target){
        int size=nums.size();
        int idx=0;
        idx=findMinGreenIndex(nums,size,target);
        vector<int> ans{-1,-1};
        if(idx==size) return ans;
        else{
            if(nums[idx]==target){
                int idx_=findMinGreenIndex(nums,size,target+1);
                ans={idx,idx_-1};
                return ans;
            }
            else return ans;
        }
    }
};