#pragma once

#include "RE/B/BSPointerHandle.h"

namespace RE
{
	class hkpCollidable;
	class TargetEntry;
	class ZoneEntry;

	class BGSZoneTargetListener
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSZoneTargetListener;
		inline static constexpr auto VTABLE = VTABLE_BGSZoneTargetListener;

		virtual ~BGSZoneTargetListener();  // 00

		// add
		virtual ZoneEntry*   CreateZoneEntry(ObjectRefHandle a_zoneRef, const hkpCollidable* a_collidable);      // 01
		virtual TargetEntry* CreateTargetEntry(ObjectRefHandle a_targetRef, const hkpCollidable* a_collidable);  // 02

		void RemoveZoneEntry(ZoneEntry* a_zone)
		{
			using func_t = decltype(&BGSZoneTargetListener::RemoveZoneEntry);
			static REL::Relocation<func_t> func{ RELOCATION_ID(25190, 25718) };
			func(this, a_zone);
		}

		// members
		ZoneEntry* zones;  // 08
	};
	static_assert(sizeof(BGSZoneTargetListener) == 0x10);
}
