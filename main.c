#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

#define MAX_ROWS_COUNT 50
#define MAX_COLUMNS_COUNT 50
typedef int Universe[MAX_ROWS_COUNT][MAX_COLUMNS_COUNT];

int getTotalNeighboursCount(Universe universe, int rowInput, int colInput)
{
    int neighboursCount = 0;

    for (int i = rowInput - 1; i <= rowInput + 1; i++)
    {
        for (int j = colInput - 1; j <= colInput + 1; j++)
        {
            bool isCurrentCell = rowInput == i && colInput == j;

            int neighbourRow = (i + MAX_ROWS_COUNT) % MAX_ROWS_COUNT;
            int neighbourColumn = (j + MAX_COLUMNS_COUNT) % MAX_COLUMNS_COUNT;
            bool isNeighbour = universe[neighbourRow][neighbourColumn];

            if (!isCurrentCell && isNeighbour)
            {
                neighboursCount++;
            }
        }
    }

    return neighboursCount;
}

void makeLifeProgress(Universe universeInput)
{
    Universe currentCreatedUniverse;

    for (int i = 0; i < MAX_ROWS_COUNT; i++)
    {
        for (int j = 0; j < MAX_COLUMNS_COUNT; j++)
        {
            int numberOfNeighbours = getTotalNeighboursCount(universeInput, i, j);

            bool firstLifeFilter = numberOfNeighbours == 3;
            bool secondLifeFilter = universeInput[i][j] && numberOfNeighbours == 2;

            currentCreatedUniverse[i][j] = firstLifeFilter || secondLifeFilter;
        }
    }
}

int main() {
   return 0;
}