#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 70

typedef struct {
    int id;
    char VehicleName[30];
    char name[30];
    char aadharid[13];
    char phoneNumber[11];
    char type[10];
    char password[10];
    int isavailable;
    float priceperhour;
} vehicle;

vehicle vehicles[MAX];
int count = 0;

void processdata();
void savedata();
void addVehicle();
void viewAvailability();
void rentVehicle();
void removeVehicle();
void returnVehicle();
void introduction();
void entertocontinue();

int main() {
    introduction();
    entertocontinue();
    int choice, again;
    int showMenu = 1;

    processdata(); 

    while (1) {

        if (showMenu) {
            printf("\n------ WELCOME TO RIDE & RENT ------\n");
            printf("1. Add Your Vehicle\n");
            printf("2. View Availability Of Vehicle\n");
            printf("3. Rent Vehicle\n");
            printf("4. Return Vehicle\n");
            printf("5. Remove Vehicle\n");
            printf("6. Exit\n");
            printf("------------------------------------\n");
        }

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addVehicle(); break;
            case 2: viewAvailability(); break;
            case 3: rentVehicle(); break;
            case 4: returnVehicle(); break;
            case 5: removeVehicle(); break;
            case 6: savedata(); exit(0);
            default: printf("Invalid choice! Try again.\n");
        }

        printf("\nDo you want to see the menu again?\n");
        printf("1. Yes\n2. No (Exit)\nEnter your choice: ");
        scanf("%d", &again);

        if (again == 1)
            showMenu = 1;
        else {
            savedata();
            printf("Exiting program...\n");
            exit(0);
        }
    }
}

void processdata() {
    FILE *fp = fopen("vehicleInformation.txt", "r");
    if (fp == NULL) return;

    count = 0;

    while (fscanf(fp,
                  "%d %29s %29s %12s %10s %9s %9s %d %f",
                  &vehicles[count].id,
                  vehicles[count].VehicleName,
                  vehicles[count].name,
                  vehicles[count].aadharid,
                  vehicles[count].phoneNumber,
                  vehicles[count].type,
                  vehicles[count].password,
                  &vehicles[count].isavailable,
                  &vehicles[count].priceperhour) == 9)
    {
        count++;
        if (count >= MAX) break;
    }

    fclose(fp);
}

// ----------------------------------------------
// SAVE DATA TO FILE
// ----------------------------------------------
void savedata() {
    FILE *fp = fopen("vehicleInformation.txt", "w");
    if (!fp) return;

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%d|%s|%s|%s|%s|%s|%s|%d|%.2f\n",
                vehicles[i].id,
                vehicles[i].VehicleName,
                vehicles[i].name,
                vehicles[i].aadharid,
                vehicles[i].phoneNumber,
                vehicles[i].type,
                vehicles[i].password,
                vehicles[i].isavailable,
                vehicles[i].priceperhour);
    }
    fclose(fp);
}
void introduction() {
    system("clear");   

    printf("\n\n");
    printf("=============================================\n");
    printf("          VEHICLE MANAGEMENT SYSTEM\n");
    printf("=============================================\n\n");

    printf("  Developed By : Akshat Mishra\n");
    printf("  Guided By    : Avishek Majumder\n");
    printf("  Batch        : 17\n");
    printf("  Sap Id       : 590022690\n");
    printf("\n\n");
     
}
void entertocontinue() {
    printf("\nPress ENTER for main menu");
    getchar();
}

// ----------------------------------------------
// ADD VEHICLE
// ----------------------------------------------
void addVehicle() {
    char tempAadhar[50], tempPhone[50] , category[9] ;
    int valid = 0, validPhone = 0, vehid;

    printf("Enter your vehicle company Name: ");
    scanf("%29s", vehicles[count].VehicleName);

    printf("Enter your name: ");
    scanf("%29s", vehicles[count].name);

    // Aadhar validation
    while (!valid) {
        printf("Enter your 12-digit Aadhar number: ");
        scanf("%12s", tempAadhar);

        if (strlen(tempAadhar) != 12) {
            printf("Error: Must be exactly 12 digits.\n");
            continue;
        }

        valid = 1;
        for (int i = 0; i < 12; i++) {
            if (!isdigit(tempAadhar[i])) {
                valid = 0;
                printf("Error: Only digits allowed.\n");
                break;
            }
        }
    }
    strcpy(vehicles[count].aadharid, tempAadhar);

    // Phone validation
    while (!validPhone) {
        printf("Enter your 10-digit phone number: ");
        scanf("%10s", tempPhone);

        if (strlen(tempPhone) != 10) {
            printf("Error: Must be exactly 10 digits.\n");
            continue;
        }

        validPhone = 1;
        for (int i = 0; i < 10; i++) {
            if (!isdigit(tempPhone[i])) {
                validPhone = 0;
                printf("Error: Only digits allowed.\n");
                break;
            }
        }
    }
    strcpy(vehicles[count].phoneNumber, tempPhone);

    while (1) {
    printf("Enter your Vehicle ID: ");
    scanf("%d", vehid);

    int exists = 0;
    for (int i = 0; i < count; i++) {
        if (vehid == vehicles[i].id) {
            exists = 1;
            printf("This ID already exists! Enter a new ID.\n");
            break;
        }
    }

    if (!exists) {
        vehicles[count].id = vehid;
        break;
    }
}

    while(1){
    printf("Enter type (scooty/car/bike): \n");
    scanf("%9s", category);
    if (strcmp (category,"car") == 0||
        strcmp (category,"bike") == 0||
        strcmp (category,"scooty")== 0){
            strcpy(vehicles[count].type, category);
            break;
        }
        else{
            printf(" INVALID! only vehicle allowed are scooty , bike , car ");
        }
    }

    printf("Enter price per hour: ");
    scanf("%f", &vehicles[count].priceperhour);

    vehicles[count].isavailable = 1;

    printf("Set your password: ");
    scanf("%9s", vehicles[count].password);

    printf("Vehicle added successfully!\n");

    count++;
    savedata();
}

// ----------------------------------------------
// VIEW AVAILABILITY
// ----------------------------------------------
void viewAvailability() {
    if (count == 0) {
        printf("No vehicles available.\n");
        return;
    }

    printf("\n------ AVAILABLE VEHICLES ------\n");

    for (int i = 0; i < count; i++) {
        printf("\n vehicle ID: %d | coustmer name : %s | Aadhar  number : %s | phone number : %s | Vehicle Type: %s",
               vehicles[i].id, vehicles[i].name,
               vehicles[i].aadharid,vehicles[i].phoneNumber, vehicles[i].type);

        if (vehicles[i].isavailable)
            printf(" | Status: Available\n");
        else
            printf(" | Status: Rented\n");

        printf("Price per hour: %.2f\n", vehicles[i].priceperhour);
        printf("-------------------------------\n");
    }
}

// ----------------------------------------------
// REMOVE VEHICLE
// ----------------------------------------------
void removeVehicle() {
    int  id,ch,found = 0;
    char phone[10];
    char password[10];

    printf("Enter vehicle ID to remove: ");
    scanf("%d", &id);

    printf("Enter password: ");
    scanf("%9s", password);

    for (int i = 0; i < count; i++) {
        if (vehicles[i].id == id ) {
            found = 1;

            if (strcmp(vehicles[i].password, password) == 0) {
                for (int j = i; j < count - 1; j++)
                    vehicles[j] = vehicles[j + 1];

                count--;
                savedata();
                printf("Vehicle removed successfully!\n");
                return;
            } else {
                printf("Incorrect password!\n");
                printf("reset paswword \n");
                printf("1.yes\n");
                printf("2.no\n");
                scanf("%d", &ch);
                switch(ch){
                    case 1: printf(" enter your registered mobile number");
                    scanf("%10s", phone);
                    if(strcmp(phone, vehicles[i].phoneNumber) == 0){
                        printf( "-------USER VERIFIED-------\n");
                        printf(" enter your new password\n");
                        scanf("%10s", vehicles[i].password);
                        printf(" PASSWORD UPDATED SUCESSFULLY\n");
                        savedata();
                    }
                        break;

                    case 2: 
                     exit(0);         ;
                    break;

                    default:
                    printf("invalid input");
                }
            }
        }
    }

    if (!found) printf("Vehicle ID not found.\n");
}

// ----------------------------------------------
// RENT VEHICLE
// ----------------------------------------------
void rentVehicle() {
    int  age, id;
    char rentAadhar[20];
    float hours, total, paid;
    int valid = 0;

    printf("Enter your age: ");
    scanf("%d", &age);
    if (age < 18) {
        printf("You are not eligible to rent.\n");
        return;
    }

    // Aadhar validation
    while (!valid) {
        printf("Enter your 12-digit Aadhar: ");
        scanf("%12s", rentAadhar);

        if (strlen(rentAadhar) != 12) {
            printf("Must be 12 digits.\n");
            continue;
        }

        valid = 1;
        for (int i = 0; i < 12; i++) {
            if (!isdigit(rentAadhar[i])) {
                valid = 0;
                printf("Only digits allowed.\n");
                break;
            }
        }
    }

    printf("Enter vehicle ID: ");
    scanf("%d", &id);

    printf("Enter hours to rent: ");
    scanf("%f", &hours);

    for (int i = 0; i < count; i++) {
        if (vehicles[i].id == id && vehicles[i].isavailable == 1) {

            vehicles[i].isavailable = 0;
            total = hours * vehicles[i].priceperhour;

            printf("Total Bill: %.2f\n", total);
            printf("Enter amount paid: ");
            scanf("%f", &paid);

            if (paid >= total) {
                printf("Change: %.2f\n", paid - total);
                printf("Vehicle rented successfully!\n");
            } else {
                printf("Payment insufficient!\n");
                vehicles[i].isavailable = 1;
            }

            savedata();
            return;
        }
    }

    printf("Vehicle not available or not found.\n");
}

// ----------------------------------------------
// RETURN VEHICLE
// ----------------------------------------------
void returnVehicle() {
    int id;
    printf("Enter vehicle ID to return: ");
    scanf("%d", id);

    for (int i = 0; i < count; i++) {
        if (vehicles[i].id == id && vehicles[i].isavailable == 0) {
            vehicles[i].isavailable = 1;
            savedata();
            printf("Vehicle returned successfully!\n");
            return;
        }
    }

    printf("Invalid vehicle ID.\n");
}
