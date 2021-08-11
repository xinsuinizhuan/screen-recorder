#include "enumer_monitor.h"

namespace am {

BOOL WINAPI EnumMonitorProc(HMONITOR hmonitor,
  HDC hdc,
  LPRECT lprc,
  LPARAM data) {

  MONITORINFOEX info_ex;
  info_ex.cbSize = sizeof(MONITORINFOEX);

  GetMonitorInfo(hmonitor, &info_ex);

  if (info_ex.dwFlags == DISPLAY_DEVICE_MIRRORING_DRIVER)
    return true;

  auto monitors = ((std::vector<Monitor>*)data);
  std::string name = info_ex.szDevice;
  auto monitor = Monitor(hmonitor, name, info_ex.dwFlags & MONITORINFOF_PRIMARY);

  monitors->emplace_back(monitor);

  return true;
}

std::vector<Monitor> EnumerateMonitors()
{
  std::vector<Monitor> monitors;

  ::EnumDisplayMonitors(NULL, NULL, EnumMonitorProc, (LPARAM)&monitors);

  return monitors;
}

}