
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Structure to store agricultural sensor data
struct FieldData {
    int fieldID;
    float soilMoisture;
    float temperature;
    float humidity;
    float cropHealth;
    double latitude;
    double longitude;
};

// Function to collect sensor data
void collectData(struct FieldData data[], int n) {
    int i;

    for (i = 0; i < n; i++) {
        printf("\nEnter details for Field %d\n", i + 1);

        data[i].fieldID = i + 1;

        printf("Soil Moisture (%%): ");
        scanf("%f", &data[i].soilMoisture);

        printf("Temperature (C): ");
        scanf("%f", &data[i].temperature);

        printf("Humidity (%%): ");
        scanf("%f", &data[i].humidity);

        printf("Crop Health (0-100): ");
        scanf("%f", &data[i].cropHealth);

        printf("GPS Latitude: ");
        scanf("%lf", &data[i].latitude);

        printf("GPS Longitude: ");
        scanf("%lf", &data[i].longitude);
    }
}

// Function to save data in a file
void saveData(struct FieldData data[], int n) {
    FILE *fp = fopen("field_data.txt", "w");

    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d %.2f %.2f %.2f %.2f %.6lf %.6lf\n",
                data[i].fieldID,
                data[i].soilMoisture,
                data[i].temperature,
                data[i].humidity,
                data[i].cropHealth,
                data[i].latitude,
                data[i].longitude);
    }

    fclose(fp);
    printf("\nData successfully saved!\n");
}

// Function to read stored data
int readData(struct FieldData data[]) {
    FILE *fp = fopen("field_data.txt", "r");

    int count = 0;

    if (fp == NULL) {
        printf("No stored data found!\n");
        return 0;
    }

    while (count < MAX &&
           fscanf(fp, "%d %f %f %f %f %lf %lf",
                  &data[count].fieldID,
                  &data[count].soilMoisture,
                  &data[count].temperature,
                  &data[count].humidity,
                  &data[count].cropHealth,
                  &data[count].latitude,
                  &data[count].longitude) == 7) {
        count++;
    }

    fclose(fp);
    return count;
}

// Function to analyze irrigation requirements
void checkIrrigation(struct FieldData d) {
    if (d.soilMoisture < 30) {
        printf("Irrigation Required");
    }
    else if (d.soilMoisture < 50) {
        printf("Soil Moisture is Low - Monitor");
    }
    else {
        printf("Irrigation Not Required");
    }
}

// Function to generate field monitoring report
void generateReport(struct FieldData data[], int n) {
    float totalMoisture = 0;
    int irrigationCount = 0;

    printf("\n========== FIELD MONITORING REPORT ==========\n");

    for (int i = 0; i < n; i++) {
        printf("\nField ID: %d\n", data[i].fieldID);

        printf("Soil Moisture: %.2f%%\n",
               data[i].soilMoisture);

        printf("Temperature: %.2f C\n",
               data[i].temperature);

        printf("Humidity: %.2f%%\n",
               data[i].humidity);

        printf("Crop Health: %.2f%%\n",
               data[i].cropHealth);

        printf("GPS Coordinates: %.6lf, %.6lf\n",
               data[i].latitude,
               data[i].longitude);

        printf("Irrigation Status: ");
        checkIrrigation(data[i]);

        if (data[i].soilMoisture < 30)
            irrigationCount++;

        totalMoisture += data[i].soilMoisture;

        printf("\n---------------------------------------------\n");
    }

    if (n > 0) {
        printf("\nTotal Fields Monitored: %d\n", n);
        printf("Average Soil Moisture: %.2f%%\n",
               totalMoisture / n);

        printf("Fields Requiring Irrigation: %d\n",
               irrigationCount);

        printf("Fields Not Requiring Immediate Irrigation: %d\n",
               n - irrigationCount);
    }

    printf("\n========== REPORT COMPLETED ================\n");
}

// Main function
int main() {
    struct FieldData data[MAX];
    int n, choice, count;

    while (1) {
        printf("\n\n===== SMART AGRICULTURE MONITORING SYSTEM =====\n");
        printf("1. Collect Sensor Data\n");
        printf("2. Save Sensor Data\n");
        printf("3. Read Stored Data\n");
        printf("4. Generate Field Monitoring Report\n");
        printf("5. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter number of fields to monitor: ");
                scanf("%d", &n);

                if (n < 1 || n > MAX) {
                    printf("Invalid number of fields!\n");
                    break;
                }

                collectData(data, n);
                break;

            case 2:
                if (n > 0)
                    saveData(data, n);
                else
                    printf("Please collect data first!\n");
                break;

            case 3:
                count = readData(data);

                printf("\nStored data loaded: %d records\n", count);
                break;

            case 4:
                count = readData(data);

                if (count > 0)
                    generateReport(data, count);
                else
                    printf("No data available for report!\n");
                break;

            case 5:
                printf("Exiting Smart Agriculture System...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

