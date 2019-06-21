//#ifndef __INIT_H
//#define __INIT_H
#pragma once
//#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include <fstream>
#include <string>
using namespace std;
enum { Bites = 8, Byte = 1, Word = 2, Qword = 4 };
//#define MaxCounterOfBytes	8
//#define MaxAmountOfBites 8
class Init
{
private:

	int NumberOfMessages, Lenght;
	string NameOfMessage;
	string name_list;
	string f_name;
	string ID;
	string RegisterName;
	int ArrMes[9][8];
	int BitesStructure[8];
	/*string ID[8];*/
	short TypeOfByte;
	int  MaxCounterOfBytes = 8, MaxAmountOfBites = 8;
public:
	 //int i, j, k;
	/*static int global_tick;*/
	Init();
	bool InitDialog();
	void CreateHeadline(int);
	int CreateModel(char **Mname, int bitStructureModel, int Aj, int _pointerForReadNames, int _balance, int j);
	void ParseID(void);
	int CreateDefines(char **Mname, int bitStructureModel, int Aj, int _pointerForReadNames, int _bytePosition, int j);
	void ParseDefines(char **Mname, int _NumberOfBytes,  string _RegName);
	~Init();
};
//#endif
