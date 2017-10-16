import java.util.*;

class Arraysum{
	private int sum;

	int arr(int nums[]){
		sum = 0;
		for(int i=0;i<nums.length;i++){
			sum += nums[i];
			System.out.println("Running total for " + Thread.currentThread().getName() + " " + sum);
			try{
				Thread.sleep(10);
			}
			catch(InterruptedException e){
				System.out.println(Thread.currentThread().getName() + " interrupted");
			}
		}
		return sum;
	}
}


class MyThread implements Runnable{
	Thread thrd;
	static Arraysum sa = new Arraysum();
	int a[];
	int answer;

	MyThread(String name,int arr[]){
		thrd = new Thread(this,name);
		a = arr;
		thrd.start();
	}

	public void run(){
		int sum;
		System.out.println("Starting " + thrd.getName());
		synchronized(sa){
			answer = sa.arr(a);
		}
		System.out.println("Total sum for " + thrd.getName() + " is " + answer);

		System.out.println(thrd.getName() + " terminating");
	}
}

class syncdemo{
	public static void main(String args[]){
		int a[] = {1,2,3,4,5};
		MyThread mt1 = new MyThread("child 1",a);
		MyThread mt2 = new MyThread("child 2",a);

		try{
			mt1.thrd.join();
			mt2.thrd.join();
		}
		catch(InterruptedException e){
			System.out.println("Main thread interrupted");
		}
	}
}