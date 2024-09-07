#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <dirent.h>
#include <string.h>

#define PROC_STAT_PATH "/proc/stat"

float cpu_usage() {

	FILE *file;

	unsigned long long int total_user, total_user_low, total_sys, total_idle, total_iowait, total_irq, total_softirq, total_steal;
	static unsigned long long int last_total_user, last_total_user_low, last_total_sys, last_total_idle, last_total_iowait, last_total_irq, last_total_softirq, last_total_steal;
	unsigned long long int total, total_diff;
	float percent;

	file = fopen("/proc/stat", "r");

	if (file == NULL) {
	
		perror("fopen");
		return -1;
	}

	fscanf(file, "cpu %llu %llu %llu %llu %llu %llu %llu %llu", &total_user, &total_user_low, &total_sys, &total_idle, &total_iowait, &total_irq, &total_softirq, &total_steal);
	fclose(file);

	total = (total_user - last_total_user) + (total_user_low - last_total_user_low) +
		(total_sys - last_total_sys) + (total_iowait - last_total_iowait) + 
		(total_irq - last_total_irq) + (total_softirq - last_total_softirq) + 
		(total_steal - last_total_steal);

	total_diff = total + (total_idle - last_total_idle);

	if (total_diff == 0) {
	
		percent = 0.0;
	}
       
	else {

		percent = (total * 100.0) / total_diff;
	}

	last_total_user = total_user;
	last_total_user_low = total_user_low;
	last_total_sys = total_sys;
	last_total_idle = total_idle;
	last_total_iowait = total_iowait;
	last_total_irq = total_irq;
	last_total_softirq = total_softirq;
	last_total_steal = total_steal;

	return percent;
}

int main() {

	struct sysinfo info;

	while(1) {

		if(sysinfo(&info) != 0) {

			perror("sysinfo");
			return -1;
		}

		float cpu = cpu_usage();
		long t_ram = info.totalram / 1024 / 1024;
		long f_ram = info.freeram / 1024 / 1024;
		long u_ram = t_ram - f_ram;
		long t_swp = info.totalswap / 1024 / 1024;
		long u_swp = info.freeswap / 1024 / 1024;
		long f_swp = t_swp - u_swp;

		printf("\033[H\033[J");
		printf("CPU Usage : %.2f\%%\n", cpu);
		printf("Total RAM : %ld MB | Used RAM : %ld MB | Free RAM : %ld MB\n", t_ram, u_ram, f_ram);
		printf("Total SWP : %ld MB | Used SWP : %ld MB | Free SWP : %ld MB\n", t_swp, u_swp, f_swp);

		fflush(stdout); 

		sleep(1.2);  
	}

	return 0;
}


