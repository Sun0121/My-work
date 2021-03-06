

客户端

package ChatClient;

import java.awt.BorderLayout;
import java.awt.TextArea;
import java.awt.TextField;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.EOFException;
import java.io.IOException;
import java.net.Socket;
import java.net.SocketException;
import java.net.UnknownHostException;

import javax.swing.JFrame;

	public class ChatClient extends JFrame{
	
		private TextField tf = null;
		private TextArea ta = null;
		
		private Socket client =null;
		private DataOutputStream  dos = null;
		private DataInputStream dis = null;
		
		private boolean b_conn =false;
		
		public static void main(String[] args) {
			new ChatClient().launch();
		}
	
		private void launch() {
			this.setTitle("client端");
			this.setLocation(300, 400);
			this.setSize(300, 400);
			/*
			 * 关闭窗口的两种方法
			 * */
			//this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			this.addWindowListener(new WindowAdapter(){//为了关闭窗口
			   public void windowClosing(WindowEvent e)
			   {
				   disconnect();
			       System.exit(0);
			   }
			  });
			
			tf=new TextField();
			ta=new TextArea();
			
			//为TextField添加回车事件响应
			tf.addActionListener(new ClientLisenter());
			
			this.add(BorderLayout.SOUTH,tf);
			this.add(BorderLayout.NORTH, ta);
			pack();//窗口自动适应大小，使窗口能正好显示里面所有的控件。
			this.setVisible(true);
			
			connect();
			//连接上了之后，开启一个线程来进行接收服务器端的数据
			
			new Thread(new RecvThread()).start();
			
		}
		
		private class RecvThread implements Runnable{

			@Override
			public void run() {
				while(b_conn){
					String str = null;
					//从服务器端接收数据有个时间限制（系统自设，也可以自己设置），超过了这个时间，便会抛出该异常  
					try {
						str = dis.readUTF();
						//将信息写入到TextArea中
						ta.setText(ta.getText()+str+'\n');
					}catch(SocketException e1){
						System.out.println("bye");
					}catch (EOFException e) {
						System.out.println("推出了，bye - bye!");
					}catch (IOException e) {
						System.out.println("我关闭了也");
						e.printStackTrace();
					}
				}
			}
			
		}
		
		private void connect() {
			//客户端请求与本机在8888端口建立TCP连接 
			try {
				client = new Socket("127.0.0.1", 8888);
				//client.setSoTimeout(10000); 
				dos = new DataOutputStream(client.getOutputStream());
				dis = new DataInputStream(this.client.getInputStream());
				b_conn = true;
			} catch (UnknownHostException e) {
				System.out.println("没有找到需要连接的主机！！");
				e.printStackTrace();
			} catch (IOException e) {
				e.printStackTrace();
			}
					
		}
		
		private void disconnect(){	
			
				try {
					b_conn = false;
					if(dos!=null) dos.close();
					if(client!=null) client.close();
				} catch (IOException e) {
					e.printStackTrace();
				}
			
		}
		
		private class ClientLisenter implements ActionListener{

				@Override
				public void actionPerformed(ActionEvent event) {
					String content = tf.getText();
					/*
					 * 判断TextArea中是否有内容,如果有，则需要先加入一个换行符，
					 * 然后再加入内容，否则直接加入内容
					 * */
					//由于服务器端会广播其发送的消息，因此，就不需要再这里完成显示了
//					if(ta.getText().trim().length()!=0){
//						ta.setText(ta.getText()+"\n"+content);
//					}
//					else{
//						ta.setText(content);
//					}
//					
					tf.setText("");
					
					try {
						dos.writeUTF(content);
						dos.flush();
						
					} catch (IOException e) {
						e.printStackTrace();
					}
			
				}
			}
		
	
	}
	
	
	
	
	
	
	
	
	服务器端
	
package ChatServer;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

	public class ChatServer {
	
		private ServerSocket server = null;
		
		//记录所有连接上此服务器的客户端
		private List<ServerThread> serverThreads = new ArrayList<ServerThread>();
		
		public static void main(String[] args) {
			new ChatServer().start();
		}
		
		private void start(){
			boolean b_serverStart = false;
			try {
				//监听本地地址且端口号为8888
				server = new ServerSocket(8888);
				b_serverStart = true;
			} catch (IOException e) {
				//解决打开多个Server端的情况
				System.out.println("请关闭已经打开的Server端，重新开启");
				System.exit(0);
			}
			
			while(b_serverStart){
				//等待客户端的连接，如果没有获取连接  
	            Socket client = null;
				try {
					client = server.accept();
				} catch (IOException e) {
					e.printStackTrace();
				}  
	            System.out.println("与客户端连接成功！");  
	          //为每个客户端连接开启一个线程  
	            ServerThread st = new ServerThread(client);
	            serverThreads.add(st);
	            new Thread(st).start();  
			}
			
			try {
				server.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		
		}
		
		private class ServerThread implements Runnable{
			private Socket client = null;
			private DataInputStream dis = null;
			private DataOutputStream dos = null;
			private boolean b_connect = false;
			
			public  ServerThread(Socket client) {
				this.client=client;
				try {
					dis = new DataInputStream(this.client.getInputStream());
					dos = new DataOutputStream(client.getOutputStream()); 
					b_connect=true;
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			@Override
			public void run() { 
				
				try{
					while(b_connect){  
		                //接收从客户端发送过来的数据  
		                String str= dis.readUTF();
		                if(str == null || "".equals(str)){  
		                	b_connect = false;  
		                }else{  
		                    if("bye".equals(str)){  
		                    	b_connect = false;  
		                    }else{  
		                        //将接收到的字符串前面加上输出到控制台
		                        System.out.println(str);
		                        //将Client端发送过来的数据广播出去
		                        for(int i=0;i<serverThreads.size();i++){
		                        	ServerThread st = serverThreads.get(i);
		                        	st.send(str);
		                        }
		                        
		                    }  
		                }  
		            }
				}
				catch(IOException e){
					System.out.println("client端关闭了");
					//e.printStackTrace();
				}
				finally{
					try{
						if(dis!=null) dis.close();
						if(dos!=null) dos.close();
						if(client!=null) client.close();
					}
					catch(IOException e){
						e.printStackTrace();
					}				
				}
			}
			private void send(String str) {
				//如果发送数据发生异常，则说明此连接已经不再，则需要在Server端将此Client移除
				try {
					this.dos.writeUTF(str);
				} catch (IOException e) {
					serverThreads.remove(this);
				}
			}			
		}
	
	}
	
	
	
	
	
	
	
	
	
	
	
	
	