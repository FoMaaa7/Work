package Zadachi;
//lol
import javax.swing.JFrame;
import javax.swing.JTextField;
import javax.swing.JLabel;
import java.awt.Font;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.Color;
import java.awt.Toolkit;

public class HESH extends JFrame {
	private JTextField textField;
	private JTextField textField_1;
	private JTextField textField_2;
	private JTextField textField_3;
	private JTextField textField_4;
	public int p;
	public int q;
	public HESH() {
		setIconImage(Toolkit.getDefaultToolkit().getImage("C:\\Users\\\u0414\u043C\u0438\u0442\u0440\u0438\u0439\\Downloads\\iStock-1034901762_d_850.jpg"));
		getContentPane().setBackground(Color.CYAN);
		setTitle("4");
		getContentPane().setLayout(null);
		
		textField = new JTextField();
		textField.setBounds(25, 11, 81, 20);
		getContentPane().add(textField);
		textField.setColumns(10);
		
		JLabel lblNewLabel = new JLabel("p");
		lblNewLabel.setFont(new Font("Tahoma", Font.PLAIN, 14));
		lblNewLabel.setBounds(10, 4, 29, 30);
		getContentPane().add(lblNewLabel);
		
		JLabel lblNewLabel_1 = new JLabel("q");
		lblNewLabel_1.setFont(new Font("Tahoma", Font.PLAIN, 14));
		lblNewLabel_1.setBounds(147, 9, 29, 20);
		getContentPane().add(lblNewLabel_1);
		
		textField_1 = new JTextField();
		textField_1.setBounds(176, 11, 74, 20);
		getContentPane().add(textField_1);
		textField_1.setColumns(10);
		
		JLabel lblNewLabel_2 = new JLabel("H0:");
		lblNewLabel_2.setFont(new Font("Tahoma", Font.PLAIN, 14));
		lblNewLabel_2.setBounds(271, 11, 29, 17);
		getContentPane().add(lblNewLabel_2);
		
		textField_2 = new JTextField();
		textField_2.setBounds(311, 11, 68, 20);
		getContentPane().add(textField_2);
		textField_2.setColumns(10);
		
		JButton btnNewButton = new JButton("\u0425\u0435\u0448");
		btnNewButton.setBackground(Color.GREEN);
		btnNewButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				p=Integer.parseInt(textField.getText());
				q=Integer.parseInt(textField_1.getText());
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
				textField_4.setText(Integer.toString(H));
			}
		});
		btnNewButton.setFont(new Font("Tahoma", Font.PLAIN, 14));
		btnNewButton.setBounds(0, 55, 123, 23);
		getContentPane().add(btnNewButton);
		
		JLabel lblNewLabel_3 = new JLabel("\u0422\u0435\u043A\u0441\u0442");
		lblNewLabel_3.setFont(new Font("Tahoma", Font.PLAIN, 14));
		lblNewLabel_3.setBounds(10, 33, 74, 20);
		getContentPane().add(lblNewLabel_3);
		
		textField_3 = new JTextField();
		textField_3.setBounds(58, 33, 118, 20);
		getContentPane().add(textField_3);
		textField_3.setColumns(10);
		
		textField_4 = new JTextField();
		textField_4.setBounds(133, 58, 106, 20);
		getContentPane().add(textField_4);
		textField_4.setColumns(10);
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		HESH lol=new HESH();
		lol.setVisible(true);
		//lol.a=Integer.parseInt(lol.textField.getText());
		lol.setSize(405,120);
	}
}
