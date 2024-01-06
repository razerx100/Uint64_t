#ifndef UINT64_T_HPP_
#define UINT64_T_HPP_
#include <concepts>
#include <cstdint>

class Uint64_t
{
    template<std::integral T>
    [[nodiscard]]
    constexpr std::uint64_t GetComparator(size_t index) const noexcept { return m_storage; }

public:
    template<std::integral T>
    constexpr Uint64_t& Set(T value, size_t index) noexcept
    {
        constexpr size_t bitCount = sizeof(T) * 8u;
        constexpr size_t offsetCount = (64u / bitCount) - 1u;

        auto value64 = static_cast<std::uint64_t>(value);

        value64 = value64 << ((offsetCount - index) * bitCount);

        m_storage |= value64;

        return *this;
    }

    constexpr Uint64_t& Set(std::uint64_t value) noexcept
    {
        m_storage = value;

        return *this;
    }

    [[nodiscard]]
    constexpr std::uint64_t Get() const noexcept { return m_storage; }

    template<std::integral T>
    [[nodiscard]]
    constexpr auto Get(size_t index) const noexcept
    {
        constexpr size_t bitCount = sizeof(T) * 8u;
        constexpr size_t offsetCount = (64u / bitCount) - 1u;

        return static_cast<T>(
            (m_storage ^ GetComparator<T>(index)) >> ((offsetCount - index) * bitCount)
            );
    }

private:
    std::uint64_t m_storage;
};

template<>
[[nodiscard]]
constexpr std::uint64_t Uint64_t::GetComparator<std::uint8_t>(
    size_t index
) const noexcept {
    switch (index)
    {
    case 0:
    {
        return 0x00ffffffffffffffu;
    }
    case 1:
    {
        return 0xff00ffffffffffffu;
    }
    case 2:
    {
        return 0xffff00ffffffffffu;
    }
    case 3:
    {
        return 0xffffff00ffffffffu;
    }
    case 4:
    {
        return 0xffffffff00ffffffu;
    }
    case 5:
    {
        return 0xffffffffff00ffffu;
    }
    case 6:
    {
        return 0xffffffffffff00ffu;
    }
    case 7:
    {
        return 0xffffffffffffff00u;
    }
    }

    return 0xffffffffffffffffu;
}

template<>
[[nodiscard]]
constexpr std::uint64_t Uint64_t::GetComparator<std::uint16_t>(
    size_t index
) const noexcept {
    switch (index)
    {
    case 0:
    {
        return 0x0000ffffffffffffu;
    }
    case 1:
    {
        return 0xffff0000ffffffffu;
    }
    case 2:
    {
        return 0xffffffff0000ffffu;
    }
    case 3:
    {
        return 0xffffffffffff0000u;
    }
    }

    return 0xffffffffffffffffu;
}

template<>
[[nodiscard]]
constexpr std::uint64_t Uint64_t::GetComparator<std::uint32_t>(
    size_t index
) const noexcept {
    switch (index)
    {
    case 0:
    {
        return 0x00000000ffffffffu;
    }
    case 1:
    {
        return 0xffffffff00000000u;
    }
    }

    return 0xffffffffffffffffu;
}

template<>
[[nodiscard]]
constexpr std::uint64_t Uint64_t::GetComparator<std::int8_t>(
    size_t index
) const noexcept
{
    return GetComparator<std::uint8_t>(index);
}

template<>
[[nodiscard]]
constexpr std::uint64_t Uint64_t::GetComparator<std::int16_t>(
    size_t index
) const noexcept
{
    return GetComparator<std::uint16_t>(index);
}

template<>
[[nodiscard]]
constexpr std::uint64_t Uint64_t::GetComparator<std::int32_t>(
    size_t index
) const noexcept
{
    return GetComparator<std::uint32_t>(index);
}

#endif