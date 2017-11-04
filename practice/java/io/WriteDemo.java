import java.util.*;
import java.io.*;

class WriteDemo{
	public static void main(String args[])
	{
		byte data[] = {48,49,50,51,52,53,54,55,56,57,58};
		System.out.write(data,2,8);
		System.out.write('\n');
	}
}
