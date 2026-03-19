#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX 70

//structure to store vehicle informations//
 typedef struct{
    int id;
    char VehicleName[30];
    char name[30];
    char aadharid[13];
    char phoneNumber[11];
    char type[10];
    char password[10];
    int isavailable;
    float priceperhour;
 }vehicle;

vehicle vehicles[MAX];
int count=0;

//declaration of function//
 void processdata();
 void savedata();
 void addVehicle();
 void viewAvailability();
 void rentVehicle();
 void removeVehicle();
 void returnVehicle();

 int main(){
    int choice;
    int showMenu = 1;  // flag to control menu visibility
    int again;

    processdata();

    while(1){

        if(showMenu == 1){
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
        scanf("%d", &choice);

        switch(choice){
            case 1: addVehicle(); break;
            case 2: viewAvailability(); break;
            case 3: rentVehicle(); break;
            case 4: returnVehicle(); break;
            case 5: removeVehicle();break; 
            case 6: savedata();exit(0);
            default: printf("Invalid choice! Try again.\n");
        }

        // Ask user if they want to see menu again
        printf("\nDo you want to see the menu again?\n");
        printf("1. Yes\n");
        printf("2. No (Exit)\n");
        printf("Enter your choice: ");
        scanf("%d", &again);

        if(again == 1){
            showMenu = 1;   // show menu again
        } 
        else {
            savedata();
            printf("Exiting program...\n");
            exit(0);
        }
    }
}
//process data from file//
void processdata(){
    FILE*fp=fopen("vehicleInformation.txt","r");
    if(fp==NULL)return;
    
    while(fscanf(fp, "%d%s%s%s%s%s%s%d%f", 
        &vehicles[count].id, 
        vehicles[count].VehicleName,
        vehicles[count].name,
        vehicles[count].aadharid,
        vehicles[count].phoneNumber,
        vehicles[count].type,
        vehicles[count].password,
        &vehicles[count].isavailable,
        &vehicles[count].priceperhour)!=EOF){
            count++;
        }
        fclose(fp);
}

//saving data to file//
void savedata(){
    FILE*fp=fopen("vehicleInformation.txt","w");
    for(int i=0;i<count;i++){
        fprintf(fp,"%d %s %s %s %s %s %s %d %.2f\n",
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

//add a vehicle//
void addVehicle() {
    char tempAadhar[100];
    char tempPhone[50];
    int isValid = 0;
    int isRight = 0;

    printf("Enter your vehicle company Name: ");
    scanf("%s", vehicles[count].VehicleName);
    printf("Enter your name:");
    scanf("%s", vehicles[count].name);

    // Aadhar input and validation loop
    while (!isValid) {
        printf("Enter your 12-digit Aadhar number: ");
        scanf("%s", tempAadhar);

        if (strlen(tempAadhar) != 12) {
            printf(" Error: Aadhar number must be exactly 12 digits.\n");
            continue;
        }

        isValid = 1;
        for (int i = 0; i < 12; i++) {
            if (!isdigit(tempAadhar[i])) {
                isValid = 0;
                printf("Error: Aadhar number must contain only digits.\n");
                break;
            }
        }
    }
    while(!isRight){
        printf("Enter your 10-digit phone number:");
        scanf("%s", tempPhone);

        if(strlen(tempPhone) !=10){
            printf("Error: phone number must be exactly 10 digits\n");
            continue;
        }

        isRight=1;
        for(int i=0;i<10;i++){
            if (!isdigit(tempPhone[i])) {
                isRight = 0;
                printf("Error: phone number must contain only digits.\n");
                break;
        }
    }
    }
    strcpy(vehicles[count].aadharid, tempAadhar);
    strcpy(vehicles[count].phoneNumber, tempPhone);

    printf("Enter your Vehicle ID: ");
    scanf("%d", &vehicles[count].id);

    printf("Enter type (scooty/car/bike): ");
    scanf("%s", vehicles[count].type);

    printf("Enter rent price per hour: ");
    scanf("%f", &vehicles[count].priceperhour);

    vehicles[count].isavailable = 1;

    printf("Set your password: ");
    scanf("%s", vehicles[count].password);

    printf("✅ Vehicle added successfully!\n");

    count++;
    savedata();
}

// view avilability//
void viewAvailability(){

    if(count == 0){
        printf("No vehicles available.\n");
        return;
    }

    printf("\n------ AVAILABLE VEHICLES ------\n");

    for(int i=0; i<count; i++){
        printf("\nVehicle ID: %d | Vehicle Name: %s |Customer name: %s |Aadhar Number: %s |Phone number: %s |Type: %s ",vehicles[i].id,vehicles[i].VehicleName,vehicles[i].name,vehicles[i].aadharid,vehicles[i].phoneNumber,vehicles[i].type);

        if(vehicles[i].isavailable == 1){
            printf("|Status: Available\n");
        } else {
            printf("|Status: Rented\n");
        }

        printf("Price per hour: %.2f\n", vehicles[i].priceperhour);
        printf("-------------------------------\n");
    }
}

// remove vehicle//
void removeVehicle(){
    int id;
    char password[10];
    int found =0;
    printf("ID of vehicle you want to remove : ");
    scanf("%d", &id);
    printf("Enter your password:");
    scanf("%s",password);
    for(int i=0; i<count; i++){
        if( vehicles[i].id ==id){
            found =1;
            if (strcmp(vehicles[i].password, password) == 0){
            printf("password matched successfully\n");

            for( int j=i; j<count-1; j++){
                vehicles[j] = vehicles[j+1];
            }

            count--;
            savedata();

            printf("---- Vehicle  removed sucessfully -----\n");
            return; 
        }
        else{
            printf("incorrect password! try again");
        }
            }
        }
   if( found == 0){
    printf("------Vehicle ID not found -----");
   }
}

//rent a vehicle//
void rentVehicle(){
    int id;
    int age;
    char renteraadhar[100];  
    char rentercontact[50];
    float time;
    float totalAmount;
    int isValid = 0;
    int isRight=0;

    printf("Enter your age:");
    scanf("%d",&age);
    if(age<18){
        printf("You are not eligible to rent a vehicle\n");
        return;
    }

    // Aadhar input and validation loop
    while (!isValid) {
        printf("Enter your 12-digit Aadhar number: ");
        scanf("%s", renteraadhar);

        if (strlen(renteraadhar) != 12) {
            printf(" Aadhar number must be exactly 12 digits.\n");
            continue;
        }

        isValid = 1;
        for (int i = 0; i < 12; i++) {
            if (!isdigit(renteraadhar[i])) {
                isValid = 0;
                printf("Error: Aadhar number must contain only digits.\n");
                break;
            }
        }
    }
    while(!isRight){
        printf("Enter your 10-digit contact number: ");
        scanf("%s", rentercontact);

        if (strlen(rentercontact) != 10) {
            printf(" contact number must be exactly 10 digits.\n");
            continue;
        }

        isRight = 1;
        for (int i = 0; i < 10; i++) {
            if (!isdigit(rentercontact[i])) {
                isRight = 0;
                printf("Error: contact number must contain only digits.\n");
                break;
            }
        }
    }

    printf("Enter vehicle id to rent:");
    scanf("%d",&id);
    printf("Enter for how many hours you rent a vehicle:");
    scanf("%f", &time);

    for(int i=0;i<count;i++){
        if(vehicles[i].id==id && vehicles[i].isavailable==1){
            vehicles[i].isavailable=0;
            totalAmount = time * vehicles[i].priceperhour;

            printf("Total rent: %.2f\n", totalAmount);
            printf("Please proceed with the payment.\n");

            float paidAmount;
            printf("Enter payment amount: ");
            scanf("%f", &paidAmount);

            if (paidAmount >= totalAmount) {
                float change = paidAmount - totalAmount;
                printf("Payment successful! Change to return: %.2f\n", change);
                printf("-----Vehicle rented successfully-----\n");
            } else {
                printf("Insufficient payment. Rental failed.\n");
                vehicles[i].isavailable = 1; // Revert availability
            }

            savedata(); // Save data after transaction
            return;
        }
    }

    printf("----- Vehicle not available or not found -----\n");
    savedata();
}
 //return vehicle//
 void returnVehicle(){
    int id;
    printf("Enter vehicle id to return:");
    scanf("%d" , &id);
    for(int i=0;i<count;i++){
    if(vehicles[i].id==id && vehicles[i].isavailable==0){
        vehicles[i].isavailable=1;
        savedata();
        printf("-----Vehicle returned successfully-----\n");
        return;
    }
    }
    printf("-----Invalid vehicle id-----\n");
 }