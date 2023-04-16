//
// Created by gitpod on 4/8/23.
//
#include "stdio.h"
#include "string.h"
#define MAX 30
typedef struct bk
{
    int alloc;
    struct bk *next;
}Block;

typedef struct dr
{
    char name[20];
    int length;
    int start;
}DIR;

DIR dir[20];

Block  bit_vec[MAX];

int create_file(int size, int vec_size)
{
    int count =0;
    int is_first = 1;
    int start = -1;
    Block *prev[vec_size];
    for (int i = 0; i < vec_size; ++i) {

        if(bit_vec[i].alloc == 1 && count < size)
        {

            prev[count] = &bit_vec[i];
            prev[count]->alloc = 0;
            if (is_first)
            {
                start = i;
                is_first = 0;
            }
            count++;
        }
    }
    //Forming a chain
    for(int i=0; i<count-1; i++)
    {
        prev[i]->next = prev[i+1];
    }

    return start;
}

int main()
{
    int ch=99, vec_size, file_size, count=0;
    char fname[20];
    printf("\nEnter vec size: ");
    scanf("%d",&vec_size);
    //init
    for (int i = 0; i < vec_size; ++i) {
        bit_vec[i].alloc = 1;
    }


    do {
        printf("\n1:Show bit vec\n2:Create new file\n3:Show Directory\n4:Delete file\n5:Exit\nChoice: ");
        scanf("%d",&ch);
        switch (ch) {
            case 1:
                printf("\nBit Vec\n");
                for (int i = 0; i < vec_size; ++i) {
                    printf("\t%d",bit_vec[i].alloc);
                }
                break;

            case 2:
                printf("\nEnter file name: ");
                scanf("%s",fname);
                strcpy(dir[count].name, fname);
                printf("\nEnter file size: ");
                scanf("%d",&file_size);
                dir[count].length = file_size;
                dir[count++].start = create_file(file_size, vec_size);
                break;
            case 3:
                for(int i=0; i<count; i++)
                {
                    printf("\nName: %s", dir[i].name);
                    printf("\nStart: %d",dir[i].start);
                    printf("\nFile size: %d", dir[i].length);
                }
                break;
        }

    } while (ch != 5);
}
