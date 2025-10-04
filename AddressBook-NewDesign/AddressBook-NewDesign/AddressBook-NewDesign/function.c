#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "contact.h"

int name_fun(AddressBook *addressBook, int);
int phone_fun(AddressBook *addressBook, int);
int email_fun(AddressBook *addressBook, int);

int valid_name(char []);
int valid_phoneNumber(char []);
int valid_email(char[]);

int name_fun(AddressBook *addressBook, int i)
{
    char str[50];
    while(1)
    {
        printf("Enter the name \n");
        scanf(" %[^\n]",str);
        int res= valid_name(str);
        if(res == 1)
        {
            strcpy(addressBook->contacts[i].name, str);
            return 1;
        }
        else{
            continue;
        }
    }
}

int phone_fun(AddressBook *addressBook, int i)
{
    char ph[15];
    int duplicate = 0;
    while(1)
    {
        printf("Enter the phone number\n");
        scanf(" %[^\n]",ph);
        int res = valid_phoneNumber(ph);
        if(res != 1)
        {
            continue;
        }
        for(int j=0;j<addressBook->contactCount;j++)
        {
            if(j != i && !strcmp(ph, addressBook->contacts[j].phone))
            {
                duplicate=1;
                break;
            }

        }
        if(duplicate==1)
        {
            printf("The number is duplicate\n");
            break;
        }
        strcpy(addressBook->contacts[i].phone, ph);
        return -1;
    }
}

int email_fun(AddressBook *addressBook, int i)
{
    char email[36];
    int duplicate=0;
    while(1)
    {
        printf("Enter the Email id\n");
        scanf(" %[^\n]",email);
        int res = valid_email(email);
        if(res != 1)
        {
            continue;

        }
        for(int j=0;j<addressBook->contactCount;j++)
        {
            if(j != i && !strcmp(email, addressBook->contacts[i].email))
            {
                duplicate=1;
                break;
            }
        }
        if(duplicate==1)
        {
            printf("The email id is duplicate");
            break;
        }
        strcpy(addressBook->contacts[i].email, email);
        return -1;
    }
}
