//Sorting array in ascending order using 

#include<stdio.h>
int main()
{
    int a[100],hold,i,j,n;
    printf("Enter value of n: ");
    scanf("%d",&n);
    printf("\nEnter elements: \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nData items of original order: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    //Bubble Sort
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                hold=a[j];
                a[j]=a[j+1];
                a[j+1]=hold;
            }
        }
    }
    printf("\nData items in Ascending order: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}