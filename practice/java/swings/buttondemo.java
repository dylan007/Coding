import javax.swing.*;
import java.applet.*;
import java.awt.*;
import java.awt.event.*;

class buttondemo implements ActionListener{
	JLabel jlab;

	buttondemo(){
		JFrame jfrm = new JFrame("Button Demo");
		jfrm.setLayout(new FlowLayout());
		jfrm.setSize(220,90);
		jfrm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		JButton jbtn1 = new JButton("First");
		JButton jbtn2 = new JButton("Second");
		jbtn1.addActionListener(this);
		jbtn2.addActionListener(this);

		jfrm.add(jbtn1);
		jfrm.add(jbtn2);
		jlab = new JLabel("Press a button");
		jfrm.add(jlab);
		
		jfrm.setVisible(true);

	}

	public void actionPerformed(ActionEvent e){
		if(e.getActionCommand().equals("First"))
			jlab.setText("First Button was pressed");
		else
			jlab.setText("Second Button was pressed");
	}

	public static void main(String args[]){
		SwingUtilities.invokeLater(new Runnable(){
			public void run(){
				new buttondemo();
			}
		});
	}
}
