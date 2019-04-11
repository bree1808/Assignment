/*
   Title: Rotation Cipher
   Description: Rotation cipher encrypts a text message by substituting each letter in the alphabet with a letter a fixed number of places away
                in the alphabet. the "key" is the number of letters by which the aplhabet is shifted when calculating the sunstitution.
   Usage: This program produces a menu to select either to encrypt or decrypt a message inputted by the user as a rotation cipher.
          The program will then encrypt or decrypt the inputted text based on the users selection and print the final product to the screen.
            
   How it works: 
*/


#include <stdio.h>
#include <stdlib.h>

int main() 
{

   char message[100];
   int key; //key shift
   int i;
   
//print options/menu to the screen to either encrypt the message or decrypt the message

   printf("Enter operation of message: \n");
   printf("a) encrypt\n");
   printf("b) decrypt\n");
   printf("Selection: ");

//read character from stdin and store its ASCII value in c

   char c;
   scanf("%c", &c);
   
//need to read users input at least once, c needs to be a or b to continue
   
while(c < 'a' || c > 'd') 
{
  switch(c)
   {
      case 1: //if a is chosen - encrypt
      {
         printf("Enter message to encrypt\n");
         scanf("%s", message); //user enters message to encrypt

         printf("Enter key\n"); //user enters key shift of alphabet
         scanf("%d", &key); //stores 

         for (i = 0; message[i] != '\0'; i++)
         {
            message[i] = message[i] + key;
            if (message[i] < 'a')
               message[i] = message[i] - 26;
         }
         printf("Encrypted message: %s\n", message);
         break;
      }
      
      case 2: 
      {
         printf("Enter message to decrypt\n");
         scanf("%s", message);

         printf("Enter key\n");
         scanf("%d", &key);

         for (i = 0; message[i] != '\0'; i++)
         {
            message[i] = message[i] + key;
            if (message[i] < 'a')
               message[i] = message[i] + 26;
         }
         
         printf("Decrypted message: %s\n", message);
         break;
      }  
   }
}

}