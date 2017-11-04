import java.io.*;
import java.util.*;

class ReadBytes{
	public static void main(String args[]) throws IOException{
		byte[] data = new byte[10];
		int numRead = System.in.read(data);
		for(int i=0;i<numRead;i++)
			System.out.print((char) data[i]);

	}
}
