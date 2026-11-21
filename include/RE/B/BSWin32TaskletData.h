#pragma once

#include "RE/B/BSAtomic.h"
#include "RE/B/BSTaskletData.h"

namespace RE
{
	class BSWin32TaskletGroupData;

	class BSWin32TaskletData : public BSTaskletData
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSWin32TaskletData;
		inline static constexpr auto VTABLE = VTABLE_BSWin32TaskletData;

		~BSWin32TaskletData() override;  // 00

		// members
		BSWin32TaskletGroupData* groupData;     // 10
		bool                     runOnStartup;  // 18
		std::uint8_t             pad19;         // 19
		std::uint16_t            pad1A;         // 1A
		BSNonReentrantSpinLock   taskLock;      // 1C
		BSWin32TaskletData*      next;          // 20
	};
	static_assert(sizeof(BSWin32TaskletData) == 0x28);
}
