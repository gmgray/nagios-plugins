#include <stdio.h>
// Program level constants definitions

const char* PROGRAM_VERSION = "1.0";
const char* PROGRAM_NAME    = "oraQuery";


// structure cli_params holds commandline options
typedef struct  {
    char *warning ;
    char *critical;
    char *user;
    char *password;
    char *host;
    char *sid;
    int port;
    char *query;
    int help;
    int verbose;
} cli_params;

// utility functions

void print_help() {
    printf("Nagios plugin %s ver. %s \n", PROGRAM_NAME,PROGRAM_VERSION);    
    printf("Usage: \n");
    printf(""
    "   -w <int>          warning level\n"
    "   -c <int>          critical level\n"
    "   -u <user>         database user\n"
    "   -p <password>     database password\n"
    "   -H <hostname>     database hostname\n"
    "   -P <1521>         database port (default 1521 if not set)\n"
    "   -s <sid>          database SID\n"
    "   -q \"query text\"   SQL query to be execu ted\n"
    "   -h                show this help text\n"
    "   -v                verbose output, with parameters summary.\n"
    );
}