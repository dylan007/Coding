import java.util.*;
import java.io.*;
import java.awt.*;
import java.applet.*;

/*<applet code="banner" width=300 height=50></applet>*/

public class banner extends Applet implements Runnable{
	String msg = "Java suxxx";
	Thread t;
	boolean stopFlag;

	public void init(){
		t = null;
	}

	public void start(){
		t = new Thread(this);
		stopFlag = false;
		t.start();
	}

	public void run()
	{
		for(;;)
		{
			try{
				repaint();
				Thread.sleep(250);
				if(stopFlag) break;
			}catch(InterruptedException exc){
				System.out.println("Couldn't paint");
			}
		}
	}

	public void stop()
	{
		stopFlag = true;
		t = null;
	}

	public void paint(Graphics g)
	{
		char ch;
		ch = msg.charAt(0);
		msg = msg.substring(1,msg.length());
		msg += ch;
		g.drawString(msg,50,30);
		showStatus("Java suxx");
	}
}
