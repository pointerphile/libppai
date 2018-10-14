#include "PPBT.h"

PP::Node::Node() {}
PP::Node::~Node() {}

const std::list<PP::Node*>& PP::CompositeNode::GetChildren() const {
	return listChildren;
}

void PP::CompositeNode::AddChild(PP::Node * pNodeChild)
{
	listChildren.emplace_back(pNodeChild);
}

bool PP::Selector::Run() {
	for (PP::Node* pNodeChild : GetChildren()) {
		if (pNodeChild->Run()) {
			return true;
		}
	}
	return false;
}

bool PP::Sequence::Run() {
	for (PP::Node* pNodeChild : GetChildren()) {
		if (pNodeChild->Run()) {
			return false;
		}
	}
	return true;
}
