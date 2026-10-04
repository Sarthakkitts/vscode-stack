#include<stdio.h>
struct array{
    int arr[6];
    int n; 

} ; 
    int main() {
        int i;
    
        struct array a;
        for(i=0;i<6;i++)
        {
            printf("enter the number of the arrray",i+1);
            scanf("%d",&a.arr[i]);
        }; 
    

        
        
        printf("the numbers of the array are %d",a.arr[i]);
        return 0;
    }
    

        
        
    
