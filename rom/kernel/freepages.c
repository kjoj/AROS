#include <exec/alerts.h>
#include <exec/execbase.h>
#include <proto/exec.h>

#include <kernel_base.h>
#include "memory_intern.h"

/*****************************************************************************

    NAME */
#include <proto/kernel.h>

AROS_LH2(void, KrnFreePages,

/*  SYNOPSIS */
	AROS_LHA(void *, addr, A0),
	AROS_LHA(uint32_t, length, D0),

/*  LOCATION */
	struct KernelBase *, KernelBase, 28, Kernel)

/*  FUNCTION

    INPUTS

    RESULT

    NOTES

    EXAMPLE

    BUGS

    SEE ALSO

    INTERNALS

******************************************************************************/
{
    AROS_LIBFUNC_INIT

    struct MemHeader *mh;

    ForeachNode(&SysBase->MemList, mh)
    {
	/* Test if the memory belongs to this MemHeader. */
	if (mh->mh_Lower > addr || mh->mh_Upper <= addr)
	    continue;

	/* Test if it really fits into this MemHeader. */
	if ((addr + length) > mh->mh_Upper)
	    /* Something is completely wrong. */
	    Alert(AN_MemCorrupt|AT_DeadEnd);

	krnFree(mh, addr, length, KernelBase);
    }

    AROS_LIBFUNC_EXIT
}
