#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void check_mask( int sig, char *signame ) {

    sigset_t sigset;

    sigprocmask( SIG_SETMASK, NULL, &sigset );
    if( sigismember( &sigset, sig ) )
        printf( "the %s signal is blocked\n", signame );
    else
        printf( "the %s signal is unblocked\n", signame );
}

void catcher( int sig ) {

    printf( "inside catcher() function\n" );
    check_mask( SIGUSR1, "SIGUSR1" );
    check_mask( SIGUSR2, "SIGUSR2" );
}

int main(int argc, char *argv[]) {

    struct sigaction sigact, old_sigact;
    sigset_t sigset; // sigset_t is an unsigned int pretty much


   /*
    * Set up an American National Standard C style signal handler
    * by setting the signal mask to the empty signal set and
    * using the do-not-defer signal, and reset the signal handler
    * to the SIG_DFL signal flag options.
    */

    sigemptyset( &sigact.sa_mask ); // is this line even necesary in this case? Probably just a good practice
    sigact.sa_flags = 0;
    sigact.sa_flags = sigact.sa_flags | SA_NODEFER | SA_RESETHAND;
    // printf("%d\n", sigact.sa_flags);
    sigact.sa_handler = catcher;
    sigaction( SIGUSR1, &sigact, NULL );  // The sigaction() system call assigns an action for a signal specified by sig.

   /*
    * Send a signal to this program by using
    *    kill(getpid(), SIGUSR1)
    * which is the equivalent of the American
    * National Standard C raise(SIGUSR1)
    * function call.
    */

    printf( "raise SIGUSR1 signal\n" );
    kill( getpid(), SIGUSR1 );

   /*
    * Get the current value of the signal handling action for
    * SIGUSR1.  The signal-catching function should have been
    * reset to SIG_DFL
    */

    sigaction( SIGUSR1, NULL, &old_sigact ); // Transferring the configuration of sigact to oldact (not sure why still)
    // printf("Old sigact mask : %u\n", old_sigact.sa_mask);
    // printf("Old sigact flags: %d\n", sigact.sa_flags);
    if ( old_sigact.sa_handler != SIG_DFL )
        printf( "signal handler was not reset\n" );

   /*
    * Reset the signal-handling action for SIGUSR1
    */

    sigemptyset( &sigact.sa_mask );
    sigaddset( &sigact.sa_mask, SIGUSR2 );
    sigact.sa_flags = 0;
    sigact.sa_handler = catcher;
    sigaction( SIGUSR1, &sigact, NULL );

    printf( "raise SIGUSR1 signal\n" );
    kill( getpid(), SIGUSR1 );

   /*
    * Get the current value of the signal-handling action for
    * SIGUSR1.  catcher() should still be the signal catching
    * function.
    */

    sigaction( SIGUSR1, NULL, &old_sigact );
    if( old_sigact.sa_handler != catcher )
        printf( "signal handler was reset\n" );

    return( 0 );

}