#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
	public:
		BitcoinExchange();
		BitcoinExchange( const BitcoinExchange& other );
		BitcoinExchange & operator=( const BitcoinExchange& other );
		~BitcoinExchange();

		void loadDataBase( const std::string & filename );
		void inputParser( const std::string & filename );

		typedef std::map<std::string, float>::const_iterator const_iterator;

	private:
		std::map<std::string, float> _data_base;
		void computeExchange( const std::string & key, float value );
		float getExchangeRate( const std::string & key ) const;
};

#endif