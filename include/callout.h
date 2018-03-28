/* callout.h - contains the structs for storing callout functions */

struct callout {
   uint32 time;          /* Time of delay in ms */
   void (*funcaddr)();   /* Function pointer */
   void *argp;           /* Function arguments */
   uint32 cid;           /* Callout id for the specific callout */
};

extern struct callout callouttab[];
