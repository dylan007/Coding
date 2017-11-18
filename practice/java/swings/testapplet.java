import java.applet.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

/*<applet code="testapplet" width=400 height=200></applet>*/

public class testapplet extends Applet implements Runnable{
	int count;
	Thread t;

	public void init()
	{
		t = null;
	}

	public void start()
	{
		t = new Thread(this);
		count = 0;
		t.start();
	}

	public void run()
	{
		try{
			while(count < 20){
				repaint();
				Thread.sleep(1000);
			}
		}catch(Exception E){
		}
	}

	public void paint(Graphics g)
	{
		count++;
		g.drawString("" + count,100,50);
	}
}
