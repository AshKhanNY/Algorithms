// Mark I

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sort(int* A, int n);

int main()
{
    int i, offset, j;
    int* B = (int*)malloc(1e7 * sizeof(int));
    time_t t;
    srand((unsigned)time(&t));
    offset = rand() % 10000000;
    for (i = 0; i < 10000000; i++)
    {
        B[i] = ((91 * i) % 10000000) + offset;
    }
    printf("Prepared array of 10 million integers; calling sort\n");
    sort(B, 10000000);
    printf("finished sort, now check result\n");
    for (i = 0, j = 0; i < 10000000; i++)
        if (B[i] != i + offset) j++;
    if (j == 0)
        printf("Passed Test\n");
    else
        printf("Failed Test. %d numbers wrong.\n", j);
    time_t now;
    time(&now);
    printf("%i seconds!\n", int(now - t));
}

void sort(int* A, int n) {
    const int HEXMAX = 16*16*16*16;
    int i, last, place, shift, temp, *bucket, *output;
    // First round for 0 to 2^16
    // bucket holds number of occurrences where the digit is 0000, 0001,..., FFFF
    // output depends on bucket for concatenation, places numbers at right index
    bucket = (int*)malloc(HEXMAX * sizeof(int));
    for (i = 0; i < HEXMAX; ++i) bucket[i] = 0;
    output = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n; ++i) output[i] = 0;
    i = 0;
    while (i < n) bucket[A[i++] & 0xFFFF] += 1;
    // Corrects indices so we can place numbers into bucket in order
    i = 0; last = bucket[0];
    while (i < HEXMAX) {
        bucket[i] = last - bucket[i++];
        last += bucket[i];
    }
    // Puts the number into output and increments bucket so it's ready to give
    // next number that has the same digit.
    i = 0;
    while (i < n) {
        temp = A[i] & 0xFFFF;
        place = bucket[temp];
        bucket[temp] += 1;
        output[place] = A[i++];
    }
    // Override original array with count sorted numbers
    i = 0;
    while (i < n) A[i] = output[i++];
    // Second round for 2^16 to 2^32
    for (i = 0; i < HEXMAX; ++i) bucket[i] = 0;
    for (i = 0; i < n; ++i) output[i] = 0;
    i = 0;
    while (i < n) bucket[(A[i++] >> 16) & 0xFFFF] += 1;
    i = 0; last = bucket[0];
    while (i < HEXMAX) {
        bucket[i] = last - bucket[i++];
        last += bucket[i];
    }
    i = 0;
    while (i < n) {
        temp = (A[i] >> 16) & 0xFFFF;
        place = bucket[temp];
        bucket[temp] += 1;
        output[place] = A[i++];
    }
    i = 0;
    while (i < n) A[i] = output[i++];
}
