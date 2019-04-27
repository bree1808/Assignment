/*
 * Title: Ciphers
 * Description: 
         Rotation Cipher: 
                         Encryption: Encrypts a message by substituting each letter in the alphabet with a letter a fixed number of places away
                                     in the alphabet. The "key" is the number of letters by which the aplhabet is shifted when calculating the substitution.
                         Decryption: Decryption replaces each letter of the encrypted message with an inverse alphabet key shift. 
                                     The "key" is the number of letters by which the aplhabet is shifted when calculating the substitution. 
                                     If key is not known, the program will test and send all possible key shifts and their message to the screen.
         Substitution Cipher: 
                         Encryption: Encrypts a message by replacing each of the 26 message letters (e.g. alphabet) with an encrypted letter. 
                                     The "key" is the 26 encrypted letters.
                         Decryption: Decrypts the message by replacing each of the 26 "key" encrypted letters with alphabetic letters.
 * Usage: To run the program, in the terminal enter: 
                        cd /projects/assignment1 <ENTER>
                        ./a.out <ENTER>
          After it has been set once, after each quit of the program, only ./a.out <ENTER> needs to be typed into the terminal to run again.
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
    char message[1000], ch; // initialising varables - message[1000] used as input and output message variable; ch used as character variable.
	int i, key; //initialising varables - i is the counter variable; key is used as the key shift .
	
	printf("Enter a message to encrypt using rotation (in UPPERCASE): "); //user enters message to encrypt in UPPERCASE when prompted.
	fgetc(stdin); //refer to case 3 (line 93) for use.
    fgets(message, 1000, stdin); //refer to case 3 (line 94) for use.
	
	printf("Enter key shift (1-25): "); //user when prompted un==enters numbered key shift of alphabet.
	scanf("%d", &key); //stores key shift in variable key.
	
	for(i = 0; message[i] != '\0'; ++i) //for loop used to shift each character in the users message the set amount of key shifts - where the message is not a NULL character (white space).
	{
		ch = message[i]; //character variable is stores as message varable.
		
		if(ch >= 'A' && ch <= 'Z') // if statement - if the character is between and including A-Z (alphabet) - ASCII value between 65-90.
		{ 
			ch = ch + key; // new encrypted character is equal to the character + key shift.
			
			if(ch > 'Z') //if character is greater than 'Z' after key shift.
			{
				ch = ch - 'Z' + 'A' - 1; //loops character to within letters A-Z by substracting the value of 'Z' and adding the value of 'A' -1 so that the resulting char is again one in the selected range of A-Z.
			}
			
			message[i] = ch; //new encrypted message of size i has the value of the new character shifts for each letter in the message.
		}
	}
	
	printf("Encrypted message: %s", message); //prints encrypted message to screen.
	
	return 0; //quits program.
}

char *decryptionRotKey() //decryption rotation cipher with key definition.
{
    char message[1000], ch; // initialising varables - message[1000] used as input and output message variable; ch used as character variable.
	int i, key; //initialising varables - i is the counter variable; key is used as the key shift.
	
	printf("Enter a message to decrypt using rotation (in UPPERCASE): "); //user enters message to encrypt in UPPERCASE when prompted.
	fgetc(stdin); //refer to case 3 (line 93) for use.
    fgets(message, 1000, stdin); //refer to case 3 (line 94) for use.
	
	printf("Enter key shift (1-25): "); //user when prompted un==enters numbered key shift of alphabet.
	scanf("%d", &key); //stores key shift in variable key.
	
	for(i = 0; message[i] != '\0'; ++i) //for loop used to shift each character in the users message the set amount of key shifts - where the message is not a NULL character (white space).
	{
		ch = message[i]; //character variable is stores as message varable.
		
		if(ch >= 'A' && ch <= 'Z') // if statement - if the character is between and including A-Z (alphabet) - ASCII value between 65-90.
		{
			ch = ch - key; // new encrypted character is equal to the character - key shift (opposite way to encryption).
			
			if(ch < 'A') //if character is less than 'A' after key shift.
			{
				ch = ch + 'Z' - 'A' + 1; //loops character to within letters A-Z by adding the value of 'Z' and substracting the value of 'A' +1 so that the resulting char is again one in the selected range of A-Z.
			}
			
			message[i] = ch; //new encrypted message of size i has the value of the new character shifts for each letter in the message.
		}
	}
	
	printf("Decrypted message: %s", message); //prints encrypted message to screen.
	
	return 0; //quits program.
}

char *decryptionRotNoKey() //decryption rotation cipher without key.
{
    char message[1000], ch; // initialising varables - message[1000] used as input and output message variable; ch used as character variable.
	int i, key = 0; //initialising varables - i is the counter variable; key is used as the key shift (set key shift to 0 to test all key shifts).
	
	printf("Enter a message to decrypt using rotation (in UPPERCASE): "); //user enters message to encrypt in UPPERCASE when prompted.
	fgetc(stdin); //refer to case 3 (line 93) for use.
    fgets(message, 1000, stdin); //refer to case 3 (line 94) for use.
	
	
	while (key < 25) //while loop - while the key shift is less than 25.
	{
    	for(i = 0; message[i] != '\0'; ++i) //for loop used to shift each character in the users message the set amount of key shifts - where the message is not a NULL character (white space).
    	{
    		ch = message[i]; //character variable is stores as message varable.
    		
    		if(ch >= 'A' && ch <= 'Z') // if statement - if the character is between and including A-Z (alphabet) - ASCII value between 65-90.
    		{
    			ch = ch - 1; // new encrypted character is equal to the character -1 ASCII value.
    			
    			if(ch < 'A') //if character is less than 'A' after ASCII value shift.
    			{
    				ch = ch + 'Z' - 'A' + 1; //loops character to within letters A-Z by adding the value of 'Z' and substracting the value of 'A' +1 so that the resulting char is again one in the selected range of A-Z.
    			}
    			
    			message[i] = ch; //new encrypted message of size i has the value of the new character shifts for each letter in the message.
    		}
    	}
    	
    	
       key++; //key increments by one each iteration of the while loop to test all key shift outcomes.
    	printf("\nKey: %d", key); //prints key shift to terminal.
    	printf("\nDecrypted message: %s", message); //prints decrypted message for each key in the terminal.
    }
    	
	
	return 0; //quits program.
}


char *encryptionSub(char (outputText[])) //encryption substitution - outputText is the message printed to screen after encryption.
{
    int i, j; //initialising counter variables i and j to use in array size.
    char encryptionSubKey[26]; //initialising encryption substitution key of size 26 (26 letters) - encryption substitution key used to encrypt message from alphabet (alpha[26]).    
    printf("Enter a key of 26 characters for encryption (only use each character ONCE and in UPPERCASE): "); //user enters 26 characters in UPPERCASE into terminal when prompted. Each character can only be used ONCE.
    scanf("%s", encryptionSubKey); //stores inputted key in encryptionSubKey.
    
    for(i = 0; i < strlen(outputText); i++) //for loop used outisde other for loop to carry out instructions for both counters i and j - i set to 0 to start at 1; i is less than the length of the string outputText; i is incremented by 1 each loop.
    {
        for(j = 0; j < 26; j++) //for loop used to convert alphabet key message to encryption substitution key message - set j to 0 to start at 1; j is less than 26 (size of alphabet); j is incremented by 1 each loop.
        {
            if(alpha[j] == outputText[i]) //if statement - if the outputText originally has its key as alpha[26] (alphabet).
            {
                outputText[i] = encryptionSubKey[j]; //outputText will change its key to the key inputted by the user - encryptionSubKey.
                break;
            }
        }
    }
    printf("\nEncrypted message: %s", outputText); //prints new encrypted message to the terminal.
    return 0; //quits program.
}
char *decryptionSub(char (outputText[])) //decryption substitution - outputText is the message printed to screen after decryption.
{
    int i, j; //initialising counter variables i and j to use in array size.
    char msg[1000]; //initialising msg from inputted message (used in switch statement).
    
    printf("Enter a key of 26 characters for decryption (only use each character ONCE and in UPPERCASE): "); //user enters 26 characters in UPPERCASE into terminal when prompted. Each character can only be used ONCE.
    scanf("%s", decryptionSubKey); //stores inputted key in decryptionSubKey.
    msg[1000] = decryptionSubKey[26]; //set key for msg inputted by the user as decryptionSubKey.
    outputText[1000] = alpha[26]; //set key for outputText sent to the screen as alpha[26] - changes from key inputted by the user to the alphabetic key.
    
    
    for(i = 0; i < strlen(outputText); i++) //for loop used outisde other for loop to carry out instructions for both counters i and j - i set to 0 to start at 1; i is less than the length of the string outputText; i is incremented by 1 each loop.
    {
        for(j = 0; j < 26; j++) //for loop used to convert alphabet key message to encryption substitution key message - set j to 0 to start at 1; j is less than 26 (size of alphabet); j is incremented by 1 each loop.
        {
            if (decryptionSubKey[j] == outputText[i]) //if statement - if the outputText is in the key inputted by the user.
            {
                outputText[i] = alpha[j]; //sets outputText to alpha[26] - converts from key inputted by user to alphabetic key to be sent to terminal.
                break;
            }
        }
    }
    printf("\nEncrypted message: %s", outputText); //prints new decrypted message to terminal.
    return 0; //quits program.
    
}
