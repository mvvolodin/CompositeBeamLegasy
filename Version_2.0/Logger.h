#define DEBUG_ENABLED
//---------------------------------------------------------------------------
#define DEBUG_SP_35 // DEBUG_SP_266 | DEBUG_SP_35
//---------------------------------------------------------------------------
//#define DEBUG_STEEL_SECT
//#define DEBUG_CONC_SECT
#define DEBUG_COMP_SECT
#define DEBUG_STUDS
//---------------------------------------------------------------------------
#ifdef DEBUG_ENABLED

	#include "uFrmLogger.h"

	#if defined DEBUG_SP_266
		#if defined DEBUG_COMP_SECT
			#define DEBUG_COMP_SECT_SP266
		#endif
		#if defined DEBUG_STUDS
			#define DEBUG_STUDS_SP266
		#endif
	#elif defined DEBUG_SP_35
		#if defined DEBUG_COMP_SECT
			#define DEBUG_COMP_SECT_SP35
		#endif
		#if defined DEBUG_STUDS
			#define DEBUG_STUDS_SP35
		#endif
	#endif

	#undef DEBUG_COMP_SEC
	#undef DEBUG_STUDS

#else

	#undef DEBUG_STEEL_SECT
	#undef DEBUG_CONC_SECT
	#undef DEBUG_COMP_SECT
	#undef DEBUG_STUDS

#endif








