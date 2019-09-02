#include "../include/transfert_rates.hpp"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("initialisations","[conversions]")
{
	transfert_rate_t const _1KBps{ fromKBps( 1 ) };
	REQUIRE( toKBps<int>( _1KBps ) == 1 );
}


