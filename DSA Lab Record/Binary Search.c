#include <stdio.h>
int BinarySearch(int array[], int L, int R, int search);
void main()
{
    int i, n, search;
    printf("Enter number of elements : ");
    scanf("%d", &n);
    int array[n];
    for(i = 0; i < n; i++){
        printf("Enter an element : ");
        scanf("%d", &array[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d", &search);
    int key = BinarySearch(array, 0, n - 1, search);
    if (key == -1){
        printf("Element not found..!!");
    }
    else{
        printf("Element is found at the index %d.", key);
    }
}
 
int BinarySearch(int array[], int L, int R, int search){
    while(L <= R){
        int mid = L + (R - L) / 2;
        if (array[mid] == search){
            return mid;
        }
        if (array[mid] < search){
            L = mid + 1;
        }
        else{
            R = mid - 1;
        }
    }
    return -1;
}
