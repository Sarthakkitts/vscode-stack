#include<stdio.h>
struct matrix{
    int arr[10][10];
    int x;
    int y;
}
;
int main()
{
    int i,j;
    struct matrix m;
    int **ptr=(int **)malloc(m.x * sizeof(int *));
    for(i=0;i<m.x;i++)
    {
