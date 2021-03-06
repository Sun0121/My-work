C++中的get(),getchar(),getline()等的用法与区别：

在输入流中有一个字符指针，可以随流移动，每次指向当前应访问字符。


1、get()
	
	1) 无参get()
		用法：cin,get();
		可以从输入流中提取一个字符（包括空白字符），若遇到输入流中的文件结束符，
		则函数值返回文件结束标志EOF(End Of File)，一般以-1代表EOF，
		
		[例] 用get函数读入字符。

			#include <iostream>
			using namespace std;
			int main( )
			{
			int c;
			cout<<"enter a sentence:"<<endl;
			while((c=cin.get())!=EOF)
			cout.put(c);
			return 0;
			}
			
			运行情况如下：
			enter a sentence:
			I study C++ very hard   //(输入一行字符)
			I study C++ very hard      // (输出该行字符)
			^Z↙(程序结束)
			
	2) 有一个参数的get()函数
		形式：cin.get(ch);
		其作用是从输入流中读取一个字符，赋给字符变量ch。
		
		上面的例子可以改写如下：

		#include <iostream>
		using namespace std;
		int main( )
		{
		  char c;
		  cout<<"enter a sentence:"<<endl;
		  while(cin.get(c)) //读取一个字符赋给字符变量c,如果读取成功,cin.get(c)为真
		  {cout.put(c);}
		  cout<<"end"<<endl;
		  return 0;
		}
		
	3) 有三个参数的get()函数
		形式： cin.get(字符数组, 字符个数n, 终止字符) 或 cin.get(字符指针, 字符个数n, 终止字符)
				如果终止字符不写，则默认为换行符。
		其作用是从输入流中读取n-1个字符，赋给指定的字符数组(或字符指针指向的数组)，如果在读取n-1
		个字符之前遇到指定的终止字符，则提前结束读取。如果读取成功则函数返回true(真)，
		如失败(遇文件结束符) 则函数返回false(假)。
		
		上例：

		#include <iostream>
		using namespace std;
		int main( )
		{
		  char ch[20];
		  cout<<"enter a sentence:"<<endl;
		  cin.get(ch,10,'\\n');//指定换行符为终止字符
		 cout<<ch<<endl;
		  return 0;
		}
		
		运行情况如下：

		enter a sentence:
		I study C++ very hard
		I study
		
2、getchar()   {因为该函数由c语言而来，所以没有cin.getchar()的说法}
	此函数的作用是从终端(或系统隐含指定的输入设备)输入一个字符。getchar函数没有参数，
	其一般形式为getchar( )函数的值就是从输入设备得到的字符。
	用法：char ch = getchar();
	getchar()与cin.get()效果类似。
	
3、getline()
	该函数作用是从输入流读取一行字符(包括空格)。  【如果当前没输入流就创造输入条件给用户输入，创造输入流】
	1) 针对字符类字符串
	用法：与get()三个函数的类似， cin.getline(字符数组(或字符指针), 字符个数n, 终止标志字符)
	
	2)针对string类
	用法：getchar(cin,str);
	读取一行字符存于串str中；
	
4、cin>>
	创建输入流，遇空格或换行就结束。
		
		
基本应用：
面对不知道输入几个元素，即碰到回车换行即停问题
#include <iostream> 
#include <string>
#include<stdio.h>
using namespace std; 
int main() 
{ 
	int i = 0,array[10000],temp;
	while(cin>>temp)
	{
		array[i++] = temp;
		if(cin.get() == '\n')
			break;
	}
	for(int j = 0;j<i;++ j)
	{
		cout<<array[j]<<" ";
	}
} 

注意，判断是否为换行符的语句if(cin.get() == '\n') break;
一定要放在循环体里面最后的那一部分，才能将字符全部读入。
			
		
		
		
			