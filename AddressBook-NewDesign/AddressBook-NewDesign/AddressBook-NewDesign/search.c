#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "contact.h"

int search_name(AddressBook *addressBook);
int search_phone(AddressBook *addressBook);
int search_email(AddressBook *addressBook);

int search_name(AddressBook *addressBook)
{
    char str[50];
    int flag = 0, count = 0;
    printf("Enter name: ");
    scanf(" %[^\n]", str); 

    for (int i = 0; i < addressBook->contactCount; i++)
    {
        // here we are checking the user enter name and contact list present in the file
        if (!strcmp(str, addressBook->contacts[i].name))
        {
            flag = 1; 
            count++;
            printf("Person %d\n", i + 1); 
            printf("Name: %s\nPhone number: %s\nEmail ID : %s\n\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
            return i;
        }
    }
    // if no name found in the file
    if (flag == 0) 
    {
        printf("Person Not Found...\nTRY AGAIN\n");
    }
    else if (count > 1) 
    {
        printf("Enter the Index of the person\n");
        int index = 0;
        scanf("%d", &index);

        int i = index - 1; 
        printf("Person %d\n", i + 1); 
        printf("Name: %s\nphone number: %s\nEmail ID : %s\n\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
        return index;
    }
}

int search_phone(AddressBook *addressBook)
{
    char ph[50];
    int flag = 0;
    printf("Enter Phone Number: ");
    scanf("%s", ph);

    for (int i = 0; i < addressBook->contactCount; i++)
    {
        
        if (!strcmp(ph, addressBook->contacts[i].phone))
        {
            flag = 1;
            printf("Person %d\n", i + 1);
            printf("Name: %s\nphone number: %s\nEmail ID : %s\n\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
            return i;
            break;
        }
    }
    if (flag == 0) 
    {
        printf("Person Not Found...\nTRY AGAIN\n");
    }
}

int search_email(AddressBook *addressBook)
{
    char mail[50];
    int flag = 0;
    printf("Enter Email_ID: ");
    scanf("%s", mail);

    for (int i = 0; i < addressBook->contactCount; i++)
    {
       
        if (!strcmp(mail, addressBook->contacts[i].email))
        {
            flag = 1;
            printf("Person %d\n", i + 1);
            printf("Name: %s\nphone number: %s\nEmail ID : %s\n\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
            return i;
            break;
        }
    }
    if (flag == 0) 
    {
        printf("Person Not Found...\nTRY AGAIN\n");
    }
}