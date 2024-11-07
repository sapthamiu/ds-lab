#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
  int info;
  struct node* lchild;
  struct node* rchild;
}NODE;

NODE* getnode()
{
  NODE* x;
  x = (NODE*)malloc(sizeof(NODE));
  if(x == NULL)
  {
    printf("Running out of memory \n");
    return NULL;
  }
  return x;
}

NODE* insertBST(NODE* root, int item)
{
    NODE *cur, *parent, *newnode=getnode();
    newnode->info= item;
    newnode->lchild= newnode->rchild =NULL;
    if (root==NULL) {
		root = newnode;
		return root;
	}
    cur= root;
    while(cur!=NULL && (cur->info !=item))
    {
        parent= cur;
        if(item< cur->info)
            cur=cur->lchild;
        else if(item > cur->info)
                    cur= cur->rchild;
        else {printf("No duplictaes");free(newnode);return root;}
    }

    if (item<parent->info)
        parent->lchild = newnode;
    else
        parent->rchild = newnode;
    return root;
}

NODE* deleteBST(NODE* root, int item)
{
    NODE *parent, *cur, *succ, *temp;
    if(root==NULL){
        printf("BST is empty");
        return NULL;
    }

    //traverse the tree until the item is found or entire tree is traversed
    parent = NULL;
    cur = root;
    while(cur && (cur->info!= item))
    {
        parent=cur;
        if (item<cur->info)
          cur = cur->lchild;
        else
          cur = cur->rchild;
    }

    if (cur==NULL)
    {
	  printf("Item Not Found\n");
	  return root;
    }

    //item found and check for case 1
    if (cur->lchild == NULL) //node to be deleted has empty left subtree
      temp = cur->rchild;
    else if (cur->rchild == NULL) //node to be deleted has empty right subtree
      temp = cur->lchild;
    else //interior nodes
    {
	//find inorder successor->smallest element in the right subtree of the node which will be replace node
       parent = cur;
       succ = cur->rchild; //get address of rightchild of node to be deleted*/

       while (succ->lchild)
       {    //move to the leftmost node of succ
            parent = succ;
            succ= succ->lchild;
       }
       cur->info = succ->info;//exchange the info of current and succ;
       cur = succ;
       temp= cur->rchild;
     }

     if (parent == NULL)
     {
            free(cur);
            root = temp;
            return root;
    }
    if(cur==parent->lchild)
       parent->lchild = temp;
    else
       parent->rchild = temp;
    free(cur);
    return root;
}

void inorder(NODE* root)
{
	if (root!= NULL)
	{
		inorder(root->lchild);
		printf("%d ",root->info);
		inorder(root->rchild);
	}
}

int main()
{
  NODE* root;
  int ch,item,n,i;
  while(1)
  {
    printf("\n\n~~~~~~Menu~~~~~~ ");
    printf("\n=>1. Insert Node To a Binary Search Tree");
    printf("\n=>2. Delete a Node from BST");
    printf("\n=>3. Inorder Display");
    printf("\n=>4. Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &ch);

    switch(ch)
    {
      case 1: root=NULL;
              printf("\nEnter the number of nodes:");
              scanf("%d", &n);
              printf("\nEnter the elements for BST: ");
              for(i=0;i<n;i++)
              {
                printf("\nEnter The Element ");
                scanf("%d", &item);
                root = insertBST(root,item);
              }
              break;

      case 2: printf("Enter the item to be deleted from BST \n");
              scanf("%d",&item);
              root = deleteBST(root,item);
              break;

      case 3: if (root == NULL)
              printf("\n Tree Is Not Created");
              else
              {
               printf("\nThe Inorder display: ");
               inorder(root);
              }
              break;
      case 4: exit(0);
      default: printf("Enter the valid choice \n");

    }
  }
   return 0;
}
