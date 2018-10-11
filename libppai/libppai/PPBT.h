#pragma once
#include "ppinclude.h"

namespace PP {
	class Node {
	public:
		Node();
		~Node();
	public:
		virtual bool Run();
	};
}
