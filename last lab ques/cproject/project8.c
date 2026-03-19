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
              " %d| %29[^|]| %29[^|]|%lld|%lld| %9[^|]| %9[^|]|%d|%f",
              vehicles[count].id,
              vehicles[count].VehicleName,
              vehicles[count].name,
              &vehicles[count].aadharid,
              &vehicles[count].phoneNumber,
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
    getchar();
}

// ADD VEHICLE

void addVehicle() {
    long long aadhar;
    long long phone ,validPhone = false;
  char category[10], name[30], input[100], vehid[10];
  float price;

    printf("Enter your vehicle company Name: ");
    scanf("%29s", vehicles[count].VehicleName);

    while(1){
    printf("Enter your name: ");
    scanf("%29s", name);

    int valid =1;
    for (int i = 0; i < strlen(name); i++) {
            if (!isalpha(name[i])) {
                valid = 0;
                break;
            }
        }

        if (valid) {
            strcpy(vehicles[count].name, name); 
            break;
        } else {
            printf(" Invalid! Name must contain only alphabets.\n Please try again.\n");
        }
    }
        while (1) {
        printf("Enter your 12-digit Aadhar number: ");
        scanf("%99s", input);

        int valid = 1;
        for (int i = 0; i < strlen(input); i++) {
            if (!isdigit(input[i])) {
                valid = 0;
                break;
            }
        }
        if (valid && strlen(input) == 12) {
            aadhar = atoll(input);
            vehicles[count].aadharid = aadhar;
            printf("✅ Aadhaar number accepted: %lld\n", aadhar);
            break;
        } else {
            printf("Invalid! Aadhaar must be exactly 12 digits (numbers only).\n");
        }
    }
    while (1) {
        printf("Enter your 10-digit Phone number: ");
        scanf("%99s", input);

        int valid = 1;
        for (int i = 0; i < strlen(input); i++) {
            if (!isdigit(input[i])) {
                valid = 0;
                break;
            }
        }
         if (valid && strlen(input) == 10) {
            phone = atoll(input);
            vehicles[count].phoneNumber = phone;
            printf(" Phone number accepted: %lld\n", phone);
            break;
        } else {
            printf(" Invalid! Phone must be exactly 10 digits (numbers only).\n");
        }
    }
        while (1) {
    printf("Enter your Vehicle ID : ");
     int status = scanf("%d", vehicles[count].id);

       if (status == 1) {
        printf("Valid integer: %d\n", vehicles[count].id);
    } else {
        printf("Invalid input! Only integers are allowed.\n");
        while (getchar() != '\n'); 
            continue;
    }


    int exists = 0;
    for (int i = 0; i < count; i++) {
        if (vehicles[count].id == vehicles[i].id){
            exists = 1;
            printf("❌ This Vehicle ID already exists! Try another.\n");
            break;
        }
    }

    if (!exists) {
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

// RENT VEHICLE

void rentVehicle() {
    int  age; 
    int id;
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
        scanf("%lld", &rentPhone);

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
while(1){
    printf("Enter vehicle ID: ");
   int status = scanf("%d", id);

   if (status == 1) {
            printf("Valid integer: %d\n", id);
        } else {
            printf("Invalid input! Only integers are allowed.\n");
            while (getchar() != '\n');
            continue;
        }

    int exists = 0;
        for (int i = 0; i < count; i++) {
            if (vehicles[i].id == id) {
                exists = 1;
                break;
            }
        }

        if (exists) {
            break;
        } else {
            printf("Vehicle ID '%d' not found in the system. Please try again.\n", id);
        }
    }

    printf("Enter hours to rent: ");
    scanf("%f", &hours);

    for (int i = 0; i < count; i++) {
        if((vehicles[i].id == id) && vehicles[i].isavailable == 1) {

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
    int vehicle_index = -1;

    while (vehicle_index == -1) {
        printf("Enter vehicle ID to return: ");
         int status= scanf("%d", id);

       if (status == 1) {
            printf("Valid integer: %d\n", id);
        } else {
            printf("Invalid input! Only integers are allowed.\n");
            while (getchar() != '\n'); 
            continue; 
        }

        
        for (int i = 0; i < count; i++) {
            if(vehicles[i].id == id)  {
                vehicle_index = i;
                break;
            }
        }
        
        if (vehicle_index == -1) {
            printf("Vehicle ID '%d' not found. Please try again.\n", id);
        }
    }

    if (vehicles[vehicle_index].isavailable == 0) {
        vehicles[vehicle_index].isavailable = 1;
        savedata();
        printf(" Vehicle returned successfully! Status is now AVAILABLE.\n");
    } else {
        printf(" Vehicle ID %d is already marked as AVAILABLE and was not previously rented.\n", id);
    }
}

// REMOVE VEHICLE


void removeVehicle() {
    int ch, found_index = -1;
    long long phone = 0; 
    bool valid_phone = false;
    char password[10];
    int id;
    
    while (found_index == -1) {
        printf("Enter vehicle ID to remove: ");
         int status= scanf("%d", id);

       if (status == 1) {
            printf("Valid integer: %d\n", id);
        } else {
            printf("Invalid input! Only integers are allowed.\n");
            while (getchar() != '\n'); 
            continue; 
        }


        for (int i = 0; i < count; i++) {
            if (vehicles[i].id == id)  {
                found_index = i;
                break;
            }
        }

        if (found_index == -1) {
            printf("Vehicle ID '%d' not found in the system. Please try again.\n", id);
        }
    }

    printf("Enter password: ");
    scanf("%9s", password);

    printf("Enter your registered phone number: ");
    scanf("%lld", &phone);
    
    if (strcmp(password, vehicles[found_index].password) == 0) {

        if (phone == vehicles[found_index].phoneNumber) {
            
            for (int j = found_index; j < count - 1; j++) {
                vehicles[j] = vehicles[j + 1];
            }

            count--;
            savedata();
            printf("✅ Vehicle removed successfully!\n");
            return;
        } else {
            printf("❌ Incorrect phone number for this vehicle owner.\n");
        }
    } else {
        printf("❌ Incorrect password!\n");
        
        printf("Reset password?\n");
        printf("1. Yes\n");
        printf("2. No\n");
        if (scanf("%d", &ch) != 1) { ch = 0; }
        
        switch (ch) {
            case 1:
                while (!valid_phone) {
                    long long reset_phone = 0;
                    printf("Enter your registered mobile number for verification: \n");
                    scanf("%lld", &reset_phone);

                    if (vehicles[found_index].phoneNumber == reset_phone) {
                        printf("-------USER VERIFIED-------\n");
                        printf("Enter your new password: \n");
                        scanf("%9s", vehicles[found_index].password);  
                        printf("✅ PASSWORD UPDATED SUCCESSFULLY\n");
                        savedata();
                        valid_phone = true;   
                    } else {
                        printf("Invalid Phone number, try again.\n");
                    }
                }
                break;
            case 2: 
                return;

            default:
                printf("Invalid input for choice.\n");
        }
    }
}