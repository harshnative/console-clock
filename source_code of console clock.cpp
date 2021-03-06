#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <ctime>
#include <vector>
#include <windows.h>
#include<unistd.h>
#include<stdlib.h>
#ifdef max
#undef max
#endif

using namespace std;

int main()
  {
  	while(1)             //techincally infinte loop
  	{
  	//FONT SIZE CHANGE 
		CONSOLE_FONT_INFOEX cfi;
		cfi.cbSize = sizeof(cfi);
		cfi.nFont = 0;
		cfi.dwFontSize.X = 0;                   // Width of each character in the font
		cfi.dwFontSize.Y = 24;                  // Height
		cfi.FontFamily = FF_DONTCARE;
		cfi.FontWeight = FW_NORMAL;
		std::wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
		SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
  	
  	
  	for(int i = 0 ;i<=10;i++)
  	{
  		cout<<endl;
	}
  	
  	
  HANDLE                     hstdout;
  CONSOLE_SCREEN_BUFFER_INFO csbi;

  hstdout = GetStdHandle( STD_OUTPUT_HANDLE );
  GetConsoleScreenBufferInfo( hstdout, &csbi );

  // This is the actual visible width of your console window in characters
  size_t width = csbi.srWindow.Right - csbi.srWindow.Left;

  // Get all the inputs (user may input any length string, of course)
 time_t now = time(0);
   
   // convert now to string form
   char* dt = ctime(&now);

  // Generate our list of things to output
  vector <string> outputs;
  outputs.push_back( dt );
 

  // Make sure that no output is too wide
  for (size_t n = 0; n < outputs.size(); n++)
    if (outputs[ n ].length() > (width - 1))
      outputs[ n ].erase( width - 1 );

  // Calculate the width of the largest output item
  size_t output_width = 0;
  for (size_t n = 0; n < outputs.size(); n++)
    output_width = max( outputs[ n ].length(), output_width );

  // Calculate our indent
  string indent( (width - output_width) / 2, ' ' );

  // Draw all the items
  for (size_t n = 0; n < outputs.size(); n++)
    cout << indent << outputs[ n ] << endl;

  outputs.clear();
	sleep(1);
  system("cls");
	}
  return 0;
  }
