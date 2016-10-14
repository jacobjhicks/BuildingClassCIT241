#include "Ui.h"

using namespace std;

int main()
{
	UI mainUI;

	do
	{
		try
		{
			// Perhaps make this return a value? var continue ?
			// If the user want to exit, set continue to false (or have the `while` check evaluate to false)
			mainUI.mainMenu();
		}
		catch (const exception& e)
		{
			cout << e.what();
		}
	} while (true /* var continue == true ? */);

	return 0;
}