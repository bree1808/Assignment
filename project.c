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

//declaring variables outside main to be used in function definitions below.
char alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'}; //declaring string alpha of size 26 (26 letters), used for substitution ciphers.
char encryptionSubKey[26]; //declaring string of size 26 (26 letters) as key for encryption substitution.
char decryptionSubKey[26]; //declaring string of size 26 (26 letters) as key for decryption substitution.
char outputText[1000]; //declaring outputText as variable for message printed to screen for substitution ciphers.  

/*int main() includes variables initialised for variables within the function and a menu for the user. The user will type a number into the terminal at prompt and press <ENTER>, where the switch statement will be used
to carry out the function of choice.*/
int main()
{
    //initialising variables within main()
    int input; //number from the menu entered by the user  
    char msg[1000]; //variable declared for the inputted message by the user and the output message for the substitution ciphers - used within switch statement and in function definition.
    //char message[1000]; //variable for inputted message by the user and the outputted message for rotation ciphers - used within 
    
    
    //menu for user to select option
    printf("1. Encryption of rotation cipher\n");
    printf("2. Decryption of rotation cipher\n");
    printf("3. Encryption of substitution cipher\n");
    printf("4. Decryption of substitution cipher\n");
    printf("5. Quit\n");
         
    printf("\nChoose an option (number) and press enter:   ");
    scanf("%d",&input); //option is stored in the variable input to be used in switch statement.
    
    //switch case used to select function based on users input option.
    switch (input)
    {
        case 1: //encryption substitution.
            encryptionRot(); //function prototype for encryption substitution - function defintition outside main();
            break; // break terminates other cases in switch statement.
            
        case 2: //decryption rotation.
            //second menu for decryption rotation - user can choose to either decrypt with key given or test decryption keys without key given.
            printf("1. Decryption of rotation cipher with key\n");
            printf("2. Decryption of rotation cipher without key\n");
    
         
            printf("\nChoose an option (number) and press enter:   ");
            scanf("%d",&input); //selection stored in variable input to be used in switch statement.
            
            //switch case used to select function of decryption rotation based on users input.
            switch (input)
            {
                case 1: //decryption rotation with key.
                    decryptionRotKey(); //function prototype for decryption rotation with key.
                    break;
                    
                case 2: //decryption rotation without key.
                    decryptionRotNoKey(); //function definition for decryption without key.
                    break;
                    
                default: //when neither 1 or 2 are chosen.
                    printf("Enter valid choice!"); //prints user - friendly message to screen, quits program.
                    break;
            }
            break;
            
        case 3: //encryption substitution.
            printf("Enter a message to encrypt using substitution (in UPPERCASE): "); //user enters message into terminal on prompt in UPPERCASE.
            fgetc(stdin); //Reads the next character from stdin and returns unsigned char cast.
            fgets(msg, 1000, stdin); //read from stdin, stores in msg of size 1000.
            encryptionSub(msg); //function prototype to be called in function definition below int main().
            break;
            
        case 4: //decryption substitution.
            printf("Enter a message to decrypt using substitution (in UPPERCASE): "); //user enters message into terminal on prompt in UPPERCASE.
            fgetc(stdin); //refer to case 3 (line 93) for use.
            fgets(msg, 1000, stdin); //refer to case 3 (line 94) for use.
            decryptionSub(msg); // function prototype to be called in function definition below int main().
            break;
            
        case 5: //quit program.
            break;
            
        default: //when none of the numbers from 1-5 are chosen.
            printf("Enter valid choice!"); //prints user - friendly message to screen, quits program.
            break;
    }
}
//function prototypes are defined below int main().
char *encryptionRot() //encryption rotation cipher definition
{
    char message[1000], ch; // initialising varables - message[1000] used as input and output message variable; ch used as character varible.
	int i, key; //initialising varables - i is the counter variable; key is used as the key shift .
	
	printf("Enter a message to encrypt using encryption rotation (in UPPERCASE): "); //user enters message to encrypt in UPPERCASE when prompted.
	fgetc(stdin); //refer to case 3 (line 93) for use.
    fgets(message, 1000, stdin); //refer to case 3 (line 94) for use.
	
	printf("Enter key shift (number): "); //uder when prompted un==enters numbered key shift of alphabet.
	scanf("%d", &key); //stores key shift in variable key.
	
	for(i = 0; message[i] != '\0'; ++i) //for loop used to shift each character in the users message the set amount of key shifts - where the message is not a NULL character (white space).
	{
		ch = message[i]; //character variable is stores as message varable.
		
		if(ch >= 'A' && ch <= 'Z') // if statement - if the character is between and including A-Z (alphabet).
		{ 
			ch = ch + key; // new encrypted character is equal to the character + key shift.
			
			if(ch > 'Z') //if character is greater than Z after key shift.
			{
				ch = ch - 'Z' + 'A' - 1; //loops character to within letters A-Z by substracting the value of 'Z' and adding the value of 'A' -1 so that the resulting char is again one in the selected range of A-Z.
			}
			
			message[i] = ch; //new encrypted message of size i has the value of the new character shifts for each letter in the message.
		}
	}
	
	printf("Encrypted message: %s", message); //prints encrypted message to screen.
	
	return 0; //quits program.
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
    char msg[1000];
    
    printf("Enter a unique key of 26 characters for decryption: "); 
    scanf("%s", decryptionSubKey);
    msg[1000] = decryptionSubKey[26];
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