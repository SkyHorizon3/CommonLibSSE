#pragma once

#include "RE/N/NiGeometryData.h"

namespace RE
{
	class NiTriBasedGeomData : public NiGeometryData
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiTriBasedGeomData;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiTriBasedGeomData;
		inline static constexpr auto VTABLE = VTABLE_NiTriBasedGeomData;

		~NiTriBasedGeomData() override;  // 00

		// override (NiGeometryData)
		const NiRTTI* GetRTTI() const override;                          // 02
		void          LoadBinary(NiStream& a_stream) override;           // 18
		void          LinkObject(NiStream& a_stream) override;           // 19
		bool          RegisterStreamables(NiStream& a_stream) override;  // 1A
		void          SaveBinary(NiStream& a_stream) override;           // 1B
		bool          IsEqual(NiObject* a_object) override;              // 1C

		// add
		virtual void                        SetActiveTriangleCount(std::uint16_t a_count);                                                                                                       // 2A - { return; }
		[[nodiscard]] virtual std::uint16_t GetActiveTriangleCount() const;                                                                                                                      // 2B - { return triangles; }
		virtual void                        GetTriangleIndices(std::uint16_t a_triangle, std::uint16_t& a_i0, std::uint16_t& a_i1, std::uint16_t& a_i2) const;                                   // 2C - { return; }
		virtual void                        GetStripData(std::uint16_t& a_strips, const std::uint16_t*& a_stripLengths, const std::uint16_t*& a_triList, std::uint32_t& a_triListLength) const;  // 2D - { return; }

		// members
		std::uint16_t numtriangles;     // 68
		std::uint16_t activeTriangles;  // 6A
		std::uint32_t pad6C;            // 6C
	};
	static_assert(sizeof(NiTriBasedGeomData) == 0x70);
}
