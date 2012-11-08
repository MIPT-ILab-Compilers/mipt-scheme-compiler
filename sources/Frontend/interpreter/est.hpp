#pragma once

namespace interpreter
{
	namespace est
	{
		enum Type2 { FUNCTION = NEXT_TYPE_ID, MACROS, SPECIAL_FORM, PORT }; //NEXT_TYPE_ID is supposed to be added at the end of Type

		class Function: public Node
		{
		public:
			Function( const Function& src);	
			Function();

			virtual Type2 type() const;
			static Type2 static_type();
	
			virtual ~Function();
		};

		class Macros: public Node
		{
		public:
			Macros( const Macros& src);	
			Macros();

			virtual Type2 type() const;
			static Type2 static_type();
	
			virtual ~Macros();
		};

		class Special_form: public Node
		{
		public:
			Special_form( const Special_form& src);	
			Special_form();

			virtual Type2 type() const;
			static Type2 static_type();
	
			virtual ~Special_form();
		};

		class Port: public Port
		{
		public:
			Port( const Port& src);	
			Port();

			virtual Type2 type() const;
			static Type2 static_type();
	
			virtual ~Port();
		};
	}
}
