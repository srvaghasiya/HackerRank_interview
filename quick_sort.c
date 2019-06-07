#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// ASC_DES 1 for ascending and 0 for decending
#define ASC_DES	1

// quick sort implementation for sorting data in decending order
void sort(int *ar,int first,int last)
{
    int pivot,i,j,temp;
    if(first<last)
    {
        pivot = first;
        i = first;
        for(j = first+1;j<=last;j++)
        {
#if ASC_DES == 1
	    if(ar[pivot] > ar[j])
#elif ASC_DES == 0
            if(ar[pivot] < ar[j])
#endif
            {
                i++;
                temp = ar[j];
                ar[j] = ar[i];
                ar[i] = temp;
            }
        }

        temp = ar[pivot];
        ar[pivot] = ar[i];
        ar[i] = temp;

        sort(ar,first,i-1);
        sort(ar,i+1,last);
    }
    return;
}

void print(int *ar,int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d ",ar[i]);
	}
	printf("\n");
}

void main()
{
	int n=5;
	int data[n];

	srand(getpid());
	for(int i=0;i<n;i++)
	{
		data[i] = rand()%100+1;
	}

	print(data,n);
	sort(data,0,n-1);
	print(data,n);
	return;

}
