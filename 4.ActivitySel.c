#include<stdio.h>
int start[6];
int finish[6];
int sol[6];
int process[6] = {1,2,3,4,5,6};
void sorting()
{
    int lens = sizeof(finish) / sizeof(finish[0]);
    for(int i=0;i<lens;i++)
    {
        int min = i;
        for(int j=i+1;j<lens;j++)
        {
            if(finish[j]<finish[min])
            {
                min = j;
            }
        }
        int temp = finish[min];
        finish[min] = finish[i];
        finish[i] = temp;
        int temp1 = start[min];
        start[min] = start[i];
        start[i] = temp1;
        int temp2 = process[min];
        process[min] = process[i];
        process[i] = temp2;
    }
}
void activity_select(int lens)
{
    sol[0]= process[0];
    int solctr=1;
    int fintr=finish[0];
    for(int i = 1;i<=lens;i++)
    {
        printf("%d vs %d\n",start[i],fintr);
        if(start[i]>fintr)
        {
            sol[solctr] = process[i];
            fintr=finish[i];
            solctr+=1;
            continue;
        }
    }
}
void main()
{
    printf("Enter Start Array Elements - \n");
    int lens = 6;
    for(int i =0;i<lens;i++)
    {
        scanf("%d",&start[i]);
    }
    printf("Enter Finish Array Elements - \n");
    for(int i =0;i<lens;i++)
    {
        scanf("%d",&finish[i]);
    }
    printf("Unsorted Arrays - \n");
    for(int i =0;i<lens;i++)
    {
        printf("%d   %d   P%d\n",start[i],finish[i],process[i]);
    }
    sorting();
    printf("Sorted Arrays - \n");
    for(int i =0;i<lens;i++)
    {
        printf("%d   %d   P%d\n",start[i],finish[i],process[i]);
    }
    activity_select(lens);
    printf("Soln Array - \n");
    for(int i =0;i<lens;i++)
    {
        printf("P%d ",sol[i]);
    }
}
