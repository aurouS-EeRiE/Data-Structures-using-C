#include<stdio.h>
void main()
{
    int i,temp,j,num;
    int sort[100];
    printf("Enter number of elements : ");
    scanf("%d",&num);
    for(i = 0; i < num; i++){
        printf("Enter element : ");
        scanf("%d",&sort[i]);
    }
    for(i = 0; i < num; i++){
        for(j = 0; j < num - 1; j++){
            if(sort[j] > sort[j+1]){
                temp = sort[j];
                sort[j] = sort[j+1];
                sort[j+1] = temp;
            }
        }
    }
    for(i = 0; i < num; i++){
        printf("%d\n",sort[i]);
    }
}