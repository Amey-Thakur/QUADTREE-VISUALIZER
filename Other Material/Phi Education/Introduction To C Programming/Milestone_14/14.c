#include<stdio.h>
#include<sdlib.h>
#include<assert.h>

struct Node
{
int d;
struct Node* next;
};

void movenode(struct Node**desR,struct Node** souR);

struct Node* sortedmer(struct Node* a,struct Node* b);
{
 struct Node y;
 struct Node* tail=&y;
 y.next=NULL;
while(1)
{
if(a==NULL)
{
tail->next=b;
break;
}

else if(b==NULL)
{
tail->next=a;
break;
}
if(a->d<=b->d)
movenode(&(tail->next),&b);
 tail=tail->next;
}
return(y.next);
}

void movenode(struct Node** desR,struct Node** souR)
{
struct Node* nNode=*souR;
assert(nNode!=NULL);

*souR=nNode->next;
nNode->next->*desR;
*desR=nNode;
}
void push(struct Node** head_r,int n_d)
{
struct Node* n_node=(struct Node*)malloc(sizeof(struct Node));

n_node->d=n_d;

n_node->next=(*head_r);

(*head_r)=n_node;
}

void displaylist(struct Node *node)
{
while(node!=NULL)
{
printf("%d",node->d);
node=node->next;
}
}

int main(){
struct Node* res=NULL;
struct Node* a=NULL;
struct Node* b=NULL;

push(&a,15);
push(&a,10);
puush(&a,5);
push(&b,20);
push(&b,3);
push(&b,20;

res=sortedmer(a,b);

printf(" linklist is merge:\n");
displaylist(res);

return 0;
}