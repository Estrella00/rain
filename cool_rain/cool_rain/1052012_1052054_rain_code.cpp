#include <iostream>
#include<windows.h>

using namespace std;

int Modulus(int iN, int iMod) {
	int iQ = (iN / iMod);
	return iN - (iQ*iMod);
}

char GetChar(int iGenerator, char cBase, int iRange) //GetChar(���͡A�_�l�I�A�d��)
{
	return (cBase + Modulus(iGenerator, iRange));
}

void Clr() //�M���ù��B���|�{�h �ѷӺ������m
{
	COORD coordScreen = { 0, 0 };     /* here's where we'll home the cursor */  
	DWORD cCharsWritten;
	CONSOLE_SCREEN_BUFFER_INFO csbi;  /* to get buffer info */
	DWORD dwConSize;                   /* number of character cells in the current buffer */
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleScreenBufferInfo(hConsole, &csbi);  /* get the number of character cells in the current buffer */
	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
	FillConsoleOutputCharacter(hConsole, TEXT(' '), dwConSize, coordScreen, &cCharsWritten);   /*fill the entire screen with blanks */
	GetConsoleScreenBufferInfo(hConsole, &csbi);                                              /* get the current text attribute */
	FillConsoleOutputAttribute(hConsole,csbi.wAttributes,dwConSize,coordScreen,&cCharsWritten);  /* now set the buffer's attributes accordingly */
	SetConsoleCursorPosition(hConsole, coordScreen);                                          /* put the cursor at (0, 0) */

}

int main() {

	HANDLE hConsole;//HANDLE����˸m(DC),����,�ɮ�,��ܤ�� 
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//����ù���X(�ޥμ��Y��windows.h) 
	SetConsoleTextAttribute(hConsole, 7);//7=Console�w�]�� 



	char caRow[80];
	char caRow2[80];
	int j = 7;

	while (true) {

		for (int countt = 0; countt < 500; countt++)
		{
			int i = 0;
			// Output a random row of characters
			while (i < 80)
			{

				if (caRow[i] != ' ')
				{
					//caRow[i] = (97, 30);
					caRow[i] = GetChar(j + i*i, 97, 30);
					
					//0 black 1 dark blue2 green 3 blue 4 red 5 purple 6 yellow 7 white 8 gray 9light blue 10light green 

					if (countt > 300 && countt < 400)
					{
						if (((i*i / 2 + j) % 71) == 0)
						{
							SetConsoleTextAttribute(hConsole, 238); //�]�m�{�q
							cout << caRow2[i];
							
						}

						else
						{
							SetConsoleTextAttribute(hConsole, 0);//�]�m�r���C�⬰�¦� 
							cout << caRow2[i];

						}

						Clr();

					}

					else
					{

						if (((i*i + j) % 71) == 0)
						{
							SetConsoleTextAttribute(hConsole, 186); //�]�m�r���C����Ŧ�� 
						}

						else
						{
							//SetConsoleTextAttribute(hConsole, 0);//�]�m�r���C�⬰�¦� 
							SetConsoleTextAttribute(hConsole, 0);
						}
						

					}
				}
				cout << caRow[i];
				++i;

				
			}
			j = (j + 26); //�U�@�Ӱ_�l�I ,�[�_�Ӥ���C��33 

			// Delay

			Sleep(10);


		}
	}


	return 0;
}