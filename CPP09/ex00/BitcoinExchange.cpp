#include "BitcoinExchange.hpp"
#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

static float toFloat( std::string & string );
static void validateValue( float value );
static void validateKey( const std::string & key );
static int getFebDays( int year );

BitcoinExchange::BitcoinExchange() { }

BitcoinExchange::BitcoinExchange( const BitcoinExchange& other ) {
	_data_base = other._data_base;
}

BitcoinExchange & BitcoinExchange::operator=( const BitcoinExchange& other ) {
	if ( this != &other )
		_data_base = other._data_base;
	return *this;
}

BitcoinExchange::~BitcoinExchange() { }

void BitcoinExchange::loadDataBase( std::string & filename ) {

	std::string line;
	std::ifstream file( filename );

	if (!file.is_open())
		throw std::runtime_error( "Error: could not open file." );
	
	std::getline(file, line);

	while (std::getline(file, line)) {
		try {
			size_t pos = line.find_first_of( ',' , 0 );
			if (pos == std::string::npos)
				throw std::runtime_error("Error: Invalid Format.");
			std::string key = line.substr( 0, pos );
			validateKey(key);
			std::string v = line.substr( pos + 1);
			float value = toFloat( v );
			_data_base.insert( std::make_pair( key, value ) );
		} catch ( std::exception & e ) {
			std::cout << e.what() << std::endl;
		}
	}
}

// static functions for the parser

static float toFloat( std::string & string ) {
	
	float res;
	std::stringstream ss(string);

	if (!(ss >> res))
		throw std::runtime_error( "Error: Conversion failed." );
	if (!(ss.eof()))
		throw std::runtime_error( "Error: Invalid Format." );

	return res;
}

static void validateValue( float value ) {
	if ( value < 0 )
		throw std::runtime_error("Error: not a positive number.");
	if ( value > 1000 )
		throw std::runtime_error("Error: too large a number.");
}

static void validateKey( const std::string & key ) {

	std::string message = "Error: bad input => " + key;

	if ( key.size() != 10 || key[4] != '-' || key[7] != '-' )
		throw std::runtime_error( message );

	int y, m, d;
	int res = sscanf(key.c_str(), "%d-%d-%d", &y, &m, &d);

	if (res != 3)
		throw std::runtime_error( message );

	int max_days[] = {0, 31, getFebDays(y), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if ( !( m >= 1 && m <= 12 ) || !( max_days[m] >= d && d >= 1 ) || y < 2009 )
		throw std::runtime_error( message );
}

static int getFebDays( int year ) {
	if ( year % 4 == 0 && ( year % 100 != 0 || year % 400 == 0 ) )
		return 29;
	return 28;
}