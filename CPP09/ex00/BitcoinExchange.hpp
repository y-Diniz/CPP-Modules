#pragma once

#include <exception>
#include <map>
#include <string>

class BitcoinExchange {
	public:
		BitcoinExchange();
		BitcoinExchange( const BitcoinExchange& other );
		BitcoinExchange & operator=( const BitcoinExchange& other );
		~BitcoinExchange();

		void loadDataBase( std::string & filename );

	private:
		std::map<std::string, float> _data_base;
};
