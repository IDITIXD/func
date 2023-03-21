using namespace std;
#include <iostream>

class STROKA
{     							//характеристики
	char* str; 	//адрес динамической строки
	int n;		//длина строки
	char ch; 	//символ
public:						//методы
	STROKA();			//пустая строка
	STROKA(char*, char);
	void SetChar(char);		//установка символа
	STROKA(const STROKA&);	//конструктор копирования
	int GetNSTR(); 		//получение длины строки
	void ClearSTR();		// очистка строки
	~STROKA(); 			//деструктор 
	char* GetSTR(char* txt);		//получение адреса строки 
	friend  void show(STROKA& A);   	//дружественная функция №1
	friend   void simw(STROKA& O);  	// дружественная функция №2
};
STROKA::STROKA()//пустая строка
{
	cout << "STROKA()\n";
};
STROKA::STROKA(char*, char)
{
	cout << "STROKA(char*, char)\n";
}
void STROKA::SetChar(char ch1)//установка символа
{
	cout << "установка символа\n";
	ch = ch1;
	cout << "введен " << ch << '\n';
}
STROKA::STROKA(const STROKA& cop)//конструктор копирования
{
	ch = cop.ch; str = cop.str;
	cout << "конструктор копирования\n";
}
int STROKA::GetNSTR() //получение длины строки
{
	n = strlen(str);

	cout << "длина " << n << '\n';
	return n;
}
void STROKA::ClearSTR()// очистка строки
{
	cout << "\nочистка строки\n ";
	*str = ' ';
}
STROKA::~STROKA() //деструктор 
{
	cout << "\nдеструктор\n ";
}
char* STROKA::GetSTR(char* txt)//получение адреса строки
{
	str = txt;
	cout << "получение адреса " << str << '\n';
	return str;
}
void show(STROKA& A)
{
	cout << "показ " << A.str << '\n';
}
void simw(STROKA& O)
{
	cout << "нахождение символа " << '\n';
	for (int i = 0; i < O.n; i++)
	{
		if (O.str[i] == O.ch) cout << i + 1 << ' ';
	};
}
int main()
{
	setlocale(0, "");
	char txt[50];
	cout << "Введите текст ";
	cin >> txt;
	char ch;
	cin >> ch;
	STROKA STROKA;
	STROKA.SetChar(ch);
	STROKA.GetSTR(txt);
	STROKA.GetNSTR();
	show(STROKA);
	simw(STROKA);
	STROKA.ClearSTR();
	show(STROKA);

}
