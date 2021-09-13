#pragma once

#   ifdef ENGINE_EXPORTS
#       define ENGINE_API __declspec(dllexport)
#   else
#       ifdef ENGINE_STATIC
#           define ENGINE_API
#       else
#           define ENGINE_API __declspec(dllimport)
#       endif
#   endif