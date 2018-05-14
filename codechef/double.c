#include<stdio.h>
#include<stdlib.h>
int main(){int n,i;scanf("%d",&n);while(n--){scanf("%d",&i);printf("%d\n",i-(i%2));}return 0;}
