#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/utsname.h>
#include <unistd.h>
#include <errno.h>


int main(int argc, char** argv) {
	char name[1024];
	if (gethostname(name, 255) == 0) printf("Host name:%s\n", name);
	struct utsname sname;
	if (uname(&sname) < 0) {
		printf("uname() err\n");
	}
	else {
		printf("Name OS: %s\nUsername: %s\nReleas: %s\nVersion: %s\nMachine: %s\n",
			sname.sysname, sname.nodename,
			sname.release, sname.version,
			sname.machine);
	}

	printf("ID: %ld\n", gethostid());
	return 0;
}
