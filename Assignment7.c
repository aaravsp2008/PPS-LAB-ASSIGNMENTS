#include <stdio.h>
#include <string.h>

struct Robot {
    int id;
    char type[50];
    float capacity;
    float load;
    float operating_time;
    float load_utilization;
    char status[20];
};

int main() {
    int n, i;

    printf("Enter the number of robots: ");
    scanf("%d", &n);

    struct Robot r[n];

    for (i = 0; i < n; i++) {
        printf("\n--- Enter details for Robot %d ---\n", i + 1);
        
        printf("Robot ID: ");
        scanf("%d", &r[i].id);
        
        printf("Robot Type: ");
        scanf(" %[^\n]", r[i].type); 
        
        printf("Capacity: ");
        scanf("%f", &r[i].capacity);
        
        printf("Load: ");
        scanf("%f", &r[i].load);
        
        printf("Operating Time (hrs): ");
        scanf("%f", &r[i].operating_time);

        if (r[i].capacity > 0) {
            r[i].load_utilization = (r[i].load / r[i].capacity) * 100.0;
        } else {
            r[i].load_utilization = 0.0;
        }

        if (r[i].load > r[i].capacity) {
            strcpy(r[i].status, "Overload");
        } else {
            strcpy(r[i].status, "Within Limit");
        }
    }

    printf("\n========================================================================================================\n");
    printf("%-10s %-18s %-12s %-12s %-15s %-18s %-15s\n", 
           "Robot ID", "Type", "Capacity", "Load", "Op. Time", "Utilization (%)", "Status");
    printf("========================================================================================================\n");

    for (i = 0; i < n; i++) {
        printf("%-10d %-18s %-12.2f %-12.2f %-15.2f %-17.2f%% %-15s\n",
               r[i].id,
               r[i].type,
               r[i].capacity,
               r[i].load,
               r[i].operating_time,
               r[i].load_utilization,
               r[i].status);
    }
    printf("========================================================================================================\n");

    return 0;
}