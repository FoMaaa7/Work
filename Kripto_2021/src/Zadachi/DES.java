package Zadachi;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.JButton;
import java.awt.Font;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.lang.*;
import java.awt.Color;
import java.awt.Toolkit;
public class DES extends JFrame {
	private JTextField textField;
	private JTextField textField_1;
	private JTextField textField_2;
	private JTextField textField_3;
	private JTextField textField_4;
	public DES() {
		getContentPane().setBackground(Color.CYAN);
		setIconImage(Toolkit.getDefaultToolkit().getImage("C:\\Users\\\u0414\u043C\u0438\u0442\u0440\u0438\u0439\\Downloads\\iStock-1034901762_d_850.jpg"));
		setTitle("1");
		getContentPane().setLayout(null);
		
		JLabel lblNewLabel = new JLabel("\u0428\u0438\u0444\u0440\u0443\u0435\u043C\u043E\u0435");
		lblNewLabel.setFont(new Font("Tahoma", Font.PLAIN, 14));
		lblNewLabel.setBounds(10, 11, 110, 14);
		getContentPane().add(lblNewLabel);
		
		textField = new JTextField();
		textField.setBounds(90, 10, 106, 20);
		getContentPane().add(textField);
		textField.setColumns(10);
		
		JLabel lblNewLabel_1 = new JLabel("\u041A\u043B\u044E\u0447");
		lblNewLabel_1.setFont(new Font("Tahoma", Font.PLAIN, 14));
		lblNewLabel_1.setBounds(224, 11, 70, 14);
		getContentPane().add(lblNewLabel_1);
		
		textField_1 = new JTextField();
		textField_1.setBounds(268, 10, 106, 20);
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
					String c=textField_3.getText();
					textField_3.setText(c+Integer.toBinaryString(i)+" ");
					}
			}
		});
		btnNewButton.setBounds(10, 36, 130, 23);
		getContentPane().add(btnNewButton);
		
		textField_2 = new JTextField();
		textField_2.setBounds(10, 70, 475, 20);
		getContentPane().add(textField_2);
		textField_2.setColumns(10);
		
		textField_3 = new JTextField();
		textField_3.setBounds(10, 95, 475, 20);
		getContentPane().add(textField_3);
		textField_3.setColumns(10);
		
		JButton btnNewButton_1 = new JButton("\u0420\u0435\u0437\u0443\u043B\u044C\u0442\u0430\u0442");
		btnNewButton_1.setBackground(Color.GREEN);
		btnNewButton_1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String text=textField_2.getText();
				String X0=textField_3.getText();
				text=text.replaceAll("\\s+","");
				System.out.println(text);
				X0=X0.replaceAll("\\s+","");
				System.out.println(X0);
				X0=X0.substring(0,7)+X0.substring(8,15)+X0.substring(16,23)+X0.substring(24,31)+X0.substring(32,39)+X0.substring(40,47)+X0.substring(48,54);
		        System.out.println(X0.length());
		        
		        String res=new String();
		        String k=new String(text);
	            res=res+k.charAt(57);
	            res=res+k.charAt(49);
	            res=res+k.charAt(41);
	            res=res+k.charAt(33);
	            res=res+k.charAt(25);
	            res=res+k.charAt(17);
	            res=res+k.charAt(9);
	            res=res+k.charAt(1);
	            res=res+k.charAt(59);
	            res=res+k.charAt(51);
	            res=res+k.charAt(43);
	            res=res+k.charAt(35);
	            res=res+k.charAt(27);
	            res=res+k.charAt(19);
	            res=res+k.charAt(11);
	            res=res+k.charAt(3);
	            res=res+k.charAt(61);
	            res=res+k.charAt(53);
	            res=res+k.charAt(45);
	            res=res+k.charAt(37);
	            res=res+k.charAt(29);
	            res=res+k.charAt(21);
	            res=res+k.charAt(13);
	            res=res+k.charAt(5);
	            res=res+k.charAt(63);
	            res=res+k.charAt(55);
	            res=res+k.charAt(47);
	            res=res+k.charAt(39);
	            res=res+k.charAt(31);
	            res=res+k.charAt(23);
	            res=res+k.charAt(15);
	            res=res+k.charAt(7);
	            res=res+k.charAt(56);
	            res=res+k.charAt(48);
	            res=res+k.charAt(40);
	            res=res+k.charAt(32);
	            res=res+k.charAt(24);
	            res=res+k.charAt(16);
	            res=res+k.charAt(8);
	            res=res+k.charAt(0);              
	            res=res+k.charAt(58);
	            res=res+k.charAt(50);
	            res=res+k.charAt(42);
	            res=res+k.charAt(34);
	            res=res+k.charAt(26);
	            res=res+k.charAt(18);
	            res=res+k.charAt(10);
	            res=res+k.charAt(2);
	            res=res+k.charAt(60);
	            res=res+k.charAt(52);
	            res=res+k.charAt(44);
	            res=res+k.charAt(36);
	            res=res+k.charAt(28);
	            res=res+k.charAt(20);
	            res=res+k.charAt(12);       
	            res=res+k.charAt(4);
	            res=res+k.charAt(62);
	            res=res+k.charAt(54);
	            res=res+k.charAt(46);
	            res=res+k.charAt(38);
	            res=res+k.charAt(30);
	            res=res+k.charAt(22);
	            res=res+k.charAt(14);
	            res=res+k.charAt(6);
		        System.out.println(res);
		        String L0=new String();
		        for (int i = 0; i < 32; i++)
		        	L0=L0+res.charAt(i);
		        String R0=new String();
		        for (int i = 32; i < 64; i++)
		        	R0=R0+res.charAt(i);
		        String longR0=new String();
		        for (int i = 0; i < 32; i += 4)
                {
                    longR0=longR0+R0.charAt(i - 1 < 0 ? 31 : i - 1);
                    longR0=longR0+R0.charAt(i);
                    longR0=longR0+R0.charAt(i +1);
                    longR0=longR0+R0.charAt(i+2);
                    longR0=longR0+R0.charAt(i+3);
                    longR0=longR0+R0.charAt(i + 4 > 31 ? 0 : i + 4);
                    
                }
		        System.out.println(longR0); 
		        //sum
		        long a=0;
				for (int i = 0; i < longR0.length(); i++) {
			        a <<= 1;
			        if (longR0.charAt(i) == '1') a++;
				}
				//System.out.println(a);
				long b=0;
				
				for (int i = 0; i < X0.length(); i++) {
			        b <<= 1;
			        if (X0.charAt(i) == '1') b++;
				}
				//System.out.println(b);
				String sum=new String();
				long c=a^b;
				//System.out.println(c);
				sum=sum+Long.toBinaryString(c);
				//String str = "101101111010101110";
				
	               
				System.out.println(sum.length());
				while(sum.length()<48) {
					sum='0'+sum;
				}
				System.out.println(sum); //summa
				//convert
				 int[][]s1= 
			        {
			            {14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7} ,
			            {0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8} ,
			            {4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0} ,
			            {15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13} };
			      int[][]  s2 = 
			        {
			            {15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10} ,
			            {13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1} ,
			            {0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15} ,
			            {13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9} };
			       int[][] s3 = 
			        {
			            {10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8} ,
			            {13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1} ,
			            {13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7} ,
			           {1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12} };
			       int[][] s4 = 
			        {
			            {7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15} ,
			            {13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9} ,
			            {10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4} ,
			            {3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14} };
			        int [][]s5 = 
			        {
			            {2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9} ,
			            {14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6} ,
			            {4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14} ,
			            {11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3} };
			        
			        int[][]s6 = 
			        {
			            {12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11} ,
			            {10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8} ,
			            {9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6} ,
			            {4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13} };

			        int [][]s7 = 
			        {
			            {4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1} ,
			            {13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6} ,
			            {1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,3} ,
			            {6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12} };

			       int [][]s8 = 
			        {
			            {13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7} ,
			            {1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2} ,
			            {7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8} ,
			            {2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11} };
			    String result=new String();
				int fromS1 = s1[(sum.charAt(0)-'0') * 2 + (sum.charAt(5)-'0')][(sum.charAt(1)-'0') * 8 + (sum.charAt(2)-'0') * 4 + (sum.charAt(3)-'0') * 2 + (sum.charAt(4)-'0')];
				String sw1=Integer.toBinaryString(fromS1);
				while(sw1.length()<4) {
					sw1='0'+sw1;
				}
				result=result+sw1;
	            int fromS2 = s2[(sum.charAt(6)-'0') * 2 + (sum.charAt(11)-'0')][(sum.charAt(7)-'0') * 8 + (sum.charAt(8)-'0') * 4 + (sum.charAt(9)-'0') * 2 + (sum.charAt(10)-'0')];
	            String sw2=Integer.toBinaryString(fromS2);
				while(sw2.length()<4) {
					sw2='0'+sw2;
				}
				result=result+sw2;
	            int fromS3 = s3[(sum.charAt(12)-'0') * 2 + (sum.charAt(17)-'0')][(sum.charAt(13)-'0') * 8 + (sum.charAt(14)-'0') * 4 + (sum.charAt(15)-'0') * 2 + (sum.charAt(16)-'0')];
	            String sw3=Integer.toBinaryString(fromS3);
				while(sw3.length()<4) {
					sw3='0'+sw3;
				}
				result=result+sw3;
	            int fromS4 = s4[(sum.charAt(18)-'0') * 2 + (sum.charAt(23)-'0')][(sum.charAt(19)-'0') * 8 + (sum.charAt(20)-'0') * 4 + (sum.charAt(21)-'0') * 2 + (sum.charAt(22)-'0')];
	            String sw4=Integer.toBinaryString(fromS4);
				while(sw4.length()<4) {
					sw4='0'+sw4;
				}
				result=result+sw4;
	            int fromS5 = s5[(sum.charAt(24)-'0') * 2 + (sum.charAt(29)-'0')][(sum.charAt(25)-'0') * 8 + (sum.charAt(26)-'0') * 4 + (sum.charAt(27)-'0') * 2 +(sum.charAt(28)-'0')];
	            String sw5=Integer.toBinaryString(fromS5);
				while(sw5.length()<4) {
					sw5='0'+sw5;
				}
				result=result+sw5;
	            int fromS6 = s6[(sum.charAt(30)-'0') * 2 + (sum.charAt(35)-'0')][(sum.charAt(31)-'0') * 8 + (sum.charAt(32)-'0') * 4 + (sum.charAt(33)-'0') * 2 + (sum.charAt(34)-'0')];
	            String sw6=Integer.toBinaryString(fromS6);
				while(sw6.length()<4) {
					sw6='0'+sw6;
				}
				result=result+sw6;
	            int fromS7 = s7[(sum.charAt(36)-'0') * 2 + (sum.charAt(41)-'0')][(sum.charAt(37)-'0') * 8 + (sum.charAt(38)-'0') * 4 + (sum.charAt(39)-'0') * 2 + (sum.charAt(40)-'0')];
	            String sw7=Integer.toBinaryString(fromS7);
				while(sw7.length()<4) {
					sw7='0'+sw7;
				}
				result=result+sw7;
	            int fromS8 = s8[(sum.charAt(42)-'0') * 2 + (sum.charAt(47)-'0')][(sum.charAt(43)-'0') * 8 + (sum.charAt(44)-'0') * 4 + (sum.charAt(45)-'0') * 2 + (sum.charAt(46)-'0')];
	            String sw8=Integer.toBinaryString(fromS8);
				while(sw8.length()<4) {
					sw8='0'+sw8;
				}
				result=result+sw8;
				System.out.println(result); //sbox
				String res1=new String();
				String k1=new String(result);
				 res1=res1+k1.charAt(15);
		         res1=res1+k1.charAt(6);
		         res1=res1+k1.charAt(19);
		         res1=res1+k1.charAt(20);
		         res1=res1+k1.charAt(28);
		         res1=res1+k1.charAt(11);
		         res1=res1+k1.charAt(27);
		         res1=res1+k1.charAt(16);
		         res1=res1+k1.charAt(0);
		         res1=res1+k1.charAt(14);
		         res1=res1+k1.charAt(22);
		         res1=res1+k1.charAt(25);
		         res1=res1+k1.charAt(4);
		         res1=res1+k1.charAt(17);
		         res1=res1+k1.charAt(30);
		         res1=res1+k1.charAt(9);
		         res1=res1+k1.charAt(1);
		         res1=res1+k1.charAt(7);
		         res1=res1+k1.charAt(23);
		         res1=res1+k1.charAt(13);
		         res1=res1+k1.charAt(31);
		         res1=res1+k1.charAt(26);
		         res1=res1+k1.charAt(2);
		         res1=res1+k1.charAt(8);
		         res1=res1+k1.charAt(18);
		         res1=res1+k1.charAt(12);
		         res1=res1+k1.charAt(29);
		         res1=res1+k1.charAt(5);
		         res1=res1+k1.charAt(21);
		         res1=res1+k1.charAt(10);
		         res1=res1+k1.charAt(3);
		         res1=res1+k1.charAt(24);
		         System.out.println(res1);
		         //System.out.println(L0);
		         a=0;
					for (int i = 0; i < res1.length(); i++) {
				        a <<= 1;
				        if (res1.charAt(i) == '1') a++;
					}
					//System.out.println(a);
				 b=0;
					
					for (int i = 0; i < L0.length(); i++) {
				        b <<= 1;
				        if (L0.charAt(i) == '1') b++;
					}
					//System.out.println(b);
					sum="";
					c=a^b;
					//System.out.println(c);
					sum=sum+Long.toBinaryString(c);
					//String str = "101101111010101110";
		               
					System.out.println(sum.length());
					while(sum.length()<32) {
						sum='0'+sum;
					}
					System.out.println(sum);
		         
		         
		         
		         
		         
		         
		         
		         
		         res1=sum+L0;
		         System.out.println(res1);
		         //last
		         String res2=new String();
		         res2=res2+res1.charAt(39);
		         res2=res2+res1.charAt(7);
		         res2=res2+res1.charAt(47);
		         res2=res2+res1.charAt(15);
		         res2=res2+res1.charAt(55);
		         res2=res2+res1.charAt(23);
		         res2=res2+res1.charAt(63);
		         res2=res2+res1.charAt(31);
		         res2=res2+res1.charAt(38);
		         res2=res2+res1.charAt(6);
		         res2=res2+res1.charAt(46);
		         res2=res2+res1.charAt(14);
		         res2=res2+res1.charAt(54);
		         res2=res2+res1.charAt(22);
		         res2=res2+res1.charAt(62);
		         res2=res2+res1.charAt(30);
		         res2=res2+res1.charAt(37);
		         res2=res2+res1.charAt(5);
		         res2=res2+res1.charAt(45);
		         res2=res2+res1.charAt(13);
		         res2=res2+res1.charAt(53);
		         res2=res2+res1.charAt(21);
		         res2=res2+res1.charAt(61);
		         res2=res2+res1.charAt(29);
		         res2=res2+res1.charAt(36);
		         res2=res2+res1.charAt(4);
		         res2=res2+res1.charAt(44);
		         res2=res2+res1.charAt(12);
		         res2=res2+res1.charAt(52);
		         res2=res2+res1.charAt(20);
		         res2=res2+res1.charAt(60);
		         res2=res2+res1.charAt(28);
		         res2=res2+res1.charAt(35);
		         res2=res2+res1.charAt(3);
		         res2=res2+res1.charAt(43);
		         res2=res2+res1.charAt(11);
		         res2=res2+res1.charAt(51);
		         res2=res2+res1.charAt(19);
		         res2=res2+res1.charAt(59);
		         res2=res2+res1.charAt(27);
		         res2=res2+res1.charAt(34);
		         res2=res2+res1.charAt(2);
		         res2=res2+res1.charAt(42);
		         res2=res2+res1.charAt(10);
		         res2=res2+res1.charAt(50);
		         res2=res2+res1.charAt(18);
		         res2=res2+res1.charAt(58);
		         res2=res2+res1.charAt(26);
		         res2=res2+res1.charAt(31);
		         res2=res2+res1.charAt(1);
		         res2=res2+res1.charAt(41);
		         res2=res2+res1.charAt(9);
		         res2=res2+res1.charAt(49);
		         res2=res2+res1.charAt(17);
		         res2=res2+res1.charAt(57);
		         res2=res2+res1.charAt(25);
		         res2=res2+res1.charAt(32);
		         res2=res2+res1.charAt(0);
		         res2=res2+res1.charAt(40);
		         res2=res2+res1.charAt(8);
		         res2=res2+res1.charAt(48);
		         res2=res2+res1.charAt(16);
		         res2=res2+res1.charAt(56);
		         res2=res2+res1.charAt(24);
		         System.out.println(res2.length());
		         res2= res2.substring(0,8) + " " + res2.substring(8,16) + " " +res2.substring(16,24) + " " +res2.substring(24,32) + " " +res2.substring(32,40) + " " +res2.substring(40,48) + " " +res2.substring(48,56) + " " +res2.substring(56,64);
			     textField_4.setText(res2);
			}			
		});
		btnNewButton_1.setBounds(10, 123, 110, 23);
		getContentPane().add(btnNewButton_1);
		
		textField_4 = new JTextField();
		textField_4.setBounds(10, 157, 475, 20);
		getContentPane().add(textField_4);
		textField_4.setColumns(10);
		
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		DES lol=new DES();
		lol.setVisible(true);
		//lol.a=Integer.parseInt(lol.textField.getText());
		lol.setSize(500,220);
	}

}
