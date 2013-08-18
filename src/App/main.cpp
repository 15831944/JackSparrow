
#include <iostream>
#include <fstream>
#include "AlgoClasses/Reader.h"
#include "CmdHelper.h"
#include "Dumper.h"
using namespace std;

const int SEPRATOR_LENGTH = 50;
const char SEPRATOR_CHAR = '*';
//////////////////////////////////////////////////////////////////////////
int main ( int argc, char* agrv[] )
{
	//////////////////////////////////////////////////////////////////////////
	//Parse Command Line
	CmdLineParams cmdLineParams;
	bool retValue = CmdHelper::ParseCommandLine(argc, agrv, cmdLineParams);
	if(false == retValue)
		return false;

	std::string inputFileName = cmdLineParams.m_FileName;
	//////////////////////////////////////////////////////////////////////////
	//Call DXF Reader
	Reader dxfReader;
	dxf::Layer::List dxfLayerList;
	dxfReader.ReadDXF(inputFileName, dxfLayerList);

	//////////////////////////////////////////////////////////////////////////
	//Export Layers
	std::string truncatedFilePath = inputFileName.substr(0, inputFileName.find_last_of('.'));
	string outputFileName = truncatedFilePath + ".dxfout";
	ofstream fout(outputFileName);
	if(!fout.good())
		return false;

	fout << "INPUT FILE : " << inputFileName << std::endl;
	fout << string(SEPRATOR_LENGTH, SEPRATOR_CHAR) << std::endl;

	Dumper dump;
	dump.DumpEntities(dxfLayerList,fout);

	fout.close();
	return 0;
}