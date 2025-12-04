#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
    int sleep_ticks;

    // Check if exactly one argument was provided (the program name is argv[0])
    if(argc < 2){
        // Write an error message to file descriptor 2 (stderr)
        fprintf(2, "Usage: sleep <number_of_ticks>\n");
        exit(1);
    }

    // Use atoi (ASCII to Integer) from user/user.h to convert the string argument
    sleep_ticks = atoi(argv[1]);

    if (sleep_ticks <= 0) {
        fprintf(2, "Error: Ticks must be a positive number.\n");
        exit(1);
    }
    
    // Call the sleep system call with the parsed integer value
    sleep(sleep_ticks);

    exit(0);
}