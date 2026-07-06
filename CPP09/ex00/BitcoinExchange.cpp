#include "BitcoinExchange.hpp"
#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <utility>

static float toFloat( const std::string & string );
static void validateValue( float value );
static void validateKey( const std::string & key );
static int getFebDays( int year );

// Rule of 3

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

// DB parser

void BitcoinExchange::loadDataBase( const std::string & filename ) {

	std::ifstream file( filename.c_str() );
	std::string line;

	if (!file.is_open())
		throw std::runtime_error( "Error: could not open file." );
	
	if (!std::getline(file, line))
		throw std::runtime_error("Error: empty data base file.");

	while ( std::getline( file, line ) ) {
		try {
			std::string message = "Error: bad input => " + line;
			size_t pos = line.find( ',' );
			if (pos == std::string::npos)
				throw std::runtime_error(message);
			std::string key = line.substr( 0, pos );
			validateKey(key);
			std::string v = line.substr( pos + 1);
			float value = toFloat( v );
			_data_base.insert( std::make_pair( key, value ) );
		} catch ( const std::exception & e ) {
			std::cout << e.what() << std::endl;
		}
	}
}

// Input parser

void BitcoinExchange::inputParser( const std::string & filename ) {

	std::ifstream file( filename.c_str() );
	std::string line;

	if (!file.is_open())
		throw std::runtime_error( "Error: could not open file." );

	if (!std::getline(file, line))
		throw std::runtime_error("Error: empty input file.");

	while ( std::getline( file, line ) ) {
		try {
			std::string message = "Error: bad input => " + line;
			size_t pos = line.find( " | " );
			if (pos == std::string::npos)
				throw std::runtime_error( message );
			std::string key = line.substr( 0, pos );
			validateKey(key);
			std::string v = line.substr( pos + 3 );
			float value = toFloat( v );
			validateValue( value );
			computeExchange( key, value );
		} catch ( const std::exception & e ) {
			std::cout << e.what() << std::endl;
		}
	}
}

void BitcoinExchange::computeExchange( const std::string & key, float value ) {
	
	float rate = getExchangeRate( key );
	const float exchange = rate * value;

	std::cout << key
          << " => "
          << value
          << " = "
          << exchange
          << std::endl;
}

float BitcoinExchange::getExchangeRate( const std::string & key ) const {

	if (_data_base.empty())
		throw std::runtime_error( "Error: Empty Data Base" );

	const_iterator it = _data_base.lower_bound( key );

	if ( it == _data_base.begin() && it->first != key ) {
		std::string message = "Error: no previous date available => " + key;
		throw std::runtime_error( message );
	}
	else if ( it == _data_base.end() || it->first != key )
		it--;

	return it->second;
}

// static functions for the parser

static float toFloat( const std::string & string ) {
	
	float res;
	std::stringstream ss(string);

	if ( !( ss >> res ) || !( ss.eof() ) ) {
		std::string message = "Error: bad input => " + string;
		throw std::runtime_error( message );
	}

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