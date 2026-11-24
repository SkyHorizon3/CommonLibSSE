#pragma once

#include "RE/B/BSPointerHandle.h"

namespace RE
{
	class hkpCollidable;

	template <class T>
	class bhkTTNode
	{
	public:
		virtual ~bhkTTNode();  // 00

		// members
		std::uint32_t  flags;       // 08
		std::uint32_t  pad0C;       // 0C
		bhkTTNode*     next;        // 10
		hkpCollidable* collidable;  // 18
		T              ref;         // 20
	};
	static_assert(sizeof(bhkTTNode<ObjectRefHandle>) == 0x28);
}
