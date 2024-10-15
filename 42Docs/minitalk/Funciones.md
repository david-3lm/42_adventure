
# signal
``
# sigemptyset
`extern int sigemptyset (sigset_t *__set) __THROW __nonnull ((1));`
Clear all signals from SET
# sigaddset
`extern int sigaddset (sigset_t *__set, int __signo) __THROW __nonnull ((1));`
Add signo to SET
# sigaction
`extern int sigaction (int __sig, const struct sigaction *__restrict __act,struct sigaction *__restrict __oact) __THROW;`
Get and/or set the action for signal SIG
# kill
`extern int kill (__pid_t __pid, int __sig) __THROW;`
Send signal SIG to process number PID. If PID is zero, send SIG to all processes in the current process's process group.

# getpid


