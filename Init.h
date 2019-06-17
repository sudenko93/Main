//#ifndef __INIT_H
//#define __INIT_H
#pragma once
//#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include <fstream>
#include <string>
using namespace std;
enum { Bites = 0, Byte = 1, Word = 2, Qword = 4 };
//#define MaxCounterOfBytes	8
//#define MaxAmountOfBites 8
class Init
{
private:

	int NumberOfMessages, Lenght;
	string NameOfMessage;
	string name_list;
	string f_name;
	char ID[9];
	int ByteLineup[8];
	int ArrMes[9][8];
	int BitesStructure[8];
	/*string ID[8];*/
	short TypeOfByte;
	int  MaxCounterOfBytes = 8, MaxAmountOfBites = 8;
public:
	Init();
	bool InitDialog();
	void CreateHeadline(int);
	void CreateBitsModel(int, int);
	void CreateByteModel(int, int);
	void ParseID(void);
	~Init();
};
//#endif
