import javax.swing.*;

class swingdemo{
	swingdemo()
	{
		JFrame jfrm = new JFrame("A Simple Swing application");
		jfrm.setSize(275,100);
		jfrm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		JLabel jlab = new JLabel("Swing suxxx");
		jfrm.add(jlab);
		jfrm.setVisible(true);
	}

	public static void main(String args[])
	{
		SwingUtilities.invokeLater(new Runnable(){
			public void run()
			{
				new swingdemo();
			}
		});	
	}
}
