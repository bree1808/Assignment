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
#include <string.h>


char *encryption(char cipher_text[]);
char *decryption(char cipher_text[]);
char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char rndm[26] = {'k', 'u', 'd', 'p', 't', 'e', 'v', 'j', 's', 'b', 'l', 'w', 'a', 'i', 'z', 'g', 'x', 'c', 'm', 'n', 'f', 'y', 'h', 'r', 'o', 'q'};

size_t strlen(const char *str);
char cipher_text[1000];
 
 
int main () {
    char message[1000], ch, substitution_key[26];
    int i, key;
    int j;
    char msg[255];
    char cipher_text[255];
    
    
    int input;
         
        printf("1. encryption of rotation cipher\n");
        printf("2. decryption of rotation cipher\n");
        printf("3. encryption of substitution cipher\n");
        printf("4. decryption of substitution cipher\n");
        printf("5. Quit\n");
         
        printf("\nChoose an option and press enter:   ");
        scanf("%d",&input);
     
    
    switch (input) {
        case 1: //encryption rotation
        	printf("Enter a message to encrypt: ");
        	fgetc(stdin);
            fgets(message, 1000, stdin);
        	
        	printf("Enter key: ");
        	scanf("%d", &key);
        	
        	for(i = 0; message[i] != '\0'; ++i){
        		ch = message[i];
        		
        		if(ch >= 'a' && ch <= 'z'){
        			ch = ch + key;
        			
        			if(ch > 'z'){
        				ch = ch - 'z' + 'a' - 1;
        			}
        			
        			message[i] = ch;
        		}
        		else if(ch >= 'A' && ch <= 'Z'){
        			ch = ch + key;
        			
        			if(ch > 'Z'){
        				ch = ch - 'Z' + 'A' - 1;
        			}
        			
        			message[i] = ch;
        		}
        	}
        	
        	printf("Encrypted message: %s", message);
            break;
            
        case 2:
            printf("Enter a message to decrypt: ");
            fgetc(stdin);
            fgets(message, 1000, stdin);
        	
        	printf("Enter key: ");
        	scanf("%d", &key);
        	
        	for(i = 0; message[i] != '\0'; ++i){
        		ch = message[i];
        		
        		if(ch >= 'a' && ch <= 'z'){
        			ch = ch - key;
        			
        			if(ch < 'a'){
        				ch = ch + 'z' - 'a' + 1;
        			}
        			
        			message[i] = ch;
        		}
        		else if(ch >= 'A' && ch <= 'Z'){
        			ch = ch - key;
        			
        			if(ch < 'A'){
        				ch = ch + 'Z' - 'A' + 1;
        			}
        			
        			message[i] = ch;
        		}
        	}
        	
        	printf("Decrypted message: %s", message);
            
            break;
            
        case 3:
        printf("Enter plain text: ");
        fgetc(stdin);
        fgets(msg, 255, stdin);
        
        printf("Enter a unique key of 26 characters for encryption: "); // KUDPTEVJSBLWAIZGXCMNFYHROQ
        fgets(substitution_key, 27, stdin);
    
            for(i = 0; i < strlen(cipher_text); i++)
            {
                for(j = 0; j < 26; j++)
                {
                    if(alpha[j] == cipher_text[i])
                    {
                        cipher_text[i] = substitution_key[j];
                        
                break;
                    }
                }
            }
                printf("\nEncrypted message: %s", cipher_text);
                return 0;
            break;
        case 4:
       printf("Enter a unique key of 26 characters for encryption: "); // KUDPTEVJSBLWAIZGXCMNFYHROQ
    scanf("%s", key);
    
    for(i = 0; i < strlen(cipher_text); i++)
    {
        for(j = 0; j < 26; j++)
        {
            if(alpha[j] == cipher_text[i])
            {
                cipher_text[i] = key[j];
                break;
            }
        }
    }
    printf("\nEncrypted message: %s", cipher_text);
    return 0;
                
            break;
        case 5:
            
            break;
    }
         
}

	

