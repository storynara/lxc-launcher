#include <stdio.h>
#include <string.h>
#include <getopt.h>
#include <errno.h>

static int lxc_cmd_index = -1;

static const struct option lxc_cmd_options[] = {
	{ "start", required_argument, 0, 's' },
	{ "stop", required_argument, 0, 't' },
	{ "freeze", required_argument, 0, 'f' },
	{ "unfreeze", required_argument, 0, 'u' },
	{ "attach", required_argument, 0, 'a' },
	{ "execute", required_argument, 0, 'e' },
	{ 0, 0, 0, 0 }
};


extern int lxc_start_main(int argc, char *argv[]);




int main(int argc, char* const* argv) {
	int c;
	int option_index = 0;

	printf("init program...\n");

	while((c = getopt_long(argc, argv, "s:t:f:u:a:e:", lxc_cmd_options, &option_index)) != -1) {
		switch(c) {
			case 0:		// handle long options
				if (lxc_cmd_options[option_index].flag != 0)
					break;

				printf("option %s", lxc_cmd_options[option_index].name);
				if(optarg)
					printf(" with arg %s", optarg);
				printf("\n");

				break;
			case 's': 
				lxc_cmd_index = 0;
				printf("lxc command : start [-s or --start] - %d\n", lxc_cmd_index);
				// optarg => "-n devzone"
				// parse => one string "-n devzone"
				// ex) argc = 3, argv[0] = progname, argv[1] = -n, argv[2] = devzone
				break;
			case 't':
				lxc_cmd_index = 1;
				printf("lxc command : stop [-t or --stop] - %d\n", lxc_cmd_index);
				break;
			case 'f':
				lxc_cmd_index = 2;
				printf("lxc command : freeze [-f or --freeze] - %d\n", lxc_cmd_index);
				break;
			case 'u':
				lxc_cmd_index = 3;
				printf("lxc command : unfreeze [-u or --unfreeze] - %d\n", lxc_cmd_index);
				break;
			case 'a':
				lxc_cmd_index = 4;
				printf("lxc command : attach [-a or --attach] - %d\n", lxc_cmd_index);
				break;
			case 'e':
				lxc_cmd_index = 5;
				printf("lxc command : execute [-e or --execute] - %d\n", lxc_cmd_index);
				break;
			case '?':
				printf("Unknown flag : %c\n", optopt);
				break;
			default:
				break;
		}

		if (lxc_cmd_index != -1)
			break;
	}

	printf("lxc command index : %d\n", lxc_cmd_index);

	return 0;
}