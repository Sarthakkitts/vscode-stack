#include<stdio.h>
#include<math.h>

int main()
{
int x,y;
int matrixA[10][10];
int matrixB[10][10];
int a,b;

printf("enter the number of rows and columns of the matrix: ");
scanf("%d %d",&x,&y);
for (int i=0;i<x;i++)
{
    for(int j=0;j<y;j++)
    {
        printf("enter the element of the matrix at position [%d][%d]: ",i+1,j+1);
        scanf("%d",&matrixA[i][j]);
    }
}
printf("enter the number of rows and columns of the matrix: ");
scanf("%d %d",&a,&b);
for (int i=0;i<a;i++)
{
    for(int j=0;j<b;j++)
    {
        printf("enter the element of the matrix at position [%d][%d]: ",i+1,j+1);
        scanf("%d",&matrixB[i][j]);
printf("the matrix is \n");
for ( int i=0;i<x;i++)
{
    for(int j=0;j<y;j++)
    {
        printf("%d",matrixA[i][j]);
    }

    printf("[\n]");
}
for ( int i=0;i<a;i++)
{
    for(int j=0;j<b;j++)
    {
        printf("%d",matrixB[i][j]);
    }

    printf("[\n]");
}
return 0;
}