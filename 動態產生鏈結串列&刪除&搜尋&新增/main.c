#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct node{
	int data;
	int data2;	
	int num;//編號 
	struct node *next;
};
struct node *createList(int);
void printList(struct node *);
void freeList(struct node *);
void insertNode(struct node *,int ,int);
struct node *refreshNode(struct node *);
struct node *searchNode(struct node *,int);
struct node *deleteNode(struct node *,struct node *);

int main(int argc, char *argv[]) {
	srand(time(NULL));
	struct node *first,*node,*wantDelete;//頭,節點,想刪除的節點 
	int input,wantAdd,wantAdd2,num,totaldata;//輸入多少資料數,增加的數值,哪個節點,總節點數 
	printf("請輸入想產生多少資料數:");
	scanf("%d",&input);
	fflush(stdin);
	first=createList(input);
	printList(first);
	while(1){
	printf("請輸入欲想插入哪個節點後:");
	scanf("%d",&num);
	if(num>input-1){printf("輸入錯誤\n");
	}
	else break;
	}
	node=searchNode(first,num);
	printf("請輸入插入的數字:");
	scanf("%d %d",&wantAdd,&wantAdd2);
	insertNode(node,wantAdd,wantAdd2);
	totaldata=refreshNode(first);
	printList(first);
	while(1){
	printf("請輸入想刪除的節點:");
	scanf("%d",&num);
	if(num>totaldata){printf("輸入錯誤\n");
	}
	else break;
	}
	wantDelete=searchNode(first,num);
	first=deleteNode(first,wantDelete);
	totaldata=refreshNode(first);
	printList(first);
	
	freeList(first);
	system("pause");
	return 0;
}

struct node *createList(int len){
	int i=0;
	struct node *first,*current,*previous;
	for(i=0;i<len;i++){
		current=(struct node *) malloc(sizeof(struct node));
		current->data=rand()%100+1;
		current->data2=rand()%100+1;
		current->num=i;
		if(i==0){
			first=current;
		}
		else{
			previous->next=current;
		}
		current->next=NULL;
		previous=current;
	}
	return first;
}
void printList(struct node* first){
	struct node* node=first;
	if(first==NULL){
		printf("List is empty!\n");
	}
	else{
		while(node!=NULL)
		{
			printf("節點:%d 資料:%3d %3d\n",node->num,node->data,node->data2);
			node=node->next;
		}
		printf("\n");
	}
}
struct node* searchNode(struct node* first,int item){
	struct node* node=first;
	while(node!=NULL)
	{
		if(node->num==item)
			return node;
		else
			node=node->next;
	}
	return NULL;
}
void insertNode(struct node* node,int item,int item2){
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=item;
	newnode->data2=item2;
	newnode->next=node->next;
	node->next=newnode;
}
struct node* refreshNode(struct node* first){
	struct node* node=first;
	int i=0;
	while(node->next!=NULL)
	{
		node->num=i;
		i++;
		node=node->next;
	}//refresh前面 
	node->num=i;
	i++;//最後一筆刷新 
	printf("刷新中....\n");
	return node->num;
}
struct node* deleteNode(struct node *first,struct node *node){
	struct node *ptr=first;
	if(first==NULL){
		printf("nothing to delete!\n");
		return NULL; 
	}
	if(node==first)
		first=first->next;
	else
	{
		while(ptr->next!=node){
			ptr=ptr->next;
		}
		ptr->next=node->next;
	}
	free(node);
	return first;
}
void freeList(struct node* first){
	struct node *current,*tmp;
	current=first;
	while(current!=NULL){
		tmp=current;
		current=current->next;
		free(tmp);
	}
}
