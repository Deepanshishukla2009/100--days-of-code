#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#ifdef _WIN32
    #define CLEAR_CMD "cls"
#else
    #define CLEAR_CMD "clear"
#endif

#define TOTAL_ITEMS 9
#define PATHS 3
#define MAXITEMS 50
#define LINEBUF 256
#define MAX_DAMAGE_STACKS 8

/* ---------- Globals ---------- */
char *assigned_items[PATHS];

/* Stats/globals for final stats feature */
int GLOBAL_ITEMS_BOUGHT = 0;        // increments when a shop purchase succeeds
int GLOBAL_REACHED_FINAL = 0;       // set to 1 when runFinalCombat() is called
int GLOBAL_LAST_PLAYER_HEALTH = 0;  // player's remaining HP at combat end (or last recorded)
int GLOBAL_LAST_COMBAT_TURNS = 0;   // turns taken in final combat (0 if not reached)
int GLOBAL_FINAL_VICTORY = 0;       // 1 if Guardian defeated, else 0

/* ---------- Player details ---------- */
struct playerdetails {
    char name[30];
    int age;
} P;

/* Inventory types */
typedef struct {
    char name[30];
    int quantity;
} Item;

typedef struct {
    Item items[MAXITEMS];
    int count;
    int equippedIndex; /* single-slot equip (weapon or shield) */
    int gold;
} Inventory;

typedef struct {
    char name[30];
    int price;
    char description[100];
} ShopItem;

/* ---------- Utility functions ---------- */

void clearScreen() {
    system(CLEAR_CMD);
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int readLine(char *dest, size_t maxlen) {
    if (!fgets(dest, (int)maxlen, stdin))
        return 0;
    size_t len = strlen(dest);
    if (len > 0 && dest[len - 1] == '\n')
        dest[len - 1] = '\0';
    return 1;
}

int readInt(int *out) {
    char buf[LINEBUF];
    if (!readLine(buf, sizeof(buf)))
        return 0;
    char *endptr;
    long val = strtol(buf, &endptr, 10);
    if (endptr == buf)
        return 0;
    *out = (int)val;
    return 1;
}

int readChar(char *out) {
    char buf[LINEBUF];
    if (!readLine(buf, sizeof(buf)))
        return 0;
    for (size_t i = 0; i < strlen(buf); ++i) {
        if (!isspace((unsigned char)buf[i])) {
            *out = buf[i];
            return 1;
        }
    }
    return 0;
}

int strCaseCmp(const char *a, const char *b) {
    while (*a && *b) {
        int ca = tolower((unsigned char)*a);
        int cb = tolower((unsigned char)*b);
        if (ca != cb)
            return ca - cb;
        a++; b++;
    }
    return tolower((unsigned char)*a) - tolower((unsigned char)*b);
}

/* pause that prompts the user and waits for Enter; returns if input closed */
void pauseReturn(void) {
    char buf[16];
    printf("\nPress Enter to continue...");
    if (!fgets(buf, sizeof(buf), stdin)) {
        /* input closed — return instead of exit */
        return;
    }
}

/* ---------- Splash & Rules ---------- */

void displaySplashScreen() {
    clearScreen();
    printf("\n=========================================================\n");
    printf("                 C PROGRAMMING PROJECT\n");
    printf(" Project Name : Forest Escape Adventure Game\n");
    printf("-----------------------------------------------------------\n");
    printf(" Submitted To : Pankaj Bhadoni\n");
    printf(" Submitted By : Manas Mishra and Harshita Mathur\n");
    printf("************************************************************\n");
    pauseReturn(); /* use consistent pause */
    clearScreen();
}

void showRules() {
#ifdef _WIN32
    system("color 06");
#endif
    clearScreen();
    printf(">>> RULES OF THE FOREST: READ BEFORE YOU ENTER <<<\n\n");
    printf("1. The forest has 3 mysterious caves. Each cave guards a relic.\n");
    printf("2. Every cave has 3 questions. Answer at least 2 to earn its relic.\n");
    printf("3. No going back after entering a cave.\n");
    printf("4. Relics go into your satchel.\n");
    printf("5. You start with Forest Tokens.\n");
    printf("6. You may access the shop or satchel between caves.\n");
    printf("7. After all 3 caves, you gain access to FINAL COMBAT if you have all relics.\n");

    pauseReturn();
    clearScreen();
#ifdef _WIN32
    system("color 07");
#endif
}

/* ---------- Inventory ---------- */

void displayInventory(const Inventory *inv) {
    clearScreen();
    printf("\nForest Tokens: %d\n", inv->gold);
    printf("%-5s %-30s %-10s\n", "S.No", "Item Name", "Quantity");
    printf("-------------------------------------------------------------\n");

    if (inv->count == 0) {
        printf("Your satchel is empty.\n");
    } else {
        for (int i = 0; i < inv->count; i++) {
            printf("%-5d %-30s %-10d", i + 1, inv->items[i].name, inv->items[i].quantity);
            if (inv->equippedIndex == i)
                printf("  <-- Equipped");
            printf("\n");
        }
    }

    pauseReturn();
}

int findItemIndex(const Inventory *inv, const char *name) {
    for (int i = 0; i < inv->count; ++i) {
        if (strCaseCmp(inv->items[i].name, name) == 0)
            return i;
    }
    return -1;
}

void addItem(Inventory *inv, const char *name, int qty) {
    if (!name || qty <= 0) {
        printf("Invalid add parameters.\n");
        return;
    }

    int index = findItemIndex(inv, name);

    if (index != -1) {
        inv->items[index].quantity += qty;
        printf("Updated '%s' quantity to %d.\n", inv->items[index].name, inv->items[index].quantity);
    } else {
        if (inv->count >= MAXITEMS) {
            printf("Your satchel is full. Cannot carry more.\n");
            return;
        }

        strncpy(inv->items[inv->count].name, name, sizeof(inv->items[inv->count].name) - 1);
        inv->items[inv->count].name[sizeof(inv->items[inv->count].name) - 1] = '\0';
        inv->items[inv->count].quantity = qty;
        inv->count++;

        printf("Added '%s' x%d to your satchel.\n", name, qty);
    }
}

void removeItem(Inventory *inv, const char *name) {
    int index = findItemIndex(inv, name);

    if (index == -1) {
        printf("Item '%s' not found.\n", name);
        return;
    }

    for (int i = index; i < inv->count - 1; i++)
        inv->items[i] = inv->items[i + 1];

    inv->count--;

    if (inv->equippedIndex == index)
        inv->equippedIndex = -1;
    else if (inv->equippedIndex > index)
        inv->equippedIndex--;

    printf("Item '%s' removed from your satchel.\n", name);
}

void equipItem(Inventory *inv, const char *name) {
    int index = findItemIndex(inv, name);

    if (index == -1 || inv->items[index].quantity <= 0) {
        printf("Cannot equip '%s'.\n", name);
        return;
    }

    inv->equippedIndex = index;
    printf("Equipped '%s'.\n", inv->items[index].name);
}

void showEquipped(const Inventory *inv) {
    if (inv->equippedIndex >= 0 && inv->equippedIndex < inv->count) {
        printf("Currently equipped: %s (Qty: %d)\n",
               inv->items[inv->equippedIndex].name,
               inv->items[inv->equippedIndex].quantity);
    } else {
        printf("No item is currently equipped.\n");
    }
}

void swapItemsAndFixEquip(Inventory *inv, int a, int b) {
    if (a == b) return;
    Item tmp = inv->items[a];
    inv->items[a] = inv->items[b];
    inv->items[b] = tmp;

    if (inv->equippedIndex == a)
        inv->equippedIndex = b;
    else if (inv->equippedIndex == b)
        inv->equippedIndex = a;
}

void sortName(Inventory *inv) {
    for (int i = 0; i < inv->count - 1; i++) {
        for (int k = 0; k < inv->count - i - 1; k++) {
            if (strCaseCmp(inv->items[k].name, inv->items[k + 1].name) > 0)
                swapItemsAndFixEquip(inv, k, k + 1);
        }
    }
    printf("Satchel sorted by name.\n");
}

void sortByQuantity(Inventory *inv) {
    for (int i = 0; i < inv->count - 1; i++) {
        for (int k = 0; k < inv->count - i - 1; k++) {
            if (inv->items[k].quantity > inv->items[k + 1].quantity)
                swapItemsAndFixEquip(inv, k, k + 1);
        }
    }
    printf("Satchel sorted by quantity.\n");
}

void searchItemName(const Inventory *inv, const char *name) {
    int index = findItemIndex(inv, name);

    if (index != -1) {
        printf("\nItem found:\nName     : %s\nQuantity : %d\n",
               inv->items[index].name,
               inv->items[index].quantity);
    } else {
        printf("Item '%s' not found.\n", name);
    }
}

/* ---------- Shop ---------- */

void openShop(Inventory *inv) {
    ShopItem tools[] = {
        {"Wooden Spear", 150, "Simple forest spear"},
        {"Vine Shield", 120, "Woven vines. +8 defence"},
        {"Stone Hatchet", 200, "Heavy hatchet. High damage"},
    };

    ShopItem utility[] = {
        {"Herbal Tonic", 50, "Restores 50 HP"},
        {"Antidote Herbs", 40, "Used as ATK buff in combat"},
    };

    int choice = 0, itemChoice = 0;

    do {
        clearScreen();
        printf("\n=== Forest Trading Post ===\n");
        printf("Forest Tokens: %d\n", inv->gold);
        printf("1. Tools\n2. Remedies & Supplies\n3. Leave Shop\n");
        printf("Choose: ");

        if (!readInt(&choice)) {
            printf("Invalid input.\n");
            pauseReturn();
            continue;
        }

        if (choice == 1) {
            printf("\n--- Tools ---\n");
            for (int i = 0; i < 3; i++)
                printf("%d. %-15s %d tokens - %s\n",
                       i + 1, tools[i].name, tools[i].price, tools[i].description);

            printf("Enter item number (0 to cancel): ");
            if (!readInt(&itemChoice)) { printf("Invalid.\n"); pauseReturn(); continue; }

            if (itemChoice >= 1 && itemChoice <= 3) {
                ShopItem selected = tools[itemChoice - 1];
                if (inv->gold >= selected.price) {
                    inv->gold -= selected.price;
                    addItem(inv, selected.name, 1);
                    GLOBAL_ITEMS_BOUGHT++;
                    printf("Purchased %s. Remaining tokens: %d\n", selected.name, inv->gold);
                } else {
                    printf("Not enough tokens!\n");
                }
                pauseReturn();
            }
        }

        else if (choice == 2) {
            printf("\n--- Remedies & Supplies ---\n");
            for (int i = 0; i < 2; i++)
                printf("%d. %-15s %d tokens - %s\n",
                       i + 1, utility[i].name, utility[i].price, utility[i].description);

            printf("Enter item number (0 to cancel): ");
            if (!readInt(&itemChoice)) { printf("Invalid.\n"); pauseReturn(); continue; }

            if (itemChoice >= 1 && itemChoice <= 2) {
                ShopItem selected = utility[itemChoice - 1];
                if (inv->gold >= selected.price) {
                    inv->gold -= selected.price;
                    addItem(inv, selected.name, 1);
                    GLOBAL_ITEMS_BOUGHT++;
                    printf("Purchased %s. Remaining tokens: %d\n", selected.name, inv->gold);
                } else {
                    printf("Not enough tokens!\n");
                }
                pauseReturn();
            }
        }

    } while (choice != 3);
}

/* Inventory UI */

void openInventoryUI(Inventory *inv) {
    int choice;
    char name[30];

    do {
        clearScreen();
        printf("\n===== Satchel Menu =====\n");
        printf("1. Drop item\n");
        printf("2. View satchel\n");
        printf("3. Equip item\n");
        printf("4. Show equipped item\n");
        printf("5. Sort by name\n");
        printf("6. Sort by quantity\n");
        printf("7. Search item by name\n");
        printf("8. Visit forest trading post\n");
        printf("9. Return to caves\n");
        printf("Enter choice: ");

        if (!readInt(&choice)) {
            printf("Invalid input.\n");
            pauseReturn();
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter item name to drop: ");
                if (!readLine(name, sizeof(name))) { printf("No input.\n"); pauseReturn(); }
                else { removeItem(inv, name); pauseReturn(); }
                break;

            case 2:
                displayInventory(inv);
                break;

            case 3:
                printf("Enter item name to equip: ");
                if (!readLine(name, sizeof(name))) { printf("No input.\n"); pauseReturn(); }
                else { equipItem(inv, name); pauseReturn(); }
                break;

            case 4:
                showEquipped(inv);
                pauseReturn();
                break;

            case 5:
                sortName(inv);
                pauseReturn();
                break;

            case 6:
                sortByQuantity(inv);
                pauseReturn();
                break;

            case 7:
                printf("Enter item name to search: ");
                if (!readLine(name, sizeof(name))) { printf("No input.\n"); pauseReturn(); }
                else { searchItemName(inv, name); pauseReturn(); }
                break;

            case 8:
                openShop(inv);
                break;

            case 9:
                clearScreen();
                return;

            default:
                printf("Invalid choice.\n");
                pauseReturn();
                break;
        }

    } while (1);
}

/* ---------- Shuffle helpers ---------- */

void shuffle_ints(int arr[], int n) {
    for (int i = n - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}

void shuffle_ptrs(char *arr[], int n) {
    for (int i = n - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        char *tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}

/* ---------- Puzzle Sets (Complete 1–9) ---------- */

void checkAnswer(char user, char correct, int *score) {
    user = toupper((unsigned char)user);
    correct = toupper((unsigned char)correct);
    if (user == correct) {
        printf("Correct!\n");
        (*score)++;
    } else {
        printf("Wrong Answer!\n");
    }
    printf("\n");
    pauseReturn();
    clearScreen();
}

/* helper to read a non-empty answer char */
/* helper to read a non-empty answer char and require A/B/C/D (case-insensitive) */
char readNonEmptyAnswer(void) {
    char buf[LINEBUF];
    while (1) {
        if (!readLine(buf, sizeof(buf))) {
            /* EOF or error: return 0 to mark invalid */
            return 0;
        }

        /* find first non-space character */
        size_t i = 0;
        while (i < strlen(buf) && isspace((unsigned char)buf[i])) i++;

        if (i < strlen(buf)) {
            char c = buf[i];
            c = toupper((unsigned char)c);

            /* accept only A, B, C, D */
            if (c == 'A' || c == 'B' || c == 'C' || c == 'D') {
                return c;
            }
            /* if user typed something else (e.g. "x" or "1"), prompt again */
        }

        /* empty line or invalid char — prompt user (and loop) */
        printf("Please enter A, B, C, or D: ");
    }
}


int set1() {
    int score=0; char ans;

    printf("Riddle: 1.A math professor writes three numbers on the board:12, 7, and 5\nHe says:'One of these numbers cannot be used to measure time in any reasonable form.'\n");
    printf("A) 12  B) 7  C) 5  D) None\nYour choice: ");
    ans = readNonEmptyAnswer(); checkAnswer(ans,'C',&score);

    printf("\n1.A ratio of 5:3 is scaled up so the first term becomes 45. What is the second term?\n");
    printf("A) 27  B) 33  C) 21  D) 36\nYour choice: ");
    ans = readNonEmptyAnswer(); checkAnswer(ans,'A',&score);

    printf("\nPuzzle:\n 14   5   9\n 7   ?   6\n 21   3  12\n");
    printf("A) 13.6  B) 9.8  C) 18.6  D) 10.5\nYour choice: ");
    ans = readNonEmptyAnswer(); checkAnswer(ans,'B',&score);

    printf("\nScore: %d/3\n",score);

    printf("Score: %d/3\n", score);
    return score;
}

int set2() {
    int score=0; char ans;

    printf("Riddle: 2.	A lighthouse flashes every 15 seconds.You stand on a cliff and count exactly 4 flashes.\n");
    printf("The fog is so thick that you missed the first flash — you saw only from the second one onwards.\n");
    printf("How much time has passed since the FIRST flash (including the one you missed)?\n");
    printf("A) 45  B) 60  C) 30  D) 15\nYour choice: ");
    ans = readNonEmptyAnswer(); checkAnswer(ans,'A',&score);

    printf("\nArithmetic: If a*b=0 and a+b=17, what is a^2+b^2?\n");
    printf("A) 289  B) 36 C) 225  D) 144\nYour choice: ");
    ans = readNonEmptyAnswer(); checkAnswer(ans,'A',&score);

    printf("\nPuzzle: Triangle with top=42, middle-left=18, middle-right=?, bottom=7,11,9\n");
    printf("A) 5  B) 8  C) 4  D) 3\nYour choice: ");
    ans = readNonEmptyAnswer(); checkAnswer(ans,'D',&score);

    printf("\nScore: %d/3\n",score);
    return score;
}

int set3() {
   int score=0; char ans;
    printf("Riddle: I cradle soft and wet, let you smell roses. What am I?\n");
    printf("A) Skull  B) Nose  C) Brain  D) Heart\nYour choice: ");
    ans = readNonEmptyAnswer(); checkAnswer(ans,'A',&score);

    printf("\nArithmetic: Sequence 15,14,12,9,5,?\n");
    printf("A) 0  B) 1  C) 2  D) -1\nYour choice: ");
    ans = readNonEmptyAnswer(); checkAnswer(ans,'A',&score);

    printf("\nThe Camera Loop\n");
    printf("Security camera looped footage 02:00-03:00. At 03:05 the alarm triggers and a guard inside claims he never left. No footprints. What likely happened?");
    printf("A) Guard colluded with thief B) Thief hid earlier in the building C) Camera hacked remotely, thief entered after loop stopped D) Painting vanished by wind\n Your choice:");
    ans = readNonEmptyAnswer(); checkAnswer(ans,'C',&score);

    printf("\nScore: %d/3\n",score);
    return score;

}

int set4() {
    int score=0; char ans;


    printf("Riddle: I rise when afraid, grow pale when cold. What am I?\n");
    printf("A) Skin  B) Hair  C) Blood  D) Eyes\nYour choice: ");
    ans = readNonEmptyAnswer(); checkAnswer(ans,'A',&score);

    printf("\nArithmetic: Which number cannot be sum of two primes?\n");
    printf("A) 10  B) 16  C) 17  D) 22\nYour choice: ");
    ans = readNonEmptyAnswer(); checkAnswer(ans,'C',&score);

    printf("\nPuzzle: Color Blind Test\n");
    printf("A man claims he can tell the color of any card in a deck without seeing it. He is blindfolded.\n Yet he guesses all 52 correctly.How?");
    printf("A) Cheating  B) Texture marks  C) Deck is of  one color  D) Always said black\nYour choice: ");
    ans = readNonEmptyAnswer(); checkAnswer(ans,'C',&score);

    printf("\nScore: %d/3\n",score);
    return score;
}

int set5() {
     int score=0; char ans;
    printf("Riddle:5 A women shoots her husband , then she hold him under water for 5 minutes ,\n Finally she hangs him , but few minutes later they both go on a   lovely dinner together ,\n how is this possible.?\n");
    printf("A) Dream  B) Photo  C) Illusion  D) Trick\nYour choice: ");
    ans = readNonEmptyAnswer(); checkAnswer(ans,'B',&score);

    printf("\nArithmetic: Sum of 3 consecutive integers is always?\n");
    printf("A) Even  B) Odd  C) Multiple of 3  D) Prime\nYour choice: ");
    ans = readNonEmptyAnswer(); checkAnswer(ans,'C',&score);

    printf("\n- Find the odd one: 2, 6, 12, 20, 30\n");
    printf("A) 2  B) 20  C) 6 D) 30\nYour choice: ");
    ans = readNonEmptyAnswer(); checkAnswer(ans,'A',&score);

    printf("\nScore: %d/3\n",score);
    printf("Score: %d/3\n", score);
    return score;
}

int set6() {
     int score=0; char ans;
    printf("Riddle: Library of Endless Books\n");
    printf("You enter a giant old library. Every shelf is filled with books, but none of them have titles.\n");
    printf("A librarian tells you:\n“Every book in this library is unique. But one thing is common:Every book begins on page 1, and ends on page 1.\n");
    printf("You open a random book.It has only one page, printed on both sides.What kind of book is it?\n");
    printf("A) Trick book  B) Diary  C) Bookmark  D) Pamphlet\nYour choice: ");
    ans = readNonEmptyAnswer(); checkAnswer(ans,'D',&score);

    printf("\nArithmetic: Which number cannot be difference of two squares?\n");
    printf("A) 5  B) 8  C) 12  D) 15\nYour choice: ");
    ans = readNonEmptyAnswer(); checkAnswer(ans,'B',&score);

    printf("\nPuzzle: Two Doors Paradox\n");
    printf("You face two doors: one leads to freedom, one to death.\n A guard ALWAYS lies, the other ALWAYS tells the truth.\nYou may ask one question to one guard.\n What should you ask?\n");
    printf("A) Which door is safe?  B) Is left door safe?  C) Which door would other guard say?  D) Are you liar?\nYour choice: ");
    ans = readNonEmptyAnswer(); checkAnswer(ans,'C',&score);

    printf("\nScore: %d/3\n",score);

    return score;
}

int set7() {
    int score=0; char ans;
    printf("Riddle:Two trains are heading toward each other in a long tunnel.Both travel at the same speed.\n");
    printf("A bat flies from the first train to the second, then back, repeating until the trains collide.\n");
    printf("At what moment does the bat stop flying?\n");
    printf("A) Tired  B) Collide  C) Exit tunnel  D) Half tunnel\nYour choice: ");
    ans = readNonEmptyAnswer(); checkAnswer(ans,'B',&score);

    printf("\nArithmetic: Divisible by 4 and 9 must also be divisible by?\n");
    printf("A) 18  B) 36  C) 12  D) 72\nYour choice: ");
    ans = readNonEmptyAnswer(); checkAnswer(ans,'B',&score);

    printf("\nPuzzle: Star Pattern:\n *=7\n**=18\n***=33\n****=?\n");
    printf("A) 45  B) 67  C) 52  D) 78\nYour choice: ");
    ans = readNonEmptyAnswer(); checkAnswer(ans,'C',&score);

    printf("\nScore: %d/3\n",score);
    return score;
}

int set8() {
    int score=0; char ans;
    printf("Riddle: A room has no windows or clocks.\nYou stay inside 24 hours.\nInside, one candle burns for exactly 6 hours,another burns for exactly 8 hours,\nand two lanterns can each burn for exactly 3 hours.\n");
    printf("You can light them in any order.\nHow can you measure exactly 12 hours?\n");
    printf("A) Burn 6 hour Candle+Lantern+Lantern  B) Burn 8 hour Candle half-way  C) Burn both candles together  D) Impossible\nYour choice: ");
    ans = readNonEmptyAnswer(); checkAnswer(ans,'D',&score);

    printf("\nArithmetic:8.	A sequence is defined:\nA1 = 1\nA2 = 4\nAn = An-1 + An-2\nThen An is always\n");
    printf("A) Odd  B) Even  C) Alternating  D) Multiple of 3\nYour choice: ");
    ans = readNonEmptyAnswer(); checkAnswer(ans,'C',&score);

    printf("\nA museum alarm goes off. Security enters and finds a painting missing, but detects no break-in.\nOnly one guard was inside.What's most likely?\n");
    printf("A) Guard  B) Thief hid earlier  C) Accidentally moved  D) Alarm malfunction\nYour choice: ");
    ans = readNonEmptyAnswer(); checkAnswer(ans,'A',&score);

    printf("\nScore: %d/3\n",score);
    return score;
}

int set9() {
    int score=0; char ans;
    printf("Riddle:9.	What is something that breaks the moment you take its  name.\n");
    printf("A) Silence  B) Glass  C) Promise  D) Thread\nYour choice: ");
    ans = readNonEmptyAnswer(); checkAnswer(ans,'A',&score);

    printf("\nArithmetic: If a number is divisible by 6, it must also be divisible by?\n");
    printf("A) 2 only  B) 3 only  C) 2 and 3  D) 12\nYour choice: ");
    ans = readNonEmptyAnswer(); checkAnswer(ans,'C',&score);

    printf("\nPuzzle: Four people (1,2,5,10 min) cross a bridge with one flashlight. Minimum total time to cross?\n");
    printf("A) 17  B) 19  C) 21  D) 23\nYour choice: ");
    ans = readNonEmptyAnswer(); checkAnswer(ans,'A',&score);

    printf("\nScore: %d/3\n",score);
    return score;
}
/* Assign relics to caves */

void assignItemsToCaves() {
    static char *items[TOTAL_ITEMS] = {
        "Moonlit Fern","Ancient Tree Bark","Forest Map",
        "Firefly Lantern","Spirit Totem","Vine Rope",
        "Hunter's Flute","Mossy Compass","Crystal Seed"
    };

    char *pool[TOTAL_ITEMS];
    for (int i = 0; i < TOTAL_ITEMS; i++) pool[i] = items[i];

    shuffle_ptrs(pool, TOTAL_ITEMS);

    for (int c = 0; c < PATHS; ++c)
        assigned_items[c] = pool[c];
}

/* Combat structures & functions */

typedef struct {
    char name[32];
    int max_health;
    int health_points;

    int base_attack;
    int base_defense;

    int attack;
    int defense;

    int potion_count;
    int damage_potion_count;

    double damage_buff_mult;
    int damage_stack_timers[MAX_DAMAGE_STACKS];
    int damage_stack_count;

    char equipped_weapon_name[32];
    char equipped_armor_name[32];

} CombatPlayer;

typedef struct {
    char name[32];
    int health;
    int max_health;
    int base_attack;
    int rage_active;
} CombatEnemy;

/* Inventory → Combat Player conversion */

int invQuantity(const Inventory *inv, const char *name) {
    int idx = findItemIndex(inv, name);
    if (idx == -1) return 0;
    return inv->items[idx].quantity;
}

void initCombatPlayerFromInventory(CombatPlayer *cp, const Inventory *inv) {
#ifdef _WIN32
    system("color 04");
#endif
    memset(cp, 0, sizeof(*cp));
    strncpy(cp->name, P.name, sizeof(cp->name)-1);

    cp->max_health = 80;
    cp->health_points = cp->max_health;

    cp->base_attack = 8;
    cp->base_defense = 1;

    cp->attack = cp->base_attack;
    cp->defense = cp->base_defense;

    cp->potion_count = invQuantity(inv, "Herbal Tonic");
    cp->damage_potion_count = invQuantity(inv, "Antidote Herbs");

    cp->damage_buff_mult = 1.0;
    cp->damage_stack_count = 0;
    for (int i = 0; i < MAX_DAMAGE_STACKS; i++)
        cp->damage_stack_timers[i] = 0;

    /* Equipment: interpret equipped item either as armor (Vine Shield) or weapon otherwise */
    int idx = inv->equippedIndex;
    if (idx >= 0 && idx < inv->count) {
        const char *ename = inv->items[idx].name;

        if (strCaseCmp(ename, "Vine Shield") == 0) {
            strncpy(cp->equipped_armor_name, ename, sizeof(cp->equipped_armor_name)-1);
            cp->defense += 8;
        } else {
            /* treat as weapon */
            strncpy(cp->equipped_weapon_name, ename, sizeof(cp->equipped_weapon_name)-1);
            if (strCaseCmp(ename, "Wooden Spear") == 0)
                cp->attack += 8;
            else if (strCaseCmp(ename, "Stone Hatchet") == 0)
                cp->attack += 18;
        }
    }
}

/* Show final stats on exit */
void showFinalStats(const Inventory *inv) {
    clearScreen();
    printf("===== FINAL STATS =====\n\n");

    /* Health */
    if (GLOBAL_REACHED_FINAL) {
        printf("Health (last recorded): %d\n", GLOBAL_LAST_PLAYER_HEALTH);
    } else {
        printf("Health (default max): %d\n", 80);
    }

    /* Gold */
    printf("Gold (Forest Tokens): %d\n", inv->gold);

    /* Key items secured: count how many of the current run's assigned relics exist in inventory */
    int secured_count = 0;
    for (int i = 0; i < PATHS; ++i) {
        if (assigned_items[i] && findItemIndex(inv, assigned_items[i]) != -1) secured_count++;
    }
    printf("Key relics secured: %d / %d\n", secured_count, PATHS);

    /* Items bought from shop */
    printf("Number of shop purchases: %d\n", GLOBAL_ITEMS_BOUGHT);

    /* Turns to defeat Guardian (if reached and defeated) */
    if (GLOBAL_REACHED_FINAL && GLOBAL_FINAL_VICTORY && GLOBAL_LAST_COMBAT_TURNS > 0) {
        printf("Turns to defeat Forest Guardian: %d\n", GLOBAL_LAST_COMBAT_TURNS);
    } else if (GLOBAL_REACHED_FINAL && !GLOBAL_FINAL_VICTORY && GLOBAL_LAST_COMBAT_TURNS > 0) {
        printf("Reached Final Grove but did not defeat Guardian. Turns in combat: %d\n", GLOBAL_LAST_COMBAT_TURNS);
    } else {
        printf("Turns to defeat Forest Guardian: N/A\n");
    }

    printf("\n========================\n");
    pauseReturn();
#ifdef _WIN32
    system("color 07");
#endif
}

/* Final Combat: modifies Inventory (consumes potions) and records globals */
int runFinalCombat(Inventory *inv) {

    CombatPlayer player;
    initCombatPlayerFromInventory(&player, inv);

    /* record that player reached final */
    GLOBAL_REACHED_FINAL = 1;
    GLOBAL_LAST_COMBAT_TURNS = 0;
    GLOBAL_LAST_PLAYER_HEALTH = 0;
    GLOBAL_FINAL_VICTORY = 0;

    CombatEnemy enemy;
    memset(&enemy,0,sizeof(enemy));
    strncpy(enemy.name,"Forest Guardian", sizeof(enemy.name)-1);

    enemy.max_health = 110;
    enemy.health = enemy.max_health;
    enemy.base_attack = 13;
    enemy.rage_active = 0;

    const int GLOBAL_CRIT_DENOM = 16;
    const double GLOBAL_CRIT_MULT = 1.5;

    double enemyCritMult = 1.5;
    int dodgeCooldown = 0;
    int turn = 1;

    printf("\n=== FINAL GROVE: The Forest Guardian Awaits ===\n");
    pauseReturn();
    clearScreen();

    while (player.health_points > 0 && enemy.health > 0) {

        if (dodgeCooldown > 0) --dodgeCooldown;

        if (!enemy.rage_active && enemy.health <= enemy.max_health / 2) {
            enemy.rage_active = 1;
            enemy.base_attack += 6;
            enemyCritMult = 1.75;
#ifdef _WIN32
           
#endif
            printf("*** The Forest Guardian enters RAGE! ***\n");
        }
#ifdef _WIN32
     
#endif
        printf("\n--- Turn %d ---\n", turn++);
        printf("You: %d/%d HP | Guardian: %d/%d HP\n",
               player.health_points, player.max_health,
               enemy.health, enemy.max_health);

        printf("1) Attack\n2)Defend\n3)Dodge");
        if (player.potion_count > 0)        printf("  4) Heal(%d)", player.potion_count);
        if (player.damage_potion_count > 0) printf("  5) Power(%d)", player.damage_potion_count);
        printf("\nChoose action: ");

        int action = 0;
        while (1) {
            if (!readInt(&action)) { printf("Invalid. Enter 1–5: "); continue; }
            if (action < 1 || action > 5)  { printf("Invalid. Enter 1–5: "); continue; }

            if (action == 4 && player.potion_count <= 0) {
                printf("You have no health potions. Choose again: ");
                continue;
            }
            if (action == 5 && player.damage_potion_count <= 0) {
                printf("You have no damage potions. Choose again: ");
                continue;
            }
            break;
        }

        /* Player Actions */

        if (action == 1) {
            int crit_denom = GLOBAL_CRIT_DENOM;
            double crit_mult = GLOBAL_CRIT_MULT;

            if (strCaseCmp(player.equipped_weapon_name, "Stone Hatchet") == 0) {
                crit_denom = 12;
                crit_mult = 1.5;
            }

            int base_roll_max = player.attack + 6;
            if (base_roll_max < 1) base_roll_max = 1;

            int raw = rand() % base_roll_max + 3;
            if (raw < 1) raw = 1;

            int dmg = (int)(raw * player.damage_buff_mult + 0.0001);

            if (rand() % crit_denom == 0) {
                dmg = (int)(dmg * crit_mult + 0.0001);
#ifdef _WIN32

#endif
                printf("CRITICAL HIT! ");
#ifdef _WIN32
                
#endif
            }

            enemy.health -= dmg;
            if (enemy.health < 0) enemy.health = 0;
#ifdef _WIN32

#endif
            printf("You deal %d damage.\n", dmg);
#ifdef _WIN32
           
#endif
        }

        else if (action == 2) {
            printf("You brace for impact.\n");

            if (strCaseCmp(player.equipped_armor_name, "Vine Shield") == 0) {
                int kb = 1 + rand() % 3;
                enemy.health -= kb;
                if (enemy.health < 0) enemy.health = 0;
                printf(" Vine Shield deals %d knockback!\n", kb);
            }
        }

        else if (action == 3) {
            if (dodgeCooldown == 0) {
                int chance = 40 + player.defense * 3;
                if (chance > 85) chance = 85;

                if (rand() % 100 < chance) {
                    printf("You dodged the attack!\n");
                    dodgeCooldown = 3;
                    goto skipEnemy;
                } else {
                    printf("Dodge failed!\n");
                    dodgeCooldown = 3;
                }
            } else {
                printf("Dodge cooldown: %d turns.\n", dodgeCooldown);
            }
        }

        else if (action == 4) {
            /* consume a Herbal Tonic from both combat and inventory */
            player.potion_count--;
            int idx = findItemIndex(inv, "Herbal Tonic");
            if (idx != -1) {
                inv->items[idx].quantity--;
                if (inv->items[idx].quantity <= 0) removeItem(inv, "Herbal Tonic");
            }
            player.health_points += 50;
            if (player.health_points > player.max_health)
                player.health_points = player.max_health;

            printf("[ITEM] +50 HP (Remaining tonics: %d)\n", player.potion_count);
        }

        else if (action == 5) {
            /* Only consume potion if there is room to stack */
            if (player.damage_stack_count >= MAX_DAMAGE_STACKS) {
                printf("Maximum stacks reached. You keep the potion.\n");
            } else {
                player.damage_potion_count--;
                int idx = findItemIndex(inv, "Antidote Herbs");
                if (idx != -1) {
                    inv->items[idx].quantity--;
                    if (inv->items[idx].quantity <= 0) removeItem(inv, "Antidote Herbs");
                }

                player.damage_stack_timers[player.damage_stack_count++] = 3;
                player.damage_buff_mult *= 1.25;
                printf("[ITEM] Damage buff stacked (+25%%) — Stacks: %d\n", player.damage_stack_count);
            }
        }

        /* Enemy Turn */

        {
            int dmg = rand() % (enemy.base_attack + 6) + 3;

            if (rand() % 16 == 0) {
                dmg = (int)(dmg * enemyCritMult + 0.0001);
#ifdef _WIN32
             
#endif
                printf("💀 Guardian CRITICAL! ");
#ifdef _WIN32
               
#endif
            } else {
                if (action == 2)
                    dmg = (dmg * 3) / 4;

                dmg -= (player.defense / 2);
                if (dmg < 1) dmg = 1;
            }

            player.health_points -= dmg;
            if (player.health_points < 0) player.health_points = 0;
#ifdef _WIN32
            
#endif
            printf("Guardian hits you for %d.\n", dmg);
#ifdef _WIN32
         
#endif
        }

        /* Skip enemy turn label */
        skipEnemy:

        /* decrement timers and expire stacks */
        for (int si = 0; si < player.damage_stack_count; si++)
            player.damage_stack_timers[si]--;

        int ii = 0;
        while (ii < player.damage_stack_count) {
            if (player.damage_stack_timers[ii] <= 0) {
                player.damage_buff_mult /= 1.25;

                for (int j = ii; j + 1 < player.damage_stack_count; j++)
                    player.damage_stack_timers[j] = player.damage_stack_timers[j + 1];

                player.damage_stack_count--;
            } else {
                ii++;
            }
        }

        /* continue combat loop */
    } /* combat loop */

    /* record final stats (turn - 1 is last completed turn) */
    GLOBAL_LAST_PLAYER_HEALTH = player.health_points;
    GLOBAL_LAST_COMBAT_TURNS = turn - 1;

    if (player.health_points <= 0) {
#ifdef _WIN32
       
#endif
        printf("\nYou were defeated...\n");

        GLOBAL_FINAL_VICTORY = 0;
        return 0;
    }
#ifdef _WIN32
  
#endif
    printf("\nYou defeated the Forest Guardian!\n");
    GLOBAL_FINAL_VICTORY = 1;
    return 1;
}

/* ----------------------------- MAIN ----------------------------- */

int main(void) {
    srand((unsigned int)time(NULL));

    displaySplashScreen();
#ifdef _WIN32
  system("color 02");
#endif
    /* simplified flow - displaySplashScreen already paused */
    clearScreen();
    
    printf("Hello Player!\n");
    pauseReturn();
    clearScreen();

    /* --- Clean nickname & age input block --- */
    printf("Enter your nickname:\n");
    if (!readLine(P.name, sizeof(P.name)) || P.name[0] == '\0') {
        strncpy(P.name, "Hero", sizeof(P.name));
        P.name[sizeof(P.name)-1] = '\0';
    }

    int ageval = 0;
    char ageBuf[LINEBUF];

    while (1) {
        printf("Enter your age (or press Enter to use default 18):\n");
        if (!readLine(ageBuf, sizeof(ageBuf))) {
            ageval = 18;
            break;
        }

        if (ageBuf[0] == '\0') {
            ageval = 18;
            break;
        }
        char *endptr = NULL;
        long v = strtol(ageBuf, &endptr, 10);
        if (endptr != ageBuf && *endptr == '\0' && v > 0 && v < 200) {
            ageval = (int)v;
            break;
        }

        printf("Invalid age. Please enter a positive number (or press Enter for default).\n");
    }

    P.age = ageval;
    clearScreen();

    printf("Player Information:\nName: %s\nAge : %d\n", P.name, P.age);
    pauseReturn();
    clearScreen();

    printf("Welcome wanderer!\n");
    printf("You went to sleep after having a great dinner at your house but to your surprise, you wake beneath a canopy of tangled vines and towering trees.\n");
    printf("The air thick with moss and mystery. The jungle surrounds you vast, ancient, and alive. Your memory is gone but your instincts remain.\n");
    pauseReturn();
    clearScreen();
    printf("Every sound could mean danger or discovery. Nature won't guide you. It only asks: will you adapt, or disappear?\n");
    printf("Find your way out through this ancient and dangerous forest, traversing through caves, dungeons, and various other hidden mysteries that lie ahead.\n");
    printf("GOAL:\nYour sole objective is to escape the forest alive.\n");
    pauseReturn();
    clearScreen();
#ifdef _WIN32
    system("color 07");
#endif
    showRules();

    Inventory playerInv = { .count = 0, .equippedIndex = -1, .gold = 300 };

    int (*sets[9])() = { set1, set2, set3, set4, set5, set6, set7, set8, set9 };

    int playAgain = 1;
    while (playAgain) {

        assignItemsToCaves();

        int indices[9];
        for (int i = 0; i < 9; ++i) indices[i] = i;
        shuffle_ints(indices, 9);

        clearScreen();
#ifdef _WIN32
        system("color 01");
#endif
        printf("Welcome to the Forest Caves, %s!\n\n", P.name);
        printf("Three mystical relics rest behind three caves:\n");
        for (int c = 0; c < PATHS; ++c) {
            printf("Cave %d: %s\n", c + 1, assigned_items[c]);
        }

        printf("\nBefore you enter a cave, open your satchel? (Y/N): ");
        char ch;
        if (!readChar(&ch)) ch = 'N';
        if (toupper((unsigned char)ch) == 'Y') openInventoryUI(&playerInv);

        printf("\nChoose a cave to challenge. Solve the puzzles (score 2/3) to claim its relic.\n\n");

        int completed[PATHS] = {0};
        int secured[PATHS] = {0};
        int total_completed = 0;

        while (total_completed < PATHS) {

            printf("Unexplored caves:\n");
            for (int c = 0; c < PATHS; ++c)
                if (!completed[c]) printf("  Cave %d\n", c + 1);

            int choice = 0;
            while (1) {
                printf("Choose your next cave (1-3): ");
                if (!readInt(&choice)) {
                    printf("Invalid input. Try again.\n");
                    continue;
                }
                if (choice < 1 || choice > 3) {
                    printf("Enter 1, 2 or 3.\n");
                    continue;
                }
                if (completed[choice - 1]) {
                    printf("That cave is already completed. Pick another.\n");
                    continue;
                }
                break;
            }

            clearScreen();

            int setIndex = indices[choice - 1];
            int score = sets[setIndex]();

            if (score >= 2) {
                printf("\nCongratulations, %s!\nYou earned the relic of Cave %d: %s\n",
                       P.name, choice, assigned_items[choice - 1]);
                secured[choice - 1] = 1;
                addItem(&playerInv, assigned_items[choice - 1], 1);
            } else {
                printf("\nYou scored %d/3.\nThe forest withholds the relic of Cave %d: %s\n",
                       score, choice, assigned_items[choice - 1]);
                secured[choice - 1] = 0;
            }

            completed[choice - 1] = 1;
            total_completed++;
            pauseReturn();
            clearScreen();

            printf("Open satchel now? (Y/N): ");
            char ic;
            if (readChar(&ic) && toupper((unsigned char)ic) == 'Y') {
                openInventoryUI(&playerInv);
            }
            clearScreen();
        }

        /* Summary */
        clearScreen();
        printf("All caves explored. Summary:\n");
        int all_secured = 1;
        for (int c = 0; c < PATHS; ++c) {
            printf("Cave %d - Relic: %s - %s\n", c + 1, assigned_items[c], secured[c] ? "Claimed" : "Missed");
            if (!secured[c]) all_secured = 0;
        }

        printf("\nHave you collected all 3 relics? (Y/N): ");
        char hasAll;
        if (!readChar(&hasAll)) hasAll = 'N';

        if (toupper((unsigned char)hasAll) == 'Y') {
            /* Verify inventory to avoid false claim */
            int missing = 0;
            for (int c = 0; c < PATHS; ++c) {
                if (findItemIndex(&playerInv, assigned_items[c]) == -1) {
                    missing = 1;
                    break;
                }
            }

            if (!missing) {
                printf("\nRelics verified. The Final Grove opens...\n");

                printf("do you want to trade the Forest tokens for tools and equip them before the final battle? (Y/N): ");
                char ic;
            if (readChar(&ic) && toupper((unsigned char)ic) == 'Y') {
                openInventoryUI(&playerInv);
            }
                clearScreen();
                pauseReturn();
                clearScreen();

                int combatResult = runFinalCombat(&playerInv);

                if (combatResult) {
                    printf("\nYou conquered the Forest Guardian and escaped the forest!\n");
                    displayInventory(&playerInv);
                    printf("\nThanks for playing, %s.\n", P.name);
                    /* show final stats before exit */
                    showFinalStats(&playerInv);
                    break; /* end game */
                } else {
                    /* Lost in final combat: retry or exit */
                    int opt = 0;
                    while (1) {
                        printf("\nYou were defeated. Try again?\n1) Retry from start\n2) Exit\nChoice: ");
                        if (!readInt(&opt)) { printf("Invalid.\n"); continue; }
                        if (opt == 1 || opt == 2) break;
                    }
                    if (opt == 2) {
                        printf("Thanks for playing, %s.\n", P.name);
                        showFinalStats(&playerInv);
                        break;
                    } else {
                        /* reset and play again */
                        clearScreen();
                        continue;
                    }
                }
            } else {
                printf("\nVerification failed: you don't have all relics in your satchel.\n");
                int opt = 0;
                while (1) {
                    printf("Try the forest again? 1) Yes  2) No : ");
                    if (!readInt(&opt)) { printf("Invalid.\n"); continue; }
                    if (opt == 1 || opt == 2) break;
                }
                if (opt == 2) { showFinalStats(&playerInv); playAgain = 0; break; }
                else { clearScreen(); continue; }
            }
        } else {
            printf("\nYou don't have all relics. The Final Grove remains closed.\n");
            int opt = 0;
            while (1) {
                printf("Would you like to retry the forest? 1) Yes  2) No : ");
                if (!readInt(&opt)) { printf("Invalid input.\n"); continue; }
                if (opt == 1 || opt == 2) break;
            }
            if (opt == 2) { showFinalStats(&playerInv); playAgain = 0; break; }
            else { clearScreen(); continue; }
        }
    } /* end playAgain */

    /* Show actual player's inventory and stats before final exit if not already shown */
    showFinalStats(&playerInv);

    printf("\nThe forest grows quiet. Farewell, %s.\n", P.name);
    return 0;
}