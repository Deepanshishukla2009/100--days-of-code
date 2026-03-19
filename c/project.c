#include <stdio.h>
#include <string.h>
#include <stdlib.h> // For exit()
#include <time.h>   // For order ID

// --- Configuration ---
#define MAX_INVENTORY 10
#define MAX_TESTS 5
#define MAX_CART 15
#define MAX_NAME 100
#define MAX_ADDRESS 250
#define ORDER_FILENAME "orders.txt"

// --- 1. STRUCTURES ---
// Structure to define a medicine
typedef struct {
    int id;
    char name[MAX_NAME];
    float price;
    int stock;
} Medicine;

// Structure to define a blood test
typedef struct {
    int id;
    char name[MAX_NAME];
    float price;
} BloodTest;

// Structure to hold user details
typedef struct {
    char name[MAX_NAME];
    char phone[15];
    char address[MAX_ADDRESS];
} User;

// Structure for a single item in the cart
typedef struct {
    int id;           // ID of the product (from Medicine or BloodTest)
    int isTest;       // 0 for Medicine, 1 for BloodTest
    char name[MAX_NAME];
    int quantity;
    float unitPrice;
} CartItem;

// Structure to hold a complete order
typedef struct {
    long orderId;
    User customer;
    CartItem items[MAX_CART];
    int itemCount;
    float totalAmount;
} Order;


// --- 2. FUNCTION PROTOTYPES (Modularity) ---
void clearInputBuffer();
int displayMainMenu();
void getUserDetails(User *user); // Uses pointer

// Medicine Functions
void displayMedicines(Medicine *inventory, int count); // Uses pointer + array
void addMedicineToCart(Medicine *inventory, int medCount, CartItem *cart, int *cartCount); // Uses pointers

// Blood Test Functions
void displayBloodTests(BloodTest *tests, int count); // Uses pointer + array
void addTestToCart(BloodTest *testMenu, int testCount, CartItem *cart, int *cartCount); // Uses pointers

// Cart & Order Functions
void viewCart(CartItem *cart, int cartCount); // Uses pointer + array
float calculateTotal(CartItem *cart, int cartCount);
void saveOrderToFile(Order *order); // Uses pointer + File Handling


// --- main() Function: The driver of the application ---
int main() {
    // --- 3. ARRAYS ---
    // Initialize our "database" of medicines and tests (Arrays of Structs)
    Medicine inventory[MAX_INVENTORY] = {
        {101, "Paracetamol 500mg", 30.50, 50},
        {102, "Aspirin 75mg", 15.00, 40},
        {103, "Cough Syrup 100ml", 120.00, 30},
        {104, "Antacid Gel 170ml", 85.75, 25},
        {105, "Vitamin C 500mg", 99.00, 60}
    };
    int medCount = 5;

    BloodTest testMenu[MAX_TESTS] = {
        {201, "Complete Blood Count (CBC)", 350.00},
        {202, "Thyroid Profile (T3, T4, TSH)", 800.00},
        {203, "Lipid Profile", 900.00},
        {204, "Blood Sugar (Fasting)", 150.00}
    };
    int testCount = 4;

    // App variables
    User customer;
    CartItem cart[MAX_CART];
    int cartCount = 0;
    int choice = 0;

    printf("=== Welcome to Quick-Med Pharmacy & Labs ===\n");
    printf("     (Your 10-minute delivery partner)\n\n");

    // Get user details first
    getUserDetails(&customer); // Pass pointer to the struct

    do {
        choice = displayMainMenu();

        switch (choice) {
            case 1:
                displayMedicines(inventory, medCount);
                addMedicineToCart(inventory, medCount, cart, &cartCount);
                break;
            case 2:
                displayBloodTests(testMenu, testCount);
                addTestToCart(testMenu, testCount, cart, &cartCount);
                break;
            case 3:
                viewCart(cart, cartCount);
                break;
            case 4:
                if (cartCount == 0) {
                    printf("Your cart is empty. Please add items before checking out.\n\n");
                } else {
                    printf("\n--- Finalizing Your Order ---\n");
                    Order finalOrder;
                    srand(time(NULL)); // Seed random number generator
                    finalOrder.orderId = time(NULL); // Simple unique order ID
                    finalOrder.customer = customer; // Copy user struct
                    
                    // Copy cart items to order
                    memcpy(finalOrder.items, cart, cartCount * sizeof(CartItem));
                    finalOrder.itemCount = cartCount;
                    finalOrder.totalAmount = calculateTotal(cart, cartCount);

                    // --- 5. FILE HANDLING ---
                    saveOrderToFile(&finalOrder); // Pass pointer to the order
                    
                    printf("\nOrder Confirmed!\n");
                    printf("Your Order ID is: %ld\n", finalOrder.orderId);
                    printf("Total Amount: %.2f\n", finalOrder.totalAmount);
                    printf("Your order will be delivered in 10 minutes to: %s\n", finalOrder.customer.address);
                    printf("Thank you for using Quick-Med!\n");
                    choice = 5; // Set choice to 5 to exit loop
                }
                break;
            case 5:
                printf("\nThank you for visiting Quick-Med. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n\n");
        }

    } while (choice != 5);

    return 0;
}


// --- FUNCTION IMPLEMENTATIONS ---

/**
 * @brief Clears the standard input buffer.
 * Necessary after using scanf() to read a number before fgets().
 */
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/**
 * @brief Gets user details and stores them in the User struct.
 * @param user A POINTER to the User struct to be filled.
 */
void getUserDetails(User *user) {
    printf("Please enter your details to begin:\n");
    
    printf("Full Name: ");
    fgets(user->name, MAX_NAME, stdin);
    user->name[strcspn(user->name, "\n")] = 0; // Remove trailing newline

    printf("Phone Number: ");
    fgets(user->phone, 15, stdin);
    user->phone[strcspn(user->phone, "\n")] = 0;

    printf("Delivery Address: ");
    fgets(user->address, MAX_ADDRESS, stdin);
    user->address[strcspn(user->address, "\n")] = 0;

    printf("\nWelcome, %s! Let's get your order.\n", user->name);
}

/**
 * @brief Displays the main navigation menu.
 * @return The user's integer choice.
 */
int displayMainMenu() {
    int choice = 0;
    printf("\n--- Quick-Med Main Menu ---\n");
    printf("1. Order Medicines\n");
    printf("2. Book a Blood Test\n");
    printf("3. View Cart\n");
    printf("4. Checkout & Place Order\n");
    printf("5. Exit\n");
    printf("---------------------------\n");
    printf("Enter your choice: ");
    
    if (scanf("%d", &choice) != 1) {
        choice = -1; // Invalid input
    }
    clearInputBuffer(); // Always clear buffer after scanf
    return choice;
}

/**
 * @brief Displays all available medicines from the inventory array.
 * @param inventory POINTER to the start of the Medicine array.
 * @param count Number of medicines in the array.
 */
void displayMedicines(Medicine *inventory, int count) {
    printf("\n--- Available Medicines ---\n");
    printf("ID   | Name                 | Price   | Stock\n");
    printf("-----|----------------------|---------|-------\n");
    for (int i = 0; i < count; i++) {
        // Use pointer arithmetic (inventory[i])
        printf("%-4d | %-20.20s | %-7.2f | %d\n",
               inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].stock);
    }
    printf("\n");
}

/**
 * @brief Displays all available blood tests.
 * @param tests POINTER to the start of the BloodTest array.
 * @param count Number of tests in the array.
 */
void displayBloodTests(BloodTest *tests, int count) {
    printf("\n--- Available Blood Tests ---\n");
    printf("ID   | Name                        | Price\n");
    printf("-----|-----------------------------|---------\n");
    for (int i = 0; i < count; i++) {
        printf("%-4d | %-27.27s | %.2f\n",
               tests[i].id, tests[i].name, tests[i].price);
    }
    printf("\n");
}

/**
 * @brief Handles logic for adding a medicine to the cart.
 * @param inventory POINTER to the medicine array.
 * @param medCount Number of medicines.
 * @param cart POINTER to the cart array.
 * @param cartCount POINTER to the cart's item count (this will be modified).
 */
void addMedicineToCart(Medicine *inventory, int medCount, CartItem *cart, int *cartCount) {
    int id, quantity;
    printf("Enter Medicine ID to add to cart: ");
    if (scanf("%d", &id) != 1) {
        clearInputBuffer();
        printf("Invalid ID.\n");
        return;
    }

    // Find the medicine
    int foundIndex = -1;
    for (int i = 0; i < medCount; i++) {
        if (inventory[i].id == id) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) {
        printf("Invalid Medicine ID.\n");
        clearInputBuffer();
        return;
    }

    printf("Enter quantity (Stock: %d): ", inventory[foundIndex].stock);
    if (scanf("%d", &quantity) != 1) {
        clearInputBuffer();
        printf("Invalid quantity.\n");
        return;
    }
    clearInputBuffer(); // Clear buffer

    if (quantity <= 0) {
        printf("Quantity must be at least 1.\n");
    } else if (quantity > inventory[foundIndex].stock) {
        printf("Sorry, only %d units are in stock.\n", inventory[foundIndex].stock);
    } else if (*cartCount >= MAX_CART) {
        printf("Your cart is full!\n");
    } else {
        // Add to cart
        CartItem *newItem = &cart[*cartCount]; // Pointer to the new cart slot
        newItem->id = inventory[foundIndex].id;
        newItem->isTest = 0; // 0 for medicine
        strcpy(newItem->name, inventory[foundIndex].name);
        newItem->quantity = quantity;
        newItem->unitPrice = inventory[foundIndex].price;
        
        // Update stock (for this session only)
        inventory[foundIndex].stock -= quantity;
        
        (*cartCount)++; // Increment cart count using pointer
        printf("Added %d x %s to your cart.\n", quantity, newItem->name);
    }
}

/**
 * @brief Handles logic for adding a blood test to the cart.
 * @param testMenu POINTER to the test array.
 * @param testCount Number of tests.
 * @param cart POINTER to the cart array.
 * @param cartCount POINTER to the cart's item count (this will be modified).
 */
void addTestToCart(BloodTest *testMenu, int testCount, CartItem *cart, int *cartCount) {
    int id;
    printf("Enter Test ID to book: ");
    if (scanf("%d", &id) != 1) {
        clearInputBuffer();
        printf("Invalid ID.\n");
        return;
    }
    clearInputBuffer(); // Clear buffer

    int foundIndex = -1;
    for (int i = 0; i < testCount; i++) {
        if (testMenu[i].id == id) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) {
        printf("Invalid Test ID.\n");
        return;
    }
    
    if (*cartCount >= MAX_CART) {
        printf("Your cart is full!\n");
    } else {
        // Add to cart
        CartItem *newItem = &cart[*cartCount]; // Pointer to new cart slot
        newItem->id = testMenu[foundIndex].id;
        newItem->isTest = 1; // 1 for test
        strcpy(newItem->name, testMenu[foundIndex].name);
        newItem->quantity = 1; // Quantity is always 1 for a test
        newItem->unitPrice = testMenu[foundIndex].price;
        
        (*cartCount)++; // Increment cart count
        printf("Added '%s' to your cart.\n", newItem->name);
    }
}

/**
 * @brief Calculates the total price of all items in the cart.
 * @param cart POINTER to the cart array.
 * @param cartCount Number of items in the cart.
 * @return The total price as a float.
 */
float calculateTotal(CartItem *cart, int cartCount) {
    float total = 0.0;
    for (int i = 0; i < cartCount; i++) {
        total += cart[i].unitPrice * cart[i].quantity;
    }
    return total;
}

/**
 * @brief Displays the current contents of the cart and the total.
 * @param cart POINTER to the cart array.
 * @param cartCount Number of items in the cart.
 */
void viewCart(CartItem *cart, int cartCount) {
    if (cartCount == 0) {
        printf("\nYour cart is empty.\n\n");
        return;
    }

    printf("\n--- Your Cart (%d items) ---\n", cartCount);
    printf("Type  | Qty | Name                 | Unit Price | Total\n");
    printf("------|-----|----------------------|------------|---------\n");

    for (int i = 0; i < cartCount; i++) {
        printf("%-5s | %-3d | %-20.20s | %-10.2f | %-7.2f\n",
               cart[i].isTest ? "Test" : "Med",
               cart[i].quantity,
               cart[i].name,
               cart[i].unitPrice,
               cart[i].unitPrice * cart[i].quantity);
    }
    
    float total = calculateTotal(cart, cartCount);
    printf("------------------------------------------------------\n");
    printf("Grand Total: %.2f\n\n", total);
}

/**
 * @brief --- 5. FILE HANDLING ---
 * Saves the completed order to a text file.
 * @param order A POINTER to the final Order struct.
 */
void saveOrderToFile(Order *order) {
    // "a" opens the file in append mode, creating it if it doesn't exist.
    FILE *file = fopen(ORDER_FILENAME, "a"); 
    
    if (file == NULL) {
        printf("CRITICAL ERROR: Could not save order to file '%s'.\n", ORDER_FILENAME);
        return;
    }

    // Get current time for timestamp
    time_t t = time(NULL);
    char *time_str = ctime(&t);
    time_str[strcspn(time_str, "\n")] = 0; // Remove newline

    // Write order details to the file
    fprintf(file, "===================================================\n");
    fprintf(file, "Order ID: %ld\n", order->orderId);
    fprintf(file, "Timestamp: %s\n", time_str);
    fprintf(file, "\n--- Customer Details ---\n");
    fprintf(file, "Name: %s\n", order->customer.name);
    fprintf(file, "Phone: %s\n", order->customer.phone);
    fprintf(file, "Address: %s\n", order->customer.address);
    fprintf(file, "\n--- Order Items (%d) ---\n", order->itemCount);
    
    for (int i = 0; i < order->itemCount; i++) {
        fprintf(file, "  - [%s] %s (Qty: %d @ %.2f each)\n",
                order->items[i].isTest ? "TEST" : "MED",
                order->items[i].name,
                order->items[i].quantity,
                order->items[i].unitPrice);
    }
    
    fprintf(file, "\n--- Total Amount: %.2f ---\n", order->totalAmount);
    fprintf(file, "===================================================\n\n");

    // Always close the file handle
    fclose(file);
    
    printf("Order details saved to %s\n", ORDER_FILENAME);
}