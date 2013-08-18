#pragma once

#pragma warning (disable:4251)	//to disable the warning related to exporting stl classes 

//////////////////////////////////////////////////////////////////////////

#if defined (DXF_DLL_DECL)
#define DXF_DLL_EXPORT __declspec(dllexport)
#else
#define DXF_DLL_EXPORT __declspec(dllimport)
#endif
