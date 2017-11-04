import java.io.*;
import java.util.*;

class ShowFile{
	public static void main(String args[]){
		int i;
		FileInputStream fin=null;

		if(args.length != 1)
		{
			System.out.println("Usage : ShowFile filename");
			return;
		}

		try{
			fin = new FileInputStream(args[0]);	
			do{
				i = fin.read();
				if(i>=0) System.out.print((char) i);
			}while(i!=-1);
		}
		catch(FileNotFoundException exc){
			System.out.println("File not found");
			return;
		}
		catch(IOException exc){
			System.out.println("Error reading File");
		}
		finally{
			try{
				if(fin != null)
					fin.close();
			}
			catch(IOException exc){
				System.out.println("Error Closing file");
			}
		}
	}
}
