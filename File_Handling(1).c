#include <stdio.h>
#include <string.h> // For strcspn
#include <unistd.h>

void SignInPage(char *username, char *pass);
void Log_In(char *login_username, char *login_pass);

int main() {
    FILE *ptr;
    ptr = fopen("Username_Password.txt", "w");

    char username[25];
    char password[9];

    SignInPage(username, password); // Calling Sign-In page

    // Store username and password in file
    fputs(username, ptr);   // Write username
    fputs("\n", ptr);
    fputs(password, ptr);   // Write password
    fputs("\n", ptr);
    fclose(ptr);


    char login_username[25];
    char login_pass[9];

    ptr = fopen("E:\\CCP_Project_total\\Username_Password.txt", "a");

    Log_In(login_username, login_pass); // Calling Login page

    fputs(login_username, ptr);
    fputs("\n", ptr);
    fputs(login_pass, ptr);
    fputs("\n",ptr);

    fclose(ptr); // Close file after writing

    if(strcmp(username,login_username)==0 && strcmp(password,login_pass)==0)
    {
        printf("Welcome to the Application!");
    }
    else{
        printf("Wrong Username or password.");
    }

    return 0;
}

void SignInPage(char *username, char *pass) {
    printf("Welcome to the Sign-Up Page! \n");
    printf("Please Enter Your Username here: ");
    fgets(username, 25, stdin);
    username[strcspn(username, "\n")] = '\0'; // Remove newline from username

    printf("Enter a Strong Password **(Enter in 8 chars only.)** : ");
    fgets(pass, 9, stdin);
    pass[strcspn(pass, "\n")] = '\0'; // Remove newline from password

    printf("******************************************************* \n");
    printf("Your Account was created successfully! \n");
    printf("We are redirecting you towards Log-in Page...\nPlease wait...\n");
    sleep(3);
}

void Log_In(char *login_username, char *login_pass) {
    fflush(stdin);
    printf("Welcome to the Login-Page! \n");
    printf("Please enter your Username: ");
    fgets(login_username, 25, stdin);
    login_username[strcspn(login_username, "\n")] = '\0'; // Remove newline

    printf("Enter Your Password: ");
    fgets(login_pass, 9, stdin);
    login_pass[strcspn(login_pass, "\n")] = '\0'; // Remove newline
}