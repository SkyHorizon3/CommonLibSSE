#pragma once

#include "RE/B/BSPointerHandle.h"
#include "RE/B/bhkTTNode.h"

namespace RE
{
	class TargetEntry;

	class ZoneEntry : public bhkTTNode<ObjectRefHandle>
	{
	public:
		inline static constexpr auto RTTI = RTTI_ZoneEntry;
		inline static constexpr auto VTABLE = VTABLE_ZoneEntry;

		~ZoneEntry() override;  // 00

		// add
		virtual TargetEntry* AddTarget(ObjectRefHandle a_targetRef, const hkpCollidable* a_collidable, std::uint32_t a_flags, bool& a_created);  // 01
		virtual void         Run(bool& a_needsCleanup);                                                                                          // 02 - { return; }

		// members
		TargetEntry* targets;  // 28
	};
	static_assert(sizeof(ZoneEntry) == 0x30);
}
