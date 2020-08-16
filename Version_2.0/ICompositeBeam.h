//---------------------------------------------------------------------------
#ifndef ICompositeBeam_H
#define ICompositeBeam_H
//---------------------------------------------------------------------------
class ICompositeBeam{
public:
	virtual double get_t_max() const = 0;
};
class ICompositeBeamUser{
	virtual void register_icopmosite_beam_user(ICompositeBeam* icomposite_beam) = 0;
};

//---------------------------------------------------------------------------
#endif
