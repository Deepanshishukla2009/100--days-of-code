#include <stdio.h>

// Define enum for traffic lights
enum TrafficLight { RED, YELLOW, GREEN };

int main() {
    // Example input
    enum TrafficLight signal = GREEN;

    // Print action based on traffic light value
    switch (signal) {
        case RED:
            printf("Stop\n");
            break;
        case YELLOW:
            printf("Wait\n");
            break;
        case GREEN:
            printf("Go\n");
            break;
        default:
            printf("Invalid signal\n");
    }

    return 0;
}