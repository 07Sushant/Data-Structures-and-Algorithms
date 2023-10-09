#include <iostream>
#include <cstdlib>
using namespace std;
struct node
{
  int data;
  struct node*left;
  struct node*right;
};
struct node*root;
void append(int d)
{
  struct node*newnode = (struct node*)malloc(sizeof(struct node));
  struct node*temp = root;
  newnode->data = d;
  newnode->left = NULL;
  newnode->right = NULL;
  if(root == NULL)
  {
    root = newnode;
  }
  else
  {
    while(true)
    {
      if(d < temp->data)
      {
        if(temp->left != NULL)
        {
          temp = temp->left;
        }
        else
        {
          temp->left = newnode;
          break;
        }
      }
      else
      {
        if(temp->right != NULL)
        {
          temp = temp->right;
        }else
        {
          temp->right = newnode;
          break;
        }
      }
    }
  }
}
void postorder(struct node*root)
{
  if(root != NULL)
  {
    
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
  }
}
int main()
{
  int d;
  do
  {
    cin>>d;
    if(d > 0)
      append(d);
  }while(d != -1);
  cout<<"Post order Traversal:"<<endl;
  postorder(root);
  return 0;
}



//sol 2



#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node*left;
  struct node*right;
};
struct node*root;
void append(int d)//1
{
  struct node*newnode = (struct node*)malloc(sizeof(struct node));
  struct node*temp = root;//6
  newnode->data = d;//4
  newnode->left = NULL;
  newnode->right = NULL;
  if(root == NULL)//6
  {
    root = newnode;//6
  }
  else
  {
    while(true)
    {
      if(d < temp->data)//4 < 3
      {
        if(temp->left != NULL)//3
        {
          temp = temp->left;//3
        }
        else
        {
          temp->left = newnode;//1
          break;
        }
      }
      else
      {
        if(temp->right != NULL)
        {
          temp = temp->right;
        }else
        {
          temp->right = newnode;
          break;
        }
      }
    }
  }
}
void postorder(struct node*root)
{
  if(root != NULL)
  {
    
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
  }
}
int main()
{
  int d;
  do
  {
    scanf("%d",&d);//4
    if(d > 0)//4
      append(d);
  }while(d != -1);//1
  printf("Post order Traversal:\n");
  postorder(root);
  return 0;
}