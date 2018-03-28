#include <xinu.h>

// uint32 addcallout(uint32, void (*)(), void*);
// void removecallout(uint32 cid);
void calloutWrapper();

qid16 calloutq;   /* Process list responsible for holding all processes for callout */

/* Method to add callout function to callout queue */
uint32 addcallout(uint32 msdelay, void (*funcaddr)(), void *argp) {
   struct callout *coptr;
   uint32 pid;

   pid = create(calloutWrapper, 1024, 200, "calloutWrapper", 0) ;

   /* Store callout struct in index of pid */
   coptr = &callouttab[pid];
   coptr->funcaddr = funcaddr;
   coptr->argp = argp;
   coptr->time = msdelay;
   coptr->cid = pid;  //cid is the same value as pid;
   
   
   insertd(pid, calloutq, msdelay);   //insert into calloutq

   return pid;
}

/* Method to remove callout process from callout q */
void removecallout(uint32 cid) {
   intmask mask;
   struct procent *prptr;
   pid32 pidnext; 

   mask = disable();
   if(isbadpid(cid)){
      restore(mask);

   }

   /* Increment delay of next process */
   pidnext = queuetab[cid].qnext;
   if(pidnext < NPROC) {
      queuetab[pidnext].qkey += queuetab[cid].qkey;
   }

   getitem(cid);
   restore(mask);
} 

/* Wrapper function to execution the function pointer */
void calloutWrapper() {
   struct callout *coptr;

   /* The proctab index is the same as the callouttab index */
   coptr = &callouttab[currpid];
   (coptr->funcaddr)(coptr->argp);
}
