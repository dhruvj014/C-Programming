#include <stdio.h>
#define V 7
#define M 6
int data[4][7];
int sol[5];

void knapsack(int w[3],int p[3])
{
    for (int i=0;i<4;i++)
    {
        for (int j=0;j<V;j++)
        {
//            printf("i - %d, j - %d \n",i,j);
            if (i==0 || j==0)
            {
                data[i][j]=0;
            }
            else if(w[i-1]>j)
            {
                data[i][j] =data[i-1][j];
            }
            else
            {
                int a = p[i-1]+data[i-1][j-w[i-1]];
                int b = data[i-1][j];
//                printf("a - %d, b - %d \n",a,b);
                int c;
                if (a>=b)
                    c=a;
                else
                    c=b;
                data[i][j]=c;
            }
            printf("%d ",data[i][j]);
        }
        printf("\n");
    }
    int ctr = M;
    int ictr=0;
    int i = 3,j=6;
    while(ctr==M)
    {
        if (data[i][j]==data[i-1][j])
        {
            printf("Same values of %d and %d\n",data[i][j],data[i-1][j]);
            i-=1;
            continue;
        }
        else
        {
            printf("Different values of %d and %d\nAdding %d to sol.\n",data[i][j],data[i-1][j],w[i-1]);
            i-=1;
            sol[ictr]=w[i-1];
            ctr-=w[i-1];
            ictr+=1;
            continue;
        }

    }
    for(i=0;i<ictr;i++)
        printf("%d ",sol[i]);
    printf("\n");
    i=3;
    while(ctr>0)
    {

        if(data[i][j]==data[i][j-1])
        {
            printf("Same values of [%d][%d]%d and [%d][%d]%d\n",i,j,data[i][j],i,j-1,data[i][j-1]);
            i-=1;
            continue;
        }
        else
        {
            printf("Different values of %d and %d\nAdding %d to sol.\n",data[i][j],data[i][j-1],w[i-1]);
            i-=1;
            sol[ictr]=w[i-1];
            ctr-=w[i-1];
            ictr+=1;
            continue;
        }
    }
    for(i=0;i<ictr;i++)
        printf("%d ",sol[i]);
}
void main()
{
    int w[3]={2,3,3};
    int p[3]={1,2,4};
    knapsack(w,p);
}
