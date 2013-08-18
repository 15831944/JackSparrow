#pragma once

#include "DataClasses/Layer.h"
#include <fstream>

class Dumper
{
public:
	Dumper(void);
	~Dumper(void);

	void DumpEntities(const dxf::Layer::List& iLayerList, std::ofstream& oFile) const;

};

