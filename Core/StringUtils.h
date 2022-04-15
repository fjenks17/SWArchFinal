#pragma once

#include <string>
#include "CoreExports.h"
#include <string_view>

CORE_API bool startsWith(std::string mainStr, std::string toMatch);

CORE_API bool endsWith(std::string str, std::string suffix);
