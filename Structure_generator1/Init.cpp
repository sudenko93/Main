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
		c = 'n'; // обновление с, в случае хождения по циклу
		cout << "Insert lenght of message: ";
		cin >> Lenght;
		if (Lenght > MaxCounterOfBytes)
		{
			/*Lenght = 0;*/
			cout << "Error amount of bytes : count > 8 !!! " << endl;
			cout << "Do you want to continue [ y ]? ";
			cin.ignore(cin.rdbuf()->in_avail());  // пропустить все оставшиеся символы , get не перехватывает символ ввод ввиду наличия в буфере чтения /n
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
	//string _regName;
	if (_start == 1) {
		ofstream fout(f_name, ios_base::app);
		if (!fout.is_open()) // если файл небыл открыт
		{
			cout << "Файл не может быть открыт или создан\n"; // напечатать соответствующее сообщение
			return;  // выполнить выход из программы
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
		ofstream fout(f_name, ios_base::app); // открываем файл для добавления информации к концу файла
		if (!fout.is_open()) // если файл небыл открыт
		{
			cout << "Файл не может быть открыт или создан\n"; // напечатать соответствующее сообщение
			return;
		}
		cout << "enter name of current register: " << endl;
		cin >> RegisterName;
		fout << "} " << RegisterName << "_REGISTR;" << endl;
		fout.close();

	}
}

int Init::CreateModel(char ** Mname, int bitStructureModel, int Aj, int __pointerForReadNames, int _balance, int j)
{
	int pointForRead = 0, numberOfTicks =0, i = 0;
	//string BYTEname;

	ofstream fout(f_name, ios_base::app); // открываем файл для добавления информации к концу файла
	if (!fout.is_open()) // если файл небыл открыт
	{
		cout << "Файл не может быть открыт или создан\n"; // напечатать соответствующее сообщение
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
			fout << " /* •••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••*/" << endl;
			fout << " /* " << j << " Byte							             							*/" << endl;
			fout << " /* •••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••*/" << endl;
			fout << "	U8 _" << Mname[__pointerForReadNames] << ";" << endl;
			pointForRead = __pointerForReadNames + 1;
		}
		else if (Aj == 2) {
			//		fout << " " << endl;
			fout << " /* •••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••*/" << endl;
			fout << " /* " << j << " Byte							             							*/" << endl;
			fout << " /* •••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••*/" << endl;
			fout << "	U16 _" << Mname[__pointerForReadNames] << ";" << endl;
			pointForRead = __pointerForReadNames + 1;
		}
		else if (Aj == 4) {
			//		fout << " " << endl;
			fout << " /* •••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••*/" << endl;
			fout << " /* " << j << " Byte							             							*/" << endl;
			fout << " /* •••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••*/" << endl;
			fout << "	U32 _" << Mname[__pointerForReadNames] << ";" << endl;
			pointForRead = __pointerForReadNames + 1;
		}
		break;
	case 1:
		fout << " " << endl;
		fout << " /* •••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••*/" << endl;
		fout << " /* " << Mname[__pointerForReadNames] << " Byte							             							*/" << endl;
		fout << " /* •••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••*/" << endl;
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
		fout << " /* •••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••*/" << endl;
		fout << " /* " << Mname[__pointerForReadNames] << " Byte							             							*/" << endl;
		fout << " /* •••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••*/" << endl;
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
		fout << "/* •••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••*/ " << endl;
		fout << " /* " << Mname[__pointerForReadNames] << " Byte							             							*/" << endl;
		fout << "/* •••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••*/ " << endl;
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
	const int ROWS = 9, СOLUMNS = 8;
	static int i = 0, j = 0, k = 0;
	int  _mode, _MaxSiseOfBitesInStruct;
	static int _NumberOfBytes;
	int N = 16;   //количество символов в строке
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
	/* Отображение структуры */
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 8; j++) {
			cout << setw(4) << ArrMes[i][j];
		}
		if (i == 0) {
			cout << setw(24) << "<--BYTES" << endl;
		}
		cout << endl;
	}
	/*Процедура подсчета количества имен для массивов*/
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 8; j++) {
			if (ArrMes[i][j] != 0) {
				row++;
			}
		}
	}
	cout << "Number of names: [" << row <<"]"<< endl;

	//Выделение памяти
	char **arr_stings = new char *[row];
	for (i = 0; i < row; i++) {
		arr_stings[i] = new char[N];
	}
	//Конец выделения памяти

	cin.ignore(cin.rdbuf()->in_avail());  // пропустить все оставшиеся символы , get не перехватывает символ ввод ввиду наличия в буфере чтения /n
	/*Ввод имён*/
	k = 0;
	for (j = 0; j < СOLUMNS; j++) {
		for (i = 0; i < ROWS; i++) {
			if (ArrMes[i][j] != 0) {
				cout << "enter name of" << j << " BYTE," << i << " bit" << endl;
				cin.getline(arr_stings[k], N);
				k++;
			}
		}
	}
#ifdef demo
	/*Отображение в консоли имен*/
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
			/*Обработка остальных байтов */
			pointerForReadNames = CreateModel(arr_stings, ArrMes[1][j], ArrMes[0][j], pointerForReadNames, ostatok, j);
			ostatok = row - pointerForReadNames;
		}
	}

	/*Finish Create headline*/
	CreateHeadline(0);


	/*create defines*/

	ParseDefines(arr_stings, _NumberOfBytes, RegisterName);
	//int bytePosition = 0;
	//for (j = 0; j < _NumberOfBytes; j++) {
	//	pointerForReadNames = CreateDefines(arr_stings, ArrMes[1][j], ArrMes[0][j], pointerForReadNames, bytePosition, j); // pointer automaticly increment in function
	//	ostatok = row - pointerForReadNames;
	//	if (ArrMes[0][j] == 8) {}
	//}
	 //Start clear memory
	for (i = 0; i < row; i++) {
		delete[]arr_stings[i];
	}
	delete[]arr_stings;
	//Finish clear memory

}

int Init::CreateDefines(char ** Mname, int bitStructureModel, int Aj, int _pointerForReadNames, int _bytePosition, int j)
{
	return 0;
}

void Init::ParseDefines(char ** Mname, int _NumberOfBytes, string _RegName)
{
	int bytePosition = 0, j = 0, i = 0, k = 0, _numberOfTicks;
	ofstream fout(f_name, ios_base::app); // открываем файл для добавления информации к концу файла
	if (!fout.is_open()) // если файл небыл открыт
	{
		cout << "Файл не может быть открыт или создан\n"; // напечатать соответствующее сообщение
		return;
	}
	for (j = 0; j < _NumberOfBytes; j++) {
		//for (i = 0; i < 9; i++) {
			if (ArrMes[0][j] == 1) {
				fout<<"#define  	"<< Mname[k]<<"  							"<<_RegName<<"."<< Mname[k]<<" /* "<< bytePosition+1 <<" byte  */"<<endl;
				k++;
//#define  	ActualEnginePercentTorque  							KnBrEEC1._ActualEnginePercentTorque					/* 	3 byte  */

				//i = 8;
				bytePosition++;
			}
			else if (ArrMes[0][j] == 2) {
				fout << "#define  	" << Mname[k] << "  							" << _RegName << "." << Mname[k] << " /* " << bytePosition +1 << " byte  */" << endl;
				k++;
				//#define  	ActualEnginePercentTorque  							KnBrEEC1._ActualEnginePercentTorque					/* 	3 byte  */

								//i = 8;
				bytePosition+=2;
			}
			else if (ArrMes[0][j] == 4) {
				fout << "#define  	" << Mname[k] << "  							" << _RegName << "." << Mname[k] << " /* " << bytePosition+1 << " byte  */" << endl;
				k++;
				//i = 8;
				bytePosition += 4;
			}
			else if (ArrMes[0][j] == 8) {
				fout << "#define		" << _RegName << "_REGISTR_All_" << bytePosition+1 << " 								" << _RegName << ".byteKnBr_" << bytePosition +1 << ".all         					/* 	" << bytePosition +1 << " byte	 */" << endl;
	/*			i++;*/
				k++;
				_numberOfTicks = MaxAmountOfBites / ArrMes[1][j];
				int weight = 0;

				for (i = 0; i < _numberOfTicks; i++){
					fout << "#define  	" << _RegName << "_" << Mname[k] << "							" << _RegName << ".byteKnBr_" << bytePosition  +1<< ".bit._" << Mname[k] << "			/*"<<i* weight <<"    - bit */ " << endl;
					k++;
					weight = MaxAmountOfBites / _numberOfTicks;
				}
				bytePosition++;
			}
			else {
			}


	/*	}*/
	}
	fout.close();
}


Init::~Init()
{
}
