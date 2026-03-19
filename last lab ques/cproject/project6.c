#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX 70

typedef struct {
    int id;
    char VehicleName[30];
    char name[30];
    long long aadharid;
    long long phoneNumber;
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
                  "%d %29s %29s %lld %lld %9s %9s %d %f",
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

// SAVE DATA TO FILE

void savedata() {
    FILE *fp = fopen("vehicleInformation.txt", "w");
    if (!fp) return;

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%d|%s|%s|%lld|%lld|%s|%s|%d|%.2f\n",
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
    printf("             RIDE & RENT\n"                     );
    printf("=============================================\n\n");

    printf("  Submitted by : Deepanshi Shukla\n");
    printf("  Submitted to : Pankaj Badoni\n");
    printf("  Batch        : 10\n");
    printf("  Sap Id       : 590021964\n");
    printf("\n\n");
     
}
void entertocontinue() {
    printf("\nPress ENTER for main menu");
    getchar();
}

// ADD VEHICLE

void addVehicle() {
    long long aadhar ,boolvalid=false;
    long long phone ,validPhone = false;
 char category[9];
 int vehid;

    printf("Enter your vehicle company Name: ");
    scanf("%29s", vehicles[count].VehicleName);

    printf("Enter your name: ");
    scanf("%29s", vehicles[count].name);
      
        while (!boolvalid) {
        printf("Enter your 12-digit Aadhar number: ");
        scanf("%lld", &aadhar);

        int digitcount = 0;
        long long temp = aadhar;
        while (temp > 0) {
            temp /= 10;
            digitcount++;
        }

        if (digitcount == 12) {
            boolvalid = true;
            vehicles[count].aadharid=aadhar;
            printf("Aadhar number accepted: %lld\n", aadhar);
        } else {
            printf("Invalid! Aadhaar number must be exactly 12 digits.\n");
        }
    }

    while (!validPhone) {
        printf("Enter your 10-digit Phone number: ");
        scanf("%lld", & phone);

        int digitcount = 0;
        long long temp = phone;
        while (temp > 0) {
            temp /= 10;
            digitcount++;
        }

        if (digitcount == 10) {
            validPhone = true;
            vehicles[count].phoneNumber=phone;
            printf("Phone number accepted: %lld\n", phone);
        } else {
            printf("Invalid! Phone number must be exactly 10 digits.\n");
        }
    }

    while (1) {
    printf("Enter your Vehicle ID: ");
    scanf("%d", &vehid);

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

// VIEW AVAILABILITY

void viewAvailability() {
    if (count == 0) {
        printf("No vehicles available.\n");
        return;
    }

    printf("\n------ AVAILABLE VEHICLES ------\n");

    for (int i = 0; i < count; i++) {
        printf("\n vehicle ID: %d | coustmer name : %s | Aadhar  number : %lld | phone number : %lld | Vehicle Type: %s",
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


// REMOVE VEHICLE

void removeVehicle() {
    int  id,ch,found = 0;
    long long phone; 
    bool valid=false;
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
                    case 1:
                    while(!valid){
                    printf(" enter your registered mobile number: \n");
                    scanf("%lld", phone);
                    for(i=0;i < count;i++){
                    if(vehicles[i].phoneNumber==phone){
                        printf( "-------USER VERIFIED-------\n");
                        printf(" enter your new password\n");
                        scanf("%10s", vehicles[i].password);
                        printf(" PASSWORD UPDATED SUCESSFULLY\n");
                        savedata();
                    }
                    else{
                        printf("Invalid Phone number, try again \n");
                    }
                }
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


// RENT VEHICLE

void rentVehicle() {
    int  age, id;
    long long rentAadhar;
    long long rentPhone;
    float hours, total, paid;
    bool valid = false,validPhone=false;

    printf("Enter your age: ");
    scanf("%d", &age);
    if (age < 18) {
        printf("You are not eligible to rent.\n");
        return;
    }

       while (!valid) {
        printf("Enter your 12-digit Aadhar number: ");
        scanf("%lld", & rentAadhar);

        int digitcount = 0;
        long long temp = rentAadhar;
        while (temp > 0) {
            temp /= 10;
            digitcount++;
        }

        if (digitcount == 12) {
            valid = true;
            printf("Aadhar number accepted: %lld\n", rentAadhar);
        } else {
            printf("Invalid! Aadhaar number must be exactly 12 digits.\n");
        }
    }

     while (!validPhone) {
        printf("Enter your 10-digit Phone number: ");
        scanf("%lld", & rentPhone);

        int digitcount = 0;
        long long temp = rentPhone;
        while (temp > 0) {
            temp /= 10;
            digitcount++;
        }

        if (digitcount == 10) {
            validPhone = true;
            printf("Phone number accepted: %lld\n", rentPhone);
        } else {
            printf("Invalid! Phone number must be exactly 10 digits.\n");
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

// RETURN VEHICLE

void returnVehicle() {
    int id;
    printf("Enter vehicle ID to return: ");
    scanf("%d", &id);

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
