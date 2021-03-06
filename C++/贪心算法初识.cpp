#include<iostream>                                          //分块，多用函数 
using namespace std;
/*-------------------------------------棋盘的定义---------------------------------------------*/
int DirX[]={2,1,-1,-2,-2,-1,1,2};                           //数组依次记录八个可走方向的横坐标   
int DirY[]={1,2,2,1,-1,-2,-2,-1};                           //数组依次记录八个可走方向的纵坐标   
int chessboard[8][8];                                                   //定义了一个8*8的棋盘   
/*--------------------------------------马的进步函数--------------------------------------------*/
void init();                                                 //初始化,主要是将棋盘各点置零   
int outnumber(int m,int n);                                  //求从某一点出发，可以有多少条路径可走   
int mix(int m,int n);                                        //求一方向，从该方向出发，到达的点，可以走的路径数目最小   
void print();                                                //打印棋盘结果   
bool isok(int m,int n);                                      //判断某个方向是否可行   
/*--------------------------------------主函数--------------------------------------------*/
int main()   
{   
	cout<<"******************************马踏棋盘*********************************";   
			int   x=0,y=0,step=1,i=0;            //X，Y用来表示初始位置的坐标，step表示走的步数，i为一代用变量   
			char ch;                             //判断输入的坐标是否正确
			init();                              //用户的输入过程  
			
			chessboard[x][y]=step;                 //记录初始位置，将该点的坐标定义为步数step   
			for(step=2;step<65;step++)
			{                                      //应用贪心算法来求解，没有回溯过程   
				i=mix(x,y);                        //求从某点出发可走的方向中，出口数最小的方向   
				x+=DirX[i];                        //前进一步   
				y+=DirY[i];   

				chessboard[x][y]=step;  
				//print();                         //打印每一步的棋盘结果，	
			}   
			print();                               //走完64步，利用贪心算法一定会有解，故无回溯，直接打印结果   
            //退出这个程序  

}   

void init()                                        //初始化棋盘，将所有的格子初始化为零   
{   
	for(int i=0;i<8;i++)   
		for(int j=0;j<8;j++)   
			chessboard[i][j]=0;   
}   

int mix(int m,int n)                               //传入参数为某点的坐标，函数返回从该点出发的所有可行的方向中，出口数最小的方向   
{                                                  //出口数为某点可走的方向数   
	int mixdir=0,mixnumber=9,a=0;                  //mixdir记录最小出口数的方向，mixnumber记录该方向的出口数，也即所有方向中最小的出口数   
	for(int i=0;i<8;i++)
	{   
		if(isok((m+DirX[i]),(n+DirY[i])))
		{                                          //首先判断某个方向是否可行   
			a=outnumber((m+DirX[i]),(n+DirY[i]));  //计算该方向的出口   
			if(a&&(a<mixnumber))  
			{                                      //如果该方向可行并且该方向的出口数比已知的最小的出口数小   
				mixnumber=a;                       //将mixnumber改为该出口数   
				mixdir=i;                          //将该方向记录为最小出口数方向   
			}   
		}   
	}   
	if(mixdir==0)  
	{                                            //此步骤针对最后一步，当step=63时，由于所有方向的出口数均为零，故需要特殊考虑   
		for(int i=0;i<8;i++)   
			if(isok   ((m+DirX[i]),(n+DirY[i])))            //找到最后可行的方向 
				return i;   
	}   
	return mixdir;                               //返回最小出口数的方向   
}   

int outnumber(int m,int n)                      //函数针对传入的坐标，返回从该点出发所有可行的方向数，即出口数   
{
	int flag=0;                                 //flag记录方向数   
	for(int i=0;i<8;i++)                        //八个方向都遍历一遍   
		if(isok((m+DirX[i]),(n+DirY[i])))  
			flag++;                             //如果某个方向可行，出口数+1   
	return flag;                            //返回出口数   
}   

bool isok(int m,int n)                         //判断该点是否已经走过，也即某个方向是否可行，可行返回1，否则返回0   
{   
	if((m>=0)&&(m<8)&&(n>=0)&&(n<8)&&(chessboard[m][n]==0))   
		return 1;                              //没有出棋盘的边缘，并且没有走过，即为可行   
	else return 0;   
}   

void print()                                   //将棋盘的信息打印，也即将走满的格子中的步数信息显示出来   
{   
	for(int i=0;i<8;i++){   
		cout<<endl; 
		cout<<endl;  
		for(int j=0;j<8;j++)
		{   
			cout.width(6);   
			cout<<chessboard[i][j];

		}   
	}   
	cout<<endl;
	cout<<endl; 
}