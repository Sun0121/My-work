import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class HelloWorld{
	public static String getString()throws IOException
	{
		InputStreamReader isr = new InputStreamReader(System.in);
		BufferedReader bf = new BufferedReader(isr);
		String s = bf.readLine();
		return s;
	}
	public static int getInt()throws IOException
	{
		String s = getString();
		return Integer.parseInt(s);
	}
	public static void main(String[] args)throws IOException
	{
		boolean sympol = true;
		while(sympol)
		{
			int randomNum,i = 0,number = -1;
			randomNum = (int)(Math.random()*100);
			System.out.println("已获取随机数(1-100)，请开始猜数：");
			while(number != randomNum)
			{
				System.out.print("请输入第"+(i+1)+"个数：");
				number = getInt();
				if(number>randomNum)
				{	
					System.out.println("该数大了,");
					++ i;
				}
				if(number<randomNum)
				{
					System.out.println("该数小了,");
					++ i;
				}
			}
			System.out.println("恭喜正确，你一共猜了"+(i+1)+"次");
			System.out.println("请选择： 重新开始 输入1； 退出输入0");
			i = getInt();
			if(i == 0)
				sympol = false;
		}
	}
}