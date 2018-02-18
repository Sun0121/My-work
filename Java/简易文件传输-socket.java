
客户端

package client
import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;
import java.util.Scanner;


class client extends JFrame implements ActionListener
{
    JButton open=null;
    JButton sub =null;
    JPanel jp = null;
    static JTextField jt = null;

    public static void main(String[] args) {

            new client();
        }


    public void upload()
    {
        try {
            Socket s = new Socket("127.0.0.1", 4242);
 //              System.out.println("输入上传文件路径");
//             Scanner sc = new Scanner(System.in);
//            String adress = sc.next();

            String adress = jt.getText();
            //System.out.println(adress);
            File f = new File(""+adress);

            //输出流
            OutputStream out = s.getOutputStream();
            //获取文件名，发送文件名
            String name = f.getName();
            out.write(name.getBytes());
            InputStream in = s.getInputStream();
            //接受服务端反馈
            byte[] bt = new byte[1024];
            int le1 = in.read(bt);
            System.out.println(new String(bt,0,le1));


            FileInputStream is = new FileInputStream(f);
            //读取本地文件
            byte[] buf = new byte[1024];
            int len = 0;
            while ((len = is.read(buf)) != -1) {
                out.write(buf, 0, len);         //文件数据写入输出流 通过网络传送
            }
            s.shutdownOutput();         //告诉服务端 文件读取完毕


            //接收客户端的反馈
            byte[] bf = new byte[1024];
            int le = in.read(bf);
            System.out.println(new String(bf, 0, le));

            //关闭资源
            s.close();
            is.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    client(){


        jt = new JTextField();
        jt.setBounds(100,100,200,27);

        sub = new JButton("上传");
        sub.setBounds(200,200,100,27);

        open=new JButton("打开");
        open.setBounds(100,200,100,27);

        jp = new JPanel();
        jp.setLayout(null);
        jp.setBounds(100, 100, 400, 400);
        jp.add(open);
        jp.add(sub);
        jp.add(jt);

        this.add(jp);
        this.setBounds(300, 300, 400, 400);
        this.setVisible(true);
        this.setLayout(null);
        this.setTitle("枷葭嘉佳迦上传Demo");
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        open.addActionListener(this);
        sub.addActionListener(this);
    }
    @Override
    public void actionPerformed(ActionEvent e) {
        // TODO Auto-generated method stub
        if(e.getActionCommand()=="上传")
        {
            upload();
        }

        if(e.getActionCommand()=="打开") {
            System.out.println("打开");
            JFileChooser jfc = new JFileChooser();
            jfc.setFileSelectionMode(JFileChooser.FILES_AND_DIRECTORIES);
            jfc.showDialog(new JLabel(),"选择文件");
            File file = jfc.getSelectedFile();
            if (file.isFile()) {
                String str = file.getAbsolutePath();
                System.out.println(str);
                jt.setText(str);

            } else
                System.out.println("选择的并不是一个文件");
            System.out.println(jfc.getSelectedFile().getName());
        }

    }
}



服务器端


package cn.chlinjiayi.upload3;

import java.io.File;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;

class server implements Runnable {
    Socket s;

    server(Socket s) {
        this.s = s;
    }

    public void run() {
        try {
            InputStream in = s.getInputStream();
            //复制的文件存放
            String IP = s.getInetAddress().getHostAddress();
            System.out.println(IP + "，，，连接成功");
            String name = null;

            byte[] bf = new byte[1024];
            int le = in.read(bf);
            name = new String(bf, 0, le);
            OutputStream out = s.getOutputStream();
            out.write("收到".getBytes());

            File f = new File("E://java服务器测试", name );
            //将数据写入到文件中
            FileOutputStream os = new FileOutputStream(f);
            //获取数据

            byte[] buf = new byte[1024];
            int len = 0;
            while ((len = in.read(buf)) != -1) {
                os.write(buf, 0, len);
            }

            out.write((f.getName() + "上传完成").getBytes());
            //关闭资源
            os.close();
            s.close();
        } catch (Exception e) {
        e.printStackTrace();
    }
    }

    public static void main(String[] args) {
        try {
            ServerSocket ss = new ServerSocket(4242);
            while (true) {
                Socket s = ss.accept();//阻塞方法
                new Thread(new cn.chlinjiayi.upload3.server(s)).start();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}








