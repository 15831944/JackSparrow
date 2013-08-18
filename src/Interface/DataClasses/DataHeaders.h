#pragma once

#include <vector>
#include <ostream>
#include <memory>
#include <iomanip>
#include <fstream>
#include <string>

//////////////////////////////////////////////////////////////////////////
#if (_MSC_VER < 1600)
	#define SPTR std::tr1::shared_ptr
#else
	#define SPTR std::shared_ptr
#endif


//////////////////////////////////////////////////////////////////////////