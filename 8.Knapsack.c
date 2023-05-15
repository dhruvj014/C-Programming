#include<stdio.h>
int value[7]={9,5,2,7,6,16,3};
float weight[7]={2,5,6,11,1,9,1};
float ratio[7];
int sol[8];
int solctr=0,M=28;
float frac=0,wk=0,pk=0;
int item[7] = {1,2,3,4,5,6,7};
void sorting()
{
    int lens = sizeof(ratio) / sizeof(ratio[0]);
    for(int i=0;i<lens;i++)
    {
        int max = i;
        for(int j=i+1;j<lens;j++)
        {
            if(ratio[j]>ratio[max])
            {
                max = j;
            }
        }
        float temp = ratio[max];
        ratio[max] = ratio[i];
        ratio[i] = temp;
        float temp1 = value[max];
        value[max] = value[i];
        value[i] = temp1;
        float temp2 = weight[max];
        weight[max] = weight[i];
        weight[i] = temp2;
        int temp3 = item[max];
        item[max] = item[i];
        item[i] = temp3;
    }
}
void knapsack(int lens)
{
    for(int i = 0;i<=lens;i++)
    {
        if (wk+weight[i]<M)
        {
            wk=wk+weight[i];
            pk=pk+value[i];
            sol[i]=item[i];
            solctr+=1;
        }
        else
        {
            printf("\n(%d - %f)/%f \n",M,wk,weight[i]);
            frac= (M-wk)/weight[i];
            wk=wk+(frac*weight[i]);
            pk=pk+(frac*value[i]);
            solctr+=1;
            break;
        }
    }
    printf("\nMax Value - %f \n",pk);
    printf("\nKnapsack Contents - \n");
    printf("I%d , ",sol[0]);
    for(int i = 1;i<solctr;i++)
    {
        if (i+1==solctr)
            printf("I%d x %f\n",sol[i],frac);
        else
            printf("I%d ,",sol[i]);
    }
}
void main()
{
    int lens = sizeof(value)/sizeof(value[0]);
    for(int i =0;i<lens;i++)
    {
        float result = (float)value[i]/weight[i];
        ratio[i]=result;
    }
    printf("Unsorted Arrays - \nItem  \tValue  \tWeight  \tRatio\n");
    for(int i =0;i<lens;i++)
    {
        printf("%Id   \t%d   \t%f   \t%f\n",item[i],value[i],weight[i],ratio[i]);
    }
    printf("\n");
    sorting();
    printf("Sorted Arrays - \nItem  \tValue  \tWeight  \tRatio\n");
    for(int i =0;i<lens;i++)
    {
        printf("%Id   \t%d   \t%f   \t%f\n",item[i],value[i],weight[i],ratio[i]);
    }
    knapsack(lens);
}
