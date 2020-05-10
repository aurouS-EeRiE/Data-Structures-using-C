#include <stdio.h>
void main()
{
    int i, temp, j, n, value;
    printf("Enter number of elements : ");
    scanf("%d", &n);
    int sort[n];
    for(i = 0; i < n; i++){
        printf("Enter an element : ");
        scanf("%d", &sort[i]);
    }
    for(i = 1; i < n; i++){
        value = sort[i];
        j = i - 1;
        while (j >= 0 && sort[j] > value){
            sort[j + 1] = sort[j];
            j = j - 1;
        }
        sort[j + 1] = value;
    }
    for(i = 0; i < n; i++){
        printf("%d  ",sort[i]);
    }
}
