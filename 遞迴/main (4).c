#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a=0;
	printf("½Ğ¿é¤J¼Æ¦r:");
	scanf("%d",&a);
	printf("fac(%d)=%d\n",a,fac(a));
	return 0;
}
int fac(int n)
{
	if(n>0)
		return(n*fac(n-1));
	else
		return 1;
}
