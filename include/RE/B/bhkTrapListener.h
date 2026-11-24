#pragma once

#include "RE/B/bhkEntityListener.h"
#include "RE/H/hkpPhantomListener.h"

namespace RE
{
	class bhkTrapListener :
		public bhkEntityListener,  // 00
		public hkpPhantomListener  // 18
	{
	public:
		inline static constexpr auto RTTI = RTTI_bhkTrapListener;
		inline static constexpr auto VTABLE = VTABLE_bhkTrapListener;

		~bhkTrapListener() override;  // 00
	};
	static_assert(sizeof(bhkTrapListener) == 0x20);
}
