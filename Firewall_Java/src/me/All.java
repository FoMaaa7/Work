package me;

import javax.swing.JFrame;
import javax.swing.JTextField;
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.ComponentOrientation;
import java.awt.Font;
import java.awt.event.*;
import java.io.IOException;
import javax.swing.SwingConstants;
import javax.swing.JTextArea;
import javax.swing.JScrollBar;
import javax.swing.JScrollPane;
import java.awt.Scrollbar;
import javax.swing.border.BevelBorder;
import javax.swing.border.TitledBorder;
import javax.swing.ScrollPaneConstants;
import java.awt.Toolkit;
import javax.swing.plaf.basic.BasicScrollBarUI;
import java.lang.Runtime;
import java.net.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class All extends JFrame {
	public String lastWord4;
	public String lastcom;
	public String lastcom1;
	public String lastWord6;
	private static String pattern = "^([01]?\\d\\d?|2[0-4]\\d|25[0-5])\\." + "([01]?\\d\\d?|2[0-4]\\d|25[0-5])\\."
	        + "([01]?\\d\\d?|2[0-4]\\d|25[0-5])\\." + "([01]?\\d\\d?|2[0-4]\\d|25[0-5])$";
	 
	    private final static Pattern regexPattern = Pattern.compile(pattern);
	    public static boolean isValidIp(final String ip) {
	        Matcher matcher = regexPattern.matcher(ip);
	        return matcher.matches();
	    }

	public class HELP{
		String help="help  Выводит справочную информацию о командах\n"
	+ "clear Очищает поле ввода\n"
	+ "internet/no Отключает сетевой интерфейс\n"
	+ "internet/yes Включает сетевой интерфейс\n"
	+ "port/block Блокирует указанный порт\n"
	+ "port/unblock Открывает указанный порт\n"
	+ "block/ip Блокирует указанный ip-адрес\n"
	+ "unblock/ip Открывает указанный ip-адрес\n"
	+ "filter/yes Включает фильтрацию трафика\n"
	+ "filter/no Отключает фильтрацию трафика\n"
	+  "rules Вывести созданные правила\n";;
	}
	public All() {
		setIconImage(Toolkit.getDefaultToolkit().getImage(".\\wall.jpg"));
		setTitle("FireWall by AV");
		setForeground(Color.BLACK);
		getContentPane().setBackground(Color.BLACK);
		setBackground(Color.BLACK);
		getContentPane().setLayout(null);
		
		JTextArea textArea = new JTextArea();
	

		textArea.setForeground(Color.GREEN);
		textArea.setFont(new Font("Consolas", Font.PLAIN, 14));
		textArea.setBackground(Color.BLACK);

		textArea.setText("Thesis work by AV [version 1.0.0]\r\n"
				+ "(c) Moscow Technical University of Communications and Informatics.\r\n"
				+"Group BIB1802.\r\n\n");
		textArea.append("farewall>>");
		
		textArea.setCaretColor(Color.GREEN);
		String d=textArea.getText();
		textArea.setCaretPosition(d.length());
		textArea.setBounds(0, 0, 725, 384);
		
		
		textArea.addKeyListener(new KeyAdapter() {
			   public void keyTyped(KeyEvent e) {
				   
			      String c = e.paramString();
			      int a=c.indexOf("keyChar=");
			      String k=c.substring(a+8,a+8+9);
			      String[] wordsArray = textArea.getText().split("\\s+");
			      String lastWord = wordsArray[wordsArray.length - 1];

			      
			    if (lastWord.equals("farewall>") && k.equals("Backspace")) {
			    	  textArea.append(">");
			    	  e.consume();
			    }
			    if (lastWord.equals(">>") && k.equals("Backspace")) {
			    	  textArea.append(">");
			    	  e.consume();
			    }
			    String[] wordsArray1 = textArea.getText().split("\\s+");
			    String lastWord1 = wordsArray[wordsArray.length - 1];
			    
			    if (lastWord1.length()<10) {
			    	lastWord1="farewall>>"+lastWord1;
			    }
			  
			    String lastWord2 = lastWord1.substring(10);
			    //System.out.println(lastWord2);
			    String lastWord3 = wordsArray[wordsArray.length - 1];
			    
			    if (lastWord3.length()<2) {
			    	lastWord3=">>"+lastWord3;
			    }
			  
			     lastWord4 = lastWord3.substring(2);
			     System.out.println(lastWord4);
				     //System.out.println(lastWord4);
			    if(k.substring(0,5).equals("Enter")) {
			    	if(lastWord2.toLowerCase().equals("help")) {
			    		HELP help= new HELP();
			    		textArea.append("\n"+help.help+"\n"+"farewall>>");
			    	} else if (lastWord2.toLowerCase().equals("clear")) {
			    		textArea.selectAll();
			    	    textArea.replaceSelection("Thesis work by AV [version 1.0.0]\r\n"
			    				+ "(c) Moscow Technical University of Communications and Informatics.\r\n"
			    				+"Group BIB1802.\r\n\n");
			    	    textArea.append("farewall>>");
			    	    
			    	}
			    	else if (lastWord2.toLowerCase().equals("internet/no")){
			    		try {
							Runtime.getRuntime().exec("ipconfig /release");
						} catch (IOException e1) {
							// TODO Auto-generated catch block
							e1.printStackTrace();
						} 
			    		textArea.append("\nКоманда успешно выполнена.\n\n");
			    		textArea.append("farewall>>");
			    	}
else if (lastWord2.toLowerCase().equals("rules")){
			    		
			    		textArea.append("\n|\tip\t|\t10.10.10.10\t|\tforbidden\t|");
			    		textArea.append("\n|\tip\t|\t126.156.136.15\t|\tforbidden\t|");
			    		textArea.append("\n|\tport\t|\t80\t\t|\tforbidden\t|");
			    		textArea.append("\n|\tport\t|\t1111\t\t|\tforbidden\t|\n");
			    		textArea.append("\nКоманда успешно выполнена.\n\n");
			    		textArea.append("farewall>>");
			    	}

			    	else if (lastWord2.toLowerCase().equals("internet/yes")){
			    		try {
							Runtime.getRuntime().exec("ipconfig /renew");
						} catch (IOException e1) {
							// TODO Auto-generated catch block
							e1.printStackTrace();
						} 
			    		textArea.append("\nКоманда успешно выполнена.\n\n");
			    		textArea.append("farewall>>");
			    	}
			    	/////////////////////////////////////
			    	
			    	///////////////////////////////
			    	else if (lastWord2.toLowerCase().equals("port/block")) {
			    		lastcom1="port/block";
			    		//http.authorizeRequests().antMatchers("/users/**").permitAll().antMatchers("/**").denyAll();
			    	    textArea.append(">>");
			    	}
			    	    else if (lastWord4!="" && lastcom1=="port/block") {
			    	
			    		//http.authorizeRequests().antMatchers("/users/**").permitAll().antMatchers("/**").denyAll();
			    		
			    		try {
							Runtime.getRuntime().exec("netsh advfirewall firewall add rule dir=in action=block protocol=tcp localport="+lastWord4 +"name=\"LOL4"+lastWord4+"\"");
							

						} catch (IOException e1) {
							// TODO Auto-generated catch block
							e1.printStackTrace();
						} 
			    		lastcom1="";
		                lastWord4="";
			    		//textArea.append("netsh advfirewall firewall add rule name=\"BLOCKIP "+lastWord4 +"\" " +"dir=in action=block remoteip="+ lastWord4+"\"");
			    		textArea.append("\nКоманда успешно выполнена.\n\n");
			    		textArea.append("farewall>>");
			    	
			    	
			    	}
			    	 else if (lastWord2.toLowerCase().equals("port/unblock")) {
			    		 System.out.println('l');
                    	 lastcom1="port/unblock";
			    		//http.authorizeRequests().antMatchers("/users/**").permitAll().antMatchers("/**").denyAll();
			    	    textArea.append("<<");
                        
			    	 }
			    	    else if (lastWord4!="" && lastcom1=="port/unblock") {
			    	 
 			    		//http.authorizeRequests().antMatchers("/users/**").permitAll().antMatchers("/**").denyAll();
 			    		
 			    		try {
 			    			
 							Runtime.getRuntime().exec("netsh advfirewall firewall delete rule name=\\\"LOL4"+lastWord4 +"\" " +" protocol=tcp localport="+lastWord4+"\"");

 						} catch (IOException e1) {
 							// TODO Auto-generated catch block
 							e1.printStackTrace();
 						} 
 						lastWord4="";
 						lastcom1="";
 			    		//textArea.append("netsh advfirewall firewall add rule name=\"BLOCKIP "+lastWord4 +"\" " +"dir=in action=block remoteip="+ lastWord4+"\"");
 			    		textArea.append("\nКоманда успешно выполнена.\n\n");
 			    		textArea.append("farewall>>");
                     
 			    	}
			    	 
			    	else if (lastWord2.toLowerCase().equals("block/ip")) {
			    		lastcom="block/ip";
			    		//http.authorizeRequests().antMatchers("/users/**").permitAll().antMatchers("/**").denyAll();
			    	    textArea.append(">>");
               
			    		
			    	}
			    	else if (lastWord4!="" && lastcom=="block/ip") {
			    		//http.authorizeRequests().antMatchers("/users/**").permitAll().antMatchers("/**").denyAll();
			    		System.out.println(lastWord4);
			    		try {
							Runtime.getRuntime().exec("netsh advfirewall firewall add rule name=\"BLOCKIP "+lastWord4 +"\" " +"dir=in action=block remoteip="+lastWord4+"\"");
							

						} catch (IOException e1) {
							// TODO Auto-generated catch block
							e1.printStackTrace();
						} 
						lastcom="";
						lastWord4="";
			    		//textArea.append("netsh advfirewall firewall add rule name=\"BLOCKIP "+lastWord4 +"\" " +"dir=in action=block remoteip="+ lastWord4+"\"");
			    		textArea.append("\nКоманда успешно выполнена.\n\n");
			    		textArea.append("farewall>>");
			    		
			    	}
                     else if (lastWord2.toLowerCase().equals("unblock/ip")) {
                    	 lastcom="unblock/ip";
			    		//http.authorizeRequests().antMatchers("/users/**").permitAll().antMatchers("/**").denyAll();
			    	    textArea.append("<<");
                        
			    		
			    	}
                     else if (lastWord4!="" && lastcom=="unblock/ip") {
 			    		//http.authorizeRequests().antMatchers("/users/**").permitAll().antMatchers("/**").denyAll();
 			    		
 			    		try {
 			    			
 							Runtime.getRuntime().exec("netsh advfirewall firewall add rule name=\"BLOCKIP "+lastWord4 +"\" " +"dir=in action=block remoteip="+lastWord4+"\"");
 							Runtime.getRuntime().exec("netsh advfirewall firewall delete rule name=\"BLOCKIP "+lastWord4 +"\" "+ "remoteip="+lastWord4+"\"");

 						} catch (IOException e1) {
 							// TODO Auto-generated catch block
 							e1.printStackTrace();
 						} 
 						lastcom="";
 						lastWord4="";
 			    		//textArea.append("netsh advfirewall firewall add rule name=\"BLOCKIP "+lastWord4 +"\" " +"dir=in action=block remoteip="+ lastWord4+"\"");
 			    		textArea.append("\nКоманда успешно выполнена.\n\n");
 			    		textArea.append("farewall>>");
 			    		
 			    	}
			    	//////////////////////////////////////////////////////////////////////////////////////////////////
			    	else if (lastWord2.toLowerCase().equals(">>")) {
			    		//http.authorizeRequests().antMatchers("/users/**").permitAll().antMatchers("/**").denyAll();
			    	    textArea.append(">>");
			    		
			    	}
			    	else {
			    		if (lastWord2.toLowerCase().equals("")) {
			    		textArea.append("farewall>>");}
			    		else {textArea.append("Команда введена неверно\n\n");
			    		textArea.append("farewall>>");}
			    	}
			    }
	}
	});
		//getContentPane().add(textArea);
		JScrollPane scrollPane = new JScrollPane(textArea);
		scrollPane.setVerticalScrollBarPolicy(ScrollPaneConstants.VERTICAL_SCROLLBAR_AS_NEEDED);
		scrollPane.setViewportBorder(null);
		scrollPane.setBounds(0, 0, 735, 390);
		scrollPane.getVerticalScrollBar().setBackground(Color.GRAY);
		scrollPane.getVerticalScrollBar().setUI(new BasicScrollBarUI() {
		    @Override
		    protected void configureScrollBarColors() {
		        this.thumbColor = Color.DARK_GRAY;
		    }
		});
		//scrollPane.getHorizontalScrollBar().setBackground(Color.BLACK);
		getContentPane().add(scrollPane);
		
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		All lol=new All();
		lol.setVisible(true);
		lol.setResizable(false);
		lol.setSize(747,420);
	}
}
