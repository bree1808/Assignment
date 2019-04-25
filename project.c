#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *encryptionSub(char[]);
char *decryptionSub(char[]);
char *encryptionRot();
char *decryptionRot();

char alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
//char rndm[26]= {'K', 'U', 'D', 'P', 'T', 'E', 'V', 'J', 'S', 'B', 'L', 'W', 'A', 'I', 'Z', 'G', 'X', 'C', 'M', 'N', 'F', 'Y', 'H', 'R', 'O', 'Q'};
char encryptionSubKey[26];
char decryptionSubKey[26];
size_t strlen(const char *str);

int main()
{
    int input;
    char *c_text;
    char *cipherText, msg[1000];
    char message[1000]; 
    char encryptionSubKey[26];
    
    printf("1. encryption of rotation cipher\n");
    printf("2. decryption of rotation cipher\n");
    printf("3. encryption of substitution cipher\n");
    printf("4. decyrption of substitution cipher\n");
    printf("5. Quit\n");
         
    printf("\nChoose an option and press enter:   ");
    scanf("%d",&input);
    
    switch (input)
    {
        case 1:
            encryptionRot();
            break;
        case 2:
            decryptionRot();
            break;
        case 3:
            printf("Enter a message: ");
            fgetc(stdin);
            fgets(msg, 1000, stdin);
            c_text = encryptionSub(msg);
            break;
        case 4:
            printf("Enter a message: ");
            fgetc(stdin);
            fgets(message, 1000, stdin);
            cipherText = decryptionSub(message);
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

char *decryptionRot()
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

char *encryptionSub(char (outputText[]))
{
    int i, j;
    char msg[1000];
    
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
    char message[255];
    
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