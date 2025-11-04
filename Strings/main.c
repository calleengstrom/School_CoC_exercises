#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include <ctype.h>

//******************************************************* */
// 2.4. Övning 8: Gör om alla bokstäver till versaler

// int main()
// {
//     char a[100];
//     printf("Enter a string: ");
//     fgets(a, 100, stdin);
//     a[strcspn(a,"\n")]=0;
//     printf("%s\n" ,a);

//     int size = strlen(a);
//     for (int i = 0; i < size; i++)
//     {
//         a[i] = toupper(a[i]);
//     }
//      printf("%s\n" ,a);
// }

//******************************************************* */
// 2.3. Övning 7: Slå ihop två strängar
// int main()
// {
//     char a[100], b[100];
//     printf("Enter first string: ");
//     fgets(a, 100, stdin);
//     printf("Enter second string: ");
//     fgets(b, 100, stdin);
//     a[strcspn(a, "\n")] = 0;
//     b[strcspn(b, "\n")] = 0;
//     // strcat(a, " ");
//     strcat(a, b);
//     printf("Result: %s\n", a);
//     return 0;
// }

//******************************************************* */
//  2.2. Övning 6: Vänd en sträng baklänges
// void reverseString(char *s, int size)
// {
//     int counter = size-1;
//     for (int i = 0; i < counter; i++, counter--)
//     {

//         char temp = s[i];
//         s[i] = s[counter];
//         s[counter] = temp;
//     }
//     printf("%s", s);
// }

// int main(void)
// {
//     char text[50];
//     printf("Enter a text\n");
//     fgets(text, sizeof(text), stdin);
//     text[strcspn(text, "\n")] = 0;
//     int size = strlen(text);

//     reverseString(text, size);
//     return 0;
// }

//******************************************************* */
// 2.1. Övning 5: Räkna antal vokaler
// int countVowls(char *text, int size){
//     int countVow = 0;

//     for (int i = 0; i < size; i++)
//     {
//         char c = tolower(text[i]);
//         if ((c=='a') ||
//             (c=='e') ||
//             (c=='i') ||
//             (c=='o') ||
//             (c=='u') ||
//             (c=='y'))
//         {
//             countVow++;
//         }

//     }
//     return countVow;

// }

// int main(void){
//     char text[50];
//     printf("Enter a text : ");
//     fgets(text,sizeof(text),stdin);
//     text[strcspn(text,"\n")]= 0;
//     int counter = strlen(text);
//     int countVow = countVowls(text,counter);
//     printf("There are %d vows in your text\n",  countVow);
//     return 0;
// }

//******************************************************* */
//   1.4. Övning 4: Jämföra två strängar
// int main(void)
// {

//     char word1[50] = "Calle Engstrom";
//     char word2[50] = "Callan";
//     int result = strcasecmp(word1, word2);
//     if (result == 0)
//         printf("Strings are equal.\n");
//     else if (result < 0)
//         printf("%s comes first.\n", word1);
//     else
//         printf("%s comes first.\n", word2);
// }

//******************************************************* */
//  1.3. Övning 3: Kopiera en sträng
// int main(void)
// {

//     char namn[50];
//     int size = sizeof(namn)/sizeof(char);
//     printf("%d\n",size);
//     printf("Ange ditt namn: ");
//     fgets(namn, sizeof(namn), stdin);
//     size = sizeof(namn)/sizeof(char);
//     printf("%d\n",size);
//     namn[strcspn(namn, "\n")] = '\0';

//     char cpy[50];

//     strcpy(cpy,namn);
//     printf("%s", cpy);
// }

//******************************************************* */
//   1.2. Övning 2: Räkna längden på en sträng
// int my_strlen(char *namn){
//     int counter = 0;

//     for (size_t i = 0; i < sizeof(namn); i++)
//     {
//         counter++;
//     }
//     return counter;

// }

// int main(void)
// {

//     char namn[50];
//     printf("Ange ditt namn: ");
//     fgets(namn,sizeof(namn), stdin);
//     namn[strcspn(namn,"\n")] = '\0';
//     int size = strlen(namn);
//     int mySizemy = strlen(namn);

//     printf("Strlen = %d\n", size);
//     printf("MyStrln = %d\n", mySizemy);

// }
