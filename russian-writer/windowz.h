/**
 * This header defines the functions needed to make this program work on Windows.
 * If any of you Mac/Linux/mobile guys want to implement this for other platforms,
 * You can set up similar headers for your platform and choose which one is used at
 * compile time or whatever (same goes for main(), of course).
 */
#include <Windows.h>
#include <stdio.h>

// Used to set whether to type in Russian or not
int russian_mode = 1;

// Maps the stuff required by RegisterHotKey to Russian characters
typedef struct {
	int id;			// The hotkey ID
	UINT code;		// The virtual keycode
	wchar_t cap;		// The capitalized form of the character
	wchar_t low;		// The lowercase form of the character
} Character;

// Lists all the characters
Character list[33];

// Used to track how many hotkeys have been registered (there will be TONS!)
int length = 0;

// Populates the list of characters
void init()
{
	// Declare variables
	const wchar_t * up = L"АБЦДЕФГЧИЙКЛМНОПЯРСТУВШХЫЗ";
	const wchar_t * lo = L"абцдефгчийклмнопярстувшхыз";
	
	// Letters
	length = 27;
	for (int i = 0; i < length; i++)
	{
		list[i].id = i;
		list[i].code = 0x41 + i;
		list[i].cap = up[i];
		list[i].low = lo[i];
	}
	
	// Punctuation
	list[length].id = length;
	list[length].code = 0xBA;	// ;
	list[length].cap = L'Ь';
	list[length].low = L'ь';
	length++;
	
	list[length].id = length;
	list[length].code = 0xBB;	// +
	list[length].cap = L'Ъ';
	list[length].low = L'ъ';
	length++;
	
	list[length].id = length;
	list[length].code = 0xC0;	// ~
	list[length].cap = L'Ё';
	list[length].low = L'ё';
	length++;
	
	list[length].id = length;
	list[length].code = 0xDB;	// [
	list[length].cap = L'Ю';
	list[length].low = L'ю';
	length++;
	
	list[length].id = length;
	list[length].code = 0xDC;	// |
	list[length].cap = L'Э';
	list[length].low = L'э';
	length++;
	
	list[length].id = length;
	list[length].code = 0xDD;	// ]
	list[length].cap = L'Щ';
	list[length].low = L'щ';
	length++;
	
	list[length].id = length;
	list[length].code = 0xDE;	// "
	list[length].cap = L'Ж';
	list[length].low = L'ж';
	length++;
}

// Turns Russian Mode on
void on()
{
	// Set Russian Mode
	russian_mode = 1;

	// This hotkey is the on/off toggle, Shift+CTRL+R
	RegisterHotKey(NULL, 100, MOD_SHIFT | MOD_CONTROL, 0x52);

	// And the rest set up the keyboard to type Russian characters
	for (int i = 0; i < length; i++)
		RegisterHotKey(NULL, list[i].id, 0, list[i].code);
	
	// We also have to do the same thing for Shift + key (capital letters).
	// This gets a little tricky with the math, so I added a
	// couple variables, but you're welcome to save a few
	// bytes if you can think of a simpler way. :)
	int old = length; length += 34;
	for (int i = old; i < length; i++)
		RegisterHotKey(NULL, i, MOD_SHIFT, list[i - old].code);
}

// Turns Russian Mode off
void off()
{
	// Set Russian Mode
	russian_mode = 0;

	// Turn off all but the first (Shift+CTRL+R) hotkey
	for (int i = 0; i < length; i++)
		UnregisterHotKey(NULL, i);

	// And reset the length
	length = 34;
}

// Unsets the first (Shift+CTRL+R) hotkey
void close()
{
	UnregisterHotKey(NULL, 100);
}

// Toggles Russian Mode
void toggle()
{
	if (russian_mode)
		off();
	else on();
}

// Types a Russian character
void type(WPARAM wp)
{
	int id = (int)wp;
	INPUT ip;
	ip.type = INPUT_KEYBOARD;
	ip.ki.wVk = 0;
	ip.ki.wScan = list[id].low;
	if (GetKeyState(VK_CAPITAL) && id < 34)
		ip.ki.wScan = list[id].cap;
	else if (id > 33)
		ip.ki.wScan = list[id - 34].cap;
	ip.ki.dwFlags = KEYEVENTF_UNICODE;		// there is no KEYEVENTF_KEYDOWN, so 0 would be used, and there's no need to do | 0 lol
	ip.ki.time = 0;
	ip.ki.dwExtraInfo = GetMessageExtraInfo();
	SendInput(1, &ip, sizeof(INPUT));

	ip.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &ip, sizeof(INPUT));
}
