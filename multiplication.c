#include<stdio.h>
struct array{

    int arr[6];
    int n; 
    char names[100];
    float price;
    char category[100];
    double rating;

} ; 
    int main() {
       
    
        struct array a;
        for(int i=0;i<6;i++)
        {
            printf("enter the number of the arrray %d: ",i+1);
            scanf("%d",&a.arr[i]);
        }; 

    printf("enter the index of the array to be displayed: ");
    scanf("%d",&i);
    if(i<0 || i>5)
    {
        printf("invalid index");
    }   
    else{

    

    printf("the value at index %d is %d",i,a.arr[i]);}
    
    for (i=0;i<6-1;i++)
    {
        for(int j=0;j<6-i-1;j++)
    {

        if(a.arr[j]>a.arr[j+1])
        {
            int temp=a.arr[j];
            a.arr[j]=a.arr[j+1];
            a.arr[j+1]=temp;
        }
    
    }
    }
    printf("\t the bubble sorted array is: ");
    for(i=0;i<6;i++)
    {
        printf("%d ",a.arr[i]);
    }
    int low=0;
    int high=6-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(a.arr[mid]==a.arr[i]){
            printf("\n element found");
        }
        else if(a.arr[mid]<a.arr[i])
        {
            low=mid+1;
        }
    }
    printf("\n element not found");
    printf("\t %d",a.arr[i]);
    printf("%s",a.names[i]);
    
    return 0;
}

