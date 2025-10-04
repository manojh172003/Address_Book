#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"


int count=0;

int name_fun(AddressBook *addressBook, int);
int phone_fun(AddressBook *addressBook, int);
int email_fun(AddressBook *addressBook, int);

int search_name(AddressBook *addressBook);
int search_phone(AddressBook *addressBook);
int search_email(AddressBook *addressBook);

int edit_name(AddressBook *addressBook);
int edit_phone(AddressBook *addressBook);
int edit_email(AddressBook *addressBook);

int input();

void listContacts(AddressBook *addressBook) 
{
    int i;
    if(addressBook->contactCount==0)
    {
        printf("No, contact found");
    }
    else{
        printf("::: list of the contacts :::\n");
        printf("Name    phone_number     Email\n");
        printf("---------------------------------\n");
        for(int i=0;i<addressBook->contactCount;i++)
        {
            //printf("person:%d\n",i+1);
            printf("%-8s %-10s %-8s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);

        }
    }
    
}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    populateAddressBook(addressBook);
    
    // Load contacts from file during initialization (After files)
    //loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}


void createContact(AddressBook *addressBook)
{
    int n,p,e;
    printf("Enter the number of the contact to be saved \n");
    int num;
    scanf("%d",&num);
    int count=addressBook->contactCount+num;
    do{
        printf("enter the details of the person %d\n",addressBook->contactCount+1);
        // to store name
        n=name_fun(addressBook, addressBook->contactCount);
        //to store phone number
        p=phone_fun(addressBook, addressBook->contactCount);
        //to store email.id
        e=email_fun(addressBook, addressBook->contactCount);
        // here it will check all condition of name phone and email id if every condition is true it will increase the count value
        if(n && p && e)
        {
            addressBook->contactCount++;
        }
    }while(addressBook->contactCount < count);
    
    
}

void searchContact(AddressBook *addressBook) 
{
    // here we will pass the funtion for search contact in search.c file
    int choice=0;
    do{
        printf("1)Name\n");
        printf("2)phone\n");
        printf("3)Email\n");
        printf("4)Exit");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            search_name(addressBook);
            break;
        case 2:
            search_phone(addressBook);
            break;
        case 3:
            search_email(addressBook);
            break;
        case 4:
            printf("Exitting\n");
            break;
        default:
            printf("Enter valid input\n");
        }
    }while(choice != 4);
}

void editContact(AddressBook *addressBook)
{
	int choice=0;
    do{
        printf("1)Name\n");
        printf("2)phone\n");
        printf("3)Email\n");
        printf("4)Exit");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            edit_name(addressBook);
            break;
        case 2:
            edit_phone(addressBook);
            break;
        case 3:
            edit_email(addressBook);
            break;
        case 4:
            printf("Exitting\n");
            break;
        default:
            printf("Enter valid input\n");
        }
    }while(choice != 4);
    
}

void deleteContact(AddressBook *addressBook)
{
    int choice=0;
    int result=0;

    do{
        printf("Enter the choice to delete\n");
        printf("1)name\n");
        printf("2)phone number\n");
        printf("3)Email\n");
        printf("4)exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            result=search_name(addressBook);
            if(result != -1)
            {
                for(int i=result; i<addressBook->contactCount ; i++)
                {
                    addressBook->contacts[i] = addressBook->contacts[i+1]; 
                }
                addressBook->contactCount--;
                saveContactsToFile(addressBook);
                printf("Contacts deleted succesfully\n");
            }
            else
            {
                printf("Contacts not found\n");
            }
            break;
        case 2:
            result=search_phone(addressBook);
            if(result != -1)
            {
                for(int i=result;i<addressBook->contactCount;i++)
                {
                    addressBook->contacts[i] = addressBook->contacts[i+1]; 
                }
                addressBook->contactCount--;
                saveContactsToFile(addressBook);
                printf("Contacts deleted succesfully\n");
            }
            else
            {
                printf("Contacts not found\n");
            }
            break;
        case 3:
            result=search_email(addressBook);
            if(result != -1)
            {
                for(int i=result;i<addressBook->contactCount;i++)
                {
                    addressBook->contacts[i] = addressBook->contacts[i+1]; 
                }
                addressBook->contactCount--;
                saveContactsToFile(addressBook);
                printf("Contacts deleted succesfully\n");
            }
            else
            {
                printf("Contacts not found\n");
            }
            break;
        case 4:
            printf("Exitting\n");
        default :
            printf("Enter valid choice\n");
                
        }
    }while(choice != 4);
   
}
