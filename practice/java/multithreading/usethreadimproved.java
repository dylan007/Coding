import java.util.*;

class MyThread implements Runnable{
	Thread thrd;

	MyThread(String name){
		thrd = new Thread(this,name);
		thrd.start();
	}

	public void run(){
		System.out.println(thrd.getName() + " starting.");
		try{
			for(int count=0; count<10; count++){
				Thread.sleep(400);
				System.out.println("In " + thrd.getName() + ", count is " + count);
			}
		}
		catch(InterruptedException e){
			System.out.println(thrd.getName() + " interrupted");
		}
		System.out.println(thrd.getName() + " terminating");
	}
}

class usethreadsimproved{
	public static void main(String args[]){
		System.out.println("Main thread starting.");

		MyThread mt = new MyThread("Child 1");

		for(int i=0;i<50;i++){
			System.out.println(".");
			try{
				Thread.sleep(100);
			}
			catch(InterruptedException e){
				System.out.println("Main thread interrupted");
			}
		}
		System.out.println("Main thread terminating");
	}
}