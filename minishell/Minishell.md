# FUNCIONES PERMITIDAS MINISHELL


## readline
`char * readline (const char *prompt);`

     readline will read a line from the terminal and return it, using
       prompt as a prompt.  If prompt is NULL or the empty string, no
       prompt is issued.  The line returned is allocated with malloc(3);
       the caller must free it when finished.  The line returned has the
       final newline removed, so only the text of thev line remains. 
## rl_clear_history
`void rl_clear_history (void)`

	Clear the history list by deleting all of the entries, in the same manner as the History library’s clear_history() function. This differs from clear_history because it frees private data Readline saves in the history list. 
## rl_on_new_line 
`int rl_on_new_line (void)`

	Tell the update functions that we have moved onto a new (empty) line, usually after outputting a newline. 
## rl_replace_line
`void rl_replace_line (const char *text, int clear_undo)`

	Replace the contents of rl_line_buffer with text. The point and mark are preserved, if possible. If clear_undo is non-zero, the undo list associated with the current line is cleared.

## rl_redisplay
`void rl_redisplay (void)`

	Change what’s displayed on the screen to reflect the current contents of rl_line_buffer.

## add_history
`¿void? add_history (char * line);`

	Save a line in the history
## printf
`realmente?`

	No hace falta descripción
## malloc
`realmente?`

	No hace falta descripción
## free
`realmente?`

	No hace falta descripción
## write
`realmente?`

	No hace falta descripción
## open
`realmente?`

	No hace falta descripción
## read
`realmente?`

	No hace falta descripción
## close
`realmente?`

	No hace falta descripción
## access
`int access(const char *pathname, int mode);`

	access() checks whether the calling process can access the file
    pathname.  If pathname is a symbolic link, it is dereferenced.

	The mode specifies the accessibility check(s) to be performed,
    and is either the value F_OK, or a mask consisting of the bitwise
    OR of one or more of R_OK, W_OK, and X_OK.  F_OK tests for the
	file exists and grants read, write, and execute permissions,
	existence of the file.  R_OK, W_OK, and X_OK test whether the
	respectively.
## fork
`pid_t fork(void);`

	fork() creates a new process by duplicating the calling process.
	The new process is referred to as the child process.  The calling
	process is referred to as the parent process.
## wait
`pid_t wait(int *_Nullable wstatus);`

	The wait() system call suspends execution of the calling thread
    until one of its children terminates. 
## waitpid
`pid_t waitpid(pid_t pid, int *_Nullable wstatus, int options);`

	The waitpid() system call suspends execution of the calling
	thread until a child specified by pid argument has changed state.
	By default, waitpid() waits only for terminated children, but
	this behavior is modifiable via the options argument.
	
	pid:

       < -1   meaning wait for any child process whose process group ID
              is equal to the absolute value of pid.

       -1     meaning wait for any child process.

       0      meaning wait for any child process whose process group ID
              is equal to that of the calling process at the time of the
              call to waitpid().

       > 0    meaning wait for the child whose process ID is equal to
              the value of pid. 
	
	options:
	   
	   WNOHANG
              return immediately if no child has exited.

       WUNTRACED
              also return if a child has stopped (but not traced via
              ptrace(2)).  Status for traced children which have stopped
              is provided even if this option is not specified.

       WCONTINUED (since Linux 2.6.10)
              also return if a stopped child has been resumed by
              delivery of SIGCONT.

		WIFEXITED(wstatus)
              returns true if the child terminated normally, that is, by
              calling exit(3) or _exit(2), or by returning from main().

       WEXITSTATUS(wstatus)
              returns the exit status of the child.  This consists of
              the least significant 8 bits of the status argument that
              the child specified in a call to exit(3) or _exit(2) or as
              the argument for a return statement in main().  This macro
              should be employed only if WIFEXITED returned true.

       WIFSIGNALED(wstatus)
              returns true if the child process was terminated by a
              signal.

       WTERMSIG(wstatus)
              returns the number of the signal that caused the child
              process to terminate.  This macro should be employed only
              if WIFSIGNALED returned true.

       WCOREDUMP(wstatus)
              returns true if the child produced a core dump (see
              core(5)).  This macro should be employed only if
              WIFSIGNALED returned true.

              This macro is not specified in POSIX.1-2001 and is not
              available on some UNIX implementations (e.g., AIX, SunOS).
              Therefore, enclose its use inside #ifdef WCOREDUMP ...
              #endif.

       WIFSTOPPED(wstatus)
              returns true if the child process was stopped by delivery
              of a signal; this is possible only if the call was done
              using WUNTRACED or when the child is being traced (see
              ptrace(2)).

       WSTOPSIG(wstatus)
              returns the number of the signal which caused the child to
              stop.  This macro should be employed only if WIFSTOPPED
              returned true.

       WIFCONTINUED(wstatus)
              (since Linux 2.6.10) returns true if the child process was
              resumed by delivery of SIGCONT.
## wait3
`pid_t wait3(int *stat_loc, int options, struct rusage *rusage);`

	Obsolete => use waitpid()
## wait4
`pid_t wait4(pid_t pid, int *stat_loc, int options, struct rusage *rusage);`

	Obsolete => use waitpid()
## signal
`sighandler_t signal(int signum, sighandler_t handler);`

	signal() sets the disposition of the signal signum to handler,
	which is either SIG_IGN, SIG_DFL, or the address of a programmer-
	defined function (a "signal handler").
## sigaction
`int sigaction(int signum,
                     const struct sigaction *_Nullable restrict act,
                     struct sigaction *_Nullable restrict oldact);`

	The sigaction() system call is used to change the action taken by
	a process on receipt of a specific signal. 
## kill
`int kill(pid_t pid, int sig);`

	The kill() system call can be used to send any signal to any
	process group or process.
## exit
`exit`

	Exit the program
## getcwd
`char *getcwd(char buf[.size], size_t size);`

	The getcwd() function copies an absolute pathname of the current
	working directory to the array pointed to by buf, which is of
	length size.
## chdir
`int chdir(const char *path);`

	chdir() changes the current working directory of the calling
	process to the directory specified in path.
## stat
`int stat(const char *path, struct stat *buf);`

	Stats the file pointed to by path and fills in buf.
## lstat
`int lstat(const char *path, struct stat *buf);`

	Identical to stat(), except that if path is a symbolic link, then the link itself is stat-ed, not the file that it refers to.
## fstat
`int fstat(int fd, struct stat *buf);`

	Is identical to stat(), except that the file to be stat-ed is specified by the file descriptor fd.
## unlink
`int unlink(const char *pathname);`

	unlink() deletes a name from the file system.
## execve
`int execve(const char *pathname, char *const _Nullable argv[],
                  char *const _Nullable envp[]);`

	execve() executes the program referred to by pathname.  This
	causes the program that is currently being run by the calling
	process to be replaced with a new program, with newly initialized
	stack, heap, and (initialized and uninitialized) data segments.
## dup
`int dup(int oldfd);`

	The dup() system call allocates a new file descriptor that refers
	to the same open file description as the descriptor oldfd.
## dup2
`int dup2(int oldfd, int newfd);`

	The dup2() system call performs the same task as dup(), but
	instead of using the lowest-numbered unused file descriptor, it
	uses the file descriptor number specified in newfd.  In other
	words, the file descriptor newfd is adjusted so that it now
	refers to the same open file description as oldfd. 
## pipe
`int pipe(int pipefd[2]);`

	pipe() creates a pipe, a unidirectional data channel that can be
    used for interprocess communication. 
## opendir
`DIR *opendir(const char *name);`

	The opendir() function opens a directory stream corresponding to the directory name, and returns a pointer to the directory stream. The stream is positioned at the first entry in the directory. 
## readdir
`int readdir_r(DIR *dirp, struct dirent *entry, struct dirent **result);`

	The readdir() function returns a pointer to a dirent structure representing the next directory entry in the directory stream pointed to by dirp. It returns NULL on reaching the end of the directory stream or if an error occurred.
## closedir
`int closedir(DIR *dirp);`

	The closedir() function closes the directory stream associated with dirp. A successful call to closedir() also closes the underlying file descriptor associated with dirp. The directory stream descriptor dirp is not available after this call.
 
## strerror
`char *strerror(int errnum);`

	The strerror() function returns a pointer to a string that
	describes the error code passed in the argument errnum, possibly
	using the LC_MESSAGES part of the current locale to select the
	appropriate language. 
## perror
`void perror(const char *s);`

	The routine perror() produces a message on the standard error output, describing the last error encountered during a call to a system or library function. 
## isatty
`int isatty(int fd);`

	isatty() returns 1 if fd is an open file descriptor referring to a terminal; otherwise 0 is returned, and errno is set to indicate the error. 
## ttyname
`char *ttyname(int fd);int ttyname_r(int fd, char *buf, size_t buflen);`

	The function ttyname() returns a pointer to the null-terminated pathname of the terminal device that is open on the file descriptor fd, or NULL on error (for example, if fd is not connected to a terminal). 
## ttyslot
`int ttyslot(void);`

	The legacy function ttyslot() returns the index of the current user's entry in some file. If successful, this function returns the slot number. On error (e.g., if none of the file descriptors 0, 1 or 2 is associated with a terminal that occurs in this data base) it returns 0 on UNIX V6 and V7 and BSD-like systems, but -1 on System V-like systems.
## ioctl
`int ioctl(int d, int request, ...);`

	The ioctl() function manipulates the underlying device parameters of special files. In particular, many operating characteristics of character special files (e.g., terminals) may be controlled with ioctl() requests. The argument d must be an open file descriptor. 
## getenv
`char *getenv(const char *name);`

	The getenv() function searches the environment list to find the environment variable name, and returns a pointer to the corresponding value string. 
## tcsetattr
`int tcsetattr(int fd, int optional_actions,
              const struct termios *termios_p);`

	tcsetattr() sets the parameters associated with the terminal (unless support is required from the underlying hardware that is not available) from the termios structure referred to by termios_p. 
## tcgetattr
`int tcgetattr(int fd, struct termios *termios_p);`

	tcgetattr() gets the parameters associated with the object referred by fd and stores them in the termios structure referenced by termios_p. This function may be invoked from a background process; however, the terminal attributes may be subsequently changed by a foreground process. 
## tgetent
`int tgetent(char *bp, const char *name);`

	The tgetent routine loads the entry for name. It returns 1 on success, 0 if there is no such entry, and -1 if the terminfo database could not be found. The emulation ignores the buffer pointer bp.
 
## tgetflag
`int tgetflag(char *id);`

	The tgetflag routine gets the boolean entry for id, or zero if it is not available. 
## tgetnum
`int tgetnum(char *id);`

	The tgetnum routine gets the numeric entry for id, or -1 if it is not available. 
## tgetstr
`char *tgetstr(char *id, char **area);`

	The tgetstr routine returns the string entry for id, or zero if it is not available. Use tputs to output the returned string. The return value will also be copied to the buffer pointed to by area, and the area value will be updated to point past the null ending this value.
 
## tgoto
`char *tgoto(const char *cap, int col, int row);`

	The tgoto routine instantiates the parameters into the given capability. The output from this routine is to be passed to tputs. 
## tputs
`int tputs(const char *str, int affcnt, int (*putc)(int));`

	The tputs routine is described on the curs_terminfo(3X) manual page. It can retrieve capabilities by either termcap or terminfo name. 