#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include <ctype.h>




// int sum(int *a, int n)
// {
//     int *p = a;

//     int s = 0;
//     for (int i = 0; i < n; i++)
//     {
//         printf("%d\n", p[i]);
//     }
//     for (int i = 0; i < n; i++)
//     {
//         printf("%d\n", *(p + i));
//     }
//     return 0;
// }

// int main(void)
// {
//     int numbers[5] = {1, 2, 3, 4, 5};
//     int size = sizeof(numbers) / sizeof(numbers[0]);

//     int result = sum(numbers, size);
//     // printf("Sum is : %d\n", result);

//     return 0;
// }

//******************************************************* */
// void sumit(int *p,int size)
// {
//     int sum = 0;
//     for (int i = 0; i < size; i++)
//     {
//         sum = sum + p[i];
//     }
//     printf("%d", sum);
// }

// int main(void)
// {
//     int numbers[5] = {1, 2, 3, 4, 5};
//     int size = sizeof(numbers) / sizeof(numbers[0]);

//     sumit(numbers,size);

//     return 0;
// }

//******************************************************* */
// int main(void)
// {
//     printf("%lld\n", sizeof(int));    // 4 byte / 32 bit
//     printf("%lld\n", sizeof(int *));  // 8 byte /64 bit
//     printf("%lld\n", sizeof(void *)); // 8 byte /64 bit
// }

//******************************************************* */
// void swap(int *a, int *b)
// {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

// int main(void)
// {
//     int x = 5;
//     int y = 2;

//     printf("x = %d \n",x);
//     printf("y = %d\n", y);

//     swap(&x,&y);

//     printf("x = %d \n",x);
//     printf("y = %d\n", y);
//     return 0;
// }

//******************************************************* */
// int main (void){
//     int x;
//     scanf("%d", &x);
//     int *p = &x;

//     if (p == NULL)
//     {
//         printf("Null\n");
//     }
//     else{
//         printf("Not null\n");
//     }

//     printf("Adress of *p = %p\n",&p);
//     printf("Adress of x = %p\n", &x);

//     printf("Adress that \"*p\" points at = %p\n", &p);

//     printf("Value of x = %d\n", x);

//     return 0;
// }

//******************************************************* */
// typedef struct
// {
//     float temp;
//     int datum;
// } TempAndDate;

// int main(void)
// {
//     float temp;
//     int date;
//     float largestTemp;
//     float lowestTemp;
//     float avgTemp;
//     int howMany;
//     int highDate;
//     int lowDate;

//     printf("How many temps would you like to add? :\n");
//     scanf("%d", &howMany);
//     TempAndDate recordings [howMany];

//     printf("Start adding your temps\n");
//     for (int i = 0; i < howMany; i++)
//     {
//         printf("Temp : ");
//         scanf("%f",&temp );

//         printf("Date \"20201010\" : ");
//         scanf("%d", &date);
//         TempAndDate record = {temp,date};
//         recordings[i] =record;
//     }

//     largestTemp = recordings[0].temp;
//     lowestTemp = recordings[0].temp;

//     int size = sizeof(recordings) / sizeof(recordings[0]);
//     for (int i = 0; i < size; i++)
//     {
//         printf("%.2f @ %d\n", recordings[i].temp, recordings[i].datum);

//         avgTemp = avgTemp +recordings[i].temp;
//         if (recordings[i].temp > largestTemp)
//         {
//             largestTemp = recordings[i].temp;
//             highDate = recordings[i].datum;
//         }
//         if (recordings[i].temp < lowestTemp)
//         {
//             lowestTemp = recordings[i].temp;
//             lowDate = recordings[i].datum;
//         }
//     }

//     avgTemp = avgTemp / howMany;
//     printf("The avg temp is : %.2f\n", avgTemp);
//     printf("The lowest temp was : %.2f and recorded at  %d\n", lowestTemp, lowDate);
//     printf("The highest temp was : %.2f and recorded at  %d\n", largestTemp, highDate);
// }

//******************************************************* */
// int main(void)
// {
//     int temps[5];
//     int size = sizeof(temps) / sizeof(temps[0]);

//     printf("Start adding your temps\n");
//     printf("All odd temps will be replaced with \"0\"\n");
//     for (int i = 0; i < size; i++)
//     {
//         scanf("%d", &temps[i]);
//     }

//     for (int i = 0; i < size; i++)
//     {
//         if (temps[i] % 2 != 0)
//         {
//             temps[i] = 0;
//         }
//     }
//     printf("New number in list :\n");
//     for (int i = 0; i < size; i++)
//     {
//         printf("%d\n", temps[i]);
//     }
// }

//******************************************************* */

// int main(void){
//     int largestNumber = 0;
//     int howMany;

//     printf("How many temps would you like to add? :\n");
//     scanf("%d", &howMany);
//     int temps[howMany];
//     printf("Start adding your temps\n");
//     for (int i = 0; i < howMany; i++)
//     {
//         scanf("%d", &temps[i]);
//     }

//     int size = sizeof(temps)/sizeof(temps[0]);
//     for (int i = 0; i < size; i++)
//     {
//         if (temps[i]>largestNumber)
//         {
//             largestNumber = temps[i];
//         }

//     }
//     printf("Your largest number is : %d",largestNumber);

// }

//******************************************************* */

// int main(void){
//     printf("Enter four temps :\n");
//     int num1;
//     int num2;
//     int num3;
//     int num4;
//     int largestNumber = 0;
//     scanf("%d %d %d %d", &num1,&num2,&num3,&num4);
//     int temps[] = {num1,num2,num3,num4};

//     int size = sizeof(temps)/sizeof(temps[0]);

//     for (int i = 0; i < size; i++)
//     {
//         if (temps[i]>largestNumber)
//         {
//             largestNumber = temps[i];
//         }

//     }
//     printf("Your largest number is : %d",largestNumber);

// }

//*************************************************** */
// typedef struct {
// int age;
// char firstName[20];
// char lastName[20];
// }Person;

// void changeName(Person* p){
//     char *newName = "Callman";
//     printf("Your name is %s\n",p->firstName);
//     // strcpy(p->firstName," Not Callaman" );
//     printf("Change name");
//     strcpy (p->firstName,newName);
// }

// int main (void){
//     Person p1 ={29,"Calle","Engstrom"};
//     printf("Hi %s %s next year you will turn %d\n",p1.firstName,p1.lastName,p1.age+1);
//     changeName(&p1);
//     printf("Name = %s\n",p1.firstName);

// }

//*************************************************** */
// bool bouns = false;

// bool addBonus(int *salary, int age)
// {
//     if (age >= 50 && *salary<30000 )
//     {

//         *salary = *salary * 1.1;
//         return true;
//     }
//     else{
//         return false;
//     }

// }
// int main(void) {
//     int age = 50;
//     int salary = 23000;
//     bool bonus;
//     printf("Age = %d & salary = %d\n",age, salary);
//     bonus = addBonus(&salary,age);
//     char *getBonus = bonus? "Yes" : "No";
//     if (bonus)
//     {
//         printf("Get bonus : %s. New salary = %d\n",getBonus,salary);
//     }
//     else{
//         printf("Get bonus : %s salary %d\n",getBonus,salary);
//     }

// }

//********************************************************* */

// bool wasSpace = true;
// void titleCase(char *text)
// {

//     for (int i = 0; i < strlen(text); i++)
//     {
//         if (wasSpace)
//         {
//             text[i] =toupper(text[i]);
//         }
//         if (text[i] != ' ')
//         {
//             wasSpace = false;
//         }
//         else{
//             wasSpace = true;
//         }
//     }
// }

// int main(void)
// {
//     char text[100] = "calle engstrom heter jag\n";
//     printf("%s", text);
//         titleCase(text);
//     printf("%s",text);
// }
//********************************************************************** */
// void swap(int* num1,int * num2){
//     int temp = *num1;
//     *num2 = temp;
//     *num1 = *num2;
// }

// int main(void)
// {
//    int num1 = 1;
//    int num2 = 5;
//    printf("num1 = %d, num2 = %d\n",num1,num2);
//    printf("Now we swap\n");
//    swap(&num1,&num2);

//    printf("Now num1 = %d and num2 = %d", num1,num2);
// }