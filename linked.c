#include "stdio.h"
#define MAX 10
#define SIZE 3

typedef struct bk
{
    int alloc;
    struct bk *next;
}Block;

int main()
{
  Block bit_vec[MAX];

    for (int i = 0; i < MAX; ++i) {

        if(i==0 || i==1 || i==3)
            bit_vec[i].alloc = 0;
        else
            bit_vec[i].alloc = 1;
    }

    for (int i = 0; i < MAX; ++i) {
        printf("\t%d", bit_vec[i].alloc);
    }

    int count =0;
    Block *prev[MAX];
    for (int i = 0; i < MAX; ++i) {

        if(bit_vec[i].alloc == 1 && count < SIZE)
        {
            prev[count] = &bit_vec[i];
            prev[count]->alloc = 0;
            count++;
        }
    }
    for(int i=0; i<count-1; i++)
    {
        prev[i]->next = prev[i+1];
    }

    printf("\n");
    for (int i = 0; i < MAX; ++i) {
        printf("\t%d", bit_vec[i].alloc);
    }

}
