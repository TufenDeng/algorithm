//双指针,一种常用算法，用于解决数组或链表中的问题；指针理解为索引，即数组下标
//主要用三种，快慢指针，对撞指针，分离双指针

//快慢指针：从同一侧出发，快指针每次走两步，慢指针每次走一步，当快指针走到头时，慢指针刚好走到中间
//可以解决的问题：
//1.判断链表是否有环，若有环，则快慢指针一定会相遇
//2.找到链表的中间节点，当快指针走到头时，慢指针刚好走到中间
//3.删除重复元素，返回新的链表


//对撞指针：从两侧出发，一个从左往右，一个从右往左，当两个指针相遇时，说明已经遍历完整个数组(l>=r)
//可以解决的问题：
//1.找到数组中两个数之和为target
//2.回文串判定
//3.反转数组、字符串

//分离双指针：两个指针分别在两个数组或链表上移动
//可以解决的问题：
//1.合并两个有序数组
//2.归并排序中的合并
//3.两组数组求交集、并集

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{//判断数组是否为回文串
public:
    bool isPalindrome(string s) {
        int l=0;
        int r=s.size()-1;
        for(l=0;l<r;l++){
            if(s[l]!=s[r]) return false;
            --r;
        }
        return true;
    }
};

class Solution2{//反转数组
public:
    vector<int> reverseArray(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        while(l<r){
            int tmp=nums[l];
            nums[l]=nums[r];
            nums[r]=tmp;
            ++l;
            --r;
        }
        return nums;
    }
};

class Solution3{//等腰三角形，数组A每一个元素代表有2根长度为Ai的红色木棍，数组B则代表有1根长度为Bi的蓝色木棍，问能组成多少个等腰三角形，都是两根红一根蓝（木棍是会被消耗的）
public:
    int isosceles_triangle(vector<int> & A,vector<int> & B,int N){
        int res=0;
        int first=0;
        int second=0;
        A.sort(A.begin(),A.end());
        B.sort(B.begin(),B.end());
        while(first<N && second<N){
            if(A[first]*2>B[second]){
                ++res;
                ++first;
                ++second;
            }else{
                ++first;
            }
        }
        return res;
    }
};