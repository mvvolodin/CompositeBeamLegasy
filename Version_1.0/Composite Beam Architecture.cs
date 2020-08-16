Class MainForm
{
	ICompBeam combeam;
	
	MainForm(ICompBeam combeam)
	{
		this->combeam=combeam;
		
	}
	
		MainForm()
	{
		combeam =new CompBeamRealization();
		
	}

	
	void btnCalcClickalcClick()
	{		
		combeam.calc();
	}
	
}

class CompBeamRealization: ICompBeam
{
void calc();
void report();
}

class CompBeamRealization2: ICompBeam
{
void calc();
void report();
}

combeam =new CompBeamRealization();

