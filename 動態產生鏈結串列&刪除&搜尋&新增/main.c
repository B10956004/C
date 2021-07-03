#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct node{
	int data;
	int data2;	
	int num;//�s�� 
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
	struct node *first,*node,*wantDelete;//�Y,�`�I,�Q�R�����`�I 
	int input,wantAdd,wantAdd2,num,totaldata;//��J�h�ָ�Ƽ�,�W�[���ƭ�,���Ӹ`�I,�`�`�I�� 
	printf("�п�J�Q���ͦh�ָ�Ƽ�:");
	scanf("%d",&input);
	fflush(stdin);
	first=createList(input);
	printList(first);
	while(1){
	printf("�п�J���Q���J���Ӹ`�I��:");
	scanf("%d",&num);
	if(num>input-1){printf("��J���~\n");
	}
	else break;
	}
	node=searchNode(first,num);
	printf("�п�J���J���Ʀr:");
	scanf("%d %d",&wantAdd,&wantAdd2);
	insertNode(node,wantAdd,wantAdd2);
	totaldata=refreshNode(first);
	printList(first);
	while(1){
	printf("�п�J�Q�R�����`�I:");
	scanf("%d",&num);
	if(num>totaldata){printf("��J���~\n");
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
			printf("�`�I:%d ���:%3d %3d\n",node->num,node->data,node->data2);
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
	}//refresh�e�� 
	node->num=i;
	i++;//�̫�@����s 
	printf("��s��....\n");
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
