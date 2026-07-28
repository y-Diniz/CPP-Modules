#include "../PmergeMe.hpp"
#include <algorithm>

static std::deque< int > jacobsthalSequence(std::size_t size) {

	std::deque<int> sequence;

	sequence.push_back(1);
	sequence.push_back(3);

	for (std::size_t i = 2; i < size; i++)
		sequence.push_back((sequence[i-1] + (2*sequence[i - 2])));
	
	return sequence;
}

static void binaryInsert( std::deque< int > & chain, int value, size_t target ) {

	size_t start = 0, end = target;

	while (start < end) {
		size_t mid = start + (end - start) / 2;
		if ( value < chain[mid] )
			end = mid;
		else
			start = mid + 1;
	}
	chain.insert(chain.begin() + start, value);
	
}

std::deque<int> PmergeMe::fordJohnson( const std::deque<int> & chain ) {

	size_t c_size = chain.size();
	
	if (c_size == 1)
		return chain;

	std::deque< std::pair<int, int> > pairs;
	std::deque<int> winners;
	size_t i;

	for ( i = 0; i <= c_size - 2; i+=2 ) {
		int a = chain[i], b = chain[i+1];
		if ( a > b )
			std::swap(a, b);
		pairs.push_back( std::make_pair(a, b) );
		winners.push_back(b);
	}

	winners = fordJohnson( winners );

	std::deque<int> ordered(winners);
	size_t p_size = pairs.size();
	std::deque<int> losers;

	for ( i = 0; i < winners.size(); i++ ) {
		for ( size_t j = 0; j < p_size; j++ ) {
			if (pairs[j].second == winners[i]) {
				if (i == 0)
					ordered.insert(ordered.begin(), pairs[j].first);
				else
					losers.push_back(pairs[j].first);
			}	
		}
	}

	size_t l_size = losers.size();
	std::deque<int> sequence = jacobsthalSequence(l_size + 2);

	size_t first = 1;
	size_t j = 1;

	while ( first <= l_size ) {
		size_t last = sequence[j] - 1;
		if (last > l_size)
			last = l_size;
		
		for ( size_t i = last; i >= first; i-- ) {
			int winner = winners[i];
			int loser = losers[i - 1];
			std::deque<int>::iterator it = std::find(ordered.begin(), ordered.end(), winner);
			std::size_t target = static_cast<std::size_t>(it - ordered.begin());
			binaryInsert(ordered, loser, target);
		}
		first = last + 1;
		++j;
	}

	if ( c_size % 2 != 0 )
		binaryInsert(ordered, chain[c_size - 1], ordered.size());

	return ordered;
}
