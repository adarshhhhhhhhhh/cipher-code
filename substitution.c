#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    //checks if the user has given a key or not
    if (argc == 1)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    //checks if the user has given more than 2 arguments
    else if (argc > 2)
    {
        printf("More than 2 arguments!\n");
        return 1;
    }

    //in case of 2 arguments
    else
        for (int i = 0, length = strlen(argv[1]); i < length; i++)
        {
            //checks if there are any non alphabets in the argument
            if (!isalpha(argv[1][i]))
            {
                printf("Key must only conatain alphabatic characters.\n");
                return 1;
            }

            //checks if there is 26 characters or not
            if (length != 26)
            {
                printf("Key must contain 26 characters.\n");
                return 1;
            }

            //checks if the same character has repeated itself
            for (int k = 0; k < length; k++)
            {
                for (int j = i + 1; j < length; j++)
                {
                    if (tolower(argv[1][i]) == tolower(argv[1][j]))
                    {
                        printf("Key must not contain repeated characters.\n");
                        return 1;
                    }
                }
            }
        }

        //input text from user
        string text = get_string("plaintext: ");
        //converting it into ciphertext
        char cipher_text[strlen(text) + 1]; // +1 for null terminator
        int check;

        for (int i = 0, j = 0, length = strlen(text); i < length; i++, j++)
        {
            if (isupper(text[i]))
            {
                check = text[i] - 'A';
                cipher_text[j] = toupper(argv[1][check]);
            }
            else if (islower(text[i]))
            {
                check = text[i] - 'a';
                cipher_text[j] = tolower(argv[1][check]);
            }
            else
            {
                cipher_text[j] = text[i]; // Copy non-alphabetic characters as-is
            }
        }

        cipher_text[strlen(text)] = '\0'; // Null-terminate the string

        printf("ciphertext: %s\n", cipher_text);

}
