#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	srand(time(NULL));
	int s[50];
	int i;
	for(i=0;i<50;i++)
	{
		s[i]=rand()%100+1;//亂數附值 
	}
	bubble(s);
	printf("成績排序:\n");
	show(s);
	int j=0,k;
	k=1;//排名 
	for(i=0;i<49;i++)
	{
		if(j!=5){
			if(s[i]!=s[i+1])
			{
				printf("第%d名成績:%d\n",k,s[i]);
				k++;
				j++;
			}
		
		}
	}//前五名 
	k=1;//排名重制 
	for(i=0;i<49;i++)
	{
		if(s[i]!=s[i+1])
		{
			if(k==25){printf("第%d名成績:%d\n",k,s[i]);break;
			}//第25名 
			else {k++;
			}
			
		}
	}
	search(s);
	return 0;
}
void show(int a[]){
	int i;
	for(i=0;i<50;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}
void bubble(int a[])
{
	int i,j,temp;
	for(i=0;i<50;i++)
	{
		for(j=0;j<(49-i);j++)
		{
			if(a[j]<a[j+1])//由高至低排序 
			{
				temp=a[j+1];
				a[j+1]=a[j];
				a[j]=temp;
			}
		}
	}
}
void search(int a[]){
	int L=49,R=0;
	while(L>=R)
	{
		int M=(L+R)/2;//24起 
		if(a[M]==59)
		{
			return printf("\n有考59分的同學");
		}
		else if(a[M]<59){
			L=M-1;//減少範圍，1.不需判斷M-1以後的數字 (即判斷M-1以前) 
		}
		else if(a[M]>59){
			R=M+1;//減少範圍，2.不需判斷M+1以前的數字 (即判斷M+1以後)
		}
	}
	return printf("\n沒有考59分的同學");
}
