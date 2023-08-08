// # include <stdio.h>
// int main
// ()
// {
//     int a[20], i, b;
//     scanf("%d",&b);
//     printf("Enter the element of array: ");
//     for(i = 0; i<=b; i++)
//     {
//         scanf("%d",&a[i]);
//     }
// }




#include <stdio.h>

int main()
{
    int a[20], i, b;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &b);

    if (b > 20) {
        printf("Array size exceeds the limit of 20.\n");
        return 1; 
    }

    printf("Enter the elements of the array: ");
    for (i = 0; i < b; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Array elements:\n");
    for (i = 0; i < b; i++)
    {
        printf("%d ", a[i]);
    }

    return 0; 
}

//Sushant