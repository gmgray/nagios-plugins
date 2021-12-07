#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

int main (int argc, char **argv)
{
    /* command line parameters initialized here. */
    /* this could be probably defined as struct, but well... */
    char *param_warning      = NULL;
    char *param_critical    = NULL;
    char *param_user        = NULL;
    char *param_password    = NULL;
    char *param_host        = NULL;
    char *param_sid         = NULL;
    int param_port          = 1521;
    char *param_query       = NULL;
    char *param_help        = NULL;
    /* end of command line parameters */
    int c;
    int index;

    opterr = 0;

    /* loop thru cli arguments to evaluate parameters */
    // TODO: convert numeric values from string using strtol ()
    // https://codeforwin.org/2018/01/convert-string-to-long-using-strtol-c.html

    while ((c = getopt (argc, argv, "w:c:u:p:H:S:P:q:h:")) != -1)
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
            case 'S':
                param_sid = optarg;
                break;
            case 'P':
                param_port = atoi(optarg);
                break;
            case 'q':
                param_query = optarg;
                break;
            case '?':
        if (optopt == 'c')
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

    printf ("Values used: \n");
    printf (" warning:  %s\n", param_warning);
    printf (" critical: %s\n", param_critical);
    printf (" host:     %s\n", param_host);
    printf (" sid:      %s\n", param_sid);
    printf (" port:     %d\n", param_port);
    printf (" username: %s\n", param_user);
    printf (" password: %s\n", param_password);
    printf (" query:    %s\n", param_query);

    for (index = optind; index < argc; index++)
        printf ("Non-option argument %s\n", argv[index]);

    return 0;

}