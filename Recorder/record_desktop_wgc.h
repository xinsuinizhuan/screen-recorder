#ifndef RECORD_DESKTOP_WGC
#define RECORD_DESKTOP_WGC

#include "record_desktop.h"

namespace am {

class record_desktop_wgc :
	public record_desktop
{
public:
	record_desktop_wgc();
	~record_desktop_wgc();

	virtual int init(
		const RECORD_DESKTOP_RECT &rect,
		const int fps);

	virtual int start();
	virtual int pause();
	virtual int resume();
	virtual int stop();

protected:
	virtual void clean_up();
};

}


#endif
