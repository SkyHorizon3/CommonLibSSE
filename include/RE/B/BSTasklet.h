#pragma once

namespace RE
{
	class BSTaskletData;

	class BSTasklet
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSTasklet;
		inline static constexpr auto VTABLE = VTABLE_BSTasklet;

		virtual ~BSTasklet();  // 00

		// members
		BSTaskletData* data;  // 08
	};
	static_assert(sizeof(BSTasklet) == 0x10);
}
