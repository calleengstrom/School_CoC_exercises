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

void defultUser(User *uList)
{
    int age = 0;
    char name[Max_name_char] = "Jon Dog";
    char email[Max_email_char] = "jon.doe@mrdogjoe.se";
    User aUser;
    strcpy(aUser.name, name);
    strcpy(aUser.email, email);
    aUser.age = age;
    for (int i = 0; i < 10; i++)
    {
        uList[i] = aUser;
    }
}

void showAllUsers(User *uList)
{
    for (int i = 0; i < 10; i++)
    {
        printf("No: %d.  Name :  %s.   Age  %d.   Email :   %s.\n", i + 1, uList[i].name, uList[i].age, uList[i].email);
    }
}

void clearBuffer()
{
    char c;
    while ((c = getchar()) == EOF)
    {
    }
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
    while(age != 1){
    printf("Enter age : ");
    scanf("%d", &age);
    clearBuffer();
    if ((age > 130) || (age < 0))
    {
        age = 0;
        printf("Invaild age, enet a age between 1 - 130\n");
    }
    else{
    uList[index].age = age;
    age =1;
    }
}
}

void addUser(User *uList, int *counter)
{

    enterName(uList, *counter);
  
    enterEmail(uList, *counter);
    
    enterAge(uList, *counter);
    
    *counter = *counter + 1;
}

void changeUser(User *uList, int size)
{
    showAllUsers(uList);
    int userChoice;

    printf("Wich user woudl you like to change ?`\n");
    scanf("%d", &userChoice);
    clearBuffer();

    for (int i = 0; i < size; i++)
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

int main(void)
{
    User uList[10];
    defultUser(uList);
    int userChoice;
    int counter = 0;
    int size = sizeof(uList) / sizeof(uList[0]);
    while (userChoice != 4)
    {
        /* code */
        printf("****************\n");
        printf("User meny \n");
        printf("1 : Add new user\n");
        printf("2 : Show all users\n");
        printf("3 : Edit a user\n");
        printf("4 : Exit \n");
        printf("****************\n");
        scanf("%d", &userChoice);
        clearBuffer();
        switch (userChoice)
        {
        case 1:
            addUser(uList, &counter);
            break;
        case 2:
            showAllUsers(uList);
            break;
        case 3:
            changeUser(uList, size);
            break;
        case 4:
            //
            break;

        default:
            printf("Sorry choice invalid\n");
            break;
        }
    }

    return 0;
}
