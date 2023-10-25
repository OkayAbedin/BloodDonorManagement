#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
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
void splashScreen()
{
printf("\n\n\n");
printf("\t\t\t\t########   #######  ##    ## ########  #######\n");  
printf("\t\t\t\t##     ## ##     ## ##   ##     ##    ##     ##\n"); 
printf("\t\t\t\t##     ## ##     ## ##  ##      ##    ##     ##\n"); 
printf("\t\t\t\t########  ##     ## #####       ##    ##     ##\n"); 
printf("\t\t\t\t##   ##   ##     ## ##  ##      ##    ##     ##\n"); 
printf("\t\t\t\t##    ##  ##     ## ##   ##     ##    ##     ##\n"); 
printf("\t\t\t\t##     ##  #######  ##    ##    ##     #######\n");  
printf("\n");
sleep(1);
printf("\t\t\t\t    ########     ###    ########    ###   \n"); 
printf("\t\t\t\t    ##     ##   ## ##      ##      ## ##  \n"); 
printf("\t\t\t\t    ##     ##  ##   ##     ##     ##   ## \n"); 
printf("\t\t\t\t    ##     ## ##     ##    ##    ##     ##\n"); 
printf("\t\t\t\t    ##     ## #########    ##    #########\n"); 
printf("\t\t\t\t    ##     ## ##     ##    ##    ##     ##\n"); 
printf("\t\t\t\t    ########  ##     ##    ##    ##     ##\n"); 
sleep(1);
printf("\n");
printf("\t\t\t\t               #            #           \n");
printf("\t\t\t\t              ###          ###          \n");
printf("\t\t\t\t             #####        #####         \n");
printf("\t\t\t\t            #######      #######        \n");
printf("\t\t\t\t           #########    #########       \n");
printf("\t\t\t\t          ###########  ###########      \n");
printf("\t\t\t\t           #########    #########       \n");
printf("\t\t\t\t              ###          ###          \n");
sleep(2);
clrscr();
}

void bloodDonorManagementSystem();
void bloodBankManagementSystem();
void showHelp()
{
    printf("============================================================================================================\n");
    printf("   Blood Donor Management System Help\n");
    printf("============================================================================================================\n");
    printf("1. Add Donor: Allows you to add a new donor to the system.\n");
    printf("2. Delete Donor: Remove a donor from the system using their contact number.\n");
    printf("3. Filter Donor: Search for a donor by blood group and address.\n");
    printf("4. Edit Donor Information by Contact Number: Modify a donor's address and last donation date by their contact number.\n");
    printf("5. View All Donors: View a list of all donors in the system.\n");
    printf("6. Save Donors to File: Save the donor data to a file for future use.\n");
    printf("0. Exit to Main Menu: Return to the main menu.\n");
    printf("============================================================================================================\n");
    printf("============================================================================================================\n");
    printf("   Blood Bank Management System Help\n");
    printf("============================================================================================================\n");
    printf("1. Add Blood Stock: Allows you to add a new blood stock to the system.\n");
    printf("2. Serve Blood to Customer: Allows you to serve blood to customer.\n");
    printf("3. View Blood Stock: View the quantity of bloods availabe.\n");
    printf("4. View Customer List: View all the customers details those have been served\n");
    printf("5. View All Donors: View a list of all donors in the system.\n");
    printf("6. Save Data to File: Save the stock and customer data to a file for future use.\n");
    printf("0. Exit to Main Menu: Return to the main menu.\n");
    printf("============================================================================================================\n");
}
void showAbout()
{
    printf("============================================================================================================\n");
    printf("   Blood Donor and Blood Bank Management System - About\n");
    printf("============================================================================================================\n");
    printf("Blood Donor and Blood Bank Management System is a sophisticated software solution designed to facilitate\n");
    printf("the efficient management of blood donor information and blood bank resources. It empowers organizations\n");
    printf("to streamline their blood donation operations, ensuring the availability of critical resources and data\n");
    printf("for life-saving activities\n");
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

int main()
{
    splashScreen();
    int choice1;
    do
    {
        printf("============================================================================================================\n");
        printf("   Blood Donor and Blood Bank Management System\n");
        printf("============================================================================================================\n");
        printf("1. Blood Donor Management System\n");
        printf("2. Blood Bank Management System\n");
        printf("3. Help\n");
        printf("4. About\n");
        printf("0. Exit\n");
        printf("============================================================================================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice1);
        printf("============================================================================================================\n");
        switch (choice1)
        {
        case 1:
            clrscr();
            bloodDonorManagementSystem();
            break;
        case 2:
            clrscr();
            bloodBankManagementSystem();
            break;
        case 3:
            clrscr();
            showHelp();
            
            break;
        case 4:
            clrscr();
            showAbout();
            break;
        case 0:
            clrscr();
            printf("Exiting...\n");
            printf("============================================================================================================\n");
            break;
        default:
            clrscr();
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice1 != 0);
}

typedef struct Donor
{
    char name[50];
    char contactNumber[100];
    char address[150];
    char bloodGroup[5];
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

    char contactNumber[100];
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

    char contactNumber[11];
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

    char bloodGroup[5];
    char address[150];

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

    char bloodGroup[5];
    char address[150];

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
    //printf("Donors data loaded from file.\n");
}
void freeMemory1()
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
void bloodDonorManagementSystem()
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
        printf("0. Exit to Main Menu\n");
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
        case 0:
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
    } while (choice != 0);

    freeMemory1();
}

struct BloodBank
{
    char bloodGroup[4];
    int stock;
    struct BloodBank *next;
};
struct Customer
{
    char name[50];
    char contactNumber[15];
    char address[100];
    char bloodGroup[4];
    int bags;
    char date[20];
    struct Customer *next;
};
struct BloodBank *readBloodStock()
{
    struct BloodBank *head = NULL;
    struct BloodBank *current = NULL;
    FILE *file = fopen("blood_stock.txt", "r");
    if (file != NULL)
    {
        char line[100];
        while (fgets(line, sizeof(line), file))
        {
            struct BloodBank *node = (struct BloodBank *)malloc(sizeof(struct BloodBank));
            sscanf(line, "%s %d", node->bloodGroup, &(node->stock));
            node->next = NULL;
            if (head == NULL)
            {
                head = node;
                current = node;
            }
            else
            {
                current->next = node;
                current = current->next;
            }
        }
        fclose(file);
    }
    return head;
}
void writeBloodStock(struct BloodBank *head)
{
    FILE *file = fopen("blood_stock.txt", "w");
    if (file != NULL)
    {
        struct BloodBank *current = head;
        while (current != NULL)
        {
            fprintf(file, "%s %d\n", current->bloodGroup, current->stock);
            current = current->next;
        }
        fclose(file);
    }
}
void addBloodStock(struct BloodBank **head)
{
    char bloodGroup[4];
    int stock;
    printf("Enter blood group: ");
    scanf("%s", bloodGroup);
    printf("Enter stock size: ");
    scanf("%d", &stock);

    struct BloodBank *current = *head;
    while (current != NULL)
    {
        if (strcmp(current->bloodGroup, bloodGroup) == 0)
        {
            current->stock += stock;
            printf("Blood group stock updated successfully.\n");
            return;
        }
        current = current->next;
    }

    struct BloodBank *node = (struct BloodBank *)malloc(sizeof(struct BloodBank));
    strcpy(node->bloodGroup, bloodGroup);
    node->stock = stock;
    node->next = *head;
    *head = node;
    printf("Blood group stock added successfully.\n");
}
void serveBlood(struct BloodBank **head, struct Customer **customerHead)
{
    char name[50];
    char contactNumber[15];
    char address[100];
    char bloodGroup[4];
    int bags;
    char date[20];
    printf("Enter customer name: ");
    scanf(" %49[^\n]", name);
    printf("Enter contact number: ");
    scanf("%s", contactNumber);
    printf("Enter address: ");
    scanf(" %99[^\n]", address);
    printf("Enter required blood group: ");
    scanf("%s", bloodGroup);
    printf("Enter required bags of blood: ");
    scanf("%d", &bags);
    printf("Enter date: ");
    scanf("%s", date);

    struct BloodBank *current = *head;
    while (current != NULL)
    {
        if (strcmp(current->bloodGroup, bloodGroup) == 0)
        {
            if (current->stock >= bags)
            {
                current->stock -= bags;

                struct Customer *node = (struct Customer *)malloc(sizeof(struct Customer));
                strcpy(node->name, name);
                strcpy(node->contactNumber, contactNumber);
                strcpy(node->address, address);
                strcpy(node->bloodGroup, bloodGroup);
                node->bags = bags;
                strcpy(node->date, date);
                node->next = *customerHead;
                *customerHead = node;

                printf("Blood served successfully.\n");
                return;
            }
            else
            {
                printf("Insufficient stock for the required blood group.\n");
                return;
            }
        }
        current = current->next;
    }

    printf("Blood group not found in stock.\n");
}
void viewBloodStock(struct BloodBank *head)
{
    printf("\nBlood Stock\n");
    printf("+-------------+-------+\n");
    printf("| Blood Group | Stock |\n");
    printf("+-------------+-------+\n");
    struct BloodBank *current = head;
    while (current != NULL)
    {
        printf("| %-11s | %-5d |\n", current->bloodGroup, current->stock);
        current = current->next;
    }
    printf("+-------------+-------+\n");
}
void displayCustomerList(struct Customer *customerHead)
{
    printf("\nCustomer List\n");
    printf("+----------------------+----------------+-----------------------+-----------------+--------+--------------+\n");
    printf("|        Name          | Contact Number |        Address        |   Blood Group   |  Bags  |     Date     |\n");
    printf("+----------------------+----------------+-----------------------+-----------------+--------+--------------+\n");
    struct Customer *current = customerHead;
    while (current != NULL)
    {
        printf("| %-20s | %-14s | %-21s | %-15s | %-6d | %-12s |\n", current->name, current->contactNumber, current->address, current->bloodGroup, current->bags, current->date);
        current = current->next;
    }
    printf("+----------------------+----------------+-----------------------+-----------------+--------+--------------+\n");
}
void saveData(struct BloodBank *bloodHead, struct Customer *customerHead)
{
    writeBloodStock(bloodHead);
    FILE *file = fopen("customer_list.txt", "w");
    if (file != NULL)
    {
        struct Customer *current = customerHead;
        while (current != NULL)
        {
            fprintf(file, "%s,%s,%s,%s,%d,%s\n", current->name, current->contactNumber, current->address, current->bloodGroup, current->bags, current->date);
            current = current->next;
        }
        fclose(file);
        printf("Data saved successfully.\n");
    }
}
void freeMemory2(struct BloodBank *bloodHead, struct Customer *customerHead)
{
    // Free memory for blood stock
    struct BloodBank *currentBlood = bloodHead;
    while (currentBlood != NULL)
    {
        struct BloodBank *tempBlood = currentBlood;
        currentBlood = currentBlood->next;
        free(tempBlood);
    }

    // Free memory for customer list
    struct Customer *currentCustomer = customerHead;
    while (currentCustomer != NULL)
    {
        struct Customer *tempCustomer = currentCustomer;
        currentCustomer = currentCustomer->next;
        free(tempCustomer);
    }
}
struct Customer *readCustomerList()
{
    struct Customer *head = NULL;
    struct Customer *current = NULL;
    FILE *file = fopen("customer_list.txt", "r");
    if (file != NULL)
    {
        char line[200];
        while (fgets(line, sizeof(line), file))
        {
            struct Customer *node = (struct Customer *)malloc(sizeof(struct Customer));
            sscanf(line, "%[^,],%[^,],%[^,],%[^,],%d,%s", node->name, node->contactNumber, node->address, node->bloodGroup, &(node->bags), node->date);
            node->next = NULL;
            if (head == NULL)
            {
                head = node;
                current = node;
            }
            else
            {
                current->next = node;
                current = current->next;
            }
        }
        fclose(file);
    }
    return head;
}
void bloodBankManagementSystem()
{
    struct BloodBank *bloodHead = readBloodStock();
    struct Customer *customerHead = readCustomerList();
    int choice;

    // Admin login
    char password[20];
    printf("Enter admin password: ");
    scanf("%s", password);
    if (strcmp(password, "admin123") != 0)
    {
        printf("Invalid password. Exiting...\n");
        freeMemory2(bloodHead, customerHead);
        return;
    }
    clrscr();
    do
    {
        printf("============================================================================================================\n");
        printf("   Blood Bank Management System\n");
        printf("============================================================================================================\n");
        printf("1. Add Blood Stock\n");
        printf("2. Serve Blood to Customer\n");
        printf("3. View Blood Stock\n");
        printf("4. View Customer List\n");
        printf("5. Save Data to File\n");
        printf("0. Exit to Main Menu\n");
        printf("============================================================================================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("============================================================================================================\n");
        switch (choice)
        {
        case 1:
            addBloodStock(&bloodHead);
            printf("\nPress Enter to continue...");
            getchar();
            getchar();
            clrscr();
            break;
        case 2:
            serveBlood(&bloodHead, &customerHead);
            printf("\nPress Enter to continue...");
            getchar();
            getchar();
            clrscr();
            break;
        case 3:
            viewBloodStock(bloodHead);
            printf("\nPress Enter to continue...");
            getchar();
            getchar();
            clrscr();
            break;
        case 4:
            displayCustomerList(customerHead);
            printf("\nPress Enter to continue...");
            getchar();
            getchar();
            clrscr();
            break;
        case 5:
            saveData(bloodHead, customerHead);
            printf("\nPress Enter to continue...");
            getchar();
            getchar();
            clrscr();
            break;
        case 0:
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
            break;
        }
    } while (choice != 0);

    freeMemory2(bloodHead, customerHead);
}