import java.util.*;
import java.io.*;
import java.applet.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class libmanagement{
	JTextField book,author;
	JLabel l1,l2;

	libmanagement(){
		JFrame jfrm = new JFrame("Library Management");
		jfrm.setSize(800,600);
		jfrm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		jfrm.setLayout(new FlowLayout());

		book = new JTextField(40);
		author = new JTextField(40);
		l1 = new JLabel("Book : ");
		l2 = new JLabel("Author : ");
		book.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				l1.setText("Book : " + book.getText());
			}
		});	
		author.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				l2.setText("Author : " + author.getText());
			}
		});
		jfrm.add(book);
		jfrm.add(author);
		jfrm.add(l1);
		jfrm.add(l2);
		jfrm.setVisible(true);
	}

	public static void main(String args[]){
		SwingUtilities.invokeLater(new Runnable(){
			public void run()
			{
				new libmanagement();
			}
		});
	}
}
