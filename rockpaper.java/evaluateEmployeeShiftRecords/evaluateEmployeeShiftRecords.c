#include <stdio.h>

int evaluateEmployeeShiftRecords(int employeeWorkHours[], int totalEmployees)
{
    int maxConsecutiveOddShifts = 0, currentConsecutiveOddShifts = 0;
    int currentShiftSum = 0, maxShiftSum = -1;

    for (int i = 0; i < totalEmployees; i++)
    {
        if (employeeWorkHours[i] % 2 != 0)
        {
            currentConsecutiveOddShifts++;
            currentShiftSum += employeeWorkHours[i];
        }
        else
        {
            employeeWorkHours[i] = 1; 

            if (currentConsecutiveOddShifts > 0)
            {
                if (currentConsecutiveOddShifts > maxConsecutiveOddShifts)
                {
                    maxConsecutiveOddShifts = currentConsecutiveOddShifts;
                    maxShiftSum = currentShiftSum;
                }
                else if (currentConsecutiveOddShifts == maxConsecutiveOddShifts)
                {
                    if (maxShiftSum == -1)
                    {
                        maxShiftSum = 0;
                    }
                    maxShiftSum += currentShiftSum;
                }
            }
            currentConsecutiveOddShifts = 0;
            currentShiftSum = 0;
        }
    }

    if (currentConsecutiveOddShifts > 0)
    {
        if (currentConsecutiveOddShifts > maxConsecutiveOddShifts)
        {
            maxConsecutiveOddShifts = currentConsecutiveOddShifts;
            maxShiftSum = currentShiftSum;
        }
        else if (currentConsecutiveOddShifts == maxConsecutiveOddShifts)
        {
            if (maxShiftSum == -1)
            {
                maxShiftSum = 0;
            }
            maxShiftSum += currentShiftSum;
        }
    }
    
    return maxShiftSum;
}

int main() 
{
    int shiftRecords[] = {3, 5, 4, 7, 9, 8, 1};
    int employeeCount = sizeof(shiftRecords) / sizeof(shiftRecords[0]);
    
    int result = evaluateEmployeeShiftRecords(shiftRecords, employeeCount);
    
    /* HERE IS THE ADDED LINE */
    printf("Sum of the longest odd sequence: %d\n", result);
    
    printf("Updated Shift Records: ");
    for(int i = 0; i < employeeCount; i++) 
    {
        printf("%d ", shiftRecords[i]);
    }
    printf("\n");
    
    return 0;
}