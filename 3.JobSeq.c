#include<stdio.h>
int max_dead=0;
int p=0;
int deadline[6]={5,3,3,2,4,2};
int profit[6]={200,180,190,300,120,100};
int sol[6]={-1,-1,-1,-1,-1,-1};
int process[6] = {1,2,3,4,5,6};
void sorting()
{
    int max;
    int lens = sizeof(profit) / sizeof(profit[0]);
    for(int i=0;i<lens;i++)
    {
        max = i;
        for(int j=i+1;j<lens;j++)
        {
            if(profit[j]>profit[max])
            {
                max = j;
            }
        }
        int temp = profit[max];
        profit[max] = profit[i];
        profit[i] = temp;
        int temp1 = deadline[max];
        deadline[max] = deadline[i];
        deadline[i] = temp1;
        int temp2 = process[max];
        process[max] = process[i];
        process[i] = temp2;
    }
    max_dead=deadline[0];
    for(int i=0;i<lens;i++)
    {
        if (deadline[i]>max_dead)
            max_dead=deadline[i];
    }
}
void job_scheduling()
{
    for(int i=0;i<max_dead;i++)
    {
        int max = i;
        int pos=deadline[i]-1;
        int ctr=pos;
        while (ctr>=0)
        {
            if (sol[ctr]==-1)
            {
                sol[ctr]=process[i];
                p+=profit[i];
                break;
            }
            else
                ctr-=1;
        }
    }
    printf("\n\nFinal Solution - ");
    for(int i=0;i<max_dead;i++)
    {
        printf("P%d ",sol[i]);
    }
}
void main()
{
    int lens = sizeof(profit) / sizeof(profit[0]);
    printf("Unsorted Arrays - \n");
    for(int i =0;i<lens;i++)
    {
        printf("%d   %d   J%d\n",deadline[i],profit[i],process[i]);
    }
    sorting();
    printf("\nSorted Arrays - \n");
    for(int i =0;i<lens;i++)
    {
        printf("%d   %d   J%d\n",deadline[i],profit[i],process[i]);
    }
    job_scheduling();
    printf("\n");
}
