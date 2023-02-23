/* Maximum possible length of output from block, expressed in number of characters. */
#define CMDLENGTH 45

/* The status bar's delimiter which appears in between each block. */
#define DELIMITER " │ "

const Block blocks[] = {
    /*Command             Interval            Signal*/
    BLOCK("cat /tmp/recordingicon 2>/dev/null",  0,  9),
    BLOCK("music",        0,                  11),
    BLOCK("pacpackages",  0,                  8),
    BLOCK("memory",       10,                 14),
    BLOCK("cpu",          10,                 18),
    /* BLOCK("disk",         10800,              6), */
    BLOCK("bright",       0,                  19),
    /* BLOCK("moonphase",    18000,              17), */
    /* BLOCK("weather",      18000,              5), */
    /* BLOCK("mailbox",      180,                12), */
    BLOCK("volume",       0,                  10),
    BLOCK("battery",      5,                  3),
    BLOCK("internet",     5,                  4),
    BLOCK("clock",        1,                  1)
};
