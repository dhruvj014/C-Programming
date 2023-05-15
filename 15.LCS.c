#include <stdio.h>
#include<string.h>
#define V 7
#define M 6
char sol[];

void main()
{
    char w[]="stone";
    char p[]="longest";
    int n = strlen(p);
    int k = strlen(w);
    printf("%d is length of stone and %d is length of longest\n",k,n);
    if (n>k)
        LCS(w,k,p,n);
    else
        LCS(p,n,w,k);
}

void LCS(char a[],int alen,char b[],int blen)
{
    int data[alen+1][blen+1];
    for(int i=0;i<=alen;i++)
    {
        for(int j=0;j<=blen;j++)
        {
            if(i==0 || j==0)
            {
                data[i][j]=0;
            }
            else if(a[i-1]==b[j-1])
            {
//                printf("%\nfilling in at [%d][%d] where %c is equal to %c\n",i,j,a[i-1],b[j-1]);
                data[i][j]=data[i-1][j-1]+1;
            }
            else
            {
                int n1 = data[i-1][j];
                int n2 = data[i][j-1];
                int c = n1>=n2?n1:n2;
                data[i][j]=c;
            }
            printf("%d ",data[i][j]);
        }
        printf("\n");
    }
    int i = 5,j=7,solctr=0;
    while(i>=0 && j>=0)
    {
        if(data[i][j]==data[i][j-1])
        {
            printf("%d at [%d][%d] is equal to %d at [%d][%d]\n",data[i][j],i,j,data[i][j-1],i,j-1);
            j-=1;
        }
        else
        {
            printf("%d at [%d][%d] is not equal to %d at [%d][%d]\nAdding %c to sol\n",data[i][j],i,j,data[i][j-1],i,j-1,a[i]);
            sol[solctr]=a[i];
            i-=1;
            j-=1;
            solctr+=1;
        }

    }
    printf("Final LCS .... Reverse it in exam - \n");
    for(i=0;i<solctr;i++)
        printf("%c ",sol[i]);
}
