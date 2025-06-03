#include "lib.hpp"

auto main() -> int
{
  auto const lib = library{};

  return lib.name == "LabDevicesManagement" ? 0 : 1;
}
