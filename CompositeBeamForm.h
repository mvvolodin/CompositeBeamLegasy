//---------------------------------------------------------------------------

#ifndef CompositeBeamFormH
#define CompositeBeamFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------

#include "CompositeBeam.h"
#include "Loads.h"
#include "Geometry.h"
#include "InternalForces.h"


//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
private:	// User declarations

	Loads* loads=new Loads();
	Geometry* geometry=new Geometry();
	std::vector<InternalForces> internalForcesList;
	CompositeBeam* compositeBeam=new CompositeBeam(loads, geometry, internalForcesList);

public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
