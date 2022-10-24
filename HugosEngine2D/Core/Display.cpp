#include "Display.h"

Display::Display(const bool create, const char* title) {
	if (create) createWindow(title);
}
