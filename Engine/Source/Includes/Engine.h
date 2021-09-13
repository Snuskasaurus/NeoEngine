#pragma once

#   ifdef ENGINE_EXPORT
#       define ENGINE_API __declspec(dllexport)
#   else
#       ifdef ENGINE_STATIC
#           define ENGINE_API
#       else
#           define ENGINE_API __declspec(dllimport)
#       endif
#   endif

#include "Core/Debug.h"
#include "Core/Entity.h"
#include "Core/Random.h"
#include "Core/Time.h"

