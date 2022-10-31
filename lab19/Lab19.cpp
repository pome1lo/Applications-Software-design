#include "stdafx.h"
#include "FST.h"

void _tmain(int argc, TCHAR* argv[])
{
	char str1[] = "bgedeafgec";
	char str2[] = "bgdeafgec";
	char str3[] = "bgdafgec";
	char str4[] = "bgedeafgec";
	char str5[] = "bgdafgc";
	char str6[] = "bgdeafgec";
	char str7[] = "bgdeafgeeec";
	char str8[] = "bgeeeeedeafifigec";
	char str9[] = "bgedeafifiigec";

	char* chains[] = { str1, str2, str3, str4, str5, str6, str7, str8, str9 };

	for (int i = 0; i < sizeof(chains) / sizeof(char*); i++)
	{
		FST::FST fst(chains[i], 8,
			FST::NODE(1, FST::RELATION('b', 1)),
			FST::NODE(1, FST::RELATION('g', 2)),
			FST::NODE(2, FST::RELATION('d', 3), FST::RELATION('e', 2)),
			FST::NODE(2, FST::RELATION('e', 3), FST::RELATION('a', 4)),
			FST::NODE(2, FST::RELATION('f', 5), FST::RELATION('i', 5)),
			FST::NODE(1, FST::RELATION('g', 6)),
			FST::NODE(2, FST::RELATION('c', 7), FST::RELATION('e', 6)),
			FST::NODE()
		);

		if (FST::execute(fst)) 
		{
			cout << "Chain " << fst.string << " recognized" << endl;
		}
		else
		{
			cout << "Chain " << fst.string << " is not recognized" << endl;
		}
	};
}
