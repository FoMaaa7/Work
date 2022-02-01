package Zadachi;

import javax.swing.JFrame;
import javax.swing.JLabel;
import java.awt.Font;
import javax.swing.JTextField;
import javax.swing.JButton;
import java.util.ArrayList;
import java.util.HashMap;
import java.awt.event.ActionListener;
import java.text.DecimalFormat;
import java.awt.event.ActionEvent;
import java.awt.Color;
import java.awt.Toolkit;

public class GOST extends JFrame {
	

	private JTextField textField;
	private JTextField textField_1;
	private JTextField textField_2;
	private JTextField textField_3;
	private JTextField textField_4;
	public int [][] s = {{4, 14, 5, 7, 6, 4, 13, 1},
		 {10, 11, 8, 13, 12, 11, 11, 15},
		 {9, 4, 1, 10, 7, 10, 4, 13},
		 { 2, 12, 13, 1, 1, 0, 1, 0 },
		 { 13, 6, 10, 0, 5, 7, 3, 5 },
		 { 8, 13, 3, 8, 15, 2, 15, 7 },
		 { 0, 15, 4, 9, 13, 1, 5, 10 },
		 { 14, 10, 2, 15, 8, 13, 9, 4 },
		 { 6, 2, 14, 14, 4, 3, 0, 9 },
		 { 11, 3, 15, 4, 10, 6, 10, 2 },
		 { 1, 8, 12, 6, 9, 8, 14, 3 },
		 { 12, 1, 7, 12, 14, 5, 7, 14 },
		 { 7, 0, 6, 11, 0, 9, 6, 6 },
		 { 15, 7, 0, 2, 3, 12, 8, 11 },
		 { 5, 5, 9, 5, 11, 15, 2, 8 },
		 { 3, 9, 11, 3, 2, 14, 12, 12 }};
	public GOST() {
		getContentPane().setBackground(Color.CYAN);
		setIconImage(Toolkit.getDefaultToolkit().getImage("C:\\Users\\\u0414\u043C\u0438\u0442\u0440\u0438\u0439\\Downloads\\iStock-1034901762_d_850.jpg"));
		setTitle("Ex2");
		getContentPane().setLayout(null);
		
		JLabel lblNewLabel = new JLabel("\u0428\u0438\u0444\u0440\u0443\u0435\u043C\u043E\u0435");
		lblNewLabel.setFont(new Font("Tahoma", Font.PLAIN, 14));
		lblNewLabel.setBounds(10, 11, 98, 19);
		getContentPane().add(lblNewLabel);
		
		JLabel lblNewLabel_1 = new JLabel("\u041A\u043B\u044E\u0447");
		lblNewLabel_1.setFont(new Font("Tahoma", Font.PLAIN, 14));
		lblNewLabel_1.setBounds(247, 11, 64, 14);
		getContentPane().add(lblNewLabel_1);
		
		textField = new JTextField();
		textField.setBounds(118, 10, 106, 20);
		getContentPane().add(textField);
		textField.setColumns(10);
		
		textField_1 = new JTextField();
		textField_1.setBounds(310, 10, 106, 20);
		getContentPane().add(textField_1);
		textField_1.setColumns(10);
		
		JButton btnNewButton = new JButton("\u041F\u0435\u0440\u0435\u0432\u043E\u0434");
		btnNewButton.setBackground(Color.GREEN);
		btnNewButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String text=textField.getText();
				String key=textField_1.getText();
				for (int k=0;k<text.length();k++) {
				char index=text.charAt(k);
				int i=index;
				i-=848;
				String c=textField_2.getText();
				textField_2.setText(c+Integer.toBinaryString(i)+" ");
				}
				for (int k=0;k<key.length();k++) {
					char index=key.charAt(k);
					int i=index;
					i-=848;
					String c=textField_4.getText();
					textField_4.setText(c+Integer.toBinaryString(i)+" ");
					}
			}
		});
		btnNewButton.setFont(new Font("Tahoma", Font.PLAIN, 14));
		btnNewButton.setBounds(10, 36, 98, 23);
		getContentPane().add(btnNewButton);
		
		textField_2 = new JTextField();
		textField_2.setBounds(10, 62, 469, 20);
		getContentPane().add(textField_2);
		textField_2.setColumns(10);
		
		JButton btnNewButton_1 = new JButton("\u0420\u0435\u0437\u0443\u043B\u044C\u0442\u0430\u0442");
		btnNewButton_1.setBackground(Color.GREEN);
		btnNewButton_1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String text=textField_2.getText();
				String X0=textField_4.getText();
				text=text.replaceAll("\\s+","");
				System.out.println(text);
				X0=X0.replaceAll("\\s+","");
				String L0=new String();
				for (int i=0;i<32;i++) {
					L0=L0+text.charAt(i);
				}
				String R0=new String();
				for (int i=32;i<64;i++) {
					R0=R0+text.charAt(i);
				}
				System.out.println(L0+R0);
				//sum
				long a=0;
				//int n = 0;
				
				for (int i = 0; i < R0.length(); i++) {
			        a <<= 1;
			        if (R0.charAt(i) == '1') a++;
				}
				System.out.println(a);
				long b=0;
				//int n = 0;
				
				for (int i = 0; i < X0.length(); i++) {
			        b <<= 1;
			        if (X0.charAt(i) == '1') b++;
				}
				System.out.println(b);
				
				// maska = 4294967295;
				//System.out.println(maska);
				long s = 0;
		        long carryin = 0; // перенос из предыдущего разряда
		        long k = 1; // маска для получения самого младшего бита
		        long temp_a = a;
		        long temp_b = b;
		        while (temp_a != 0 || temp_b != 0)
	            {
	                // извлечение самых младших битов
	                long ak = a & k, bk = b & k;

	                // вычисляем бит который переносится в следующий разряд
	                long carryout = (ak & bk) | (ak & carryin) | (bk & carryin);

	                // комбинация двух складываемых битов
	                // и бита перенесенного из предыдущего разряда
	                s |= (ak ^ bk ^ carryin);

	                // то что будет перенесено в следующий разряд
	                carryin = carryout << 1;

	                // сдвигаем маску на один бит влево
	                k <<= 1;

	                // отрезаем уже обработанные младшие биты
	                // остатки используются для контроля продолжения цикла
	                temp_a >>= 1;
	                temp_b >>= 1;
	            }
		        long k1=s | carryin;
		        System.out.println(k1);
		        System.out.println(k1 & 0b11111111111111111111111111111111);
		        k1=k1 & 0b11111111111111111111111111111111;
		        String sum=Integer.toBinaryString((int) k1);
		        System.out.println(sum);
		        int h=sum.charAt(0)-'0';
		        System.out.println(h);
		        h=sum.charAt(1)-'0';
		        System.out.println(h);
		        h=sum.charAt(3)-'0';
		        System.out.println(h);
		        int counter = 7;
		        int y=2;
		        int [][] s1= {{4, 14, 5, 7, 6, 4, 13, 1},
		       		 {10, 11, 8, 13, 12, 11, 11, 15},
		    		 {9, 4, 1, 10, 7, 10, 4, 13},
		    		 { 2, 12, 13, 1, 1, 0, 1, 0 },
		    		 { 13, 6, 10, 0, 5, 7, 3, 5 },
		    		 { 8, 13, 3, 8, 15, 2, 15, 7 },
		    		 { 0, 15, 4, 9, 13, 1, 5, 10 },
		    		 { 14, 10, 2, 15, 8, 13, 9, 4 },
		    		 { 6, 2, 14, 14, 4, 3, 0, 9 },
		    		 { 11, 3, 15, 4, 10, 6, 10, 2 },
		    		 { 1, 8, 12, 6, 9, 8, 14, 3 },
		    		 { 12, 1, 7, 12, 14, 5, 7, 14 },
		    		 { 7, 0, 6, 11, 0, 9, 6, 6 },
		    		 { 15, 7, 0, 2, 3, 12, 8, 11 },
		    		 { 5, 5, 9, 5, 11, 15, 2, 8 },
		    		 { 3, 9, 11, 3, 2, 14, 12, 12 }};
		        //System.out.println(s1[y][y]);
		        String res=new String();
		        for(int i=0; i<32; i+=4,counter --) {
		        	int l=sum.charAt(i)-'0';
		        	int l1=sum.charAt(i+1)-'0';
		        	int l2=sum.charAt(i+2)-'0';
		        	int l3=sum.charAt(i+3)-'0';
		        	int znach= l * 8 + l1 * 4 + l2 * 2 + l3;
		        	String binZnach =Integer.toString(s1[znach][counter], 2);
		        	if (binZnach.length() < 4) {
		        		for (int ii = 0; ii < 4 - binZnach.length(); ii++) {
		        			res=res+'0';
		        		}
		        		
		        	}
		        	for (int i1=0; i1<binZnach.length();i1++) {
		        		res=res+binZnach.charAt(i1);
		        	}
		        }
		        System.out.println(res);
		        String suma=new String(res);
		      //циклический сдвиг влево на 11
		        for(int i=0; i<11; i++)
	            {
	                char temp = suma.charAt(0);
	                suma = suma.substring(1);
	                suma=suma+temp;
	            }
		        System.out.println(suma);
		        long a1=0;
				//int n = 0;
				
				for (int i = 0; i < L0.length(); i++) {
			        a1 <<= 1;
			        if (L0.charAt(i) == '1') a1++;
				}
				System.out.println(a1);
				long b1=0;
				//int n = 0;
				
				for (int i = 0; i < suma.length(); i++) {
			        b1 <<= 1;
			        if (suma.charAt(i) == '1') b1++;
				}
				System.out.println(b1);
				long R1 = a1 ^ b1;
				String r1=Integer.toBinaryString((int) R1);
				System.out.println(r1);
				String res1=new String("");
				if (r1.length() < 32) {
	                for (int i = 0; i < 32 - r1.length(); i++)
	                { res1=res1+'0';}
	                }
	            for(int i=0;i<r1.length();i++)
	            {  res1=res1+r1.charAt(i);
	            }
	            System.out.println(res1);
	            
	            res1= res1.substring(0,8) + " " + res1.substring(8,16) + " " +res1.substring(16,24) + " " +res1.substring(24,32);
	            System.out.println(res1);
	            textField_3.setText(res1);
	            
			}
		});
		btnNewButton_1.setFont(new Font("Tahoma", Font.PLAIN, 14));
		btnNewButton_1.setBounds(10, 124, 118, 23);
		getContentPane().add(btnNewButton_1);
		
		textField_3 = new JTextField();
		textField_3.setBounds(10, 158, 469, 20);
		getContentPane().add(textField_3);
		textField_3.setColumns(10);
		
		textField_4 = new JTextField();
		textField_4.setBounds(10, 93, 469, 20);
		getContentPane().add(textField_4);
		textField_4.setColumns(10);
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		GOST lol=new GOST();
		lol.setVisible(true);
		//lol.a=Integer.parseInt(lol.textField.getText());
		lol.setSize(500,220);
	}

}
