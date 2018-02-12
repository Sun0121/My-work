#include<iostream>  
#include<string>  
#include<cstring>  
#include<algorithm>  
#include<fstream>  
#define N 4  
using namespace std;  
  
int flag=0;  
int num[N];  
  
void solveByDfs(int index,int result,int num[])  
{  
    if(result==24)  
    {  
        flag=1;  
        return ;  
    }  
    if(result > 24 || index>=4)  
        return ;  
    for(int choose=0; choose<4; choose++)  
    {  
        switch(choose)  
        {  
        case 0:  
            solveByDfs(index+1,result+num[index],num);  
            break;  
        case 1:  
            solveByDfs(index+1,result-num[index],num);  
            break;  
        case 2:  
            solveByDfs(index+1,result*num[index],num);  
            break;  
        case 3:  
            solveByDfs(index+1,result/num[index],num);  
            break;  
        }  
        if(flag)  
            return;  
    }  
}  
  
int main()  
{  
    int test=0;  
    while(cin>>num[0]>>num[1]>>num[2]>>num[3])  
    {  
        flag=0;  
        test=0;  
        sort(num,num+4);  
        do  
        {  
            solveByDfs(0,test,num);  
        }  
        while(next_permutation(num,num+4));  
        if(flag)  
            cout<<"YES"<<endl;  
        else  
            cout<<"NOT"<<endl;  
    }  
  
    return 0;  
}  