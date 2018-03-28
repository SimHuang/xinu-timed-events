/* wakeupc.c - wakeupc */

#include <xinu.h>

/*------------------------------------------------------------------------
 *  wakeupc  -  Called by clock interrupt handler to awaken processes from calloutq
 *------------------------------------------------------------------------
 */
void	wakeupc(void)
{
	/* Awaken all processes that have no more time to sleep */

	resched_cntl(DEFER_START);
	while (nonempty(calloutq) && (firstkey(calloutq) <= 0)) {
		ready(dequeue(calloutq));
	}

	resched_cntl(DEFER_STOP);
	return;
}
