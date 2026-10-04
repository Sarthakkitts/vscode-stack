#include <stdio.h>

#define MAX_SIZE 100
#define NO_SEQUENCE_FOUND (-1)

static void processSequence(
    int currentLength,
    int currentSum,
    int *maximumLength,
    int *totalSum,
    int *sequenceFound)
{
    if (currentLength == 0)
        return;

    if (currentLength > *maximumLength)
    {
        *maximumLength = currentLength;
        *totalSum = currentSum;
        *sequenceFound = 1;
    }
    else if (currentLength == *maximumLength)
    {
        *totalSum += currentSum;
    }
}

int getSumLSEVEN(const int numbers[], int size, int *maximumLength)
{
    int currentLength = 0;
    int currentSum = 0;

    int totalSum = 0;
    int sequenceFound = 0;

    *maximumLength = 0;

    for (int index = 0; index < size; index++)
    {
        if (numbers[index] % 2 == 0)
        {
            currentLength++;
            currentSum += numbers[index];
        }
        else
        {
            processSequence(
                currentLength,
                currentSum,
                maximumLength,
                &totalSum,
                &sequenceFound);

            currentLength = 0;
            currentSum = 0;
        }
    }

    processSequence(
        currentLength,
        currentSum,
        maximumLength,
        &totalSum,
        &sequenceFound);

    return sequenceFound ? totalSum : NO_SEQUENCE_FOUND;
}

void displayLongestSequences(const int numbers[], int size, int maximumLength)
{
    int currentLength = 0;

    printf("\nLongest Even Sequence(s):\n");

    for (int index = 0; index <= size; index++)
    {
        if (index < size && numbers[index] % 2 == 0)
        {
            currentLength++;
        }
        else
        {
            if (currentLength == maximumLength)
            {
                for (int i = index - currentLength; i < index; i++)
                {
                    printf("%d ", numbers[i]);
                }
                printf("\n");
            }

            currentLength = 0;
        }
    }
}

int main(void)
{
    int numbers[MAX_SIZE];
    int size;
    int maximumLength;

    printf("Enter number of elements: ");
    scanf("%d", &size);

    if (size <= 0 || size > MAX_SIZE)
    {
        printf("-1\n");
        return 0;
    }

    printf("Enter %d elements:\n", size);

    for (int index = 0; index < size; index++)
    {
        scanf("%d", &numbers[index]);
    }

    int totalSum = getSumLSEVEN(numbers, size, &maximumLength);

    if (totalSum == NO_SEQUENCE_FOUND)
    {
        printf("-1\n");
        return 0;
    }

    displayLongestSequences(numbers, size, maximumLength);

    printf("\nSum of Longest Sequence(s): %d\n", totalSum);

    return 0;
}