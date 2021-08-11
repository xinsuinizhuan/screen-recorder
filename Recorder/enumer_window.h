#ifndef RECORD_ENUMER_WINDOW_H_
#define RECORD_ENUMER_WINDOW_H_

#include <Windows.h>

#include <string>
#include <vector>

namespace am {

struct Window
{
public:
  Window(HWND hwnd, std::string const& title, std::string& className)
  {
    m_hwnd = hwnd;
    m_title = title;
    m_className = className;
  }

  HWND Hwnd() const noexcept { return m_hwnd; }
  std::string Title() const noexcept { return m_title; }
  std::string ClassName() const noexcept { return m_className; }

private:
  HWND m_hwnd;
  std::string m_title;
  std::string m_className;
};

std::vector<Window> EnumerateWindows();

}

#endif
