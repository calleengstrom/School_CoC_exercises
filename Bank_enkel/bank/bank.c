// bank.c
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "..//include/accounts.h"
#include "../include/bank.h"

void withdraw(float *balance)
{
    int withdrawSum = 0;
    printf("How much would you like to withdraw?\n");
    printf("You balance is : %.2f kr\n", *balance);
    scanf("%d", &withdrawSum);
    if (withdrawSum < 0)
    {
        printf("Can't withdraw negative sum!\n");
        withdraw(balance);
    }
    else if (withdrawSum > *balance)
    {
        printf("Not enough balance!\n");
        withdraw(balance);
    }
    else
    {
        *balance = *balance - withdrawSum;
        printf("New balance : %.2f", *balance);
    }
}

void deposit(float *balance)
{
    int depositSum = 0;
    printf("How much would you like to deposit?\n");
    printf("You balance is : %.2f kr\n", *balance);
    scanf("%d", &depositSum);
    if (depositSum < 0)
    {
        printf("Can't deposit negative sum!\n");
        deposit(balance);
    }
    else
    {

        *balance = *balance + depositSum;
        printf("New balance : %.2f", *balance);
    }
}

void transfer(Accounts *listOfUsers, float *balance, int size, int thisUser)
{

    int pinOk;
    float transferSum;
    int selectedUser;
    int userinput;
    printf("You balance is : %.2f kr\n", *balance);
    printf("Enter account number you want to transfer to:");

    selectedUser = accComfirm(listOfUsers, size);
    if (selectedUser == -1)
    {
        printf("Invalid account number\n");
        transfer(listOfUsers, balance, size, thisUser);
    }
    
    printf("Account found:\n%s, Account num: %d\n", listOfUsers[selectedUser].name, listOfUsers[selectedUser].acountNum);
    printf("Do you want to continue? 1 = Yes, else no");
    scanf("%d", &userinput);
    if (userinput != 1)
    {
        printf("Retruning\n");
        return;
    }

    printf("How much do you want to transfer?\n");
    scanf("%f", &transferSum);
    printf("Transfering %.2f SEK from your account to\n%s %d\n", transferSum, listOfUsers[selectedUser].name, listOfUsers[selectedUser].acountNum);
    printf("Do you want to continue? 1 = Yes, else no");
    scanf("%d", &userinput);
    if (userinput != 1)
    {
        printf("Retruning\n");
        return;
    }
    clearBuffer();
    printf("Comfirm your PIN \n");
    pinOk = pinComfirm(listOfUsers[thisUser].pin);
    if (pinOk == 1)
    {
        listOfUsers[selectedUser].money = listOfUsers[selectedUser].money + transferSum;
        *balance = *balance - transferSum;
        printf("Transfer complete !\n");
    }
    else
    {
        printf("Invalid pin, returning to Main menu\n");
    }
}

void bankMenu(Accounts *listOfUsers, int i, int size)
{
    int userChoie;
    while (userChoie != 5)
    {
        printf("\n*********************\n");
        printf("Bank Menu\n");
        printf("1 : Balance\n");
        printf("2 : Deposit\n");
        printf("3 : Withdraw\n");
        printf("4 : Tansfer\n");
        printf("5 : Quit\n");
        printf("*********************\n");
        scanf("%d", &userChoie);
        clearBuffer();

        switch (userChoie)
        {
        case 1:
            printf("You balance is : %.2f kr\n", listOfUsers[i].money);
            break;
        case 2:
            deposit(&listOfUsers[i].money);
            break;
        case 3:
            withdraw(&listOfUsers[i].money);
            break;
        case 4:
            transfer(listOfUsers, &listOfUsers[i].money, size, i);
            break;
        case 5:
            printf("Thank you! Goodbye!\n");
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}
