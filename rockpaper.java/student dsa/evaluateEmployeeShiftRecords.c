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