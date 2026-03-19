#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX 70
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 70

// structure to store vehicle information
typedef struct {
    int id;
    char VehicleName[30];
    char name[30];
    char phonenumber[11];
    char aadharid[13];
    char type[10];
    char password[10];
    int isavailable;
    float priceperhour;
} vehicle;

vehicle vehicles[MAX];
int count = 0;

// declarations
void processdata(void);
void savedata(void);
void addVehicle(void);
void viewAvailability(void);
void rentVehicle(void);
void removeVehicle(void);
void returnVehicle(void);

int main(void) {
    int choice;
    int showMenu = 1;
    int again;

    processdata();

    while (1) {
        if (showMenu == 1) {
            printf("\n------ WELCOME TO RIDE & RENT ------\n");
            printf("------ Vehicle Renting System ------\n");
            printf("1. Add Your Vehicle\n");
            printf("2. View Availability Of Vehicle\n");
            printf("3. Rent Vehicle\n");
            printf("4. Return Vehicle\n");
            printf("5. Remove Vehicle\n");
            printf("6. Exit\n");
            printf("-----------------------------------------------\n");
        }

        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            int c; while ((c = getchar()) != '\n' && c != EOF);
            printf("Invalid input. Try again.\n");
            continue;
        }

        switch (choice) {
            case 1: addVehicle(); break;
            case 2: viewAvailability(); break;
            case 3: rentVehicle(); break;
            case 4: returnVehicle(); break;
            case 5: removeVehicle(); break;
            case 6: savedata(); printf("Exiting program...\n"); return 0;
            default: printf("Invalid choice! Try again.\n");
        }

        // Ask user if they want to see menu again
        printf("\nDo you want to see the menu again?\n");
        printf("1. Yes\n");
        printf("2. No (Exit)\n");
        printf("Enter your choice: ");
        if (scanf("%d", &again) != 1) {
            int c; while ((c = getchar()) != '\n' && c != EOF);
            printf("Invalid input. Showing menu.\n");
            showMenu = 1;
            continue;
        }

        if (again == 1) {
            showMenu = 1;
        } else {
            savedata();
            printf("Exiting program...\n");
            return 0;
        }
    }

    return 0;
}

// process data from file
void processdata(void) {
    FILE *fp = fopen("vehicleInformation.txt", "r");
    if (fp == NULL) return;

    char line[512];
    while (fgets(line, sizeof(line), fp) != NULL) {
        // tokenize by whitespace
        char *tokens[12];
        int t = 0;
        char *p = strtok(line, " \t\r\n");
        while (p != NULL && t < 12) {
            tokens[t++] = p;
            p = strtok(NULL, " \t\r\n");
        }

        if (t < 9) {
            // skip malformed lines
            continue;
        }

        vehicles[count].id = atoi(tokens[0]);
        strncpy(vehicles[count].VehicleName, tokens[1], sizeof(vehicles[count].VehicleName)-1);
        vehicles[count].VehicleName[sizeof(vehicles[count].VehicleName)-1] = '\0';
        strncpy(vehicles[count].name, tokens[2], sizeof(vehicles[count].name)-1);
        vehicles[count].name[sizeof(vehicles[count].name)-1] = '\0';
        strncpy(vehicles[count].phonenumber, tokens[3], sizeof(vehicles[count].phonenumber)-1);
        vehicles[count].phonenumber[sizeof(vehicles[count].phonenumber)-1] = '\0';
        strncpy(vehicles[count].aadharid, tokens[4], sizeof(vehicles[count].aadharid)-1);
        vehicles[count].aadharid[sizeof(vehicles[count].aadharid)-1] = '\0';
        strncpy(vehicles[count].type, tokens[5], sizeof(vehicles[count].type)-1);
        vehicles[count].type[sizeof(vehicles[count].type)-1] = '\0';
        strncpy(vehicles[count].password, tokens[6], sizeof(vehicles[count].password)-1);
        vehicles[count].password[sizeof(vehicles[count].password)-1] = '\0';
        vehicles[count].isavailable = atoi(tokens[7]);
        vehicles[count].priceperhour = (float)atof(tokens[8]);

        count++;
        if (count >= MAX) break;
    }

    fclose(fp);
}

// saving data to file
void savedata(void) {
    FILE *fp = fopen("vehicleInformation.txt", "w");
    if (fp == NULL) return;

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%d %s %s %s %s %s %s %d %.2f\n",
                vehicles[i].id,
                vehicles[i].VehicleName,
                vehicles[i].name,
                vehicles[i].phonenumber,
                vehicles[i].aadharid,
                vehicles[i].type,
                vehicles[i].password,
                vehicles[i].isavailable,
                vehicles[i].priceperhour);
    }

    fclose(fp);
}

// add a vehicle
void addVehicle(void) {
    if (count >= MAX) {
        printf("Cannot add more vehicles. Storage full.\n");
        return;
    }

    printf("Enter your vehicle company Name: ");
    scanf(" %29s", vehicles[count].VehicleName);
    printf("Enter your name: ");
    scanf(" %29s", vehicles[count].name);

    while (1) {
        printf("Enter your 10-digit phone number: ");
        if (scanf(" %10s", vehicles[count].phonenumber) != 1) {
            int c; while ((c = getchar()) != '\n' && c != EOF);
            printf("Input error. Please try again.\n");
            continue;
        }

        if (strlen(vehicles[count].phonenumber) != 10) {
            printf("phone number must be exactly 10 digits long. Please try again.\n");
            continue;
        }

        int valid = 1;
        for (int i = 0; i < 10; i++) {
            if (!isdigit((unsigned char)vehicles[count].phonenumber[i])) {
                valid = 0;
                break;
            }
        }

        if (valid) break;
        printf("phone number must contain only digits. Please try again.\n");
    }
     while (1) {
        printf("Enter your 12-digit aadhar number: ");
        if (scanf(" %12s", vehicles[count].aadharid) != 1) {
            int c; while ((c = getchar()) != '\n' && c != EOF);
            printf("Input error. Please try again.\n");
            continue;
        }

        if (strlen(vehicles[count].aadharid) != 12) {
            printf("Aadhar number must be exactly 12 digits long. Please try again.\n");
            continue;
        }

        int valid = 1;
        for (int i = 0; i < 12; i++) {
            if (!isdigit((unsigned char)vehicles[count].aadharid[i])) {
                valid = 0;
                break;
            }
        }

        if (valid) break;
        printf("aadhar number must contain only digits. Please try again.\n");
    }
    printf("Enter your Vehicle ID: ");
    scanf("%d", &vehicles[count].id);
    printf("Enter type (scooty/car/bike): ");
    scanf(" %9s", vehicles[count].type);
    printf("Enter rent price per hour: ");
    scanf("%f", &vehicles[count].priceperhour);

    vehicles[count].isavailable = 1;

    printf("Set your password: ");
    scanf(" %9s", vehicles[count].password);

    printf("----- Vehicle added successfully -----\n");

    count++;
    savedata();
}

// view availability
void viewAvailability(void) {
    if (count == 0) {
        printf("No vehicles available.\n");
        return;
    }

    printf("\n------ AVAILABLE VEHICLES ------\n");

    for (int i = 0; i < count; i++) {
        printf("\nVehicle ID: %d |VehicleName: %s |Customer name: %s |Phone number: %s |Aadhar Number: %s |Type: %s\n",
               vehicles[i].id,
               vehicles[i].VehicleName,
               vehicles[i].name,
               vehicles[i].phonenumber,
               vehicles[i].aadharid,
               vehicles[i].type);

        printf("Status: %s\n", vehicles[i].isavailable ? "Available" : "Rented");
        printf("Price per hour: %.2f\n", vehicles[i].priceperhour);
        printf("-------------------------------\n");
    }
}

// remove vehicle
void removeVehicle(void) {
    int id;
    char password[16];
    int found = 0;

    printf("ID of vehicle you want to remove : ");
    if (scanf("%d", &id) != 1) {
        int c; while ((c = getchar()) != '\n' && c != EOF);
        printf("Invalid input.\n");
        return;
    }

    printf("Enter your password: ");
    scanf(" %15s", password);

    for (int i = 0; i < count; i++) {
        if (vehicles[i].id == id) {
            found = 1;
            if (strcmp(vehicles[i].password, password) == 0) {
                for (int j = i; j < count - 1; j++) {
                    vehicles[j] = vehicles[j + 1];
                }
                count--;
                savedata();
                printf("---- Vehicle removed successfully -----\n");
                return;
            } else {
                printf("incorrect password!\n");
                return;
            }
        }
    }

    if (!found) {
        printf("------Vehicle ID not found -----\n");
    }
}

// rent a vehicle
void rentVehicle(void) {
    int id;
    int age;
    int renteraadhar;
    float time;
    float totalAmount;

    printf("Enter your age: ");
    if (scanf("%d", &age) != 1) return;
    if (age < 18) {
        printf("you are not eligible to rent a vehicle\n");
        return;
    }

    printf("Enter your aadhar id number: ");
    scanf("%d", &renteraadhar);
    printf("Enter vehicle id to rent: ");
    scanf("%d", &id);
    printf("Enter for how many hours you rent a vehicle: ");
    scanf("%f", &time);

    for (int i = 0; i < count; i++) {
        if (vehicles[i].id == id && vehicles[i].isavailable == 1) {
            vehicles[i].isavailable = 0;
            totalAmount = time * vehicles[i].priceperhour;

            printf("Total rent: %.2f\n", totalAmount);
            printf("Please proceed with the payment.\n");

            float paidAmount;
            printf("Enter payment amount: ");
            scanf("%f", &paidAmount);

            if (paidAmount >= totalAmount) {
                float change = paidAmount - totalAmount;
                printf("Payment successful! Change to return: %.2f\n", change);
            } else {
                printf("Insufficient payment. Rental failed.\n");
                vehicles[i].isavailable = 1; // revert
            }

            savedata();
            printf("-----Vehicle rented successfully-----\n");
            return;
        }
    }

    printf("----- Vehicle not available or not found-----\n");
}

// return vehicle
void returnVehicle(void) {
    int id;
    printf("Enter vehicle id to return: ");
    if (scanf("%d", &id) != 1) return;

    for (int i = 0; i < count; i++) {
        if (vehicles[i].id == id && vehicles[i].isavailable == 0) {
            vehicles[i].isavailable = 1;
            savedata();
            printf("-----Vehicle returned successfully-----\n");
            return;
        }
    }

    printf("-----Invalid vehicle id-----\n");
}