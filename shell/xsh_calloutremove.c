/* xsh_calloutremove.c - xsh_calloutremove */

#include <xinu.h>
#include <stdio.h>
#include <string.h>

/*------------------------------------------------------------------------
 * xsh_calloutremove - shell command to remove callout function from callout queue
 *------------------------------------------------------------------------
 */
shellcmd xsh_calloutremove(int nargs, char* args[]) {
   char *cid = args[1];
   removecallout(atoi(cid));
   return 0;
}