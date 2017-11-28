import java.util.*;
import java.io.*;

class Box{
	int h,b,w;

	Box()
	{
		h = 10;
		b = 10;
		w = 10;
	}

	Box(int h,int b,int w)
	{
		this.h = h;
		this.b = b;
		this.w = w;
	}

	void display()
	{
		System.out.println(h + " " + b + " " + w);
	}
}

class box{
	public static void main(String args[])
	{
		Box t = new Box();
		t.display();
		t = new Box(5,5,5);
		t.display();
	}
}