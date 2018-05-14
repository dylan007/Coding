import java.util.*;
import java.io.*;

class RandomAccessDemo{
	public static void main(String args[])
	{
		double[] data = {19.4, 10.1, 123.54, 33.0, 87.9, 74.25};
		double d;

		try(RandomAccessFile raf = new RandomAccessFile("random.data","rw"))
		{
			for(int i=0;i<data.length;i++)
			{
				raf.writeDouble(data[i]);
			}

			for(int i=0;i<data.length;i+=2)
			{
				raf.seek(8*i);
				d = raf.readDouble();
				System.out.println(d + " ");
			}
		}catch(IOException exc){
			System.out.println("I/O Error : " + exc);
		}
	}
}
