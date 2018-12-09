#pragma once

#include <arduino.h>


class PR_Relay {
        public:
			PR_Relay( const uint8_t pin, const bool onValue );
			~PR_Relay();
			
			void	on();
			void	off();
			void	toggle();
			void	set(const bool state);
			bool	getVal();	
			
			void	loop();
						
        protected:
			uint8_t	_pin;
			bool	_offValue;
			bool	_state;	
			
			inline void	_set();
};

PR_Relay::PR_Relay(const uint8_t pin, const bool onValue ) : 	_pin(pin),
																_offValue(!onValue),
																_state(false)
{
	pinMode(_pin, OUTPUT);
	set(false);
}

PR_Relay::~PR_Relay() {
	
	pinMode(_pin, INPUT);

}

void	PR_Relay::on() 		{ set(true);	}
void	PR_Relay::off()  	{ set(false);	}

void	PR_Relay::toggle() {
	_state = !_state;
	_set();
}

void	PR_Relay::set(const bool value) {
	_state = value;
	_set();
}

inline void	PR_Relay::_set() {
	digitalWrite(_pin, _offValue ^ _state);
}


bool	PR_Relay::getVal() 		{ return _state;  }

void	PR_Relay::loop() {

	_set();	//reduce risk of wrong pin state if changed somewhere
}	