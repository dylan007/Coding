import java.applet.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;

class stopwatch implements ActionListener{
	JLabel jlab;
	long start;

	stopwatch(){
		JFrame jfrm = new JFrame("StopWatch");

		jfrm.setLayout(new FlowLayout());
		jfrm.setSize(400,200);
		jfrm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		JButton start = new JButton("Start");
		JButton stop = new JButton("Stop");

		start.addActionListener(this);
		stop.addActionListener(this);

		jfrm.add(start);
		jfrm.add(stop);
		
		jlab = new JLabel("Start the stopwatch");
		jfrm.add(jlab);

		jfrm.setVisible(true);
	}

	public void actionPerformed(ActionEvent e){
		Calendar cal = Calendar.getInstance();
		if(e.getActionCommand().equals("Start"))
		{
			start = cal.getTimeInMillis();
			jlab.setText("Stopwatch is Running...");
		}
		else
		{
			long x = cal.getTimeInMillis();
			jlab.setText("Time elasped is " + ((double)(x-start))/1000);
		}
	}

	public static void main(String args[])
	{
		SwingUtilities.invokeLater(new Runnable(){
			public void run()
			{
				new stopwatch();
			}
		});
	}
}
