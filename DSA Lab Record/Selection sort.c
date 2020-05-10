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
        for(j = i+1; j < num ; j++){
            if(sort[j] > sort[i]){
                temp = sort[j];
                sort[j] = sort[i];
                sort[i] = temp;
                
            }
        }
    }
    for(i = 0; i < num; i++){
        printf("%d\n",sort[i]);
    }
}