#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	srand(time(NULL));
	int ans[4];
	int user;
	int user_A[4];
	int i,j,a=1,A=0,B=0,count=1,check=1;
	for(i=0;i<4;i++)
	{
		ans[i]=rand()%10;
		for(j=0;j<i;j++)
		{
			while(ans[j]==ans[i])
			{
				ans[i]=rand()%10;//���ƼƦr���� 
				j=0;//�k�s���s�P�_ 
			}
		}
		//printf("%d",ans[i]);//�������ҥ� 
	}
	//printf("\n");
	while(a)
	{
		fflush(stdin);
		printf("�п�J4��Ʀr\n");
		scanf("%4d",&user);
		for(i=3;i>=0;i--)
		{
			user_A[i]=user%10;
			user=user/10;
		}//���@�Ʀr 

		for(i=0;i<4;i++)
		{
			if(user_A[i]==user_A[i+1]){
					check=0;
					break;
				}
			if(user_A[i]==ans[i])
			{
				A=A+1;
                B=B-1;//���T�Ʀr��m���~-1
			}
			for(j=0;j<4;j++)
			{
				if(user_A[j]==ans[i])
				{
                	B=B+1;//���T�Ʀr��m���~+1
				}
			}
		}
		if(check==0) {
			printf("�����J�ۦP�Ʀr��!\n");
			count--;
		}
		else {printf("A:%d B:%d\n",A,B);}//��ܴXA�XB 
		if(A==4)
		{
			a=0;
			break;
		}
		printf("�q��!�Э��s��J�A�q�F%d��\n",count);
		A=0;B=0;//�k�s
		check=1; 
		count++;//�q�X�� 
		
	}
	printf("�A�w�ӧQ�q�F%d��\n",count);
	system("pause");
	return 0;
}
