/*
 * Drone Fleet Management System
 * Names: Shamail Khan and Tony Le
 * Variation 1A: Basic Console Menu
 * Variation 2A: Enhanced Search
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // for strcasecmp()

#define MAX_FLEET 100
#define MAX_LEN 30

// Arrays
int ids[MAX_FLEET];
char models[MAX_FLEET][MAX_LEN];
float batteries[MAX_FLEET];
float positions[MAX_FLEET][2];
char modelName[MAX_LEN];
int droneCount = 0;

void addDrone(void)
{
    if (droneCount >= MAX_FLEET)
    {
        printf("Fleet is full! Cannot add more drones.\n");
        return;
    }

    int id;
    char model[MAX_LEN];
    float battery, x, y;

    printf("Enter Drone ID (Positive Integer): ");
    if (scanf("%d", &id) != 1)
    {
        printf("Invalid input for ID.\n");
        // clear stdin
        int c;
        while ((c = getchar()) != '\n' && c != EOF)
        {
        }
        return;
    }
    if (id <= 0)
    {
        printf("Invalid ID! Must be a positive integer.\n");
        return;
    }

    printf("Enter Drone Model: ");
    if (scanf("%29s", model) != 1)
    {
        printf("Invalid input for model.\n");
        return;
    }

    printf("Enter Battery Level (0-100): ");
    if (scanf("%f", &battery) != 1)
    {
        printf("Invalid input for battery.\n");
        return;
    }
    if (battery < 0 || battery > 100)
    {
        printf("Invalid Battery Level! Must be between 0 and 100.\n");
        return;
    }

    printf("Enter Current Position (x y): ");
    if (scanf("%f %f", &x, &y) != 2)
    {
        printf("Invalid input for position.\n");
        return;
    }

    ids[droneCount] = id;
    strcpy(models[droneCount], model);
    batteries[droneCount] = battery;
    positions[droneCount][0] = x;
    positions[droneCount][1] = y;

    droneCount++;
    printf("Drone added successfully!\n");
}

void displayDrones(void)
{
    printf("\n%-5s | %-15s | %-8s | %-6s | %-6s\n", "ID", "Model", "Battery", "X", "Y");
    printf("----------------------------------------------------------\n");
    for (int i = 0; i < droneCount; i++)
    {
        printf("%-5d | %-15s | %-8.1f | %-6.2f | %-6.2f\n",
               ids[i], models[i], batteries[i], positions[i][0], positions[i][1]);
    }
}

//"searchDronebyID" retrieves a drone by entering its ID.
// This function works by looping through the array of IDs until it finds a match.
void searchDroneByID(int id)
{
    int inFleet = 0;
    int fleetPosition;
    for (int i = 0; i < MAX_FLEET; i++)
    {
        if (ids[i] == id)
        {
            inFleet = inFleet + 1;
            fleetPosition = i;
        }
    }

    if (inFleet == 1)
    {
        printf("\n%-5s | %-15s | %-8s | %-6s | %-6s\n", "ID", "Model", "Battery", "X", "Y");
        printf("----------------------------------------------------------\n");
        printf("%-5d | %-15s | %-8.1f | %-6.2f | %-6.2f\n",
               id, models[fleetPosition], batteries[fleetPosition], positions[fleetPosition][0], positions[fleetPosition][1]);
    }
    else

        printf("Drone not found.");
}

//"calculateAverageBattery" calculates the average battery of all the drones.
// This function works by finding the sum of the battery array and then dividing that value by the total number of drones.
void calculateAverageBattery(void)
{
    float sumBatteries = 0;
    if (droneCount > 0)
    {
        for (int i = 0; i < droneCount; i++)
        {
            sumBatteries += batteries[i];
        }
        printf("Average Battery Level: %.2f%%\n", sumBatteries / droneCount);
    }
    else
        printf("No drones available.\n");
}

//"searchDroneByModelName" retrieves a drone by entering its Model Name.
//This function works by looping through the array of models until there is a match.
void searchDroneByModelName(void)
{
    int inFleet = 0;
    int fleetPosition = 0;
    for (int i = 0; i < MAX_FLEET; i++)
    {
        if (strcasecmp((models[i]), (modelName)) == 0)
        {
            inFleet = inFleet + 1;
            fleetPosition = i;
            break;
        }
    }

    if (inFleet == 1)
    {
        printf("\n%-5s | %-15s | %-8s | %-6s | %-6s\n", "ID", "Model", "Battery", "X", "Y");
        printf("----------------------------------------------------------\n");
        printf("%-5d | %-15s | %-8.1f | %-6.2f | %-6.2f\n",
               ids[fleetPosition], models[fleetPosition], batteries[fleetPosition], positions[fleetPosition][0], positions[fleetPosition][1]);

    }

    else

        printf("Drone not found.\n");
}

int main(void)
{
    int id;
    int choice;

    while (1)
    {
        printf("\n1. Add Drone\n2. Display Drones\n3. Search by ID\n4. Search by Model Name\n5. Show average battery\n6. Exit\nEnter choice: ");
        scanf("%d", &choice);
        if (choice == 1)
            addDrone();
        else if (choice == 2)
            displayDrones();

        else if (choice == 3)
        {
            printf("Enter Drone ID: ");
            scanf("%d", &id);
            searchDroneByID(id);
        }
        else if (choice == 4)
        {
            printf("Enter Drone Model Name: ");
            scanf("%29s", modelName);
            searchDroneByModelName();
        }
        else if (choice == 5)
        {
            calculateAverageBattery();
        }

        else if (choice == 6)
        {
            printf("Exiting program.\n");
            break;
        }
        else
            printf("Invalid choice! Please try again.\n");
    }
    return 0;
}
