#pragma once

#include "RE/N/NiTriBasedGeomData.h"

namespace RE
{
	class NiTriShapeData : public NiTriBasedGeomData
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiTriShapeData;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiTriShapeData;
		inline static constexpr auto VTABLE = VTABLE_NiTriShapeData;

		~NiTriShapeData() override;  // 00

		// override (NiTriBasedGeomData)
		const NiRTTI*   GetRTTI() const override;                                                                                                                                     // 02
		void            LoadBinary(NiStream& a_stream) override;                                                                                                                      // 18
		void            LinkObject(NiStream& a_stream) override;                                                                                                                      // 19
		bool            RegisterStreamables(NiStream& a_stream) override;                                                                                                             // 1A
		void            SaveBinary(NiStream& a_stream) override;                                                                                                                      // 1B
		bool            IsEqual(NiObject* a_object) override;                                                                                                                         // 1C
		NiTriShapeData* AsTriShapeData() override;                                                                                                                                    // 28 - { return this; }
		void            CalculateNormals() override;                                                                                                                                  // 29
		void            GetTriangleIndices(std::uint16_t a_triangle, std::uint16_t& a_i0, std::uint16_t& a_i1, std::uint16_t& a_i2) const override;                                   // 2C
		void            GetStripData(std::uint16_t& a_strips, const std::uint16_t*& a_stripLengths, const std::uint16_t*& a_triList, std::uint32_t& a_triListLength) const override;  // 2D

		// members
		std::uint32_t  triListLength;  // 70
		std::uint32_t  pad74;          // 74
		std::uint16_t* triList;        // 78
	};
	static_assert(sizeof(NiTriShapeData) == 0x80);
}
