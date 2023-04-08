//
// Created by gitpod on 4/7/23.
//
#include "stdio.h"
#include "string.h"

typedef struct {
    char name[20];
    int start;
    int length;
}DIR;

DIR dir[20];

void show_bit_vec(int arr[], int length)
{
    printf("\nBit Vector:\n");
    for(int i=0; i<length; i++)
    {
        printf("\t%d",arr[i]);
    }
    printf("\n");
}
int create_file(int bit_vec[], int length, int file_size)
{
    int buff[3];
    int count,flag=0;
    int start = -1;

    for(int i=0; i<length; i++)
    {
        for(int k=0; k<file_size; k++)
            buff[k] = -1;
        count = 0;
        flag=0;
        for(int j=i; j<i+file_size; j++)
        {
            if(bit_vec[j] == 1)
            {
                buff[count++] = bit_vec[i];
            }
            else
                flag=1;
        }
        if(flag==0)
        {
            for(int l=0; l<file_size; l++)
            {
                printf("\nbuff[%d] = %d", l ,buff[l]);

            }
            start = i;
            break;
        }


    }
    printf("\nStart Pos: %d\n", start);

    for(int i=0; i<length; i++)
    {
        printf("\t%d", bit_vec[i]);
    }
    printf("\n");

    if(start != -1)
    {
        for(int i=start; i<start+file_size; i++)
        {
            bit_vec[i] = 0;
        }
    }

    for(int i=0; i<length; i++)
    {
        printf("\t%d", bit_vec[i]);
    }
    return start;
}

int main()
{
    int bit_vec[20];
    int length, ch =99, fsize, fcount=0;
    char fname[20];

    printf("\nEnter bit vector length: ");
    scanf("%d",&length);

    printf("\nEnter bit vector ");
    for(int i=0; i<length; i++)
        scanf("%d", &bit_vec[i]);

    do {
        printf("\n1:Show bit vec\n2:Create new file\n3:Show Directory\n4:Delete file\n5:Exit\nChoice: ");
        scanf("%d",&ch);


        switch (ch) {
            case 1:
                show_bit_vec(bit_vec,length);
                break;
            case 2:
                printf("\nEnter file name: ");
                scanf("%s",fname);
                printf("\nEnter file size: ");
                scanf("%d", &fsize);
                strcpy(dir[fcount].name, fname);
                dir[fcount].start = create_file(bit_vec,length,fsize);
                dir[fcount++].length = fsize;
                break;
            case 3:
                for(int i=0; i<fcount; i++)
                {
                    printf("\nName: %s", dir[i].name);
                    printf("\nStart: %d",dir[i].start);
                    printf("\nFile size: %d", dir[i].length);
                }
                break;
            case 4:
                printf("\nEnter name of file to delete: ");
                scanf("%s",fname);
                for(int i=0; i<fcount; i++)
                {
                    if(strcmp(fname, dir[i].name) == 0)
                    {
                        for(int j=dir[i].start; j<dir[i].start+dir[i].length; j++)
                            bit_vec[j] = 1;

                        strcpy(dir[i].name,"");
                        dir[i].start  = -1;
                        dir[i].length = -1;
                        break;
                    }
                }
        }

    } while (ch != 5);

    return 0;
}
