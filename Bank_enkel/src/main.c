// main.c
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../include/accounts.h"
#include "../include/bank.h"

void clearBuffer()
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

void defaultAccounts(Accounts *listOfUsers, int *counter)
{
    if (*counter >= 5)
    {
        printf("No momory left\n");
        return;
    }
    char name[MAX_NAME_CHAR];

    listOfUsers[*counter].acountNum = 10001;

    strncpy(name, "Calle Engstrom", MAX_NAME_CHAR);
    name[strcspn(name, "\n")] = 0;
    strncpy(listOfUsers[*counter].name, name, MAX_NAME_CHAR);
    listOfUsers[*counter].pin[0] = 0;
    listOfUsers[*counter].pin[1] = 8;
    listOfUsers[*counter].pin[2] = 0;
    listOfUsers[*counter].pin[3] = 8;
    listOfUsers[*counter].money = 35000;

    (*counter)++;

    listOfUsers[*counter].acountNum = 10002;
    // name[MAX_NAME_CHAR] = "Stina Gustavsson";
    // name[strcspn(name, "\n")] = 0;

    strncpy(name, "Stina Gustavsson", MAX_NAME_CHAR);
    name[strcspn(name, "\n")] = 0;
    strncpy(listOfUsers[*counter].name, name, MAX_NAME_CHAR);
    listOfUsers[*counter].pin[0] = 1;
    listOfUsers[*counter].pin[1] = 5;
    listOfUsers[*counter].pin[2] = 1;
    listOfUsers[*counter].pin[3] = 5;
    listOfUsers[*counter].money = 42000;

    (*counter)++;
}

int pinComfirm(int masterPin[]){
    
    int pinOk = 0;
    int pinTry = 3;
    int userPin[4];
    
    
    while (pinTry != 0 && pinOk != 1)
        {
            printf("Enter your pin :");
            char inputPin[5];

            fgets(inputPin, sizeof(inputPin), stdin);
            clearBuffer();
            for (int i = 0; i < 4 && isdigit(inputPin[i]); i++)
            {
                userPin[i] = inputPin[i] - '0';
            }

            if (memcmp(userPin, masterPin, sizeof(userPin)) == 0)
            {
                pinOk = 1;
            }
            else
            {
                pinTry--;
                printf("\nWorng pin, %d atemps left\n", pinTry);
            }
        }
        return pinOk;
}
 
int accComfirm(Accounts *listOfUsers, int size)
{
    int userAccNum;
    int selectedUser = -1;
    scanf("%d", &userAccNum);
    clearBuffer();
    for (int i = 0; i < size; i++)
    {
        if (userAccNum == listOfUsers[i].acountNum)
        {
            selectedUser = i;
        }
    }
    if (selectedUser == -1)
    {
        printf("Invalid account number\n");
    }
    return selectedUser;
}

int main(void)
{
    int capacity = 5;
    int counter = 0;
    int selectedUser;
    int userInput;
    Accounts *listOfUsers = malloc(capacity * sizeof(Accounts));
    if (listOfUsers == NULL)
    {
        printf("Not engough memory");
        return 1;
    }

    defaultAccounts(listOfUsers, &counter);

    while (userInput !=9)
    {
        int pinOk = 0;
    
        printf("1 : Bank menu\n");
        // printf("2 : Add new account\n");
        printf("9 : Quit :");
        scanf("%d",&userInput);
        if (userInput == 9)
        {
            break;
        }
        else if (userInput ==2)
        {
            // Add new user
        }
        else
        


        printf("Hello welcome to the bank!\n");
        printf("Enter your acoount number: \n");
        selectedUser = accComfirm(listOfUsers, counter);
        if (selectedUser ==  -1)
        {
            continue;
        }
        pinOk = pinComfirm(listOfUsers[selectedUser].pin);

        if (pinOk == 1)
        {
            bankMenu(listOfUsers, selectedUser, counter);
        }
        else
        {
            printf("Invalid pin\n");
            continue;
        }
    }

    free(listOfUsers);
}
