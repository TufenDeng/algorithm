#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//贪心（线性表）：没有固定算法，按照某种策略一步一步去选择，每次选择都是当前阶段的最优选，不从整体最优考虑
//与搜索（树）（把每种情况跑完，选择最优）、动态规划（有向无环图）（存储枚举过的状态，下一次只需从这里出发）不同

//当每步都可以最优解并能达到全局最优解，就用贪心

//先深搜，时间复杂度允许就过；如果状态能够存在哈希表、线性表，就转为dp，即是空间换时间；最后才考虑贪心

//翻硬币（把相邻的两个硬币翻转记作一次）:遍历字符数组，发现当前不一致，就翻转该硬币和后一个硬币，直至结束
class Solution1{
public:
    int reverseCoins(string prototype,string result){
        int cnt=0;
        for(int i=0;i<prototype.size();i++){
            if(i==prototype.size()-1){
                if(prototype[i]!=result[i]){
                prototype[i]=result[i];
                cnt++;
                }
            }
            if(prototype[i]!=result[i]){
                prototype[i]=result[i];
                prototype[i+1]=result[i];
                ++cnt;
            }
        }
        return cnt;
    }
};

//先排序后处理的贪心：
//若数a、a+1、a+2都存在于数组，res加一
class Solution2{
public:
    int existNumber(int A[100001]){
        int res=0;
        int n=0;
        cin>>n;
        sort(A,A+n);
        int f=1;int s=0;//快慢指针去重
        while(f<n){
            if(A[s]!=A[f]){
                A[++s]=A[f];
            }
            f++;
        }//s+1就是无重复数字的个数

        //对数组进行排序和去重,然后暴力遍历就行了
        for(int i=0;i<s-2;++i){
            int a=A[i];
            if(A[i+1]==a+1&&A[i+2]==a+2) res++;
        }
        return res;
    }
};

//分隔元音，由于局部最优，每个元音左边带有左括号，右括号在下一个元音前面
class Solution3{
    bool isYuanyin(char x){
        if(x=='a'||x=='e'||x=='o'||x=='i'||x=='u') return true;
        return false;
    }
public:
    string returnNewString(string str){
        int size=str.size();
        string ret="(";
        bool flag=false;//表示字符串中是否出现元音
        int cnt=0;//记录元音出现次数
        for(int i=0;i<size;++i){
            if(isYuanyin(str[i])){
                flag=true;
                cnt++;
            }
            if(cnt>1&&isYuanyin(str[i])){
                ret+=")";
                ret+="(";
            }
            ret+=str[i];
        }
        ret+=")";
        if(flag==false) ret=str;
        return ret;
    }
};