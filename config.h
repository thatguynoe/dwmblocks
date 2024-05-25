#ifndef CONFIG_H
#define CONFIG_H

// String used to delimit block outputs in the status.
#define DELIMITER " │ "

// Maximum number of Unicode characters that a block can output.
#define MAX_BLOCK_OUTPUT_LENGTH 45

// Control whether blocks are clickable.
#define CLICKABLE_BLOCKS 0

// Control whether a leading delimiter should be prepended to the status.
#define LEADING_DELIMITER 0

// Control whether a trailing delimiter should be appended to the status.
#define TRAILING_DELIMITER 0

// Define blocks for the status feed as X(icon, cmd, interval, signal).
#define BLOCKS(X)                                       \
    X("", "cat /tmp/recordingicon 2>/dev/null",  0,  9) \
    X("", "music",        0,                  11)       \
    X("", "pacpackages",  0,                  8)        \
    X("", "memory",       10,                 14)       \
    X("", "cpu",          10,                 18)       \
    X("", "bright",       0,                  19)       \
    X("", "mailbox",      600,                12)       \
    X("", "volume",       0,                  10)       \
    X("", "battery",      5,                  3)        \
    X("", "internet",     5,                  4)        \
    X("", "clock",        1,                  1)

#endif  // CONFIG_H

// Disabled blocks.
    /*X("", "disk",         10800,              6)        \*/
    /*X("", "moonphase",    18000,              17)       \*/
    /*X("", "weather",      18000,              5)        \*/
