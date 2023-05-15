#include <stdio.h>
#define M 8
int data[4][M+1];
int sol[5];
void coin(int d[])
{
    for(int i=0;i<=3;i++)
    {
        for(int j=0;j<=M;j++)
        {
            if(i==0 || j==0)
            {
//                printf("%\nfilling in j<d[i-1] at [%d][%d]\n",i,j);
                data[i][j]=0;
            }
            else if (i==1)
            {
//                printf("%\nfilling in j<d[i-1] at [%d][%d]\n",i,j);
                data[i][j]=1+data[1][j-d[i-1]];
            }

            else if(j<d[i-1])
            {
//                printf("%\nfilling in j<d[i-1] at [%d][%d]\n",i,j);
                data[i][j]=data[i-1][j];
            }
            else if (i==j)
                data[i][j]=1+data[1][j-d[i-1]];
            else
            {
//                printf("%\n\nin the else");
                int a = data[i-1][j];
                int b = 1+data[i][j-d[i-1]];
                int c = (a>=b)?b:a;
//                printf("%\nfilling in min(%d,%d) at [%d][%d]\na=data[%d][%d] = %d\n",a,b,i,j,i-1,j,a);
                data[i][j]=c;
            }
            printf("%d ",data[i][j]);
        }
        printf("\n");
    }

    int i = 3,j=8,solctr=0;
    while(i>=0 && j>=0)
    {
        if(data[i][j]==data[i-1][j])
        {
            printf("%d at [%d][%d] is equal to %d at [%d][%d]\n",data[i][j],i,j,data[i-1][j],i-1,j);
            i-=1;
        }
        else
        {
            printf("%d at [%d][%d] is not equal to %d at [%d][%d]\nAdding %d to sol\n",data[i][j],i,j,data[i-1][j],i-1,j,d[i-1]);
            sol[solctr]=d[i-1];
            j-=d[i-1];
            solctr+=1;
            printf("i - %d , j = %d\n",i,j);
        }

    }
    printf("Final Coins .... Reverse it in exam - \n");
    for(i=0;i<solctr;i++)
        printf("%d ",sol[i]);
}
int main() {
    int d[] = {1,4,6};
    coin(d);
    return 0;
}
