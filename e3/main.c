#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

void main()
{
    srand(time(NULL));
    int totalThrows = 0;
    for (int i = 0; i < 1000000; i++)
    {
        
        int throws = 0;
        while (true)
        {
            int dice1 = 1 + rand() % 6;
            int dice2 = 1 + rand() % 6;
            int dice3 = 1 + rand() % 6;
            int dice4 = 1 + rand() % 6;
            int dice5 = 1 + rand() % 6;
            throws++;
            if (dice1 == 1 && dice2 == 1 && dice3 == 1 && dice4 == 1 && dice5 == 1)
            {
                break;
            }
            else if (dice1 == 2 && dice2 == 2 && dice3 == 2 && dice4 == 2 && dice5 == 2)
            {
                break;
            }
            else if (dice1 == 3 && dice2 == 3 && dice3 == 3 && dice4 == 3 && dice5 == 3)
            {
                break;
            }
            else if (dice1 == 4 && dice2 == 4 && dice3 == 4 && dice4 == 4 && dice5 == 4)
            {
                break;
            }
            else if (dice1 == 5 && dice2 == 5 && dice3 == 5 && dice4 == 5 && dice5 == 5)
            {
                break;
            }
            else if (dice1 == 6 && dice2 == 6 && dice3 == 6 && dice4 == 6 && dice5 == 6)
            {
                break;
            }
        }
        totalThrows = throws+totalThrows;
    }
    printf("\nSnitt kast för Yasty = %d\n",totalThrows/1000000);
}
