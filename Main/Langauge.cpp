#include <iostream>
#include <sstream>
#include <cmath>
#include <vector>

#define WARN_IF_ERR(F,M) try { F; } catch { std::cout << "Interputer Error: " << M <<"." << std::endl; }

using String = const char*;

/*
*
*
*  CONSTS and FUNCTIONS
*
*
*/


template<typename LengthFigure>
inline int ArrayLength(LengthFigure Text) { return (int) std::floor( sizeof(Text) / sizeof(LengthFigure));}

const char DIGHTS[] = "0123456789";
bool CharacterANumber(char Character) {
	for (char CharacterPicked : DIGHTS) {
		if (CharacterPicked == Character) {
			return true;
		}
	}
	return false;
}



/*
* 
* 
* TOKEN SYSTEM
* 
*
*/





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
	String Value;
	Token(TokenType ValueType = _NULL, String SetValue= "\0") {
		this->Type = ValueType;
		this->Value = SetValue;
	};

	
	template<class ReturnType>
	ReturnType GetValue() {
		ReturnType ReturnValue;
		std::stringstream SS(this->Value);
		SS >> ReturnValue;
		return ReturnValue;
	};
	

};
using TokensVector = std::vector<Token>;





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
		this->CurrentCharacter = (this->Text[Position] > ArrayLength<String>(this->Text) ? this->Text[Position] : '\0');
	}

	Token MakeNumberToken() {
		String Number;

	}

	TokensVector MakeTokens() {
		TokensVector TokensStored;


		while (this->CurrentCharacter != '\0')
			
		{
			
			TokenType D;
			switch (CharacterANumber(this->CurrentCharacter))
			{
			case true:

			}

			switch (this->CurrentCharacter)
			{
			case ' \t':
				this->Advance();
				break;
			case '+':
			{
				D = PLUS;
				Token T(D);
				TokensStored.push_back(T);
				this->Advance();
				break;
			};
			case '-':
			{
				D = MINUS;
				Token T(D);
				TokensStored.push_back(T);
				this->Advance();
				break;
			};
			case '/':
			{
				D = DIV;
				Token T(D);
				TokensStored.push_back(T);
				this->Advance();
				break;
			};
			case '*':
			{
				D = MUL;
				Token T(D);
				TokensStored.push_back(T);
				this->Advance();
				break;
			};
			case '(':
			{
				D = LPAREN;
				Token T(D);
				TokensStored.push_back(T);
				this->Advance();
				break;
			};
			case ')':
			{
				D = RLPAREN;
				Token T(D);
				TokensStored.push_back(T);
				this->Advance();
				break;
			};
			}
		}


		return TokensStored;

	}

public:
	Lexer(String SetText) {
		this->Text = SetText;
		this->Advance();
	}
};