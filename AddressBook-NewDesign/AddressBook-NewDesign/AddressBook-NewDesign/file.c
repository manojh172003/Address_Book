#include <stdio.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook)
{
    FILE *fptr;
    fptr = fopen("names.csv", "w");
    if (fptr == NULL)
    {
        printf("File not Found\n");
        return;
    }
    fprintf(fptr, "%d\n", addressBook->contactCount);
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        fprintf(fptr, "%d,%s,%s,%s\n", i + 1, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
    }
    printf("Contact saved Sucessfully ....\n");
    fclose(fptr);
}

void loadContactsFromFile(AddressBook *addressBook)
{
    
    FILE *fptr = fopen("names.csv", "r");
    if (fptr == NULL)
    {
        printf("No saved contacts found.\n");
        addressBook->contactCount = 0;
        return;
    }

    if (fscanf(fptr, "%d", &addressBook->contactCount) != 1) {
        printf("Error: Could not read contact count.\n");
        addressBook->contactCount = 0;
        fclose(fptr);
        return;
    }

    int j;
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        if (fscanf(fptr, "%d,%[^,],%[^,],%[^\n]",
                   &j,
                   addressBook->contacts[i].name,
                   addressBook->contacts[i].phone,
                   addressBook->contacts[i].email) != 4)
        {
            printf("Error: Could not read contact %d\n", i + 1);
            addressBook->contactCount = i; // only loaded i contacts
            break;
        }
    }

    fclose(fptr);
}
