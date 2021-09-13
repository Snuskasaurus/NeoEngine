#pragma once

#   ifdef NEOENGINE_EXPORT
#       define NEOENGINE_API __declspec(dllexport)
#   else
#       ifdef NEOENGINE_API_STATIC
#           define NEOENGINE_API
#       else
#           define NEOENGINE_API __declspec(dllimport)
#       endif
#   endif

#include "Core/Debug.h"
#include "Core/Entity.h"
#include "Core/Random.h"
#include "Core/Time.h"

