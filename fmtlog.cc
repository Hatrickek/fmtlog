#include "fmtlog-inl.h"

#include <chrono>

static int64_t TSCNS::rdsysns() {
  using namespace std::chrono;
  return duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();
}