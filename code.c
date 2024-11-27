#include <stdio.h>
#include <string.h> // For strcspn
#include <unistd.h>

void Signup(char *username, char *pass); //function declaration
void Log_In(char *correctlogin_username, char *correctlogin_password);

int main() {
    FILE *ptr;
    ptr = fopen("E:\\CCP_Project_total\\Username_Password.txt", "a+");

    char username[25];
    char password[9];

    Signup(username, password); // Calling Sign-Up page

    // Store username and password in file
    fputs(username, ptr);   // Write username
    fputs("\n", ptr);
    fputs(password, ptr);   // Write password
    fputs("\n", ptr);

    fclose(ptr); // Close file after writing

    // Call the login page, passing the correct username and password
    Log_In(username, password);

    return 0;
}

void Signup(char *username, char *pass) //Signup function definition
{
    printf("Welcome to the Sign-Up Page! \n");
    printf("Please Enter Your Username here: ");
    fgets(username, 25, stdin);
    username[strcspn(username, "\n")] = 0; // Remove newline from username

    printf("Enter a Strong Password *(Enter in 8 chars only.)* : ");
    fgets(pass, 9, stdin);
    pass[strcspn(pass, "\n")] = 0; // Remove newline from password

    printf("******************************************************* \n");
    printf("Your Account is created successfully! \n");
    printf("We are redirecting you towards Log-in Page...\nPlease wait...\n");
    sleep(3);
}

void Log_In( char *correctlogin_username, char *correctlogin_password) //Login function definition
 {
    char login_username[25];
    char login_pass[9];
    fflush(stdin);

    while (1)
        {
        +fflush(stdin);
        printf("Please enter your Username: ");
        fgets(login_username, 25, stdin);
        login_username[strcspn(login_username, "\n")] = 0; // Remove newline

        printf("Enter Your Password: ");
        fgets(login_pass, 9, stdin);
        login_pass[strcspn(login_pass, "\n")] = 0; // Remove newline

        if (strcmp(correctlogin_username, login_username) == 0 && strcmp(correctlogin_password, login_pass) == 0) {
            printf("Welcome!\n");
            break; // Exit the loop upon successful login
        }
        else
        {
            printf("Wrong Username or Password. Please try again.\n");
        }
    }
}