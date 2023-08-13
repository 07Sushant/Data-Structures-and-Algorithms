#include<stdio.h>
int main(){
	int arr[50],i,j,n,temp;
	printf("enter the elements for array:");
	scanf("%d",&n);
	printf("enter elements");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	for(i=0;i<n;i++){
		for(j=0;j<n-1;i++){
	        if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
	}
        }
    }
	printf("sorted elements are:");
    for(i=0; i<n; i++)
    {
        printf("%d",arr[i]);
    }
    return 0;
	}	

	
