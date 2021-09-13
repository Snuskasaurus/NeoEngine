#pragma once

#   ifdef NEOENGINE_EXPORT
#       define NEOENGINE_API __declspec(dllexport)
#   else
#       ifdef NEOENGINE_STATIC
#           define NEOENGINE_API
#       else
#           define NEOENGINE_API __declspec(dllimport)
#       endif
#   endif