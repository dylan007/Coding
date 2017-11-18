import java.applet.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class textfielddemo{
	JTextField jtf1,jtf2;

	textfielddemo(){
		JFrame jfrm = new JFrame("TextField Demo");
		jfrm.setSize(400,200);
		jfrm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		jfrm.setLayout(new FlowLayout());

		jtf1 = new JTextField(30);
		jtf1.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				String s = jtf1.getText();
				String out = "";
				for(int i=0;i<s.length();i++)
					out += (char)(s.charAt(i) + 1);
				jtf2.setText(out);
			}
		});
		jtf1.setActionCommand("encode");
		jfrm.add(jtf1);

		jtf2 = new JTextField(30);
		jtf2.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				String s = jtf2.getText();
				String out = "";
				for(int i=0;i<s.length();i++)
					out += (char)(s.charAt(i) - 1);
				jtf1.setText(out);
			}
		});
		jtf2.setActionCommand("decode");
		jfrm.add(jtf2);

		jfrm.setVisible(true);
	}

	public static void main(String args[])
	{
		SwingUtilities.invokeLater(new Runnable(){
			public void run(){
				new textfielddemo();
			}
		});
	}
}	
