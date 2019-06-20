#include "pch.h"
#include "Init.h"
#include <fstream> 
#include <iomanip>
#define demo


static int global_tick = 0;
Init::Init()
{
	//i = 0, j = 0, k = 0;
}

bool Init::InitDialog(void)
{
	int i = 0, j = 0;		
	char c = 'n';

#ifdef demo
	ID = "18FF0205";
	NameOfMessage = "CCVS1";
#else 
	cout << "Insert ID of message ";
	cin >> ID;
	cout << "Insert Name of message: ";
	cin >> NameOfMessage;
#endif // demo
	do
	{
		c = 'n'; // îáíîâëåíèå ñ, â ñëó÷àå õîæäåíèÿ ïî öèêëó
		cout << "Insert lenght of message: ";
		cin >> Lenght;
		if (Lenght > MaxCounterOfBytes)
		{
			/*Lenght = 0;*/
			cout << "Error amount of bytes : count > 8 !!! " << endl;
			cout << "Do you want to continue [ y ]? ";
			cin.ignore(cin.rdbuf()->in_avail());  // ïðîïóñòèòü âñå îñòàâøèåñÿ ñèìâîëû , get íå ïåðåõâàòûâàåò ñèìâîë ââîä ââèäó íàëè÷èÿ â áóôåðå ÷òåíèÿ /n
			cin.get(c);
			if (c != 'y')
			{
					return 0;
			}
		}



	} while (c == 'y');
	cout << "File name:";
	cin >> f_name;
	name_list = f_name;
	f_name += ".txt";
	//f_name += ".h";
	cout << endl;
	return 1;
}

void Init::CreateHeadline(int _start)
{
	int i = 0;
	string _regName;
	if (_start == 1) {
		ofstream fout(f_name, ios_base::app);
		if (!fout.is_open()) // åñëè ôàéë íåáûë îòêðûò
		{
			cout << "Ôàéë íå ìîæåò áûòü îòêðûò èëè ñîçäàí\n"; // íàïå÷àòàòü ñîîòâåòñòâóþùåå ñîîáùåíèå
			return;  // âûïîëíèòü âûõîä èç ïðîãðàììû
		}
		fout << "/*" << endl;
		fout << "* @ Ministry of Magic Programm @ " << endl;
		fout << "*/" << endl;
		fout << "/*" << i << "*/" << "#define ID_" << NameOfMessage << " 0x" << ID << "/* Electronic Brake Controller....... [ 100 ms ]" << endl;
		fout << "*/" << endl;
		fout << "/*===========================================================================" << endl;
		fout << NameOfMessage << endl;
		fout << "/*===========================================================================" << endl;
		fout << "* Message:" << NameOfMessage << " xxxx  " << endl;
		fout << "* Sender: " << "ABS to All systems " << endl;
		fout << "* Destination " << endl;
		fout << "* Frame Id: " << " 0x" << ID << endl;
		fout << "* Data Length: " << Lenght << " Byte" << endl;
		fout << "* Time b/w frames: " << "100 " << "msec" << endl;
		fout << "*===========================================================================*/ " << endl;
		fout << " " << endl;
		fout << "typedef struct { " << endl;

		fout.close();
	}
	else {
		ofstream fout(f_name, ios_base::app); // îòêðûâàåì ôàéë äëÿ äîáàâëåíèÿ èíôîðìàöèè ê êîíöó ôàéëà
		if (!fout.is_open()) // åñëè ôàéë íåáûë îòêðûò
		{
			cout << "Ôàéë íå ìîæåò áûòü îòêðûò èëè ñîçäàí\n"; // íàïå÷àòàòü ñîîòâåòñòâóþùåå ñîîáùåíèå
			return;
		}
		cout << "enter name of current register: " << endl;
		cin >> _regName;
		fout << "} " << _regName << "_REGISTR;" << endl;
		fout.close();

	}
}

int Init::CreateModel(char ** Mname, int bitStructureModel, int Aj, int __pointerForReadNames, int _balance, int j)
{
	int pointForRead = 0, numberOfTicks =0, i = 0;
	//string BYTEname;

	ofstream fout(f_name, ios_base::app); // îòêðûâàåì ôàéë äëÿ äîáàâëåíèÿ èíôîðìàöèè ê êîíöó ôàéëà
	if (!fout.is_open()) // åñëè ôàéë íåáûë îòêðûò
	{
		cout << "Ôàéë íå ìîæåò áûòü îòêðûò èëè ñîçäàí\n"; // íàïå÷àòàòü ñîîòâåòñòâóþùåå ñîîáùåíèå
		return 0;
	}
	if (Aj == 8 ) {
		string ByteName = Mname[j]; 
		pointForRead = __pointerForReadNames + 1;	
		numberOfTicks = 8 / bitStructureModel;
	}
	else if (Aj == 1 || Aj == 2 || Aj == 4) {
		string ByteName = Mname[j];
	}
	else return 0;


	switch (bitStructureModel)
	{
	case 0 :
		if (Aj == 1) {
			fout << " /* */" << endl;
			fout << " /* " << j << " Byte							             							*/" << endl;
			fout << " /* */" << endl;
			fout << "	U8 _" << Mname[__pointerForReadNames] << ";" << endl;
			pointForRead = __pointerForReadNames + 1;
		}
		else if (Aj == 2) {
			//		fout << " " << endl;
			fout << " /* */" << endl;
			fout << " /* " << j << " Byte							             							*/" << endl;
			fout << " /* */" << endl;
			fout << "	U16 _" << Mname[__pointerForReadNames] << ";" << endl;
			pointForRead = __pointerForReadNames + 1;
		}
		else if (Aj == 4) {
			//		fout << " " << endl;
			fout << " /* */" << endl;
			fout << " /* " << j << " Byte							             							*/" << endl;
			fout << " /* */" << endl;
			fout << "	U32 _" << Mname[__pointerForReadNames] << ";" << endl;
			pointForRead = __pointerForReadNames + 1;
		}
		break;
	case 1:
		fout << " " << endl;
		fout << " /* */" << endl;
		fout << " /* " << Mname[__pointerForReadNames] << " Byte							             							*/" << endl;
		fout << " /* */" << endl;
		fout << " 	union {" << endl;
		fout << " 		struct {" << endl;

		for (i = 0; i < 8; i++) {

			fout << " 		unsigned _" << Mname[pointForRead] << " : 1; /*	bit" << i << "*/" << endl;
			pointForRead++;
			//global_tick++;
		}
		fout << " 		}  bit;" << endl;
		fout << " 		U8 all;" << endl;
		fout << " 	} byte_" << Mname[__pointerForReadNames] << ";" << endl;
		fout << " " << endl;
		break;
	case 2:
		fout << " " << endl;
		fout << " /* */" << endl;
		fout << " /* " << Mname[__pointerForReadNames] << " Byte							             							*/" << endl;
		fout << " /* */" << endl;
		fout << " 	union {" << endl;
		fout << "		U8  byte_" << j << "; " << endl;
		fout << " 		struct {" << endl;
		for (i = 0; i < 4; i++) {
			fout << " 		/*    Spare bit - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */" << endl;
			if (i == 0) {
				fout << " 		/*  0,1	   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  */" << endl;
			}
			else if (i == 1) {
				fout << " 		/*  2,3	   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  */" << endl;
			}
			else if (i == 2) {
				fout << " 		/*  4,5	   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  */" << endl;
			}
			else {
				fout << " 		/*  6,7	   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  */" << endl;
			}

			fout << " 		unsigned _" << Mname[pointForRead] << " : 2; /*	00 Release " << Mname[pointForRead] << "," << endl;
			fout << " 							01 Activate " << Mname[pointForRead] << " */" << endl;
			pointForRead++;
		}
		fout << " 		}  bit;" << endl;
		fout << " 		U8 all;" << endl;
		fout << " 	} byte_" << Mname[__pointerForReadNames] << ";" << endl;
		fout << " " << endl;

		break;
	case 4:
		fout << " " << endl;
		fout << "/* */ " << endl;
		fout << " /* " << Mname[__pointerForReadNames] << " Byte							             							*/" << endl;
		fout << "/* */ " << endl;
		fout << "	union { " << endl;
		fout << "		U8  byte_" << j << "; " << endl;
		fout << "		struct { " << endl;
		for (int i = 0; i < 2; i++) {
			fout << " 		/*    Spare bit - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */" << endl;
			if (i == 0) {
				fout << " 		/*  1,2,3,4	   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  */" << endl;
			}
			else {
				fout << " 		/*  5,6,7,8	   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  */" << endl;
			}
			fout << " 		unsigned _" << Mname[pointForRead] << " : 4; /*	0000 Release " << Mname[pointForRead] << "," << endl;
			fout << " 												0001 Accelerator Pedal" << endl;
			fout << "												0010 Cruise Control " << endl;
			fout << "												0011 PTO Governor " << endl;
			fout << " 												0101 ASR Control" << endl;
			fout << " 												0110 Transmission Control" << endl;
			fout << " 												0111 ABS Control" << endl;
			fout << " 												1001 High Speed Governor" << endl;
			fout << " 												1010 Brake System" << endl;
			fout << " 												1011 Not defined" << endl;
			fout << " 												1100 Other" << endl;
			fout << " 												1111 Not available 		*/" << endl;
			pointForRead++;
		}
		fout << " 		} bit;" << endl;
		fout << " 		U8 all;" << endl;
		fout << " 	} byte_" << Mname[__pointerForReadNames] << ";" << endl;
		fout << " " << endl;
		break;
	default:
		break;
	}
	/*static string ByteName = Mname[j];*/


	fout.close();
	/*return _usedBefore + usednow;*/
	return  pointForRead;
}

void Init::ParseID(void)
{
	const int ROWS = 9, ÑOLUMNS = 8;
	static int i = 0, j = 0, k = 0;
	int  _mode, _MaxSiseOfBitesInStruct;
	static int _NumberOfBytes;
	int N = 16;   //êîëè÷åñòâî ñèìâîëîâ â ñòðîêå
	int row =0, pointerForReadNames =0, ostatok = 0;

	int _balance = Lenght;
	while (_balance) {
		cout << "Insert type of Byte : Bites = [0], Byte =[1] , Word = [2], Qword = [4]) :  ";
		cin >> ArrMes[i][j];
		if (ArrMes[i][j] == 8) {
			//ArrMes[i][j] = 8;
			cout << " enter the bit-model for [" << j << "] byte. [1] || [2] || [4]: ";
			cin >> k;
			for (i = 1; i <= (8 / k); i++) {
				ArrMes[i][j] = k;
			}
			i = 0;
		}
		if (ArrMes[i][j] == 8) {
			_balance -= 1;
		}
		else {
			_balance -= ArrMes[i][j];
		}

		j++;
		_NumberOfBytes++;
	}
	/* Îòîáðàæåíèå ñòðóêòóðû */
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 8; j++) {
			cout << setw(4) << ArrMes[i][j];
		}
		if (i == 0) {
			cout << setw(24) << "<--BYTES" << endl;
		}
		cout << endl;
	}
	/*Ïðîöåäóðà ïîäñ÷åòà êîëè÷åñòâà èìåí äëÿ ìàññèâîâ*/
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 8; j++) {
			if (ArrMes[i][j] != 0) {
				row++;
			}
		}
	}
	cout << "Number of names: [" << row <<"]"<< endl;

	//Âûäåëåíèå ïàìÿòè
	char **arr_stings = new char *[row];
	for (i = 0; i < row; i++) {
		arr_stings[i] = new char[N];
	}
	//Êîíåö âûäåëåíèÿ ïàìÿòè

	cin.ignore(cin.rdbuf()->in_avail());  // ïðîïóñòèòü âñå îñòàâøèåñÿ ñèìâîëû , get íå ïåðåõâàòûâàåò ñèìâîë ââîä ââèäó íàëè÷èÿ â áóôåðå ÷òåíèÿ /n
	/*Ââîä èì¸í*/
	k = 0;
	for (j = 0; j < ÑOLUMNS; j++) {
		for (i = 0; i < ROWS; i++) {
			if (ArrMes[i][j] != 0) {
				cout << "enter name of" << j << " BYTE," << i << " bit" << endl;
				cin.getline(arr_stings[k], N);
				k++;
			}
		}
	}
#ifdef demo
	/*Îòîáðàæåíèå â êîíñîëè èìåí*/
	cout << "\nOurs strings:\n";
	for (i = 0; i < row; i++) cout << arr_stings[i] << '\n';
#else
#endif
	ostatok = row;



	/*Start Create headline*/
	CreateHeadline(1);
	/*create union*/
	for (j = 0; j < _NumberOfBytes; j++) {
		if (ArrMes[0][j] == 8) {
			pointerForReadNames = CreateModel(arr_stings,ArrMes[1][j], ArrMes[0][j], pointerForReadNames, ostatok,j); // pointer automaticly increment in function
			ostatok = row - pointerForReadNames;
		}
		else {
			/*Îáðàáîòêà îñòàëüíûõ áàéòîâ */
			pointerForReadNames = CreateModel(arr_stings, ArrMes[1][j], ArrMes[0][j], pointerForReadNames, ostatok, j);
			ostatok = row - pointerForReadNames;
		}
	}

	/*Finish Create headline*/
	CreateHeadline(0);

	 //Start clear memory
	for (i = 0; i < row; i++) {
		delete[]arr_stings[i];
	}
	delete[]arr_stings;
	//Finish clear memory

}


Init::~Init()
{
}
