#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// Soal F No 1

void trigger(int x) {
    printf("SIGABRT\n");
}


void sig_handler(int signum)
{
    printf("\nHasil CTRL C\n\n");
    sleep(1); 

    signal(SIGABRT, trigger);
    abort();
}



int main()
{

    signal(SIGINT, sig_handler);
    for (int i = 1;; i++)
    { 
        printf("Enter CTRL + C \n", i);
        sleep(1);
    }
    return 0;
}
