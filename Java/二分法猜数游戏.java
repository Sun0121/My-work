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
			System.out.println("�ѻ�ȡ�����(1-100)���뿪ʼ������");
			while(number != randomNum)
			{
				System.out.print("�������"+(i+1)+"������");
				number = getInt();
				if(number>randomNum)
				{	
					System.out.println("��������,");
					++ i;
				}
				if(number<randomNum)
				{
					System.out.println("����С��,");
					++ i;
				}
			}
			System.out.println("��ϲ��ȷ����һ������"+(i+1)+"��");
			System.out.println("��ѡ�� ���¿�ʼ ����1�� �˳�����0");
			i = getInt();
			if(i == 0)
				sympol = false;
		}
	}
}