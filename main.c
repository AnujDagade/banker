#include <stdio.h>

#define Pro 10
#define Res 10

int ava[Res];
int alloc[Pro][Res];

int max[Pro][Res];

int need[Pro][Res];

void display_mat(int arr[][Res], int n, int m)
{
    int i,j;
    printf("\nMatrix\n");

    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < m; j++)
            printf(" %d", arr[i][j]);

        printf("\n");
    }
}

int safetea(int n, int m)
{
    int work[m];
    int finish[n];
    int limit_crossed = 0;
    int is_safe = 0;
    int proc,k;

    for(int pr=0; pr<n; pr++)
        finish[pr]=0;

    for (k = 0; k < 3; k++)
        work[k] = ava[k];

    int i = 0, over=0; // i for process
    int res;

    while(over<n)
    {
        i=0;
        while (i < n)
        {
            limit_crossed = 0;
            if (finish[i] != 1)
            {
                for (res = 0; res < m; res++)
                {
                    if (need[i][res] > work[res])
                    {
                        limit_crossed = 1;


                    }
                }

                if (!limit_crossed)
                {
                    for (res = 0; res < m; res++)
                    {
                        work[res] += alloc[i][res];
                        finish[i] = 1;

                        break;
                    }
                }

            }
            i++;
        }
        over++;
    }

    for(proc=0; proc<n; proc++)
    {
        if(finish[proc] != 1)
        {
            is_safe = 0;
            return is_safe;
        }
    }

    is_safe = 1;
    return is_safe;
}

void res_req(int pno, int req[],int n, int m)
{
    int temp_alloc[n][m], temp_need[n][m], temp_ava[m];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            temp_alloc[i][j] = alloc[i][j];
            temp_need[i][j] = need[i][j];
        }
        temp_ava[i] = ava[i];

    }



    for(int i=0; i<m; i++)
    {
        if(req[i] <= need[pno][i] && req[i] <= ava[i])
            temp_alloc[pno][i] = req[i];
        else
        {
            printf("\nError lack of res");
        }
    }

    for(int i=0; i<m; i++)
    {
        ava[i] -= req[i];
        alloc[pno][i]  += req[i];
        need[pno][i] -= req[i];
    }

    printf("\nIn res fun");

    safetea(n,m)?printf("\nSafe\n"):printf("\nNot Safe\n");

    printf("%d",safetea(n,m));

}

int main()
{
    int i,j,n,m,pno;

    printf("\nEnter process and resources");
    scanf("%d %d", &n, &m);

    int req[m];

    printf("\nEnter Allocation matrix\n");
    for(i=0; i<n; i++)
    {
        for(j=0;j<m; j++)
        {
            scanf("%d",&alloc[i][j]);
        }
    }

    printf("\nEnter Max matrix\n");
    for(i=0; i<n; i++)
    {
        for(j=0;j<m; j++)
        {
            scanf("%d",&max[i][j]);
        }
    }

    printf("\nEnter Available matrix\n");
    for(i=0; i<m; i++)
    {
        scanf("%d",&ava[i]);
    }

    //Calculate need
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }



    printf("\nALLOC");
    display_mat(alloc,n,m);

    printf("\nMAX");
    display_mat(max,n,m);

    printf("\nNeed");
    display_mat(need,n,m);

    printf("\nAvailable\n");
    for(i=0; i<m; i++)
    {
        printf(" %d", ava[i]);
    }


    //Accept request
    printf("\nProcess no, Resources: ");
    scanf("%d",&pno);
    for(int i=0; i<m; i++)
    {
        scanf("%d", &req[i]);
    }

    //This is safety baby
    safetea(n,m)?printf("\nSafe\n"):printf("\nNot Safe\n");

    //printf("%d",safetea(n,m)); // This prints safety  return code baby baby baby OHH!


    res_req(pno,req,n,m);

    return 0;
}
