#pragma once
#define IN_MAX_LEN_TEXT 1024*1024 // максимальный размер исходного кода
#define IN_CODE_ENDL '\n' // символ конца строки

// таблица проверки входной информации, индекс = код (Windows-1251) символа
// значения IN::F - запрещенный символ, IN::F = разрешенный символ, IN::F - игнорировать (не вводить),
// если 0 <= значение < 256 - то вводится данное значение

#define MAX_LEN_LINE 1000
namespace In
{
	void dell_in(char* str, int index);
	struct IN
	{
		enum
		{
			T = 1024, // допустимый символ
			F = 2048, // недопустимый
			I = 4096  // игнорировать, иначе изменить
		};

		int size,   // размер исходного кода
			lines,  // количество строк
			ignore; // количество проигнорированных символов

		unsigned char* text; // исходный код(Windows-1251);

		int code[256] =
		{
			IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, // 0
			IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, // 16
			IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, // 32
			IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, // 48
			IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, // 64
			IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, // 80
			IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, // 96
			IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, // 112

			IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, // 128
			IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, // 144
			IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, // 160
			IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, // 176
			IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, // 192
			IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, // 208
			IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, // 224
			IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F
		}; // таблица проверки: T, F, I новое значение

		IN()
		{ //   пробел     0          2          3         P          U           Z          I          K          O         V       
			code[32] = code[48] = code[50] = code[51] = code[80] = code[85] = code[90] = code[73] = code[75] = code[79] = code[86] =
				//    A         L          E        X          E         Y            p          u           z           i           k           o         v     
				code[65] = code[76] = code[69] = code[88] = code[69] = code[89] = code[112] = code[117] = code[122] = code[105] = code[75] = code[111] = code[118] = 
				//   a          l         e			   x           e            y          П          У          З            И            К         О            В
				code[97] = code[108] = code[101] = code[120] = code[101] = code[121] = code[207] = code[211] = code[199] = code[200] = code[202] = code[206] = code[194] =
				//    А          Л         Е           К          С            Е           Й          п           у           з             о          в           а
				code[192] = code[203] = code[197] = code[202] = code[209] = code[197] = code[201] = code[239] = code[243] = code[234] = code[238] = code[226] = code[224] =
				//    л          е         к          с             е           й            -
				code[235] = code[229] = code[234] = code[241] = code[229] = code[233] = code[45] = IN::T;

			code[192] = '-'; // A
			code[88] = IN::I;// X
			
		}
	};

	IN getin(wchar_t infile[]);
}