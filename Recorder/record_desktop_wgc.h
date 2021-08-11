#ifndef RECORD_DESKTOP_WGC
#define RECORD_DESKTOP_WGC

#include "record_desktop.h"

#include <d3d11.h>
#include <wrl/client.h>
#include <Windows.Graphics.Capture.Interop.h>
#include <winrt/base.h>
#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.Foundation.Metadata.h>
#include <winrt/Windows.Graphics.Capture.h>
#include <winrt/windows.graphics.imaging.h>
#include <winrt/Windows.System.h>
#include <windows.graphics.directx.direct3d11.interop.h>
#include <DispatcherQueue.h>

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

private:
	bool is_cursor_support();
};

}


#endif
