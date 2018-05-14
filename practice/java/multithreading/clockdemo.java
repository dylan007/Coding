import java.util.*;

class TickTock{
	String state;

	synchronized void tick(boolean running){
		if(!running){
			state = "ticked";
			notify();
			return;
		}
		System.out.print("Tick ");
		state = "ticked";
		notify();
		try{
			while(!state.equals("tocked")){
				wait();
			}
		}
		catch(InterruptedException e){
			System.out.println("Thread interrupted");
		}
	}

	synchronized void tock(boolean running){
		if(!running){
			state = "tocked";
			notify();
			return;
		}
		System.out.println("Tock");
		state = "tocked";
		notify();
		try{
			while(!state.equals("ticked")){
				wait();
			}
		}
		catch(InterruptedException e){
			System.out.println("Thread interrupted");
		}
	}
}


class MyThread implements Runnable{
	TickTock ttob;
	Thread thrd;

	MyThread(String name,TickTock tt){
		thrd = new Thread(this,name);
		ttob = tt;
		thrd.start();
	}

	public void run(){
		if(thrd.getName().compareTo("Tick") == 0){
			for(int i=0;i<5;i++) ttob.tick(true);
			ttob.tick(false);
		}
		else{
			for(int i=0;i<5;i++) ttob.tock(true);
			ttob.tock(false);
		}
	}
}

class clockdemo{
	public static void main(String args[]){
		TickTock tt = new TickTock();
		MyThread mt1 = new MyThread("Tick",tt);
		MyThread mt2 = new MyThread("Tock",tt);

		try{
			mt1.thrd.join();
			mt2.thrd.join();
		}
		catch(InterruptedException e){
			System.out.println("Main thread interrupted");
		}
	}
}