import java.util.*;

class MyThread implements Runnable{
	String thrdname;
	MyThread(String name){
		this.thrdname = name;
	}
	public void run(){
		System.out.println(thrdname + " Starting");
		try{
			for(int i=0;i<10;i++){
				Thread.sleep(400);
				System.out.println("In " + thrdname + " count is " + i);
			}
		}
		catch(InterruptedException e){
			System.out.println("Thread " + thrdname + " terminating");
		}
		System.out.println(thrdname + " terminating");
	}
}

class usethreads{
	public static void main(String args[]){
		System.out.println("Main thread starting.");

		MyThread mt = new MyThread("Child 1");

		Thread nt = new Thread(mt);

		nt.start();

		for(int i=0;i<50;i++){	
			System.out.print(".");
			try{
				Thread.sleep(100);
			}
			catch(InterruptedException e){
				System.out.println("Main thread Interrupted");
			}
		}
		System.out.println("Main thread ending");
	}
}