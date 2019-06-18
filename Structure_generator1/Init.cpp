#include "pch.h"
#include "Init.h"
#include <fstream> 
#include <iomanip>



Init::Init()
{

}

bool Init::InitDialog(void)
{
	int i = 0, j = 0;
	char c = 'n';
	do
	{
		/*cout << a[0][0] << endl;
		cout << a[0][1] << endl;*/

		cout << "Insert ID of message ";
		//scanf("%õ%s", &ID);
		cin >> ID;
		cout << "Insert Name of message: ";
		cin >> NameOfMessage;
		cout << "Insert lenght of message: ";
		cin >> Lenght;
		if (Lenght > MaxCounterOfBytes)
		{
			Lenght = 0;
			cout << "Error amount of bytes : count > 8 !!! " << endl;
			cout << "Do you want to continue (y/n)? ";
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
		ofstream fout(f_name);
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

void Init::CreateBitsModel(int rej, int _CurrentByte)
{
	string _bitname;
	int i = 0;
	/*ofstream fout(f_name);*/
	ofstream fout(f_name, ios_base::app); // îòêðûâàåì ôàéë äëÿ äîáàâëåíèÿ èíôîðìàöèè ê êîíöó ôàéëà
	//fout.open(f_name, ios::app);
	if (!fout.is_open()) // åñëè ôàéë íåáûë îòêðûò
	{
		cout << "Ôàéë íå ìîæåò áûòü îòêðûò èëè ñîçäàí\n"; // íàïå÷àòàòü ñîîòâåòñòâóþùåå ñîîáùåíèå
		return;
	}
	switch (rej)
	{
	case 1:
		fout << " " << endl;
		fout << " /* •••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••*/" << endl;
		fout << " /* " << _CurrentByte << " Byte							             							*/" << endl;
		fout << " /* •••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••*/" << endl;
		fout << " 	union {" << endl;
		fout << " 		struct {" << endl;

		for (i = 0; i < 8; i++) {
			cout << "enter name of" << _CurrentByte << " BYTE, [ " << i << " ] bit: " << endl;;
			cin >> _bitname;

			fout << " 		unsigned _" << _bitname << " : 1; /*	bit" << i << "*/" << endl;
		}
		fout << " 		}  bit;" << endl;
		fout << " 		U8 all;" << endl;
		fout << " 	} byte_" << _CurrentByte << ";" << endl;
		fout << " " << endl;
		break;
	case 2:
		fout << " " << endl;
		fout << " /* •••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••*/" << endl;
		fout << " /* " << _CurrentByte << " Byte							             							*/" << endl;
		fout << " /* •••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••*/" << endl;
		fout << " 	union {" << endl;
		fout << "		U8  byte_" << _CurrentByte << "; " << endl;
		fout << " 		struct {" << endl;
		for (i = 0; i < 4; i++) {
			cout << "enter name of" << _CurrentByte << " BYTE, [ " << i << " ] bit: " << endl;;
			cin >> _bitname;
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

			fout << " 		unsigned _" << _bitname << " : 2; /*	00 Release " << _bitname << "," << endl;
			fout << " 							01 Activate " << _bitname << " */" << endl;
		}
		fout << " 		}  bit;" << endl;
		fout << " 		U8 all;" << endl;
		fout << " 	} byte_" << _CurrentByte << ";" << endl;
		fout << " " << endl;

		break;
	case 4:
		fout << " " << endl;
		fout << "/* •••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••*/ " << endl;
		fout << " /* " << _CurrentByte << " Byte							             							*/" << endl;
		fout << "/* •••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••*/ " << endl;
		fout << "	union { " << endl;
		fout << "		U8  byte_" << _CurrentByte << "; " << endl;
		fout << "		struct { " << endl;
		for (int i = 0; i < 2; i++) {
			cout << "enter name of " << _CurrentByte << " BYTE, [ " << i << " ] bit: " << endl;
			cin >> _bitname;
			fout << " 		/*    Spare bit - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */" << endl;
			if (i == 0) {
				fout << " 		/*  1,2,3,4	   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  */" << endl;
			}
			else {
				fout << " 		/*  5,6,7,8	   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  */" << endl;
			}
			fout << " 		unsigned _" << _bitname << " : 4; /*	0000 Release " << _bitname << "," << endl;
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
		}
		fout << " 		} bit;" << endl;
		fout << " 		U8 all;" << endl;
		fout << " 	} byte_" << _CurrentByte << ";" << endl;
		fout << " " << endl;
		break;
	default:
		break;
	}

	fout.close();

}

void Init::CreateByteModel(int _ByteLenght, int _CurrentByte)
{
	string _bytname;
	int j = 0;
	/*ofstream fout(f_name);*/
	ofstream fout(f_name, ios_base::app); // îòêðûâàåì ôàéë äëÿ äîáàâëåíèÿ èíôîðìàöèè ê êîíöó ôàéëà
	//fout.open(f_name, ios::app);
	if (!fout.is_open()) // åñëè ôàéë íåáûë îòêðûò
	{
		cout << "Ôàéë íå ìîæåò áûòü îòêðûò èëè ñîçäàí\n"; // íàïå÷àòàòü ñîîòâåòñòâóþùåå ñîîáùåíèå
		return;
	}
	switch (_ByteLenght)
	{
	case 1:
		//		fout << " " << endl;
		fout << " /* •••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••*/" << endl;
		fout << " /* " << _CurrentByte << " Byte							             							*/" << endl;
		fout << " /* •••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••*/" << endl;
		cout << "enter name of" << _CurrentByte << " BYTE: " << endl;;
		cin >> _bytname;
		fout << "	U8 _" << _bytname << ";" << endl;
		break;
	case 2:
		//		fout << " " << endl;
		fout << " /* •••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••*/" << endl;
		fout << " /* " << _CurrentByte << " Byte							             							*/" << endl;
		fout << " /* •••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••*/" << endl;
		cout << "enter name of" << _CurrentByte << " BYTE: " << endl;;
		cin >> _bytname;
		fout << "	U16 _" << _bytname << ";" << endl;
		break;
	case 4:
		//		fout << " " << endl;
		fout << " /* •••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••*/" << endl;
		fout << " /* " << _CurrentByte << " Byte							             							*/" << endl;
		fout << " /* •••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••*/" << endl;
		cout << "enter name of" << _CurrentByte << " BYTE: " << endl;;
		cin >> _bytname;
		fout << "	U32 _" << _bytname << ";" << endl;
		break;
	default:
		break;
	}
	fout.close();

}

void Init::ParseID(void)
{
	static int i = 0, j = 0, k = 0;
	int  _mode, _MaxSiseOfBitesInStruct;
	static int _NumberOfBytes;

	int _balance = Lenght;
	while (_balance) {
		cout << "Insert type of Byte : Bites = [0], Byte =[1] , Word = [2], Qword = [4]) :  ";
		cin >> ArrMes[i][j];
		if (ArrMes[i][j] == 0) {
			ArrMes[i][j] = 1;
			cout << " enter the bit-model for [" << j << "] byte. [1] || [2] || [4]: ";
			cin >> k;
			for (i = 1; i <= (8 / k); i++) {
				ArrMes[i][j] = k;
			}
			i = 0;
		}
		_balance -= ArrMes[i][j];
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
	/*Start Create headline*/
	CreateHeadline(1);
	for (j = 0; j < _NumberOfBytes; j++) {
		if (ArrMes[0][j] == 1) {
			/*Âûäåëåíèå áèòîâûõ êîìïîíåíòîâ ïî 1 â ìàññèâå*/
			if (ArrMes[0 + 1][j] != 0) {
				CreateBitsModel(ArrMes[0 + 1][j], j);
			}
			/*âûäåëåíèå íàñòîÿùèõ áàéòîâ åäèíè÷íûõ*/
			else {
				CreateByteModel(ArrMes[0][j], j);
			}
		}
		else {
			/*Îáðàáîòêà îñòàëüíûõ áàéòîâ */
			CreateByteModel(ArrMes[0][j], j);
		}
	}
	/*Finish Create headline*/
	CreateHeadline(0);
}


Init::~Init()
{
}
