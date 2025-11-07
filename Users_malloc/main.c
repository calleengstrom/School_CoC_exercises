#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Max_email_char 50
#define Max_name_char 35

typedef struct
{
    char name[Max_name_char];
    char email[Max_email_char];
    int age;
} User;

void showAllUsers(User *uList, int counter)
{
    for (int i = 0; i < counter; i++)
    {
        printf("No: %d.  Name :  %s.   Age  %d.   Email :   %s.\n", i + 1, uList[i].name, uList[i].age, uList[i].email);
    }
}

void clearBuffer()
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {}
 
}

int checkName(char *name, int size)
{
    int nameOk = 0;
    for (int i = 0; i < size; i++)
    {
        if (name[i] == ' ')
        {
            nameOk++;
        }
    }

    if (nameOk <= 0)
    {
        printf("Invalid name\n");
    }
    return nameOk;
}

int checkEmail(char *email, int size)
{

    int emailOk = 0;

    for (int i = 0; i < size; i++)
    {
        if (email[i] == '@')
        {
            emailOk++;
        }
    }

    if (emailOk != 1)
    {
        printf("Invalid email\n");
    }
    return emailOk;
}

void enterName(User *uList, int index)
{
    int nameOk = 0;
    while (nameOk != 1)
    {
        char name[Max_name_char];
        printf("Enter name : ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = 0;
        nameOk = checkName(name, strlen(name));
        strcpy(uList[index].name, name);
    }
}

void enterEmail(User *uList, int index)
{
    int emailOk = 0;
    while (emailOk != 1)
    {

        char email[Max_email_char];
        printf("Enter  email : ");
        fgets(email, sizeof(email), stdin);
        email[strcspn(email, "\n")] = 0;
        emailOk = checkEmail(email, strlen(email));
        strcpy(uList[index].email, email);
    }
}

void enterAge(User *uList, int index)
{
    int age = 0;
    while (age != 1)
    {
        printf("Enter age : ");
        scanf("%d", &age);
        clearBuffer();
        if ((age > 130) || (age < 0))
        {
            age = 0;
            printf("Invaild age, enet a age between 1 - 130\n");
        }
        else
        {
            uList[index].age = age;
            age = 1;
        }
    }
}

void addUser(User *uList, int counter)
{

    enterName(uList, counter);

    enterEmail(uList, counter);

    enterAge(uList, counter);
}

void changeUser(User *uList, int capacity)
{
    showAllUsers(uList, capacity);
    int userChoice;

    printf("Wich user woudl you like to change ?`\n");
    scanf("%d", &userChoice);
    clearBuffer();

    for (int i = 0; i < capacity; i++)
    {
        if (i == userChoice - 1)
        {

            printf("What would you like to change ?\n");
            printf("1:  Name.   2:   Email.   3:   Age\n");

            scanf("%d", &userChoice);
            clearBuffer();

            switch (userChoice)
            {
            case 1:
                enterName(uList, i);
                break;
            case 2:
                enterEmail(uList, i);
                break;

            case 3:
                enterAge(uList, i);
                break;
            default:
                break;
            }
        }
    }
}

void increaseMemory(User **uList, int *capacity)
{
    int userInput;
    printf("How many users would you like to add?\n");
    scanf("%d", &userInput);
    clearBuffer();
    *capacity = *capacity + userInput;
    User *temp = realloc(*uList, *capacity * sizeof(User));
    if (temp == NULL)
    {
        printf("Not available memory");
        free(*uList);
        *uList = NULL;
        return;
    }
    printf("Memory increased\n");
    *uList = temp;
}

void decreaseMemory(User **uList, int *capacity)
{
    if (*capacity<=1)
    {
        return;
    }
    else{
    *capacity = *capacity-1;
    User *temp = realloc(*uList, *capacity * sizeof(User));
    if (temp == NULL)
    {
        printf("Not available memory");
        free(*uList);
        *uList = NULL;
        return;
    }
    printf("Memory decreased\n");
    *uList = temp;
    }
}
int main(void)
{
    int capacity = 1;
    int counter = 0;
    int userChoice = 0;

    User *uList = malloc(capacity * sizeof(User));
    if (uList == NULL)
    {
        printf("Not available memory");
        return 1;
    }

    while (userChoice != 5)
    {
        printf("****************\n");
        printf("User meny \n");
        printf("1 : Add new user\n");
        printf("2 : Show all users\n");
        printf("3 : Edit a user\n");
        printf("4 : Remove user \n");
        printf("5 : Exit \n");
        printf("****************\n");
        scanf("%d", &userChoice);
        clearBuffer();
        switch (userChoice)
        {
        case 1:
            if (counter >= capacity)
            {
                printf("List is full !\n");
                printf("Do you want to increase memory? (1 = Yes, else no)?\n");
                scanf("%d", &userChoice);
                if (userChoice == 1)
                {
                    increaseMemory(&uList,&capacity);
                }
            }
            else
            {
                addUser(uList, counter);
                counter = counter + 1;
            }
            break;

        case 2:
            if (counter >= 1)
            {
                showAllUsers(uList, counter);
            }
            else
            {
                printf("List is empty\n");
            }

            break;

        case 3:
            changeUser(uList, counter);
            break;
        case 4:
            showAllUsers(uList, counter);
            printf("Wich user would you like to remove ? (0 = retrun)\n");
            scanf("%d", &userChoice);
            if (userChoice != 0)
            {
                for (int i = userChoice; i < counter; i++)
                {
                    uList[i-1] = uList[i];
                }
                
                decreaseMemory(&uList,&capacity);
                counter--;
                
                userChoice =0;
            }
                break;
        case 5:
            break;

        default:
            printf("Sorry choice invalid\n");
            break;
        }
    }
    free(uList);
    uList = NULL;
    return 0;
}
