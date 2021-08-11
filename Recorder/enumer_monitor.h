#ifndef RECORD_ENUMER_MONITOR_H_
#define RECORD_ENUMER_MONITOR_H_

#include <Windows.h>

#include <string>
#include <vector>

namespace am {

struct Monitor
{
public:
  Monitor(HMONITOR hmonitor, std::string& className, bool isPrimary)
  {
    m_hmonitor = hmonitor;
    m_className = className;
    m_bIsPrimary = isPrimary;
  }

  HMONITOR Hmonitor() const noexcept { return m_hmonitor; }
  std::string ClassName() const noexcept { return m_className; }
  bool IsPrimary() const noexcept { return m_bIsPrimary; }

private:
  HMONITOR m_hmonitor;
  std::string m_className;
  bool m_bIsPrimary;
};

std::vector<Monitor> EnumerateMonitors();

}



#endif // !RECORD_ENUMER_MONITOR_H_
