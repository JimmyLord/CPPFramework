#ifndef __FrameworkPCH_H__
#define __FrameworkPCH_H__

// This file includes many static headers and must be included by all files
//   inside this Framework project.
// Any changes to any of these headers will cause a full rebuild of the
//   Framework project, which isn't desirable.

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <windowsx.h>

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <math.h>

#include <map>
#include <vector>
#include <queue>
#include <string>

#include <GL/GL.h>
#include "GL/glext.h"
#include "GL/wglext.h"

#include "GL/GLExtensions.h"
#include "GL/WGLExtensions.h"

#include "../Libraries/imgui/imgui.h"
#include "../Libraries/rapidjson/document.h"

#include "Memory/MyMemory.h"

#endif //__FrameworkPCH_H__
