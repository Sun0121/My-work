
�ͻ���

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
 //              System.out.println("�����ϴ��ļ�·��");
//             Scanner sc = new Scanner(System.in);
//            String adress = sc.next();

            String adress = jt.getText();
            //System.out.println(adress);
            File f = new File(""+adress);

            //�����
            OutputStream out = s.getOutputStream();
            //��ȡ�ļ����������ļ���
            String name = f.getName();
            out.write(name.getBytes());
            InputStream in = s.getInputStream();
            //���ܷ���˷���
            byte[] bt = new byte[1024];
            int le1 = in.read(bt);
            System.out.println(new String(bt,0,le1));


            FileInputStream is = new FileInputStream(f);
            //��ȡ�����ļ�
            byte[] buf = new byte[1024];
            int len = 0;
            while ((len = is.read(buf)) != -1) {
                out.write(buf, 0, len);         //�ļ�����д������� ͨ�����紫��
            }
            s.shutdownOutput();         //���߷���� �ļ���ȡ���


            //���տͻ��˵ķ���
            byte[] bf = new byte[1024];
            int le = in.read(bf);
            System.out.println(new String(bf, 0, le));

            //�ر���Դ
            s.close();
            is.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    client(){


        jt = new JTextField();
        jt.setBounds(100,100,200,27);

        sub = new JButton("�ϴ�");
        sub.setBounds(200,200,100,27);

        open=new JButton("��");
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
        this.setTitle("����μ����ϴ�Demo");
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        open.addActionListener(this);
        sub.addActionListener(this);
    }
    @Override
    public void actionPerformed(ActionEvent e) {
        // TODO Auto-generated method stub
        if(e.getActionCommand()=="�ϴ�")
        {
            upload();
        }

        if(e.getActionCommand()=="��") {
            System.out.println("��");
            JFileChooser jfc = new JFileChooser();
            jfc.setFileSelectionMode(JFileChooser.FILES_AND_DIRECTORIES);
            jfc.showDialog(new JLabel(),"ѡ���ļ�");
            File file = jfc.getSelectedFile();
            if (file.isFile()) {
                String str = file.getAbsolutePath();
                System.out.println(str);
                jt.setText(str);

            } else
                System.out.println("ѡ��Ĳ�����һ���ļ�");
            System.out.println(jfc.getSelectedFile().getName());
        }

    }
}



��������


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
            //���Ƶ��ļ����
            String IP = s.getInetAddress().getHostAddress();
            System.out.println(IP + "���������ӳɹ�");
            String name = null;

            byte[] bf = new byte[1024];
            int le = in.read(bf);
            name = new String(bf, 0, le);
            OutputStream out = s.getOutputStream();
            out.write("�յ�".getBytes());

            File f = new File("E://java����������", name );
            //������д�뵽�ļ���
            FileOutputStream os = new FileOutputStream(f);
            //��ȡ����

            byte[] buf = new byte[1024];
            int len = 0;
            while ((len = in.read(buf)) != -1) {
                os.write(buf, 0, len);
            }

            out.write((f.getName() + "�ϴ����").getBytes());
            //�ر���Դ
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
                Socket s = ss.accept();//��������
                new Thread(new cn.chlinjiayi.upload3.server(s)).start();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}








