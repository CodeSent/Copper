#include <iostream>
#include <sstream>
#include <cmath>

#define WARN_IF_ERR(F,M) try { F; } catch { std::cout << "Interputer Error: " << M <<"." << std::endl; }

using String = const char*;


template<typename LengthFigure>
inline int ArrayLength(LengthFigure Text) { return (int) std::floor( sizeof(Text) / sizeof(LengthFigure));}

/*
* 
* 
* TOKEN SYSTEM
* 

*/

 ;
enum TokenType
{
	_NULL   =  0,
	INT     =  1,
	FLOAT   =  2,
	PLUS    =  3,
	MINUS   =  4,
	MUL     =  5,
	DIV     =  6,
	LPAREN  =  7,
	RLPAREN =  8
};



struct Token {
	TokenType Type;
	std::stringstream Value;

	Token(TokenType ValueType, String SetValue) : Type(ValueType) {
		this->Value << SetValue;
	};

	template<class ReturnType>
	ReturnType GetValue() {
		ReturnType ReturnValue;
        this->Value >> ReturnValue;
		return ReturnValue;
	};

};
+


/*
* 
* 
* LEXER
* 
* 
*/

class Lexer
{
	int Position = -1;
	char CurrentCharacter;
	String Text;

	void Advance() {
		this->Position++;
		this->CurrentCharacter = (this->Text[Position] > ArrayLength<String>(this->Text) ? this->Text[Position] : '/0');
	}

public:
	Lexer(String SetText) {
		this->Text = SetText;
		this->Advance();
	}
};