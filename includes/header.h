#ifndef SHELL_HEAD
# define SHELL_HEAD

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

// //readline history <- copy from docs, defined in it's own header.
// typedef void *histdata_t;

// typedef struct _hist_entry {
// 	char *line;
// 	char *timestamp;
// 	histdata_t data;
// }	HIST_ENTRY;

// /*
//  * A structure used to pass around the current state of the history.
//  */
// typedef struct _hist_state {
//   HIST_ENTRY **entries; /* Pointer to the entries themselves. */
//   int offset;           /* The location pointer within this array. */
//   int length;           /* Number of elements within this array. */
//   int size;             /* Number of slots allocated to this array. */
//   int flags;
// } HISTORY_STATE;

#endif
