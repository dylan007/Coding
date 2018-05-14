import java.util.*;
import java.io.*;

class ReadLines{
	public static void main(String args[]) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str;

		System.out.println("Enter lines of text. Enter \"Stop\" to quit");
		do{
			str = br.readLine();
			System.out.println(str);
		}while(!str.equals("Stop"));
	}
}
