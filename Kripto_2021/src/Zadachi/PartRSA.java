package Zadachi;

import javax.swing.JFrame;
import java.awt.Color;
import javax.swing.JLabel;
import java.awt.BorderLayout;
import javax.swing.SwingConstants;
import java.awt.Font;
import java.awt.Window.Type;
import javax.swing.JButton;
import javax.swing.JTextField;
import java.awt.event.ActionListener;
import java.math.BigInteger;
import java.awt.event.ActionEvent;
import java.awt.Toolkit;

public class PartRSA extends JFrame {
	private JTextField textField;
	private JTextField textField_1;
	private JTextField textField_2;
	private JTextField textField_3;
	private JTextField textField_4;
	private JTextField textField_5;
	public int q;
	public int p;
	public int param_e;
	public int pq;
	public int d;
	private JTextField textField_6;
	private JLabel lblNewLabel_3;
	private JLabel lblNewLabel_4;
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
        System.out.println(k);
        return e;
    }
	public PartRSA() {
		setIconImage(Toolkit.getDefaultToolkit().getImage("C:\\Users\\\u0414\u043C\u0438\u0442\u0440\u0438\u0439\\Downloads\\iStock-1034901762_d_850.jpg"));
		getContentPane().setBackground(Color.CYAN);
		setTitle("Part3");
		setForeground(Color.WHITE);
		getContentPane().setLayout(null);
		//setVisible(true);
		JLabel lblNewLabel = new JLabel("q");
		lblNewLabel.setFont(new Font("Dialog", Font.BOLD, 16));
		lblNewLabel.setBounds(102, 0, 21, 29);
		getContentPane().add(lblNewLabel);
		
		textField = new JTextField();
		textField.setBounds(126, 6, 73, 20);
		getContentPane().add(textField);
		textField.setColumns(10);
		
		
		JLabel lblP = new JLabel("p");
		lblP.setFont(new Font("Dialog", Font.BOLD, 16));
		lblP.setBounds(10, 0, 21, 29);
		getContentPane().add(lblP);
		
		textField_1 = new JTextField();
		textField_1.setBounds(26, 6, 66, 20);
		getContentPane().add(textField_1);
		textField_1.setColumns(10);
		
		JLabel lblNewLabel_1 = new JLabel("\u0428\u0438\u0444\u0440\u0443\u0435\u043C\u043E\u0435");
		lblNewLabel_1.setFont(new Font("Dialog", Font.BOLD, 14));
		lblNewLabel_1.setBounds(209, 7, 92, 16);
		getContentPane().add(lblNewLabel_1);
		
		textField_2 = new JTextField();
		textField_2.setBounds(311, 6, 104, 20);
		getContentPane().add(textField_2);
		textField_2.setColumns(10);
		
		textField_3 = new JTextField();
		textField_3.setBounds(86, 34, 104, 20);
		getContentPane().add(textField_3);
		textField_3.setColumns(10);
		
		textField_4 = new JTextField();
		textField_4.setBounds(311, 34, 104, 20);
		getContentPane().add(textField_4);
		textField_4.setColumns(10);
		
		JLabel lblNewLabel_2 = new JLabel("Public key");
		lblNewLabel_2.setFont(new Font("Dialog", Font.BOLD, 14));
		lblNewLabel_2.setBounds(10, 35, 128, 16);
		getContentPane().add(lblNewLabel_2);
		
		JLabel lblNewLabel_2_1 = new JLabel("Private key");
		lblNewLabel_2_1.setFont(new Font("Dialog", Font.BOLD, 14));
		lblNewLabel_2_1.setBounds(204, 35, 128, 16);
		getContentPane().add(lblNewLabel_2_1);
		
		JButton btnNewButton = new JButton("\u0428\u0438\u0444\u0440\u043E\u0432\u0430\u0442\u044C");
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
				textField_3.setText("("+param_e+","+pq+")"); 
				textField_4.setText("("+d+","+pq+")");
				String codeText1=textField_2.getText();
				System.out.println(codeText1);
				int[] codeText=new int[3];
				for (int i=0;i<codeText1.length();i++) {
				char letter = codeText1.charAt(i);
				int ascii = (int) letter;
				
				codeText[i]=ascii-1039;
				if(ascii>=1046) {codeText[i]++;}
				if(ascii==1025) {codeText[i]=7;}
				System.out.println(codeText[i]);}
				BigInteger c=new BigInteger(Integer.toString(pq));
				for (int temp:codeText)
	            {
	                BigInteger b=new BigInteger(Integer.toString(temp));
	                
	                System.out.println(b);
	                b = b.pow(param_e);
	                b=b.mod(c);
	                System.out.println(b);
	                String k=textField_5.getText();
	                textField_5.setText(k+b+",");
	            }
				StringBuffer l=new StringBuffer(textField_5.getText());
				System.out.println(l.delete(l.length()-1,l.length()));
				textField_5.setText(l.toString());
			}
		});
		btnNewButton.setBounds(10, 65, 122, 26);
		getContentPane().add(btnNewButton);
		
		textField_5 = new JTextField();
		textField_5.setBounds(77, 95, 122, 20);
		getContentPane().add(textField_5);
		textField_5.setColumns(10);
		
		JButton btnNewButton_1 = new JButton("\u0414\u0435\u0448\u0438\u0444\u0440\u043E\u0432\u0430\u0442\u044C");
		btnNewButton_1.setBackground(Color.GREEN);
		btnNewButton_1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String c=textField_5.getText();
				int[] codeText=new int[3];
				String lol="";
				int k=0;
				for (int i=0;i<c.length();i++) {
					if (c.charAt(i)==',') {
						codeText[k]=Integer.parseInt(lol);
						//System.out.println(codeText[k]);
						k++;
						lol="";
					}
					else {
						lol=lol+c.charAt(i);
					}
					
				}
				codeText[k]=Integer.parseInt(lol);
				System.out.println(codeText);
				BigInteger cd=new BigInteger(Integer.toString(pq));
				String str = "ÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏÐÑÒÓÔÕÖ×ØÙÚÛÜÝÞß";
				for (int temp:codeText)
	            {
	                BigInteger b=new BigInteger(Integer.toString(temp));
	                
	                //System.out.println(b);
	                b = b.pow(d);
	                b=b.mod(cd);
	                System.out.println(b.intValue());
	                char ks=str.charAt(b.intValue()-1);
	                String lp=textField_6.getText();
	                textField_6.setText(lp+ks);
	            }
			}
		});
		btnNewButton_1.setBounds(272, 65, 138, 26);
		getContentPane().add(btnNewButton_1);
		
		textField_6 = new JTextField();
		textField_6.setBounds(323, 95, 138, 20);
		getContentPane().add(textField_6);
		textField_6.setColumns(10);
		
		lblNewLabel_3 = new JLabel("\u0420\u0435\u0437\u0443\u043B\u044C\u0442\u0430\u0442");
		lblNewLabel_3.setBounds(10, 97, 122, 16);
		getContentPane().add(lblNewLabel_3);
		
		lblNewLabel_4 = new JLabel("\u0420\u0435\u0437\u0443\u043B\u044C\u0442\u0430\u0442");
		lblNewLabel_4.setBounds(250, 97, 138, 16);
		getContentPane().add(lblNewLabel_4);
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		PartRSA lol=new PartRSA();
		lol.setVisible(true);
		//lol.a=Integer.parseInt(lol.textField.getText());
		lol.setSize(470,150);
		//System.out.println(lol.a);
	}
}
