#pragma once

#include <arduino.h>


class PR_RelayClass {
        public:
			PR_RelayClass(const uint8_t pin, const bool onValue );
            void	begin();
			
			void	on();
			void	off();
			void	set(const bool state);
			
			void	loop();
						
        protected:
			uint8_t	_pin;
			bool	_onValue;
			bool	_state;
			
};

PR_RelayClass::PR_RelayClass(const uint8_t pin, const bool onValue ) 
	:
		_pin(pin),
		_onValue(onValue),
		_state(false)
	{
	begin();
}

void	PR_RelayClass::begin() {
	
	pinMode(_pin, OUTPUT);
	digitalWrite(_pin, !_onValue);
}

void	PR_RelayClass::set(const bool state) {
	
	if ( state ) on(); else off(); 
}

void	PR_RelayClass::on() {
	
	digitalWrite(_pin, _onValue);
	_state = true;
}

void	PR_RelayClass::off() {
	
	digitalWrite(_pin, !_onValue);
	_state = false;
}

void	PR_RelayClass::loop() {

	set(_state);	//reduce risk of wrong pin state if changed somewhere
}	