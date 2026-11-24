#pragma once

#include "RE/N/NiTriBasedGeomData.h"

namespace RE
{
	class NiTriStripsData : public NiTriBasedGeomData
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiTriStripsData;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiTriStripsData;
		inline static constexpr auto VTABLE = VTABLE_NiTriStripsData;

		~NiTriStripsData() override;  // 00

		// override (NiTriBasedGeomData)
		const NiRTTI*               GetRTTI() const override;                                                                                                                                     // 02
		void                        LoadBinary(NiStream& a_stream) override;                                                                                                                      // 18
		void                        LinkObject(NiStream& a_stream) override;                                                                                                                      // 19
		bool                        RegisterStreamables(NiStream& a_stream) override;                                                                                                             // 1A
		void                        SaveBinary(NiStream& a_stream) override;                                                                                                                      // 1B
		bool                        IsEqual(NiObject* a_object) override;                                                                                                                         // 1C
		[[nodiscard]] std::uint32_t GetBlockAllocationSize() const override;                                                                                                                      // 21
		NiTriStripsData*            AsTriStripsData() override;                                                                                                                                   // 27 - { return this; }
		void                        CalculateNormals() override;                                                                                                                                  // 29
		void                        GetTriangleIndices(std::uint16_t a_triangle, std::uint16_t& a_i0, std::uint16_t& a_i1, std::uint16_t& a_i2) const override;                                   // 2C
		void                        GetStripData(std::uint16_t& a_strips, const std::uint16_t*& a_stripLengths, const std::uint16_t*& a_triList, std::uint32_t& a_triListLength) const override;  // 2D

		// members
		std::uint16_t  numStrips;     // 70
		std::uint16_t  pad72;         // 72
		std::uint32_t  pad74;         // 74
		std::uint16_t* stripLengths;  // 78
		std::uint16_t* stripLists;    // 80
	};
	static_assert(sizeof(NiTriStripsData) == 0x88);
}
