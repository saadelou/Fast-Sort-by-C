#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void change(int*, int*);
void Fast_Srot( int*, int, int);

int main () {
    srand(time(NULL));
    int* array;
    int length , count;

    printf("How Much Element : ");
    scanf("%d",&length);

    array = (int*)calloc(length,sizeof(int));
    if(!array){
        printf("\n\t************ Reservation Of Memory >> FAILED << *************");
        exit(33);
    }
    count=0;
    while( count < length ){
        array[count]=rand()%20;
        ++count;
    }
    printf("\n\n--> Your Array >> BEFORE << Sorting:\n\n\t |");
    count=0;
    while( count < length ){
        printf("%6d", array[count]);
        ++count;
    }
    printf("    |");

    Fast_Srot(array, 0, length - 1);

    printf("\n\n--> Your Array >> AFTER << Sorting:\n\n\t |");
    count=0;
    while( count < length ){
        printf("%6d", array[count]);
        ++count;
    }
    printf("    |");
    free(array);
    return 0;
}

void change(int *element_1, int* element_2){
    int temp;
    temp = *element_1;
    *element_1 = *element_2;
    *element_2= temp;
}

void Fast_Srot(int *array, int first, int end){
    int pivot, i ,j;
    if( first < end){
        pivot = first;
        i = first;
        j = end;
        while (i < j){
            while ( array[i] <= array[pivot] && i < end)
                i++;
            while ( array[j] > array[pivot])
                j--;
            if( i < j){
                change(&array[i], &array[j]);
            }
        }
        change(&array[pivot], &array[j]);
        Fast_Srot(array, first, j-1);
        Fast_Srot(array, j+1, end);
    }
}
