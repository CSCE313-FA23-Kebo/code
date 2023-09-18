/*
Example of signal sets and sigprocmask
Block and unblock signals
*/

#include "apue.h"

#include <signal.h>
#include <stdio.h>

int main() {
  sigset_t new_mask, old_mask;

  // Initialize the new signal mask.
  sigemptyset(&new_mask);
  sigaddset(&new_mask, SIGINT);

  // blocks the signals in the new_mask set and returns the old signal mask in the old_mask variable.
  sigprocmask(SIG_BLOCK, &new_mask, &old_mask);

  // Print a message.
  printf("SIGINT is blocked.\n");

  // Sleep for 5 seconds.
  sleep(5);

  printf("Before restore\n");
  // Restore the old signal mask.
  sigprocmask(SIG_SETMASK, &old_mask, NULL);

  // Print a message.
  printf("All signals are unblocked.\n");

  return 0;
}
