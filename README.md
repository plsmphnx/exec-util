# exec-util

This is a collection of utilities which exist to execute commands (via `execvp`)
under certain conditions with minimal overhead.

-   `exec-vt <vt> <cmd...>` - Wait until the specified VT is active, then exec
    the command. Note that this only works on TTYs.
-   `exec-join <cmd...> <join> [...]` - Exec the specified commands in sequence,
    using the joins (single character `;`, `&`, or `|`) to determine whether the
    next command should execute. The final command will replace the process; a
    final join will repeat the sequence.
