#pragma once

#include "RE/B/BGSZoneTargetListener.h"
#include "RE/B/bhkTrapListener.h"

namespace RE
{
	class TriggerEntry;

	class TESTrapListener :
		public BGSZoneTargetListener,  // 00
		public bhkTrapListener         // 10
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESTrapListener;
		inline static constexpr auto VTABLE = VTABLE_TESTrapListener;

		~TESTrapListener() override;  // 00

		// override (BGSZoneTargetListener)
		ZoneEntry* CreateZoneEntry(ObjectRefHandle a_zoneRef, const hkpCollidable* a_collidable) override;  // 01

		// override (bhkEntityListener)
		void EntityAddedCallback(hkpEntity* a_entity) override;              // 01 - { return; }
		void EntityRemovedCallback(hkpEntity* a_entity) override;            // 02
		void EntityDeletedCallback(hkpEntity* a_entity) override;            // 05 - { return; }
		void Update(float a_delta) override;                                 // 06
		bool ContactPointAddedCallback(hkpRootCdPoint& a_point) override;    // 07
		bool ContactPointRemovedCallback(hkpRootCdPoint& a_point) override;  // 08

		// override (hkpPhantomListener)
		void PhantomAddedCallback(hkpPhantom* a_phantom) override;    // 01
		void PhantomRemovedCallback(hkpPhantom* a_phantom) override;  // 02
		void PhantomDeletedCallback(hkpPhantom* a_phantom) override;  // 04 - { return; }

		// members
		TriggerEntry* triggers;  // 30
		std::uint64_t unk38;     // 38
	};
	static_assert(sizeof(TESTrapListener) == 0x40);
}
