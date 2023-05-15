#include <stdio.h>
#include<string.h>
#define V 7
#define M 5
int sol[];
int p[6]={4,10,3,12,20,7};

void main()
{
    matrixdp(p);
}

int cost(int x,int y)
{
    int kctr=0;
    for (int i =x;i<y;i++)
        kctr+=1;
    if (kctr>=1)
    {
        int k=x;
        int temp[7];
        for (int i=0;i<7;i++)
        {
            if(x<=k && k<y)
            {
                temp[i] = cost(x,k)+cost(k+1,y)+(p[x-1]*p[k]*p[y]);
                k+=1;
                continue;
            }
            else
                temp[i] = 99999;
        }
        int min = temp[0];
        for (int i =0;i<kctr;i++)
        {
            if (temp[i]<min)
                min = temp[i];
        }
//        printf("C[%d,%d] is %d\n",x,y,min);
        return min;
    }
    else
    {
//        printf("C[%d,%d] is 0\n",x,y);
        return 0;
    }
}
void matrixdp()
{
    printf("\n");
    int data[5][5];
    for (int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if (i>=j)
                data[i][j]=0;
            else
            {
//                printf("\nI'm In Here at x=%d and y=%d\n",i+1,j+1);
                data[i][j] = cost(i+1,j+1);
            }
            printf("%d ",data[i][j]);
        }
        printf("\n");
    }

}
