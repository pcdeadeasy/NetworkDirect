// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

#ifndef PCH_H
#define PCH_H

#pragma once

#ifdef _DEBUG 
#include <crtdbg.h> 
#endif

#define _WINSOCKAPI_

// TODO: add headers that you want to pre-compile here
#include "../../libraries/logger/Logger.h"
#include "../../libraries/ndutil/ndutil.h"
#include "../../libraries/ndutil/ndtestutil.h"
#include "../../libraries/ndutil/ndsupport.h"
#include "../../libraries/ndutil/include/ndcommon.h"
#include "ndscope.h"
//#include "../../libraries/ndutil/ndtestutil.h"

#include <stdio.h>
#include <ctype.h>
#include "../../libraries/winshim/Winshim.h"
#include "../../libraries/winshim/WinHeap.h"

#endif //PCH_H
