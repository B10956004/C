#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int A,B;
	printf("請輸入數字A及B(用空白隔開):");
	scanf("%d %d",&A,&B);
	int A_g =A;
	int B_g =B;
	while(A_g!=B_g)
	{
		if(A_g>B_g)
		{
			A_g-=B_g;
		}
		else(B_g-=A_g);
	}
	printf("GCD:%d\n",A_g);
	int LCM=A*B/A_g;
	printf("LCM:%d\n",LCM); 
	return 0;
}
