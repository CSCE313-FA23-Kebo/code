/*
In this example, both SIGINT and SIGTERM signals are added to the current signal mask, effectively blocking them.
*/
sigset_t new_set;
sigemptyset(&new_set);
sigaddset(&new_set, SIGINT);
sigaddset(&new_set, SIGTERM);
sigprocmask(SIG_BLOCK, &new_set, NULL);

/*
In this example, both SIGINT and SIGTERM signals are removed from the current signal mask, allowing them to be delivered.
*/
sigset_t new_set;
sigemptyset(&new_set);
sigaddset(&new_set, SIGINT);
sigaddset(&new_set, SIGTERM);
sigprocmask(SIG_UNBLOCK, &new_set, NULL);

/*
In this example, the current signal mask is replaced with a new signal mask containing only the SIGUSR1 and SIGUSR2 signals.
*/
sigset_t new_set;
sigemptyset(&new_set);
sigaddset(&new_set, SIGUSR1);
sigaddset(&new_set, SIGUSR2);
sigprocmask(SIG_SETMASK, &new_set, NULL);

