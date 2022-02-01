package Zadachi;

import javax.swing.JFrame;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.Font;
import java.awt.Color;
import java.awt.Toolkit;

public class ALL extends JFrame {
	public ALL() {
		setIconImage(Toolkit.getDefaultToolkit().getImage("C:\\Users\\\u0414\u043C\u0438\u0442\u0440\u0438\u0439\\Downloads\\iStock-1034901762_d_850.jpg"));
		getContentPane().setBackground(Color.CYAN);
		setTitle("ALL");
		getContentPane().setLayout(null);
		
		JButton btnNewButton = new JButton("\u2116 1");
		btnNewButton.setBackground(Color.GREEN);
		btnNewButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				DES lol=new DES();
				lol.setVisible(true);
				//lol.a=Integer.parseInt(lol.textField.getText());
				lol.setSize(500,220);
			}
		});
		btnNewButton.setFont(new Font("Tahoma", Font.PLAIN, 13));
		/*
		btnNewButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				EZP lol=new EZP();
				lol.setVisible(true);
				//lol.a=Integer.parseInt(lol.textField.getText());
				lol.setSize(490,208);
			}
			
		});
		*/
		btnNewButton.setBounds(20, 11, 91, 23);
		getContentPane().add(btnNewButton);
		
		JButton btnNewButton_1 = new JButton("\u2116 2");
		btnNewButton_1.setBackground(Color.GREEN);
		btnNewButton_1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				GOST lol=new GOST();
				lol.setVisible(true);
				//lol.a=Integer.parseInt(lol.textField.getText());
				lol.setSize(500,220);
			}
		});
		btnNewButton_1.setFont(new Font("Tahoma", Font.PLAIN, 13));
		btnNewButton_1.setBounds(125, 12, 91, 23);
		getContentPane().add(btnNewButton_1);
		
		JButton btnNewButton_1_1 = new JButton("\u2116 3");
		btnNewButton_1_1.setBackground(Color.GREEN);
		btnNewButton_1_1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				PartRSA lol=new PartRSA();
				lol.setVisible(true);
				//lol.a=Integer.parseInt(lol.textField.getText());
				lol.setSize(470,150);
			}
		});
		btnNewButton_1_1.setFont(new Font("Tahoma", Font.PLAIN, 13));
		btnNewButton_1_1.setBounds(234, 12, 91, 23);
		getContentPane().add(btnNewButton_1_1);
		
		JButton btnNewButton_1_2 = new JButton("\u2116 4");
		btnNewButton_1_2.setBackground(Color.GREEN);
		btnNewButton_1_2.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				HESH lol=new HESH();
				lol.setVisible(true);
				//lol.a=Integer.parseInt(lol.textField.getText());
				lol.setSize(405,120);
			}
		});
		btnNewButton_1_2.setFont(new Font("Tahoma", Font.PLAIN, 13));
		btnNewButton_1_2.setBounds(335, 11, 91, 23);
		getContentPane().add(btnNewButton_1_2);
		
		JButton btnNewButton_1_3 = new JButton("\u2116 5");
		btnNewButton_1_3.setBackground(Color.GREEN);
		btnNewButton_1_3.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				EZP lol=new EZP();
				lol.setVisible(true);
				//lol.a=Integer.parseInt(lol.textField.getText());
				lol.setSize(490,180);
			}
		});
		btnNewButton_1_3.setFont(new Font("Tahoma", Font.PLAIN, 13));
		btnNewButton_1_3.setBounds(441, 11, 91, 23);
		getContentPane().add(btnNewButton_1_3);
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ALL lol=new ALL();
		lol.setVisible(true);
		//lol.a=Integer.parseInt(lol.textField.getText());
		lol.setSize(550,80);
	}

}
