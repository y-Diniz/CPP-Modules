#ifndef RPN_HPP
#define RPN_HPP

#include <stack>

class RPN {

	public:
		RPN();
		RPN( const RPN & other );
		RPN & operator=( const RPN & other );
		~RPN();

		void parseExpression( char *s );
		void getResult();

	private:
		std::stack<double> _numbers;
		void applyOperator( char op );
};

#endif