#include<stdio.h>   // Standard input-output functions
#include<string.h>  // For string functions like strlen()
#include<ctype.h>   // For character checking functions like isupper(), islower()
#include<math.h>    // Included but not used in the program

void main() // Main function (better practice: use int main())
{
    char plain[100], cipher[100]; // Arrays to store plain text and encrypted text
    int key, i, length, result;   // Variables for key, loop index, length of text, and an unused result variable

    printf("Enter the message\n");
    scanf("%s",&plain);  // Takes user input for the message (unsafe, should use fgets)

    printf("Enter the key value\n");
    scanf("%d", &key);  // Takes the shift key from the user

    printf("Plain text %s is\n", plain);  // Displays the original message
    printf("Encrypted text:\n");

    // Encryption process
    for(i = 0, length = strlen(plain); i < length; i++)  
    {
        cipher[i] = plain[i] + key; // Shifts each character forward by 'key' positions

        // Handling uppercase letters (A-Z) to keep them within range
        if(isupper(plain[i]) && (cipher[i] > 'Z'))
            cipher[i] = cipher[i] - 26; // Wraps around back to 'A'

        // Handling lowercase letters (a-z) to keep them within range
        if(islower(plain[i]) && (cipher[i] > 'z'))
            cipher[i] = cipher[i] - 26; // Wraps around back to 'a'

        printf("%c", cipher[i]); // Prints the encrypted character
    }

    printf("\nAfter Decryption\n");

    // Decryption process
    for(i = 0; i < length; i++)
    {
        plain[i] = cipher[i] - key; // Shifts each character backward by 'key' positions

        // Handling uppercase letters (A-Z) to keep them within range
        if(isupper(cipher[i]) && (plain[i] < 'A'))
            plain[i] = plain[i] + 26; // Wraps around back to 'Z'

        // Handling lowercase letters (a-z) to keep them within range
        if(islower(cipher[i]) && (plain[i] < 'a'))
            plain[i] = plain[i] + 26; // Wraps around back to 'z'

        printf("%c", plain[i]); // Prints the decrypted character
    }
}