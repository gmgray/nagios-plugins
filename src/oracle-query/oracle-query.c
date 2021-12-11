#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include "oracle-query.h"

int main (int argc, char **argv)
{
    /* command line parameters initialized here. */
    
    cli_params params = {     
        .warning     = NULL,
        .critical    = NULL,
        .user        = NULL,
        .password    = NULL,
        .host        = NULL,
        .sid         = NULL,
        .port          = 1521,
        .query       = NULL,
        .help          = 0,
        .verbose       = 0};
    
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
                params.warning = optarg;
                break;
            case 'c':
                params.critical = optarg;
                break;
            case 'u':
                params.user = optarg;
                break;
            case 'p':
                params.password = optarg;
                break;
            case 'H':
                params.host = optarg;
                break;
            case 'h':
                print_help();
                params.help = 1;
                break;
            case 'v':
                params.verbose = 1;
                break;
            case 's':
                params.sid = optarg;
                break;
            case 'P':
                //if (strlen(optarg) > 0)
                    params.port = atoi(optarg);               
                break;
            case 'q':
                params.query = optarg;
                break;
            case '?':
                // check if all required options are passed with parameters
                if (
                        optopt =='c' || 
                        optopt =='w' || 
                        optopt =='H' || 
                        optopt =='u' || 
                        optopt =='p' || 
                        optopt =='P' ||
                        optopt =='s'
                    )
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

        
    if (params.verbose == 1) {
        printf ("Verbose switch enabled.\n");
        printf ("Values used: \n");
        printf (" warning:  %s\n", params.warning);
        printf (" critical: %s\n", params.critical);
        printf (" host:     %s\n", params.host);
        printf (" sid:      %s\n", params.sid);
        printf (" port:     %d\n", params.port);
        printf (" username: %s\n", params.user);
        printf (" password: %s\n", params.password);
        printf (" query:    %s\n", params.query);
        printf (" verbose output enabled\n");
        if (params.help == 1) 
            printf (" help text enabled\n");
        else
            printf (" help text disabled\n");
    }
    
    return 0;

}