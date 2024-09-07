#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void print_cpu_clock_speed() {
    FILE *fp;
    char buffer[1024];
    char *match;

    fp = fopen("/proc/cpuinfo", "r");
    if (fp == NULL) {
        perror("Failed to read /proc/cpuinfo");
        return;
    }

    while (fgets(buffer, sizeof(buffer), fp)) {
        if ((match = strstr(buffer, "cpu MHz")) != NULL) {
            printf("CPU Clock Speed: %s", match);
            break;
        }
    }

    fclose(fp);
}

void print_ram_speed() {
    printf("RAM Speed (use `sudo dmidecode --type memory` for detailed output):\n");
    system("sudo dmidecode --type memory | grep 'Speed'");
}

void print_internet_speed() {
    printf("\nRunning speedtest...\n");
    system("speedtest-cli --simple");
}

int main() {
    while (1) {
        system("clear"); // Clears the screen for updating info live

        print_cpu_clock_speed();
        printf("\n");

        print_ram_speed();
        printf("\n");

        print_internet_speed();

        sleep(1); // Wait for 60 seconds before the next update
    }

    return 0;
}

