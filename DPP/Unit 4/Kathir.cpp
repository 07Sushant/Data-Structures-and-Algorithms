#include<stdio.h>
#include<stdlib.h>
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
        }else
        {
          temp->left = newnode;
          break;
        }
      }else
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
void leafsum(node *root,int *sum)
{
  if(!root)
    return;
  if(!root->left && !root->right)
    *sum+= root->data;
  leafsum(root->left,sum);
  leafsum(root->right,sum);
}
int main()
{
  int d;
  do
  {
    scanf("%d",&d);
    if(d > 0)
      append(d);
  }while(d != -1);
  int sum = 0;
  leafsum(root,&sum);
  printf("Sum of all leaf nodes are %d",sum);
  return 0;
}



//Sol 2


#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
  int data;
  struct node* left;
  struct node* right;
};
struct node* root;

struct node* createNode(int d)
{
  struct node* newnode = (struct node*)malloc(sizeof(struct node));
  newnode->data = d;
  newnode->left = NULL;
  newnode->right = NULL;
  return newnode;
}

void append(int d)
{
  struct node* newnode = createNode(d);
  struct node* temp = root;
  if (root == NULL)
  {
    root = newnode;
  }
  else
  {
    while (true)
    {
      if (d < temp->data)
      {
        if (temp->left != NULL)
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
        if (temp->right != NULL)
        {
          temp = temp->right;
        }
        else
        {
          temp->right = newnode;
          break;
        }
      }
    }
  }
}

void leafsum(node* root, int* sum)
{
  if (!root)
    return;
  if (!root->left && !root->right)
    *sum += root->data;
  leafsum(root->left, sum);
  leafsum(root->right, sum);
}

int main()
{
  int d;
  do
  {
    cin >> d;
    if (d > 0)
      append(d);
  } while (d != -1);
  int sum = 0;
  leafsum(root, &sum);
  cout << "Sum of all leaf nodes are " << sum;
  return 0;
}

