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
				ans[i]=rand()%10;//重複數字替換 
				j=0;//歸零重新判斷 
			}
		}
		//printf("%d",ans[i]);//答案驗證用 
	}
	//printf("\n");
	while(a)
	{
		fflush(stdin);
		printf("請輸入4位數字\n");
		scanf("%4d",&user);
		for(i=3;i>=0;i--)
		{
			user_A[i]=user%10;
			user=user/10;
		}//拆成單一數字 

		for(i=0;i<4;i++)
		{
			if(user_A[i]==user_A[i+1]){
					check=0;
					break;
				}
			if(user_A[i]==ans[i])
			{
				A=A+1;
                B=B-1;//正確數字位置錯誤-1
			}
			for(j=0;j<4;j++)
			{
				if(user_A[j]==ans[i])
				{
                	B=B+1;//正確數字位置錯誤+1
				}
			}
		}
		if(check==0) {
			printf("不能輸入相同數字喔!\n");
			count--;
		}
		else {printf("A:%d B:%d\n",A,B);}//顯示幾A幾B 
		if(A==4)
		{
			a=0;
			break;
		}
		printf("猜錯!請重新輸入，猜了%d次\n",count);
		A=0;B=0;//歸零
		check=1; 
		count++;//猜幾次 
		
	}
	printf("你已勝利猜了%d次\n",count);
	system("pause");
	return 0;
}
