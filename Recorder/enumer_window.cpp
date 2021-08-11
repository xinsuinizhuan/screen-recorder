#include "enumer_window.h"

#include <array>
#include <dwmapi.h>

namespace am {

std::string GetClassName(HWND hwnd)
{
  std::array<TCHAR, 1024> className;

  ::GetClassName(hwnd, className.data(), (int)className.size());

  std::string title(className.data());
  return title;
}

std::string GetWindowText(HWND hwnd)
{
  std::array<TCHAR, 1024> windowText;

  ::GetWindowText(hwnd, windowText.data(), (int)windowText.size());

  std::string title(windowText.data());
  return title;
}

bool IsAltTabWindow(Window const& window)
{
  HWND hwnd = window.Hwnd();
  HWND shellWindow = GetShellWindow();

  auto title = window.Title();
  auto className = window.ClassName();

  if (hwnd == shellWindow)
  {
    return false;
  }

  if (title.length() == 0)
  {
    return false;
  }

  if (!IsWindowVisible(hwnd))
  {
    return false;
  }

  if (GetAncestor(hwnd, GA_ROOT) != hwnd)
  {
    return false;
  }

  LONG style = GetWindowLong(hwnd, GWL_STYLE);
  if (!((style & WS_DISABLED) != WS_DISABLED))
  {
    return false;
  }

  DWORD cloaked = FALSE;
  HRESULT hrTemp = DwmGetWindowAttribute(hwnd, DWMWA_CLOAKED, &cloaked, sizeof(cloaked));
  if (SUCCEEDED(hrTemp) &&
    cloaked == DWM_CLOAKED_SHELL)
  {
    return false;
  }

  return true;
}

BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam)
{
  auto class_name = GetClassName(hwnd);
  auto title = GetWindowText(hwnd);

  auto window = Window(hwnd, title, class_name);

  if (!IsAltTabWindow(window))
  {
    return TRUE;
  }

  std::vector<Window>& windows = *reinterpret_cast<std::vector<Window>*>(lParam);
  windows.push_back(window);

  return TRUE;
}

std::vector<Window> EnumerateWindows()
{
  std::vector<Window> windows;
  EnumWindows(EnumWindowsProc, reinterpret_cast<LPARAM>(&windows));

  return windows;
}

}