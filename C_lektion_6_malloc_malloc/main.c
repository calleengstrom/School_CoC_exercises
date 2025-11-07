#include <stdio.h>
#include <stdlib.h>

void addNumsToCalloc(int *idx, int *numbers, int n)
{
    int userNums;

    printf("Enter numbers: \n");
    while (*idx < n)
    {
        scanf("%d", &userNums);
        if (userNums > 0)
        {
            numbers[*idx] = userNums;
            *idx = *idx + 1;
            // for (int i = 0; i < n; i++)
            // {
            //     printf("Nr : %d = %d\n", i + 1, numbers[i]);
            // }
        }
        else
        {
            printf("Invalid number\n");
        }
    }
}

int main(void)
{
    int idx = 0;
    size_t n;
    size_t capacity;
    int newNums;
    printf("How many values do you want to enter? ");
    if (scanf("%zu", &n) != 1)
    {
        fprintf(stderr, "Invalid number.\n");
        return 1;
    }
    capacity = (n * 1.2);
    printf("(Available memory : %zu)\n", capacity);
    int *numbers = calloc(capacity, sizeof(int));
    if (numbers == NULL)
    {
        printf("No no no, no memory for you\n");
        return 1;
    }
    else{
    addNumsToCalloc(&idx, numbers, n);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", numbers[i]);
    }

    printf("Lets add some new numbers.\nHow many more number would you like to add?\n");
    scanf("%d", &newNums);

    n = n + newNums;
    if (n > capacity)
    {
        printf("Not enough memory\nHave to increase\n");
        // return 1;
        capacity = n * 1.1;
        int *temp = realloc(numbers, capacity * sizeof(int));
        if (temp == NULL)
        {
            printf("No no no, no memory for you\n");
            free (numbers);
            return 1;
        }
        numbers = temp;
        addNumsToCalloc(&idx, numbers, n);
    }
    else
    {
        addNumsToCalloc(&idx, numbers, n);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", numbers[i]);
    }

    if (n == 0)
    {
        printf("Nothing to do (n = 0).\n");
        return 0;
    }

    free(numbers);
    numbers = NULL;
    
    return 0;
}
