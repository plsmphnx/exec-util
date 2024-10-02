# exec-util

This is a collection of utilities which exist to execute commands (via `execvp`)
under certain conditions with minimal overhead.

-   `exec-vt <vt> <cmd...>` - Wait until the specified VT is active, then exec
    the command. Note that this only works on TTYs.
-   `exec-after <cmd...> <join> [...]` - Exec the specified commands in order,
    using the joins (single character `;`, `&`, or `|`) to determine whether the
    next command should execute. If the last command is reached, it will replace
    the process.
-   `exec-repeat <join> <cmd...>` - Repeatedly exec the command according to the
    join (as above).
