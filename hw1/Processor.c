#include <stdio.h>
#include <stdlib.h>

int get_iteration_count(int rand)
{
    /*
     * Takes in a random number and maps it to the
     * range [100 - 120)
     * Used to get the number of iterations in the range
     */

    return ((rand % (120 - 100) + 100) * 1);
}

int get_arr_size(int rand)
{
    /*
     * Takes in a random number and maps it to the
     * range [100 - 200)
     * Used to get the size of array within the range
     */

    return ((rand % (200 - 100) + 100) * 1);
}

int get_arr_val(int rand)
{
    /*
     * Takes in a random number and maps it to the
     * range [1 - 1000)
     * Used to get the value of an element in the array within the range
     */

    return ((rand % (1000 - 1) + 1) * 1);
}

float num_ratio(int *arr, int size)
{
    /*
     * This is the method that you need to implement.
     * Implement the following steps in the given order.
     *
     * 1. Initialize variable count to 0. Thhis keeps track of odd number count.
     *
     * 2. Loop through each element
     *      2 a. Check if that element is odd. If it is increase te variable count by 1.
     *
     * 3. Find the ratio by dividing the count of odd numbers with the count of even numbers
     *    (size-count). Print required statement. Return the ratio.
     */

    /* Write your code in here */
    float ocount = 0;

    for (int i = 0; i < size; i++)
    {
        if ((arr[i] % 2) != 0)
        {
            ocount++;
        }
    }
    float ecount = size - ocount;
    float result = ocount / ecount;
    return result;
}

double get_running_ratio()
{
    /*
     * This is the method that you need to implement.
     * Implement the following steps in the given order.
     *
     * 1. Generate the number of iterations
     *      - Generate a random number. Map it to the range [100 - 120) using the
     *      utility function 'get_iteration_count'.
     *
     * 2. For each iteration:
     *      2.a Generate an array size - Generate a random number and map it to the range [100 - 200) using
     *          the utility function 'get_arr_size'.
     *
     *      2.b Allocate memory for the array in the heap.
     *
     *      2.c Check if the current array size is the maximum among the arrays generated so far. If
     *          it is, keep track of it.
     *
     *      2.d Populate the array with random numbers and map number to the range [1 - 1000) using
     *          the get_arr_val utility function.
     *
     *      2.e Get the ratio of odd numbers to even numbers by calling num_ratio(). Keep track of the sum of ratio.
     *
     * 3. Find the average ratio among all of the arrays.
     *
     * 4. Display the largest size among all the arrays in terms of bytes, not the number of
     *    elements.
     *
     * 5. Return the average ratio to Starter.c
     */

    /* Write your code in here */
    int maxSize = 0;
    float ratioSum = 0;
    int numIter = get_iteration_count(rand());
    printf("[Processor]: Number of iterations is %i\n", numIter);
    for (int i = 0; i < numIter; i++)
    {
        int sizeArray = get_arr_size(rand());
        int *arr = (int *)malloc(sizeof(int) * sizeArray);
        if (maxSize < sizeArray)
        {
            maxSize = sizeArray;
        }
        for (int j = 0; j < sizeArray; j++)
        {
            *(arr + j) = get_arr_val(rand());
        }
        ratioSum += num_ratio(arr, sizeArray);
        free(arr);
    }
    double aRatio = ratioSum / numIter;
    printf("[Processor]: Largest array size is %i\n", maxSize * 4);
    return aRatio;
}