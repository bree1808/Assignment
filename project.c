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
 
void encryptionRotation();
void decryptionRotation();
void encryptionSubstitution();
void decryptionSubstitution();
void quit();
 
int main () {
    // insert code here...
    
    
    int input;
         
     
    
         
        printf("1. encryption of rotation cipher\n");
        printf("2. decyrption of rotation cipher\n");
        printf("3. encryption of substitution cipher\n");
        printf("4. decyrption of substitution cipher\n");
        printf("5. Quit\n");
         
         
         
         
     
    printf("\nChoose an option and press enter:   ");
     
     
    scanf("%d",&input);
     
     
     
    if(input <= 5 && input >= 1)
    switch (input) {
        case 1:
            encryptionRotation();;
            break;
        case 2:
            decryptionRotation();
            break;
        case 3:
           encryptionSubstitution();
            break;
        case 4:
           decryptionSubstitution();
            break;
        case 5:
            quit();
            break;
    }
         
    else {
     
    printf("\nInvalid choice!");
    return 0;
    }
}

char * message;
int key;
int i;
 
void encryptionRotation(){
printf("Enter message to encrypt:\n");
scanf("%s", message); //user enters message to encrypt

printf("Enter key shift:/n"); //user enters key shift of alphabet
scanf("%d", &key); //stores key shift into variable key

for (i = 0; message[i] != '\0'; i++)
    {
        message[i] = message[i] + key;
            if (message[i] < 'a') 
                message[i] = message[i] - 26;
             printf("Encrypted message: %s\n", message);
    }
}
 
void decryptionRotation()
{
    printf("\nChoose from a save file");
}

void encryptionSubstitution(){
printf("\nStarting new game....");
}
 
 
void decryptionSubstitution(){
printf("\nChoose from a save file");
}

 
void quit(){
    printf("\nThanks for playing.../n");

}