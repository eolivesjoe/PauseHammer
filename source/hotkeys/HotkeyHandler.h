#pragma once

#include "../process/ThreadManager.h"

namespace hotkeys 
{
	class Handler
	{
	public:
		Handler(process::ThreadManager& manager);

		void Listener();

	private:
		process::ThreadManager& m_manager;
	};
} // namespace hotkeys