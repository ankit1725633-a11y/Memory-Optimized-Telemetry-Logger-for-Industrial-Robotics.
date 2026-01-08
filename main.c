#include <stdio.h>

#define MAX_LOGS 5

typedef struct {
    int id;
    float speed;
    int temperature;
    char status[10];
} RobotLog;

RobotLog blackBox[MAX_LOGS];
int head = 0;

void add_log(int id, float speed, int temp, char* stat) {
    blackBox[head].id = id;
    blackBox[head].speed = speed;
    blackBox[head].temperature = temp;
    
    for(int i = 0; i < 9; i++) {
        blackBox[head].status[i] = stat[i];
        if (stat[i] == '\0') break;
    }
    blackBox[head].status[9] = '\0';

    printf("Saving Log #%d... [Memory Index: %d]\n", id, head);
    head = (head + 1) % MAX_LOGS;
}

void crash_dump() {
    printf("\n!!! CRASH DETECTED - DUMPING RECENT HISTORY !!!\n");
    printf("----------------------------------------------\n");
    for (int i = 0; i < MAX_LOGS; i++) {
        printf("Log ID: %d | Speed: %.2f m/s | Temp: %d C | Status: %s\n", 
                blackBox[i].id, blackBox[i].speed, blackBox[i].temperature, blackBox[i].status);
    }
    printf("----------------------------------------------\n");
}

int main() {
    int id, temp;
    float speed;

    printf("--- Robot Telemetry Input ---\n");
    printf("Enter data as: [ID] [Speed] [Temp]\n");
    
    for(int i = 0; i < 6; i++) {
        printf("\nEnter Log Data (Entry %d/6): ", i + 1);
        if (scanf("%d %f %d", &id, &speed, &temp) != 3) {
            printf("Invalid input. Try again.\n");
            while(getchar() != '\n'); 
            i--;
            continue;
        }
        add_log(id, speed, temp, "ACTIVE");
    }

    crash_dump();
    return 0;
}