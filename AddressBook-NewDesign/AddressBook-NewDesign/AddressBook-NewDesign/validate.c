#include <stdio.h>
#include <string.h>
#include <ctype.h>

int valid_name(char []);
int valid_phoneNumber(char []);
int valid_email(char[]);


int valid_name(char str[])
{
    int len = strlen(str); 
    // checking the condition for the name
    for (int i = 0; i < len; i++)
    {
        if (!isalpha(str[i]) && str[i] != ' ' && str[i] != '.')
        {
            printf("Error!!!\n");
            printf("Enter the valid name\n");
            return 0;
        }
    }

    return 1;
}

int valid_phoneNumber(char str[])
{
    int i = 0, num = 10, len = strlen(str); //here len is the cheking the length of the user output
    for (i = 0; i < len; i++)
    {
        //here it's checking all the values are digit
        if (isdigit(str[i]) == 0) 
        {

            printf("Error!!!\n");
            printf("Enter only digits\n");
            return 0;
        }
    }

    // in up we have mention len =10 if condition is stisfied no changes required 
    if (len == num) 
        return 1;
    // if num len != 10 it will print error
    else
    { 
        printf("Error!!!\n");
        printf("Enter 10 digits\n");
        return 0;
    }
    return 1;
}

int valid_email(char str[])

{
    int len = strlen(str), i, j;
    
    // here it's checking the 1st ch is @
    if (str[0] == '@')
    {
        printf("Enter a name before @\n");
        return 0;
    }
    
    //here it's for last digit should be.com
    char string[4] = ".com";
    int comval = 4;
    j = 0;
    for (i = 0; i < 4; i++)
    {
        if (str[len - comval + i] != string[i])
        {
            printf(".com Not present\n");
            return 0;
        }
    }
    int atrate = 0;
    for (int i = 0; i < len; i++)
    {
        //checking condition for @ 
        if (str[i] == '@')
        {
            atrate++;
        }
    }
    //if @ is not present it should be error email 
    if (atrate == 0)
    {
        printf("Enter @ !!!\n");
        return 0;
    }
    // if @ has more than once it's error
    if (atrate > 1)
    {
        printf("@ more than 1 times!!\n");
        return 0;
    }

    int index = 0;
    for (int i = 0; i < len; i++)
    {
        if (str[i] == '@')
        {
            index = i;
        }
    }
    //there should be some ch in b/w @ and .com like @gmail.com
    if (len - comval - index <= 1)
    {
        printf("No domain name between @ and .com!\n");
        return 0;
    }
    // here checking the condition of the email
    for (i = 0; i < len; i++)
    {
        if (!isalnum(str[i]) && str[i] != '.' && str[i] != '_' && str[i] != '@')
        {
            printf("Error!!!\n");
            printf("Enter valid mail\n");
            return 0;
        }
    }

    return 1;
}