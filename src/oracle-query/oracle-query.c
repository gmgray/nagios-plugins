#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
#include <unistd.h>
#include <getopt.h>

char *PROGRAM_VERSION = "1.0";
char *PROGRAM_NAME = "oraQuery";

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
    "   -q \"query text\"   SQL query to be executed\n"
    "   -h                show this help text\n"
    "   -v                verbose output, with parameters summary.\n"
    );
}

int main (int argc, char **argv)
{
    /* command line parameters initialized here. */
    /* this could be probably defined as struct, but well... */
    char *param_warning     = NULL;
    char *param_critical    = NULL;
    char *param_user        = NULL;
    char *param_password    = NULL;
    char *param_host        = NULL;
    char *param_sid         = NULL;
    int param_port          = 1521;
    char *param_query       = NULL;
    int param_help          = 0;
    int param_verbose       = 0;
    // char *param_help        = NULL; //
    /* end of command line parameters */
    int c;
    // int index;

    opterr = 0;

    /* loop thru cli arguments to evaluate parameters */
    // TODO: convert numeric values from string using strtol ()
    // https://codeforwin.org/2018/01/convert-string-to-long-using-strtol-c.html

    while ((c = getopt (argc, argv, "w: c: u: p: H: s: P: q: h v")) != -1)
        switch (c) 
        {
            case 'w':
                param_warning = optarg;
                break;
            case 'c':
                param_critical = optarg;
                break;
            case 'u':
                param_user = optarg;
                break;
            case 'p':
                param_password = optarg;
                break;
            case 'H':
                param_host = optarg;
                break;
            case 'h':
                print_help();
                param_help = 1;
                break;
            case 'v':
                param_verbose = 1;
                break;
            case 's':
                param_sid = optarg;
                break;
            case 'P':
                //if (strlen(optarg) > 0)
                    param_port = atoi(optarg);               
                break;
            case 'q':
                param_query = optarg;
                break;
            case '?':
                // check if all required options are passed with parameters
                if (optopt == 'c' || optopt =='w' || optopt =='H' || optopt == 'u' || optopt == 'p' || optopt == 'P')
                    fprintf (stderr, "Option -%c requires an argument.\n", optopt);                
                else if (isprint (optopt))
                    fprintf (stderr, "Unknown option `-%c'.\n", optopt);
                else
                    fprintf (stderr,
                            "Unknown option character `\\x%x'.\n",
                            optopt);
                return 1;
            default:
                abort ();
        }

        
    if (param_verbose == 1) {
        printf ("Verbose switch enabled.\n");
        printf ("Values used: \n");
        printf (" warning:  %s\n", param_warning);
        printf (" critical: %s\n", param_critical);
        printf (" host:     %s\n", param_host);
        printf (" sid:      %s\n", param_sid);
        printf (" port:     %d\n", param_port);
        printf (" username: %s\n", param_user);
        printf (" password: %s\n", param_password);
        printf (" query:    %s\n", param_query);
        printf (" verbose output enabled\n");
        if (param_help == 1) 
            printf (" help text enabled\n");
        else
            printf (" help text disabled\n");
    }
    

    // for (index = optind; index < argc; index++)
    //     printf ("Non-option argument %s\n", argv[index]);

    return 0;

}