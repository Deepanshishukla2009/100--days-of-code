//q5Create a union containing 6 strings: name, home_address, hostel_address, city, state and zip. Write a C program to display your present address.

#include<stdio.h>
#include<string.h>

union address{
 char name[20];
 char homeadress[50];
 char hosteladress[50];
 char city[20];
 char state[20];
 char zip[10];
 };
  int main() {
   union  address addr;

    
    strcpy(addr.name, "abcd");
    printf("Name: %s\n", addr.name);
    
    strcpy(addr.homeadress,"128/108 d block");
    printf("home address: %s\n", addr.homeadress); 

    strcpy(addr.hosteladress, "Hostel No. 2, Room 208");
    printf("hosteladress: %s\n", addr.hosteladress);
    
     strcpy(addr.city, "dehradun");
    printf("City: %s\n", addr.city);

    strcpy(addr.state, "Uttarakhand");
    printf("State: %s\n", addr.state);

    strcpy(addr.zip, "208011");
    printf("ZIP: %s\n", addr.zip);

    return 0;
  }
