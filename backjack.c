#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int deck[52] = {1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 6, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};

int initialDealing(int *sum, int *i)
{

   int bid, a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, dsum = 0, total = 0;
   // dealing of card with generation of random no.
   srand(time(0));

   // player's 1st card
   a = (rand() % 52);
   // printf("%d\n", a);
   e = deck[a];
   printf("1st card dealt is: %d\n", e);

   // removal of generated no.
   for (c = a; c < 52 - 1; c++)
   {
      deck[c] = deck[c + 1];
   }

   // dealer's 1st card
   b = (rand() % 52);
   // printf("%d\n", b);
   f = deck[b];
   printf("card dealt to dealer is: %d\n", f);
   for (c = b; c < 52 - 1; c++)
   {
      deck[c] = deck[c + 1];
   }
   *i = f;

   // player's 2nd card
   d = (rand() % 52);
   // printf("%d\n", d);
   g = deck[d];
   printf("2nd card dealt is: %d\n", g);
   for (c = d; c < 52 - 1; c++)
   {
      deck[c] = deck[c + 1];
   }
   *sum = sumer(e, g);

   return *sum, *i;
   // // sum after initial dealing
   // sum = g + e;
   // printf("sum for now is %d\n", sum);
}

int sumer(int a, int b)
{
   int sum = a + b;
   printf("sum for now is %d\n", sum);
   return sum;
}

int sumer2(int sum, int a)
{
   sum = sum + a;
   printf("sum for now is %d\n", sum);
}

// checking blackjack
int checking(int sum)
{
   int  sum1, sum2,next;
   
   
   if (sum == 21)
   {
      return sum;
   }
   else if (sum > 21)
   {

      return sum;
   }
   else
   {
      printf("Want another card? 1/0 : ");
      scanf("%d", &next);

      // players Next card
      if (next == 1)
      {

         sum1 = nextCard(sum);
         sum2 = checking(sum1);
      }
      else
      {
         return;
      }
   }
}

int nextCard(int sum)
{

   int bid, a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, dsum = 0, total = 0;
   d = (rand() % 52);
   printf("%d\n", d);
   g = deck[d];
   printf("next card dealt is: %d\n", g);
   for (c = d; c < 52 - 1; c++)
   {
      deck[c] = deck[c + 1];
   }
   sum = sum + g;
   printf("sum for now is %d\n", sum);
   return sum;
}

int dealers(int dsum)
{
   int bid, a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, total = 0,sum;
   

   // dealer's next card
   a = (rand() % 52);
   // printf("%d\n", a);
   g = deck[a];
   printf("card dealt to dealer is: %d\n", g);
   for (c = b; c < 52 - 1; c++)
   {
      deck[c] = deck[c + 1];
   }
   sum = sumerDealer(dsum, g);

   sum = dealerCheck(sum);
   return sum;
}

int sumerDealer(int a, int b)
{
   int sum = a + b;
   printf("sum for dealer is %d\n", sum);
   return sum;
}

int dealerCheck(int sum)
{
   if (sum == 21)
   {
      printf("Dealer hit BlackJack\nYou lost\n");
   }
   else if (sum > 21)
   {
      printf("\nDealer Lost\nYou won\n");
   }
   else if (sum < 17)
   {
      sum = dealers(sum);
      return sum;
   }
   else if (sum > 17 && sum < 21)
   {
      int a = (rand() % 10);
      printf("%d",a);
      if (a > 6)
      {
         sum = dealers(sum);
      }
      else
      {
         sum = dealerCheck(sum);
      }
   }
}

int main()
{

   int bid, sum = 0, dsum = 0, total = 100, sum2 = 0,rem = 0, money;
   int next,game;

   printf("How much do you wanna place: ");
   scanf("%d", &money);
   rem = (total - money);
   printf("You placed Rs%d\n", money);
   printf("Remaining money= %d\n", rem);

   initialDealing(&sum, &dsum);
   printf("\ndealer has %d\n", dsum);

   sum = checking(sum);
   if (sum > 21)
   {
      printf("\nYou Lost\nYour money = %d\n", rem);
   }
   else
   {
      sum2 = dealers(dsum);
      if (sum2 > sum)
      {
         printf("\nYou Lost\nYour money = %d\n", rem);
      }
      else if (sum == sum2 || sum > sum2 || sum2 > 21)
      {
         total=rem + money * 2;
         printf("\nYou win\nYour money = %d\n", total);
      }
      else if (sum == 21)
      {
         total=rem + money * 4;
         printf("\nCongrats!! You've hit BlackJack\nYour money = %d\n", total);
      }

   }
    printf("\nDo you want to play again? 1/0: ");
    scanf("%d",&game);
    if(game==1){
      int main();
    }
       
   return 0;
}





