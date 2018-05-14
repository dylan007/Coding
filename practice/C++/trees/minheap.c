/*
 * =====================================================================================
 *
 *       Filename:  minheap.c
 *
 *    Description:  Implementation of minheap, insertion and deletion of a number
 *
 *        Version:  1.0
 *        Created:  Wednesday 11 March 2015 04:12:28  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shounak Dey (), dylandey1996@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void swap(int *a,int *b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
}

void insert(int *heap,int x,int index)
{
	heap[index] = x;
	while(heap[index]>heap[index/2] && index>0)
		swap(&heap[index],&heap[index/2]);
}

void print(int *heap,int size)
{
	int i;
	for(i=0;i<size;i++)
		printf("%d ",heap[i]);
	printf("\n");
}

int main()
{
	int size = 0;
	int choice = 0;
	int *heap[20000];
	int x;
	while(choice != 4)
	{
		printf("1.Insert into heap \n 2.Delete from heap \n 3.Print the heap \n 4.Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter the number to be inserted : ");
				scanf("%d",&x);
				insert(heap,x,size);
				size++;
				break;
			case 2:
				printf("Enter the number to be deleted : ");
				scanf("%d",&x);
				//delete(heap,x,size);
				size--;
				break;
			case 3:
				print(heap,size);
				break;
		}
	}
	return 0;
}
