#include <windows.h>

#include "HotkeyHandler.h"
#include "../logger/Logger.h"

namespace hotkeys 
{
	Handler::Handler(process::ThreadManager& manager)
		: m_manager(manager)
	{

	}

	void
	Handler::listener()
	{
		const int HOTKEY_ID_CTRL_P = 1;
		if (!RegisterHotKey(NULL, HOTKEY_ID_CTRL_P, MOD_CONTROL, 0x50))
		{
			logger::error("Failed to register hotkey CTRL+P");
			return;
		}
		logger::info("Hotkey listener running. Press CTRL+P...");

		MSG msg = { 0 };
		while (GetMessage(&msg, NULL, 0, 0))
		{
			if (msg.message == WM_HOTKEY && msg.wParam == HOTKEY_ID_CTRL_P)
			{
				m_manager.togglePause();
			}
		}

		UnregisterHotKey(NULL, HOTKEY_ID_CTRL_P);
	}
}