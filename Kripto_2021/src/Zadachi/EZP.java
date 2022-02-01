package Zadachi;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;
import java.awt.Font;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.math.BigInteger;
import java.awt.event.ActionEvent;
import static javax.swing.JOptionPane.showMessageDialog;
import java.awt.Toolkit;
import java.awt.Color;

public class EZP extends JFrame {
	private JTextField textField;
	private JTextField textField_1;
	private JTextField textField_2;
	private JTextField textField_3;
	private JTextField textField_4;
	private JTextField textField_5;
	private JTextField textField_6;
	private JTextField textField_7;
	public int p;
	public int q;
	public int pq;
	public int d;
	public int param_e;
	public int NOD(int x, int y)
    {
        while (x != y)
        {
            if (x > y)
                x = x - y;
            else
                y = y - x;
        }
        return x;
    }
	public int getD(int f_n)
    {
        int res = -1;

        int temp = 2;
        while (res < 0)
        {
            if (NOD(temp, f_n) == 1 && temp < f_n)
                res = temp;
            temp++;
        }
        return res;
    }
	public int getE(int d, int f_n)
    {
        //e*d=f_n*k+1
        int e = -1;

        int k=1;
        while (e < 0)
        {
            e = (f_n * k + 1) % d == 0 ? (f_n * k + 1) / d : -1;
            k++;
        }
        System.out.println("loloolo "+k);
        System.out.println("loloolo "+d);
        System.out.println("loloolo "+f_n);
        return e;
    }
	public EZP() {
		getContentPane().setBackground(Color.CYAN);
		setIconImage(Toolkit.getDefaultToolkit().getImage("C:\\Users\\\u0414\u043C\u0438\u0442\u0440\u0438\u0439\\Downloads\\iStock-1034901762_d_850.jpg"));
		setTitle("5");
		getContentPane().setLayout(null);
		
		JLabel lblNewLabel = new JLabel("p");
		lblNewLabel.setFont(new Font("Tahoma", Font.PLAIN, 14));
		lblNewLabel.setBounds(10, 4, 48, 24);
		getContentPane().add(lblNewLabel);
		
		JLabel lblNewLabel_1 = new JLabel("q");
		lblNewLabel_1.setFont(new Font("Tahoma", Font.PLAIN, 14));
		lblNewLabel_1.setBounds(10, 35, 48, 24);
		getContentPane().add(lblNewLabel_1);
		
		JLabel lblNewLabel_2 = new JLabel("H0");
		lblNewLabel_2.setFont(new Font("Tahoma", Font.PLAIN, 14));
		lblNewLabel_2.setBounds(10, 71, 48, 14);
		getContentPane().add(lblNewLabel_2);
		
		textField = new JTextField();
		textField.setBounds(23, 8, 106, 20);
		getContentPane().add(textField);
		textField.setColumns(10);
		
		textField_1 = new JTextField();
		textField_1.setBounds(33, 39, 106, 20);
		getContentPane().add(textField_1);
		textField_1.setColumns(10);
		
		textField_2 = new JTextField();
		textField_2.setBounds(43, 70, 106, 20);
		getContentPane().add(textField_2);
		textField_2.setColumns(10);
		
		JLabel lblNewLabel_3 = new JLabel("\u0422\u0435\u043A\u0441\u0442");
		lblNewLabel_3.setFont(new Font("Tahoma", Font.PLAIN, 14));
		lblNewLabel_3.setBounds(10, 96, 83, 14);
		getContentPane().add(lblNewLabel_3);
		
		textField_3 = new JTextField();
		textField_3.setBounds(53, 95, 106, 20);
		getContentPane().add(textField_3);
		textField_3.setColumns(10);
		
		textField_4 = new JTextField();
		textField_4.setBounds(272, 39, 106, 20);
		getContentPane().add(textField_4);
		textField_4.setColumns(10);
		
		textField_5 = new JTextField();
		textField_5.setBounds(272, 70, 106, 20);
		getContentPane().add(textField_5);
		textField_5.setColumns(10);
		
		JLabel lblNewLabel_4 = new JLabel("Public Key");
		lblNewLabel_4.setFont(new Font("Tahoma", Font.PLAIN, 13));
		lblNewLabel_4.setBounds(198, 41, 99, 14);
		getContentPane().add(lblNewLabel_4);
		
		JLabel lblNewLabel_5 = new JLabel("Private key");
		lblNewLabel_5.setFont(new Font("Tahoma", Font.PLAIN, 13));
		lblNewLabel_5.setBounds(196, 72, 99, 14);
		getContentPane().add(lblNewLabel_5);
		
		JButton btnNewButton = new JButton("\u041A\u043B\u044E\u0447\u0438");
		btnNewButton.setBackground(Color.GREEN);
		btnNewButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				q=Integer.parseInt(textField.getText());
				p=Integer.parseInt(textField_1.getText());
				System.out.println(q+"  "+p);
				pq=p*q;
				int f_n = (p - 1) * (q - 1);
				d = getD(f_n);
				System.out.println("uu"+d);
				param_e = getE(d,f_n);
				System.out.println("uu"+param_e);
				textField_4.setText("("+param_e+","+pq+")"); 
				textField_5.setText("("+d+","+pq+")");
			}
		});
		btnNewButton.setFont(new Font("Tahoma", Font.PLAIN, 12));
		btnNewButton.setBounds(125, 6, 83, 23);
		getContentPane().add(btnNewButton);
		
		JLabel lblNewLabel_6 = new JLabel("\u0425\u0435\u0448");
		lblNewLabel_6.setFont(new Font("Tahoma", Font.PLAIN, 13));
		lblNewLabel_6.setBounds(196, 97, 48, 14);
		getContentPane().add(lblNewLabel_6);
		
		textField_6 = new JTextField();
		textField_6.setBounds(272, 95, 106, 20);
		getContentPane().add(textField_6);
		textField_6.setColumns(10);
		
		JLabel lblNewLabel_7 = new JLabel("\u042D\u0426\u041F");
		lblNewLabel_7.setFont(new Font("Tahoma", Font.PLAIN, 13));
		lblNewLabel_7.setBounds(198, 122, 48, 14);
		getContentPane().add(lblNewLabel_7);
		
		textField_7 = new JTextField();
		textField_7.setBounds(272, 120, 106, 20);
		getContentPane().add(textField_7);
		textField_7.setColumns(10);
		
		JButton btnNewButton_1 = new JButton("\u0425\u0435\u0448");
		btnNewButton_1.setBackground(Color.GREEN);
		btnNewButton_1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				int n = p * q;
				int H=Integer.parseInt(textField_2.getText());
				String codeText1=textField_3.getText();
				System.out.println(codeText1);
				int[] codeText=new int[10];
				for (int i=0;i<codeText1.length();i++) {
				char letter = codeText1.charAt(i);
				int ascii = (int) letter;
				
				codeText[i]=ascii-1039;
				if(ascii>=1046) {codeText[i]++;}
				if(ascii==1025) {codeText[i]=7;}
				System.out.println(codeText[i]);}
				for (int i=0;i<codeText1.length();i++) {
					 H = (H + codeText[i]) * (H + codeText[i]) % n;
					 System.out.println(H);
				}
				textField_6.setText(Integer.toString(H));
			}
		});
		btnNewButton_1.setBounds(210, 7, 59, 23);
		getContentPane().add(btnNewButton_1);
		
		JButton btnNewButton_2 = new JButton("\u042D\u0426\u041F");
		btnNewButton_2.setBackground(Color.GREEN);
		btnNewButton_2.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				 int hash=Integer.parseInt(textField_6.getText());
				 BigInteger b1=new BigInteger(Integer.toString(hash));
				 b1 = b1.pow(d);
				 BigInteger c=new BigInteger(Integer.toString(pq));
				 b1=b1.mod(c);
				 textField_7.setText(b1+"");
				 //CHECK
				 /*
				 int sign= Integer.parseInt(textField_7.getText());
				 BigInteger b2=new BigInteger(Integer.toString(sign));
				 b2 = b2.pow(param_e);
				 //BigInteger c=new BigInteger(Integer.toString(pq));
				 b2=b2.mod(c);
				 BigInteger nh=new BigInteger(Integer.toString(hash));
				 System.out.println(b2+"-----"+nh);
				 if (b2.equals(nh)) {
					 showMessageDialog(null, "Подпись подлинная");
				 }
				 else {
					 showMessageDialog(null, "Подпись не подлинная");
				 }
				 */
				 //textField_7.setText(b1+"");
				 
			}
		});
		btnNewButton_2.setFont(new Font("Tahoma", Font.PLAIN, 12));
		btnNewButton_2.setBounds(272, 6, 59, 23);
		getContentPane().add(btnNewButton_2);
		
		JButton btnNewButton_3 = new JButton("\u041F\u043E\u0434\u043B\u0438\u043D\u043D\u043E\u0441\u0442\u044C ");
		btnNewButton_3.setBackground(Color.GREEN);
		btnNewButton_3.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				int hash=Integer.parseInt(textField_6.getText());
				BigInteger c=new BigInteger(Integer.toString(pq));
				 int sign= Integer.parseInt(textField_7.getText());
				 BigInteger b2=new BigInteger(Integer.toString(sign));
				 b2 = b2.pow(param_e);
				 //BigInteger c=new BigInteger(Integer.toString(pq));
				 b2=b2.mod(c);
				 BigInteger nh=new BigInteger(Integer.toString(hash));
				 System.out.println(b2+"-----"+nh);
				 if (b2.equals(nh)) {
					 showMessageDialog(null, "Подлинная");
				 }
				 else {
					 showMessageDialog(null, "Не подлинная");
				 }
				 //textField_7.setText(b1+"");
			}
		});
		btnNewButton_3.setFont(new Font("Tahoma", Font.PLAIN, 13));
		btnNewButton_3.setBounds(342, 6, 126, 23);
		getContentPane().add(btnNewButton_3);
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		EZP lol=new EZP();
		lol.setVisible(true);
		//lol.a=Integer.parseInt(lol.textField.getText());
		lol.setSize(490,180);
	}

}
