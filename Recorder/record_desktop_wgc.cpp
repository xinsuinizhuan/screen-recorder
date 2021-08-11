#include "record_desktop_wgc.h"

#include "system_lib.h"
#include "utils_string.h"
#include "system_error.h"
#include "error_define.h"
#include "log_helper.h"

namespace am {



record_desktop_wgc::record_desktop_wgc()
{
}

record_desktop_wgc::~record_desktop_wgc()
{
}

int record_desktop_wgc::init(const RECORD_DESKTOP_RECT & rect, const int fps)
{
	return 0;
}

int record_desktop_wgc::start()
{
	return 0;
}

int record_desktop_wgc::pause()
{
	return 0;
}

int record_desktop_wgc::resume()
{
	return 0;
}

int record_desktop_wgc::stop()
{
	return 0;
}

void record_desktop_wgc::clean_up()
{
}

bool record_desktop_wgc::is_cursor_support()
{
  try {
    return winrt::Windows::Foundation::Metadata::ApiInformation::IsPropertyPresent(
      L"Windows.Graphics.Capture.GraphicsCaptureSession", L"IsCursorCaptureEnabled");
  }
  catch (const winrt::hresult_error&) {
    return false;
  }
  catch (...) {
    return false;
  }
}

}