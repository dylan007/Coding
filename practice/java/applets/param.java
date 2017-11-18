import java.awt.*;
import java.applet.*;

/*<applet code="param" width=300 height=80>
 <param name=author value="Herb and Dale">
 <param name=purpose value="Demonstrate Parameters">
 <param name=version value=2>
 </applet>*/

public class param extends Applet{
	String author;
	String purpose;
	int ver;
	
	public void start(){
		String temp;
		author = getParameter("author");
		purpose = getParameter("purpose");
		temp = getParameter("version");
		try{
			if(temp!=null)
				ver = Integer.parseInt(temp);
			else
				ver = 0;
		}catch(NumberFormatException exc){
			ver = -1;
		}
	}	

	public void paint(Graphics g){
		g.drawString("Author is "+author , 10,10);
		g.drawString("Purpose is "+purpose, 10,30);
		g.drawString("Version is "+ver,10, 50);
	}
}
