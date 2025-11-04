#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include <ctype.h>



//******************************************************* */
//  14. Ta bort ett element Låt användaren ange vilket index som ska tas bort. Flytta
//  resterande element så att hålet försvinner. ** Ändra på **

// int main(void)
// {
//     int nums[5];

//     int indx;
//     int newNum;
//     int size = sizeof(nums) / sizeof(int);
//     for (int i = 0; i < size; i++)
//     {
//         printf("Enter number: ");
//         scanf("%d", &nums[i]);
//     }

//     printf("Choose a number to change (1/2/3 etc):\n");
//     for (int i = 0; i < size; i++)
//     {
//         printf("%d : %d\n",i+1, nums[i]);
//     }
//     printf(": ");
//     scanf("%d",&indx);
//     printf("What would you like to change to?\n: ");
//     scanf("%d",&newNum);

//     nums[indx-1] = newNum;

//     for (int i = 0; i < size; i++)
//     {
//         printf("%d : %d\n",i+1, nums[i]);
//     }

// }

//******************************************************* */
// 11. Byt plats på element Låt användaren skriva in 5 tal. Byt plats på första och sista
//  elementet.
// 
// int main(void)
// {
//     int nums[5];
//     int size = sizeof(nums) / sizeof(int);
//     for (int i = 0; i < size; i++)
//     {
//         printf("Enter number: ");
//         scanf("%d", &nums[i]);
//     }

//     for (int i = 0; i < size; i++)
//     {
//         printf("Numbers : %d\n", nums[i]);
//     }

//     // Swap
//     int temp = nums[0];
//     nums[0] = nums[size-1];
//     nums[size-1] = temp;
//     for (int i = 0; i < size; i++)
//     {
//         printf("Numbers : %d\n", nums[i]);
//     }
//     return 0;
// }

//******************************************************* */
//  10. Summera två arrayer Skapa två arrayer med 5 heltal vardera. Skapa en tredje
//  som innehåller summan av motsvarande element.

// int main(void){
//     int nums1[]= {1,3,5,7,9};
//     int nums2[]= {2,4,6,8,10};

//     int size = sizeof(nums1)/sizeof(nums1[0]);

//     int nums3[size];

//     for (int i = 0; i < size; i++)
//     {
//         nums3[i] = nums1[i]+nums2[i];
//     }
//     for (int i = 0; i < size; i++)
//     {
//         printf("Nums 1 = %d Nums 2 = %d Nums 3 = %d\n",nums1[i],nums2[i],nums3[i]);
//     }

//     return 0;
// }

//******************************************************* */
// 9. Kopiera en array Kopiera innehållet i en array till en annan med en loop.
// int main(void)
// {
//     char array1[] = "calle";

//     int size = sizeof(array1) / sizeof(array1[0]);
//     char array2[size];

//     for (int i = 0; i < size; i++)
//     {
//         array2[i] = array1[i];
//     }
//     // eller
//     // strcpy(array2,array1);
//     for (int i = 0; i < size; i++)
//     {
//         printf(" array 1 : %c  array 2 : %c\n",array1[i], array2[i]);
//     }

// }

//******************************************************* */