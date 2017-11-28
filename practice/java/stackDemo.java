import java.util.*;
import java.io.*;

class Stack{
	int top;
	int arr[];

	Stack()
	{
		top = 0;
		arr = new int[1000];
	}

	void push(int item)
	{
		this.arr[top++] = item;
	}

	int pop()
	{
		return arr[top--];
	}

	boolean isEmpty()
	{
		return top<0;
	}

	void display()
	{
		for(int i=0;i<top;i++)
			System.out.print(arr[i] + " ");
		System.out.println();
	}
}

class stackDemo{
	public static void main(String args[])
	{
		Stack s = new Stack();
		s.display();
		s.push(1);

		s.display();
		s.push(2);

		s.display();
		s.push(3);

		s.display();
		s.pop();

		s.display();
	}
}