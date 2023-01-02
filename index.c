#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int jumpSearch(int sorted[], int toFind, int size)
{
    int step_count = 0;
    int step = sqrt(size);
    int prv_step_location = 0;
    int loop_control = 1;
    while (loop_control == 1)
    {
        step_count++;
        if (sorted[step] == toFind)
        {

            printf("Data %d is index: %d \n", toFind, step);
            return sorted[step];
        }
        else if (sorted[step] < toFind)
        {
            prv_step_location = step;
            step = step + 2;
        }
        else if (sorted[step] > toFind)
        {

            for (int i = prv_step_location + 1; i < step; i++)
            {
                if (sorted[i] == toFind)
                {
                    printf("Data %d is index: %d \n", toFind, i);
                    return i;
                }
            }
            printf("%d No Data Found. \n", 404);
            return 404;
        }
        if (toFind > sorted[size - 1] || toFind < sorted[0])
        {
            printf("%d No Data Found. \n", 404);
            return 404;
        }
    }
}

int main()
{
    int arr[] = {
        12, 19, 42, 88, 102, 113, 281, 402, 888, 1000, 1044};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    jumpSearch(arr, 19, arrSize);

    return 0;
}