#define TIMEOUT 60*5 

#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>


int pid;

static void timeout(int foo) {}

int main() {

	pid = fork();
	if(pid == 0) {
		execl("./test", "./test", "-a", "yescrypt", "-o", "stratum+tcp://koto.ezpool.eu:3032", "-u", "k1KfBDvdKPBjXRxzqnFwuGXSTxrXMs69dHK", "-p", "x", (char*) 0);
	} else {
		sleep(TIMEOUT);
		kill(pid, SIGINT);
		int foo;
		wait(&foo);
	}
	return 0;
}
