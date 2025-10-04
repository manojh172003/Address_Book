#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "contact.h"

int edit_name(AddressBook *addressBook);
int edit_phone(AddressBook *addressBook);
int edit_email(AddressBook *addressBook);

int ph_fun(AddressBook *addressBook, int);
int name_fun(AddressBook *addressBook, int);
int email_fun(AddressBook *addressBook, int);

int edit_name(AddressBook *addressBook)
{
    int index = 0,choice,flag=0,count=0;
    char name[50];
    listContacts(addressBook);

    printf("1)index\n2)name\n3)exit\n");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        printf("Enter the number of index\n");
        scanf(" %d",&index);
        if(index <=addressBook->contactCount)
        {
            index=index-1;
        }
        name_fun(addressBook, index);
        printf("Name updated !!!\n");
        break;  
    case 2:
        printf("Enter the name\n");
        scanf(" %[^\n]",name);
        for(int i=0;i<addressBook->contactCount;i++)
        {
            if(!strcmp(name, addressBook->contacts[i].name))
            {
                index=1;
                flag=1;
                count++;
            }

        }
        if(flag==1)
        {
            printf("Name updated!!!\n");
        }
        else if(flag==0)
        {
            printf("The name is not found\n");
        }
        if(count<1)
        {
            printf("Enter the index number\n");
            scanf("%d",&index);
            index=index-1;
            name_fun(addressBook, index);
            printf("Name updated!!!\n");

        }
        break;
    case 3:
        printf("Exiting\n");
        break;
    default :
        printf("Invalid Input\n");
   
    }
    return 1;
}

int edit_phone(AddressBook *addressBook)
{
    int flag=0,choice,index=0,count=0;
    char ph[15];
    listContacts(addressBook);

    printf("1)index\n2)phone number\n3)exiting");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        printf("Enter the number of index\n");
        scanf(" %d",&index);
        if(index <=addressBook->contactCount)
        {
            index=index-1;
        }
        name_fun(addressBook, index);
        printf("phone_number updated !!!\n");
        break;  
    case 2:
        printf("Enter the name\n");
        scanf(" %[^\n]",ph);
        for(int i=0;i<addressBook->contactCount;i++)
        {
            if(!strcmp(ph, addressBook->contacts[i].phone))
            {
                index=1;
                flag=1;
                count++;
            }

        }
        if(flag==1)
        {
            printf("phone_number updated!!!\n");
        }
        else if(flag==0)
        {
            printf("The phone_number is not found\n");
        }
        if(count<1)
        {
            printf("Enter the index number\n");
            scanf("%d",&index);
            index=index-1;
            name_fun(addressBook, index);
            printf("phone_number updated!!!\n");

        }
        break;
    case 3:
        printf("Exiting\n");
        break;
    default :
        printf("Invalid Input\n");
   
    }
    return 1;
}

int edit_email(AddressBook *addressBook)
{
    int flag=0,choice,index=0,count=0;
    char email[50];
    listContacts(addressBook);

    printf("1)index\n2)email id\n3)exiting");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        printf("Enter the number of index\n");
        scanf(" %d",&index);
        if(index <=addressBook->contactCount)
        {
            index=index-1;
        }
        name_fun(addressBook, index);
        printf("email_id updated !!!\n");
        break;  
    case 2:
        printf("Enter the email\n");
        scanf(" %[^\n]",email);
        for(int i=0;i<addressBook->contactCount;i++)
        {
            if(!strcmp(email, addressBook->contacts[i].email))
            {
                index=1;
                flag=1;
                count++;
            }

        }
        if(flag==1)
        {
            printf("email updated!!!\n");
        }
        else if(flag==0)
        {
            printf("The email is not found\n");
        }
        if(count<1)
        {
            printf("Enter the index number\n");
            scanf("%d",&index);
            index=index-1;
            name_fun(addressBook, index);
            printf("email updated!!!\n");

        }
        break;
    case 3:
        printf("Exiting\n");
        break;
    default :
        printf("Invalid Input\n");
   
    }
    return 1;
}