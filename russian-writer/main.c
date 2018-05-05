#include "windowz.h"B

int main()
{
	// Load the list of characters
	init();
	
	// And turn Russian Mode on
	on();

	// Listen for hotkeys
	MSG msg = { 0 };
	while (GetMessage(&msg, NULL, 0, 0) != 0)
	{
		if (msg.message == WM_HOTKEY)
		{
			if (msg.wParam == 100)
				toggle();
			else type(msg.wParam);
		}
	}
	close();
	return 0;
}