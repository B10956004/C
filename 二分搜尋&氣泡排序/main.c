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
		s[i]=rand()%100+1;//�üƪ��� 
	}
	bubble(s);
	printf("���Z�Ƨ�:\n");
	show(s);
	int j=0,k;
	k=1;//�ƦW 
	for(i=0;i<49;i++)
	{
		if(j!=5){
			if(s[i]!=s[i+1])
			{
				printf("��%d�W���Z:%d\n",k,s[i]);
				k++;
				j++;
			}
		
		}
	}//�e���W 
	k=1;//�ƦW���� 
	for(i=0;i<49;i++)
	{
		if(s[i]!=s[i+1])
		{
			if(k==25){printf("��%d�W���Z:%d\n",k,s[i]);break;
			}//��25�W 
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
			if(a[j]<a[j+1])//�Ѱ��ܧC�Ƨ� 
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
		int M=(L+R)/2;//24�_ 
		if(a[M]==59)
		{
			return printf("\n����59�����P��");
		}
		else if(a[M]<59){
			L=M-1;//��ֽd��A1.���ݧP�_M-1�H�᪺�Ʀr (�Y�P�_M-1�H�e) 
		}
		else if(a[M]>59){
			R=M+1;//��ֽd��A2.���ݧP�_M+1�H�e���Ʀr (�Y�P�_M+1�H��)
		}
	}
	return printf("\n�S����59�����P��");
}
