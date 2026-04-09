//关键是选取关键的数据结构
//基于数组、字符串、链表、树、图、哈希表、堆、栈、队列
//也要基于一些基础算法技巧，排序、递归、迭代...
#include <iostream>
using namespace std;

class Solution1{//位运算
public:
    int hanmmingWeight(int n){
        int count=0;
        while(n){
            count+=n%2;//等价于n&1
            n/=2;
        }
        return count;
    }
};

//总之就是题目翻译成代码