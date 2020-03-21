//---------------------------------------------------------------------------
#ifndef ObserverPatternInterfaces_H
#define ObserverPatternInterfaces_H
//---------------------------------------------------------------------------
#include <System.hpp>
//---------------------------------------------------------------------------
enum class Publisher_ID{
	REBARS_FORM,
	STUDS_FORM,
	CONCRETE_FORM,
};

class IPublisher;

class IObserver_{
public:
	virtual void update(IPublisher* ipublisher) = 0;
};

class IPublisher{
public:
	virtual String get_information()const = 0;
	virtual void register_observer(IObserver_* iobserver) = 0;
	virtual Publisher_ID get_id()const = 0;
};
//---------------------------------------------------------------------------
#endif
