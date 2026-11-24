#pragma once

#include "RE/N/NiTriBasedGeometry.h"

namespace RE
{
	class NiTriStrips : public NiTriBasedGeometry
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiTriStrips;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiTriStrips;
		inline static constexpr auto VTABLE = VTABLE_NiTriStrips;

		~NiTriStrips() override;  // 00

		// override (NiTriBasedGeometry)
		const NiRTTI* GetRTTI() const override;                          // 02
		void          LoadBinary(NiStream& a_stream) override;           // 18
		void          LinkObject(NiStream& a_stream) override;           // 19
		bool          RegisterStreamables(NiStream& a_stream) override;  // 1A
		void          SaveBinary(NiStream& a_stream) override;           // 1B
		bool          IsEqual(NiObject* a_object) override;              // 1C

		// override (NiObject)
		NiTriStrips* AsTriStrips() override;                                              // 08
		NiObject*    CreateClone([[maybe_unused]] NiCloningProcess& a_cloning) override;  // 17
	};
	static_assert(sizeof(NiTriStrips) == 0x138);
}
