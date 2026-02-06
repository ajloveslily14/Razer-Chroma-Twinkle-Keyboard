#include <iostream>
#include <chrono>
#include <wtypes.h>
#include <vector>

#include "RzChromaSDKDefines.h"
#include "RzChromaSDKTypes.h"
#include "RzErrors.h"
#include "colorUtil.h"


class ChromaClass
{
public:
	ChromaClass();
	BOOL Initialize();
	void DoColors();
private:
	HMODULE m_ChromaSDKModule;
};