#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WINDOWS 1
void clrscr()
{
#ifdef WINDOWS
    system("cls");
#endif
#ifdef LINUX
    system("clear");
#endif
}

#define MAX_NAME_LENGTH 50
#define MAX_ADDRESS_LENGTH 100
#define MAX_CONTACT_LENGTH 15
#define MAX_BLOOD_GROUP_LENGTH 5

typedef struct Donor
{
    char name[MAX_NAME_LENGTH];
    char contactNumber[MAX_CONTACT_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    char bloodGroup[MAX_BLOOD_GROUP_LENGTH];
    char lastDonationDate[11];
    struct Donor *next;
} Donor;

Donor *head = NULL;

void addDonor()
{
    Donor *newDonor = (Donor *)malloc(sizeof(Donor));

    printf("Enter donor details:\n");
    printf("Name: ");
    getchar();
    gets(newDonor->name);
    printf("Contact Number: ");
    scanf("%s", newDonor->contactNumber);
    printf("Address: ");
    getchar();
    gets(newDonor->address);
    printf("Blood Group: ");
    scanf("%s", newDonor->bloodGroup);
    printf("Last Donation Date (YYYY-MM-DD): ");
    scanf("%s", newDonor->lastDonationDate);

    newDonor->next = head;
    head = newDonor;

    printf("Following donor added successfully: \n");
    printf("+------------------+-----------------+-------------------------+-----------------+-------------------------+\n");
    printf("|      Name        |  Contact Number |         Address         |   Blood Group   |   Last Donation Date    |\n");
    printf("+------------------+-----------------+-------------------------+-----------------+-------------------------+\n");

    printf("| %-16s | %-15s | %-23s | %-15s | %-23s |\n", newDonor->name, newDonor->contactNumber, newDonor->address, newDonor->bloodGroup, newDonor->lastDonationDate);

    printf("+------------------+-----------------+-------------------------+-----------------+-------------------------+\n");
    printf("Press enter and 6 to save the addition in the file.\n");
}

void deleteDonorByPhoneNumber()
{
    if (head == NULL)
    {
        printf("No donors found.\n");
        return;
    }

    char contactNumber[MAX_CONTACT_LENGTH];
    printf("Enter the contact number of the donor to delete: ");
    scanf("%s", contactNumber);

    Donor *current = head;
    Donor *prev = NULL;

    while (current != NULL)
    {
        if (strcmp(current->contactNumber, contactNumber) == 0)
        {
            if (prev == NULL)
            {
                head = current->next;
            }
            else
            {
                prev->next = current->next;
            }

            printf("Following donor deleted successfully: \n");
            printf("+------------------+-----------------+-------------------------+-----------------+-------------------------+\n");
            printf("|      Name        |  Contact Number |         Address         |   Blood Group   |   Last Donation Date    |\n");
            printf("+------------------+-----------------+-------------------------+-----------------+-------------------------+\n");

            printf("| %-16s | %-15s | %-23s | %-15s | %-23s |\n", current->name, current->contactNumber, current->address, current->bloodGroup, current->lastDonationDate);

            printf("+------------------+-----------------+-------------------------+-----------------+-------------------------+\n");
            printf("Press enter and 6 to save the deletion in the file.\n");
            free(current);

            return;
        }

        prev = current;
        current = current->next;
    }

    printf("Donor with contact number %s not found.\n", contactNumber);
}

void editDonorByPhoneNumber()
{
    if (head == NULL)
    {
        printf("No donors found.\n");
        return;
    }

    char contactNumber[MAX_CONTACT_LENGTH];
    printf("Enter the contact number of the donor to edit: ");
    scanf("%s", contactNumber);

    Donor *current = head;
    int found = 0;

    while (current != NULL)
    {
        if (strcmp(current->contactNumber, contactNumber) == 0)
        {
            printf("Enter the new address: ");
            getchar();
            gets(current->address);
            printf("Enter the new last donation date (YYYY-MM-DD): ");
            scanf("%s", current->lastDonationDate);
            printf("Following donor updated successfully: \n");
            printf("+------------------+-----------------+-------------------------+-----------------+-------------------------+\n");
            printf("|      Name        |  Contact Number |         Address         |   Blood Group   |   Last Donation Date    |\n");
            printf("+------------------+-----------------+-------------------------+-----------------+-------------------------+\n");

            printf("| %-16s | %-15s | %-23s | %-15s | %-23s |\n", current->name, current->contactNumber, current->address, current->bloodGroup, current->lastDonationDate);

            printf("+------------------+-----------------+-------------------------+-----------------+-------------------------+\n");
            printf("Press enter and 6 to save the update in the file.\n");
            found = 1;
            break;
        }

        current = current->next;
    }

    if (!found)
    {
        printf("Donor with contact number %s not found.\n", contactNumber);
    }
}

void viewFilteredDonors()
{
    if (head == NULL)
    {
        printf("No donors found.\n");
        return;
    }

    char bloodGroup[MAX_BLOOD_GROUP_LENGTH];
    char address[MAX_ADDRESS_LENGTH];

    printf("Enter blood group: ");
    scanf("%s", bloodGroup);
    printf("Enter address: ");
    scanf("%s", address);

    Donor *current = head;
    int found = 0;

    printf("Matching donors:\n");
    printf("+------------------+-----------------+-------------------------+-----------------+-------------------------+\n");
    printf("|      Name        |  Contact Number |         Address         |   Blood Group   |   Last Donation Date    |\n");
    printf("+------------------+-----------------+-------------------------+-----------------+-------------------------+\n");

    while (current != NULL)
    {
        if (strcmp(current->bloodGroup, bloodGroup) == 0 &&
            strcmp(current->address, address) == 0 &&
            strcmp(current->lastDonationDate, "N/A") != 0)
        {
            time_t now = time(NULL);
            struct tm *current_time = localtime(&now);
            struct tm last_donation_time;
            int year, month, date;
            sscanf(current->lastDonationDate, "%d-%d-%d", &last_donation_time.tm_year, &last_donation_time.tm_mon, &last_donation_time.tm_mday);
            last_donation_time.tm_year -= 1900;
            last_donation_time.tm_mon -= 1;
            double diff_in_months = (current_time->tm_year - last_donation_time.tm_year) * 12 + (current_time->tm_mon - last_donation_time.tm_mon);

            if (diff_in_months >= 3)
            {
                printf("| %-16s | %-15s | %-23s | %-15s | %-23s |\n", current->name, current->contactNumber, current->address, current->bloodGroup, current->lastDonationDate);
                found = 1;
            }
        }

        current = current->next;
    }

    if (!found)
    {
        printf("| No matching donors found.                                                                                |\n");
    }

    printf("+------------------+-----------------+-------------------------+-----------------+-------------------------+\n");
}

void searchDonor()
{
    if (head == NULL)
    {
        printf("No donors found.\n");
        return;
    }

    char bloodGroup[MAX_BLOOD_GROUP_LENGTH];
    char address[MAX_ADDRESS_LENGTH];

    printf("Enter blood group: ");
    scanf("%s", bloodGroup);
    printf("Enter address: ");
    scanf("%s", address);

    Donor *current = head;
    int found = 0;

    printf("Matching donors:\n");
    printf("+------------------+-----------------+-------------------------+-----------------+-------------------------+\n");
    printf("|      Name        |  Contact Number |         Address         |   Blood Group   |   Last Donation Date    |\n");
    printf("+------------------+-----------------+-------------------------+-----------------+-------------------------+\n");

    while (current != NULL)
    {
        if (strcmp(current->bloodGroup, bloodGroup) == 0 &&
            strcmp(current->address, address) == 0 &&
            strcmp(current->lastDonationDate, "N/A") != 0)
        {
            printf("| %-16s | %-15s | %-23s | %-15s | %-23s |\n", current->name, current->contactNumber, current->address, current->bloodGroup, current->lastDonationDate);
            found = 1;
        }

        current = current->next;
    }

    if (!found)
    {
        printf("| No matching donors found.                                                                            |\n");
    }

    printf("+------------------+-----------------+-------------------------+-----------------+-------------------------+\n");
}

void viewAllDonors()
{
    if (head == NULL)
    {
        printf("No donors found.\n");
        return;
    }

    Donor *current = head;

    printf("All donors:\n");
    printf("+------------------+-----------------+-------------------------+-----------------+-------------------------+\n");
    printf("|      Name        |  Contact Number |         Address         |   Blood Group   |   Last Donation Date    |\n");
    printf("+------------------+-----------------+-------------------------+-----------------+-------------------------+\n");

    while (current != NULL)
    {
        printf("| %-16s | %-15s | %-23s | %-15s | %-23s |\n", current->name, current->contactNumber, current->address, current->bloodGroup, current->lastDonationDate);
        current = current->next;
    }

    printf("+------------------+-----------------+-------------------------+-----------------+-------------------------+\n");
}

void saveDonorsToFile()
{
    FILE *file = fopen("donors.txt", "w");

    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    Donor *current = head;

    while (current != NULL)
    {
        fprintf(file, "%s,%s,%s,%s,%s\n", current->name, current->contactNumber, current->address, current->bloodGroup, current->lastDonationDate);
        current = current->next;
    }

    fclose(file);
    printf("Donors data saved to file.\n");
}

void loadDonorsFromFile()
{
    FILE *file = fopen("donors.txt", "r");

    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    char line[256];

    while (fgets(line, sizeof(line), file))
    {
        Donor *newDonor = (Donor *)malloc(sizeof(Donor));

        sscanf(line, "%[^,],%[^,],%[^,],%[^,],%s\n", newDonor->name, newDonor->contactNumber, newDonor->address, newDonor->bloodGroup, newDonor->lastDonationDate);

        newDonor->next = head;
        head = newDonor;
    }

    fclose(file);
    printf("Donors data loaded from file.\n");
}

void showHelp()
{
    printf("============================================================================================================\n");
    printf("Blood Donor Management System Help\n");
    printf("============================================================================================================\n");
    printf("1. Add Donor: Allows you to add a new donor to the system.\n");
    printf("2. Delete Donor: Remove a donor from the system using their contact number.\n");
    printf("3. Filter Donor: Search for a donor by blood group and address.\n");
    printf("4. Edit Donor Information by Contact Number: Modify a donor's address and last donation date by their contact number.\n");
    printf("5. View All Donors: View a list of all donors in the system.\n");
    printf("6. Save Donors to File: Save the donor data to a file for future use.\n");
    printf("7. Help: Show how to use the application.\n");
    printf("8. About: Know more about the application.\n");
    printf("9. Exit: Close the application.\n");
    printf("============================================================================================================\n");
}

void showAbout()
{
    printf("============================================================================================================\n");
    printf("Blood Donor Management System - About\n");
    printf("============================================================================================================\n");
    printf("Blood Donor Management System is a simple program designed to help organizations\n");
    printf("manage information about blood donors. It allows you to add, delete, search, and\n");
    printf("update donor information for efficient management of blood donation records.\n");
    printf("\n");
    printf("Version: 1.0\n");
    printf("Developed by: Minhazul Abedin 221-15-4919, Abid Hasan 221-15-5022\n");
    printf("Mohima Sharmin 221-15-5855, Sumaiya Akter Ritu 221-15-5173\n");
    printf("Contact: abedin15-4919@gmail.com\n");
    printf("Acknowledgments: This software is developed as a course project of CSE135 Data Structure Lab\n");
    printf("under Daffodil International University. (C) All Rights Reserved.\n");
    printf("\n");
    printf("Thank you for using Blood Donor Management System!\n");
    printf("============================================================================================================\n");
}

void freeMemory()
{
    Donor *current = head;
    Donor *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
}

int main()
{
    int choice;

    loadDonorsFromFile();

    do
    {
        printf("============================================================================================================\n");
        printf("   Blood Donor Management System\n");
        printf("============================================================================================================\n");
        printf("1. Add Donor\n");
        printf("2. Delete Donor\n");
        printf("3. Filter Donor\n");
        printf("4. Edit Donor\n");
        printf("5. View All Donors\n");
        printf("6. Save Donors to File\n");
        printf("7. Help\n");
        printf("8. About\n");
        printf("9. Exit\n");
        printf("============================================================================================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("============================================================================================================\n");

        switch (choice)
        {
        case 1:
            addDonor();
            printf("\nPress Enter to continue...");
            getchar();
            getchar();
            clrscr();
            break;
        case 2:
            deleteDonorByPhoneNumber();
            printf("\nPress Enter to continue...");
            getchar();
            getchar();
            clrscr();
            break;
        case 3:
            printf("Do you want to filter donors those donated blood less than 3 months ago?\n1.Yes\t 2.No\n");
            int ch;
            printf("Enter Choice: ");
            scanf("%d", &ch);
            switch (ch)
            {
            case 1:
                viewFilteredDonors();
                break;
            case 2:
                searchDonor();
            default:
                break;
            }
            printf("\nPress Enter to continue...");
            getchar();
            getchar();
            clrscr();
            break;
        case 4:
            editDonorByPhoneNumber();
            printf("\nPress Enter to continue...");
            getchar();
            getchar();
            clrscr();
            break;
        case 5:
            viewAllDonors();
            printf("\nPress Enter to continue...");
            getchar();
            getchar();
            clrscr();
            break;
        case 6:
            saveDonorsToFile();
            printf("\nPress Enter to continue...");
            getchar();
            getchar();
            clrscr();
            break;
        case 7:
            showHelp();
            printf("\nPress Enter to continue...");
            getchar();
            getchar();
            clrscr();
            break;
        case 8:
            showAbout();
            printf("\nPress Enter to continue...");
            getchar();
            getchar();
            clrscr();
            break;
        case 9:
            printf("Exiting...\n");
            printf("============================================================================================================\n");
            clrscr();
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            printf("\nPress Enter to continue...");
            getchar();
            getchar();
            clrscr();
        }
    } while (choice != 9);

    freeMemory();

    return 0;
}
