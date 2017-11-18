import java.io.*;

class ShowFile{
	public static void main(String args[])
	{
		FileInputStream fin = null;

		if(args.length!=1)
		{
			System.out.println("Usage : ShowFile Filename");
			return;
		}

		try{
			fin = new FileInputStream(args[0]);
		}catch(Exception e){
			System.out.println("File not found");
		}

		try{
			int x;
			do{
				x = fin.read();
				if(x != -1)
					System.out.print((char)x);
			}while(x!=-1);
		}catch(Exception e)
		{
			System.out.println("Error reading file");
		}finally{
			try{
				if(fin != null)
					fin.close();
			}catch(Exception e)
			{
				System.out.println("Error closing file");
			}
		}
	}
}
