/*
 * Title: Ciphers
 * Description: 
         Rotation Cipher: 
                         Encryption: Encrypts a message by substituting each letter in the alphabet with a letter a fixed number of places away
                                     in the alphabet. The "key" is the number of letters by which the aplhabet is shifted when calculating the substitution.
                         Decryption: Decryption replaces each letter of the encrypted message with an inverse alphabet key shift. 
                                     The "key" is the number of letters by which the aplhabet is shifted when calculating the substitution. 
         Substitution Cipher: 
                         Encryption: Encrypts a message by replacing each of the 26 message letters (e.g. alphabet) with an encrypted letter. 
                                     The "key" is the 26 encrypted letters.
                         Decryption: Decrypts the message by replacing each of the 26 "key" encrypted letters with alphabetic letters.
 * Usage: To run the program, in the terminal enter: 
                        cd /projects/assignment1 <ENTER>
                        ./a.out <ENTER>
          This program produces a menu to select either to encrypt or decrypt a message inputted by the user as either a rotation cipher or a substitution cipher.
          Selection is made by entering a number into the terminal and pressing <ENTER>. 
          The program will then encrypt or decrypt the inputted text based on the users selection and print the final product to the screen.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//funtion prototypes are used to be called from anywhere in the program.
char *encryptionSub(char[]); 
char *decryptionSub(char[]);
char *encryptionRot();
char *decryptionRotKey();
char *decryptionRotNoKey();

char alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
char *encryptionSubKey[26];
char decryptionSubKey[26];
char outputText[1000];
//size_t strlen(const char *str);

int main()
{
    //initialising variables within main()
    int input; //number from the menu entered by the user 
    //char *c_text; //variable for message entered by the user in encryption subsitution
    //char *cipherText, 
    char msg[1000]; //cipherText is the variable for the message entered by the user in decryption substitution.
                                // msg[100] is the variable for the inputted message by the user and the output message for encryption substitution.
     char message[1000]; //variable for inputted message by the user and the outputted message for decryption substitution
    //char encryptionSubKey[26]; //variable for key for encryption substitution
    
    //menu for user to select option
    printf("1. encryption of rotation cipher\n");
    printf("2. decryption of rotation cipher\n");
    printf("3. encryption of substitution cipher\n");
    printf("4. decryption of substitution cipher\n");
    printf("5. Quit\n");
         
    printf("\nChoose an option and press enter:   ");
    scanf("%d",&input); //option is stored in the variable input
    
    //switch case used to select function based on users input option
    switch (input)
    {
        case 1:
            encryptionRot(); //function prototype for encryption substitution - function defintition outside main();
            break; // break terminates other cases in switch statement
        case 2:
            //second menu for decryption rotation - user can choose to either decrypt with key given or test decryption keys without key given.
            printf("1. decryption of rotation cipher with key\n");
            printf("2. decryption of rotation cipher without key\n");
    
         
            printf("\nChoose an option and press enter:   ");
            scanf("%d",&input); //selection stored in variable input
            
            switch (input)
            {
                case 1:
                    decryptionRotKey(); //function prototype for decryption rotation with key
                    break;
                case 2:
                    decryptionRotNoKey(); //function definition for decryption without key
                    break;
                default: //when neither 1 or 2 are chosen
                    printf("Enter valid choice!");
                    break;
            }
            break;
        case 3:
            printf("Enter a message: ");
            fgetc(stdin);
            fgets(msg, 1000, stdin);
            encryptionSub(msg);
            //c_text = encryptionSub(msg);
            break;
        case 4:
            printf("Enter a message: ");
            fgetc(stdin);
            fgets(message, 1000, stdin);
            decryptionSub(message);
            //cipherText = decryptionSub(message);
            break;
        case 5:
            break;
        default:
            printf("Enter valid choice!");
            break;
    }
}
char *encryptionRot()
{
    char message[1000], ch;
	int i, key;
	
	printf("Enter a message to encrypt: ");
	fgetc(stdin);
    fgets(message, 1000, stdin);
	
	printf("Enter key: ");
	scanf("%d", &key);
	
	for(i = 0; message[i] != '\0'; ++i)
	{
		ch = message[i];
		
		if(ch >= 'a' && ch <= 'z')
		{
			ch = ch + key;
			
			if(ch > 'z')
			{
				ch = ch - 'z' + 'a' - 1;
			}
			
			message[i] = ch;
		}
		else if(ch >= 'A' && ch <= 'Z'){
			ch = ch + key;
			
			if(ch > 'Z')
			{
				ch = ch - 'Z' + 'A' - 1;
			}
			
			message[i] = ch;
		}
	}
	
	printf("Encrypted message: %s", message);
	
	return 0;
}

char *decryptionRotKey()
{
    char message[1000], ch;
	int i, key;
	
	printf("Enter a message to decrypt: ");
	fgetc(stdin);
    fgets(message, 1000, stdin);
	
	printf("Enter key: ");
	scanf("%d", &key);
	
	for(i = 0; message[i] != '\0'; ++i)
	{
		ch = message[i];
		
		if(ch >= 'A' && ch <= 'Z')
		{
			ch = ch - key;
			
			if(ch < 'A')
			{
				ch = ch + 'Z' - 'A' + 1;
			}
			
			message[i] = ch;
		}
	}
	
	printf("Decrypted message: %s", message);
	
	return 0;
}

char *decryptionRotNoKey()
{
    char message[1000], ch;
	int i, key = 0;
	
	printf("Enter a message to decrypt: ");
	fgetc(stdin);
    fgets(message, 1000, stdin);
	
	//printf("Enter key: ");
	//scanf("%d", &key);
	
	while (key < 25)
	{
    	for(i = 0; message[i] != '\0'; ++i)
    	{
    		ch = message[i];
    		
    		if(ch >= 'A' && ch <= 'Z')
    		{
    			ch = ch - 1;
    			
    			if(ch < 'A')
    			{
    				ch = ch + 'Z' - 'A' + 1;
    			}
    			
    			message[i] = ch;
    		}
    	}
    	
    	
       key++;
    	printf("\nKey: %d", key);
    	printf("\nDecrypted message: %s", message);
    }
    	
	
	return 0;
}


char *encryptionSub(char (outputText[]))
{
    int i, j;
    char encryptionSubKey[26];
    
    printf("Enter a unique key of 26 characters for encryption: "); 
    scanf("%s", encryptionSubKey);
    
    for(i = 0; i < strlen(outputText); i++)
    {
        for(j = 0; j < 26; j++)
        {
            if(alpha[j] == outputText[i])
            {
                outputText[i] = encryptionSubKey[j];
                break;
            }
        }
    }
    printf("\nEncrypted message: %s", outputText);
    return 0;
}
char *decryptionSub(char (outputText[]))
{
   int i, j;
    char message[1000];
    
    printf("Enter a unique key of 26 characters for decryption: "); 
    scanf("%s", decryptionSubKey);
    message[1000] = decryptionSubKey[26];
    outputText[1000] = alpha[26];
    
    
    for(i = 0; i < strlen(outputText); i++)
    {
        for(j = 0; j < 26; j++)
        {
            if (decryptionSubKey[j] == outputText[i])//if(encryptionSubKey[j] == outputText[i])
            {
                outputText[i] = alpha[j];
                break;
            }
        }
    }
    printf("\nEncrypted message: %s", outputText);
    return 0;
    
}