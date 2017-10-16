import java.util.*;

class MyThread extends Thread{
	MyThread(String name){
		super(name);
		start();
	}

	public void run(){
		System.out.println(getName() + " starting");
		try{
			for(int i=0;i<10;i++){
				Thread.sleep(400);
				System.out.println("count in " + getName() + " is " +  i);
			}
		}
		catch(InterruptedException e){
			System.out.println(getName() + " interrupted");
		}
		System.out.println(getName() + " terminating");
	}
}

class extendthread{
	public static void main(String args[]){
		System.out.println("Starting main thread");

		MyThread mt = new MyThread("Child");

		for(int i=0;i<50;i++)
		{
			System.out.print(".");
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