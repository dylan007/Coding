import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class PR{

	void solve()
	{
		for(int n = 2; n <= 1000; n++) 
		{ 
			DJSet ds = new DJSet(n);
			int[][] a = new int[n * (n - 1) / 2][];
			int ptr = 0;
			for(int i = 0; i < n; i++)
				for(int j = i + 1; j < n; j++)
					a[ptr++] = new int[] {i, j, i ^ j};

			Arrays.sort(a, new Comparator<int[]>()
			{
				public int compare(int[] x, int[] y)
				{
					return x[2] - y[2];
				}
			});

			long ans = 0;
			for(int[] x : a)
				if(ds.union(x[0], x[1]))
					ans += x[2];
			
			out.println(n + ": " + ans);
		}
	}
	
	public class DJSet {

		public int[] root;
		public int[] size;
		public boolean[] head;
		public int setCount;
		
		public DJSet(int n)
		{
			root = new int[n];
			size = new int[n];
			head = new boolean[n];
			setCount = n;
			for(int i=0;i<n;i++)
			{
				root[i] = i;
				size[i] = 1;
				head[i] = true;
			}
		}
		
		public int root(int x)
		{ return root[root[x]] == root[x] ? root[x] : (root[x] = root(root[x]));}
		
		public boolean union(int x, int y)
		{
			int a = root(x);
			int b = root(y);
			
			if(a == b)
				return false;
			
			setCount--;
			
			if(size[a] < size[b])
			{
				head[a] = false;
				root[a] = b;
				size[b] += size[a];
			}
			else
			{
				head[b] = false;
				root[b] = a;
				size[a] += size[b];
			}
			return true;
		}
		
		public boolean find(int x, int y)
		{ return root(x) == root(y); }
		
		public int[] getSets()
		{
			int[] heads = new int[setCount];
			int ptr = 0;
			for(int i=0;i<head.length;i++)
				if(head[i])
					heads[ptr++] = i;
			return heads;
		}
		
	}


	public static void main(String[] args){new PR().run();}
	
	private byte[] bufferArray = new byte[1024];
	private int bufLength = 0;
	private int bufCurrent = 0;
	InputStream inputStream;
	PrintWriter out;
	
	public void run()
	{
		inputStream = System.in;
		out = new PrintWriter(System.out);
		solve();
		out.flush();
	}
	
	int nextByte()
	{
		if(bufLength == -1)
			throw new InputMismatchException();
		if(bufCurrent >= bufLength)
		{
			bufCurrent = 0;
			try
			{bufLength = inputStream.read(bufferArray);}
			catch(IOException e)
			{ throw new InputMismatchException();}
			if(bufLength <= 0)
				return -1;
		}
		return bufferArray[bufCurrent++];
	}
	
	boolean isSpaceChar(int x)
	{return (x < 33 || x > 126);}
	
	boolean isDigit(int x)
	{return (x >= '0' && x <= '9');}
	
	int nextNonSpace()
	{
		int x;
		while((x=nextByte()) != -1 && isSpaceChar(x));
		return x;
	}
	
	int ni()
	{
		long ans = nl();
		if (ans >= Integer.MIN_VALUE && ans <= Integer.MAX_VALUE)
			return (int)ans;
		throw new InputMismatchException();
	}
	
	long nl()
	{
		long ans = 0;
		boolean neg = false;
		int x = nextNonSpace();
		if(x == '-') 
		{
			neg = true;
			x = nextByte();
		}
		while(!isSpaceChar(x))
		{
			if(isDigit(x))
			{
				ans = ans * 10 + x -'0';
				x = nextByte();
			}
			else
				throw new InputMismatchException();
		}
		return neg ? -ans : ans;
	}
	
	String ns()
	{
		StringBuilder sb = new StringBuilder();
		int x = nextNonSpace();
		while(!isSpaceChar(x))
		{
			sb.append((char)x);
			x = nextByte();
		}
		return sb.toString();
	}
	
	char nc()
	{ return (char)nextNonSpace();}
	
	double nd()
	{ return (double)Double.parseDouble(ns()); }
	
	char[] ca()
	{ return ns().toCharArray();}
	
	char[] ca(int n)
	{
		char[] ans = new char[n];
		int p = 0;
		int x = nextNonSpace();
		while(p<n)
		{
			ans[p++] = (char)x;
			x = nextByte();
		}
		return ans;
	}
	
	int[] ia(int n)
	{
		int[] ans = new int[n];
		for(int i=0;i<n;i++)
			ans[i] = ni();
		return ans;
	}
	
}
