#pragma once
#include "ppinclude.h"

namespace PP {
	class Node {
	public:
		Node();
		~Node();
	public:
		virtual bool Run() = 0;
	};

	class CompositeNode : public PP::Node {
	private:
		std::list<PP::Node*> listChildren;
	public:
		const std::list<PP::Node*>&GetChildren() const;
		void AddChild(PP::Node* pNodeChild);
	};

	class Selector : public PP::CompositeNode {
	public:
		virtual bool Run() override;
	};

	class Sequence : public PP::CompositeNode {
	public:
		virtual bool Run() override;
	};
}
