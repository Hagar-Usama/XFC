/*  XFC: Xfce Foundation Classes (Core Library)
 *  Copyright (C) 2004 The XFC Development Team.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA
 */

/// @file xfc/glib/rand.hh
/// @brief A C++ interface for GRand.
///
/// Provides Rand, pseudo-random number generator.

#ifndef XFC_G_RAND_HH
#define XFC_G_RAND_HH

#ifndef XFC_OBJECT_HH
#include <xfc/object.hh>
#endif

#ifndef __G_RAND_H__
#include <glib/grand.h>
#endif

#ifndef _CPP_VECTOR
#include <vector>
#endif

namespace Xfc {

namespace G {

/// @name Random Number Methods
/// @{

void random_set_seed(unsigned int seed);
///< Sets the seed for the global random number generator, which is used by the G::random_* methods, to seed.
///< @param seed A value to reinitialize the global random number generator.

bool random_boolean();
///< Gets a random boolean value (this corresponds to a unbiased coin toss).
///< @return A random bool value.

unsigned int random_int();
///< Gets a random unsigned integer equally distributed over the range [0..2^32-1].
///< @return A random number.

int random_int_range(int begin, int end);
///< Gets a random integer equally distributed over the range [begin..end-1].
///< @param begin The lower closed bound of the interval.
///< @param end The upper open bound of the interval.
///< @return A random number.

double random_double();
///< Gets a random double equally distributed over the range [0..1).
///< @return A random number.

double random_double_range(double begin, double end);
///< Gets a random double equally distributed over the range [begin..end).
///< @param begin The lower closed bound of the interval.
///< @param end The upper open bound of the interval.
///< @return A random number.

/// @}

/// @class Rand rand.hh xfc/glib/rand.hh
/// A GRand C++ wrapper interface.
///
/// Rand is a portable, fast and good pseudo-random number generator (PRNG). It uses the
/// Mersenne Twister PRNG, which was originally developed by Makoto Matsumoto and Takuji
/// Nishimura. Further information can be found at http://www.math.keio.ac.jp/~matumoto/emt.html.
///
/// If you just need a random number, you can simply call the G::random* methods, which will
/// create a globally used Rand object and use its methods internally. Whenever you need a
/// stream of reproducible random numbers, you should create a Rand object yourself and call
/// its methods directly, which will also be slightly faster. Initializing a Rand with a
/// certain seed will produce exactly the same series of random numbers on all platforms.
/// This can thus be used as a seed for games.
///
/// The Rand range methods will return high quality equally distributed random numbers,
/// whereas for example the (G::Random::get_int()\%max) approach often doesn't yield equally
/// distributed numbers.
///
/// GLib changed the seeding algorithm for the pseudo-random number generator Mersenne Twister,
/// as used by GRand and GRandom. This was necessary, because some seeds would yield very bad
/// pseudo-random streams. Also the pseudo-random integers generated by Rand range methods will
/// have a slightly better equal distribution with the new version of GLib.
///
/// The original seeding and generation algorithms, as found in GLib 2.0.x, can be used instead
/// of the new ones by setting the environment variable G_RANDOM_VERSION to the value of '2.0'.
/// Use the GLib-2.0 algorithms only if you have sequences of numbers generated with Glib-2.0
/// that you need to reproduce exactly.

class Rand : public Xfc::Object
{
	GRand *rand_;

public:
/// @name Constructors
/// @{

	Rand();
	///< Constructs a new random number generator initialized with a seed taken either
	///< from /dev/urandom (if existing) or from the current time (as a fallback).

	Rand(unsigned int seed);
	///< Constructs a new random number generator initialized with <EM>seed</EM>.
	///< @param seed A value to initialize the random number generator.

	Rand(const std::vector<unsigned int>& seed);
	///< Constructs a new random number generator initialized with seed.
	///< @param seed A vector of seeds to initialize the random number generator. 
	
	Rand(const Rand& src);
	///< Copy constructor.
	///< @param src The source random number generator.
	
	~Rand();
	///< Destructor.

	Rand& operator=(const Rand& src);
	///< Assignment operator.
	///< @param src The source random number generator.

/// @}
/// @name Accessors
/// @{

	GRand* g_rand() const;
	///< Get a pointer to the GRand object.

	operator GRand* () const;
	///< Conversion operator; Safely converts a G::Rand object into a GRand pointer.

	bool get_bool() const;
	///< Gets a random boolean value (this corresponds to a unbiased coin toss).
	///< @return A random bool value.

	unsigned int get_int() const;
	///< Gets the next random unsigned integer from the rand equally distributed over the range [0..2^32-1].
	///< @return A random number.

	int get_int_range(int begin, int end) const;
	///< Gets the next random integer from the rand equally distributed over the range [begin..end-1].
	///< @param begin The lower closed bound of the interval.
	///< @param end The upper open bound of the interval.
	///< @return A random number.

	double get_double() const;
	///< Gets the next random double from the rand equally distributed over the range [0..1).
	///< @return A random number.

	double get_double_range(double begin, double end) const;
	///< Gets the next random double from the rand equally distributed over the range [begin..end).
	///< @param begin The lower closed bound of the interval.
	///< @param end The upper open bound of the interval.
	///< @return A random number.

/// @}
/// @name Methods
/// @{

	void set_seed(unsigned int seed);
	///< Sets the seed for the random number generator to seed.
	///< @param seed A value to reinitialize the random number generator.

	void set_seed(const std::vector<unsigned int>& seed);
	///< Initializes the random number generator with a vector of unsigned int. 
	///< @param seed The vector to initialize random number generator with.
	///<
	///< The vector can be of arbitrary size, though only the first 624 values are taken.
	///< This function is useful if you have many low entropy seeds, or if you require more
	///< then 32bits of actual entropy for your application.

/// @}
};

} // namespace G

} // namespace Xfc

#include <xfc/glib/inline/rand.inl>

#endif // XFC_G_RAND_HH
