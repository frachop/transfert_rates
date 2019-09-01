#ifndef TRANSFERT_RATES
#define TRANSFERT_RATES 1

// standards includes
#include <cstdint> // for uint64_t

//- /////////////////////////////////////////////////////////////////////////////////////////////////////////
// - see https://www.fluentcpp.com/2016/12/08/strong-types-for-strong-interfaces/

template <typename T, typename PhantomType>
class TNamedType
{
public:
	explicit TNamedType(T const &value) : _value(value) {}
	explicit TNamedType(T &&value) : _value(std::move(value)) {}
	T &get() { return _value; }
	T const &get() const { return _value; }

private:
	T _value;
};

//- /////////////////////////////////////////////////////////////////////////////////////////////////////////

using transfert_rate_t = uint64_t; // in bit per seconds (bps)
using download_rate_t = TNamedType<transfert_rate_t, struct tagDlRate>;
using upload_rate_t = TNamedType<transfert_rate_t, struct tagUlRate>;

template <typename T>
inline T toBps(transfert_rate_t const &t) { return static_cast<T>(t) / static_cast<T>(8); }
template <typename T>
inline T toKBps(transfert_rate_t const &t) { return static_cast<T>(t) / static_cast<T>(8 * 1024); }
template <typename T>
inline T toMBps(transfert_rate_t const &t) { return static_cast<T>(t) / static_cast<T>(8 * 1024 * 1024); }
template <typename T>
inline T toGBps(transfert_rate_t const &t) { return static_cast<T>(t) / static_cast<T>(8 * 1024 * 1024 * 1024UL); }

template <typename T>
inline transfert_rate_t fromBps(T const &t) { return static_cast<transfert_rate_t>(static_cast<T>(8) * t); }
template <typename T>
inline transfert_rate_t fromKBps(T const &t) { return static_cast<transfert_rate_t>(static_cast<T>(8 * 1024) * t); }
template <typename T>
inline transfert_rate_t fromMBps(T const &t) { return static_cast<transfert_rate_t>(static_cast<T>(8 * 1024 * 1024) * t); }

inline namespace transfert_rate_literals
{
constexpr transfert_rate_t operator"" _bps(unsigned long long int bps) { return static_cast<transfert_rate_t>(bps); }
constexpr transfert_rate_t operator"" _Kbps(unsigned long long int Kbps) { return static_cast<transfert_rate_t>(1024_bps * Kbps); }
constexpr transfert_rate_t operator"" _Mbps(unsigned long long int Kbps) { return static_cast<transfert_rate_t>(1024_Kbps * Kbps); }
constexpr transfert_rate_t operator"" _Gbps(unsigned long long int Gbps) { return static_cast<transfert_rate_t>(1024_Mbps * Gbps); }

constexpr transfert_rate_t operator"" _Bps(unsigned long long int Bps) { return static_cast<transfert_rate_t>(8_bps * Bps); }
constexpr transfert_rate_t operator"" _KBps(unsigned long long int KBps) { return static_cast<transfert_rate_t>(1024_Bps * KBps); }
constexpr transfert_rate_t operator"" _MBps(unsigned long long int MBps) { return static_cast<transfert_rate_t>(1024_KBps * MBps); }
constexpr transfert_rate_t operator"" _GBps(unsigned long long int GBps) { return static_cast<transfert_rate_t>(1024_MBps * GBps); }
} // namespace transfert_rate_literals

#endif /* TRANSFERT_RATES */