/* xsh_calloutadd.c - xsh_calloutadd */

#include <xinu.h>
#include <stdio.h>
#include <string.h>

void testFunction(char *);
void testFunctionTwo(char *);

/*------------------------------------------------------------------------
 * xsh_calloutadd - shell command to add function to callout queue
 *------------------------------------------------------------------------
 */
shellcmd xsh_calloutadd(int nargs, char* args[]) {
   uint32 cid;

   cid = addcallout(10000, testFunction, "FIRST FUNCTION CALL");
   kprintf("cid: %d \n", cid);

   cid = addcallout(1000, testFunction, "SECOND FUNCTION CALL");
   kprintf("cid: %d \n", cid);
   
   cid = addcallout(5000, testFunction, "THIRD FUNCTION CALL");
   kprintf("cid: %d \n", cid);
   
   cid = addcallout(3000, testFunctionTwo, "SEPARATE FUNCTION");
   kprintf("cid: %d \n", cid);
   
   return 0;
}


/* The is the test function that callout will use. It is 
expecting a content argument as a string which will be printed out. */
void testFunction(char *content) {
   kprintf("Callout Test Function Execution: %s \n", content);
}

/* Second test function */
void testFunctionTwo(char *content) {
   kprintf("Test Function Two: %s \n", content);
}
