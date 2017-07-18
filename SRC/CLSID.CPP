// this redefines the DEFINE_GUID() macro to do allocation.
//
#include "Hostenv.h"        // Host environnement declarations
#include "initguid.h"

#ifndef INITGUID
# define INITGUID
#endif

// due to the previous header, including this causes the DEFINE_GUID
// definitions in the following header(s) to actually allocate data.
//
#include "vfw.h"
#include "FrmwrkInterfaces.h"


