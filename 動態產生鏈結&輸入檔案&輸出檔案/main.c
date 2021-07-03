#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct node {
	int id;
	int data;
	struct node *next;
};
void printList(struct node *);
void b_sort(struct node *);
int main(int argc, char *argv[]) {
	struct node *first,*current,*previous;
	int i,value;
	FILE *fptr;
	char ch[255];
	fptr=fopen("test.txt","r");
	if(fptr!=NULL){
		for(i=0;i<6;i++){
		current=(struct node *) malloc(sizeof(struct node));
		current->id=i+1;
		fscanf(fptr,"%s",ch);
		value=atoi(ch);
		current->data=value;
		if(i==0){
			first=current;
		}
		else{
			previous->next=current;
		}
		current->next=NULL;
		previous=current;
	}
	current=first;
	fclose(fptr);
	}
	else{
		printf("開啟失敗");
	} 
	printList(first);
	b_soft(first);
    fptr = fopen("out.txt", "w");//opening file
	for(i=0;i<6;i++){
		fprintf(fptr,"ID:%d DATA:%d\n",current->id,current->data);//writing data into file
		current=current->next;
	}  
      
    fclose(fptr);//closing file  
    printf("Write to file : out.txt finished.");
	return 0;
}
void printList(struct node* first){
	struct node* node=first;
	if(first==NULL){
		printf("List is empty!\n");
	}
	else{
		while(node!=NULL)
		{
			printf("ID:%d DATA:%3d\n",node->id,node->data);
			node=node->next;
		}
		printf("\n");
	}
}
void b_soft(struct node* first){
	struct node* node=first;
	int data[6],id[6];
	int i,j,temp,temp1;
	for(i=0;i<6;i++){
		data[i]=node->data;
		id[i]=node->id;
		node=node->next;
	}
	node=first;
	for(i=0;i<6;i++)
	{
		for(j=0;j<(5-i);j++)
		{
			if(data[j]<data[j+1])//由高至低排序 
			{
				temp=data[j+1];
				data[j+1]=data[j];
				data[j]=temp;
				
				temp1=id[j+1];
				id[j+1]=id[j];
				id[j]=temp1;
			}
		}
	}
	for(i=0;i<6;i++){
		node->id=id[i];
		node->data=data[i];
		node=node->next;
	}
}
