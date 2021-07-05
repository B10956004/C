#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a=0;
	printf("請輸入一個整數:");
	scanf("%d",&a);
	printf("最靠近%d的數為:%d",a,SQRT(a));
	return 0;
}
int SQRT(int a)
{
	int i,j;
	int count=-1;
	for(i=1;i<a;i++)
	{
		if(j<=a)
		{
			j=i*i;
			count++;
		}
		else return count;
	}
}

