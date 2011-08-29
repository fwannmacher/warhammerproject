/*
 *        M   M  M  MMM                     UUU
 *        M   M M M M M                     U    U   U
 *   WWWW M M M M M MMM                     U   UUU UUU WWWW
 *   WWWW MM MM MMM MM                      U    U   U  WWWW
 *   WW   M   M M M M M       HH HH         UUU           WW
 *   WW                       HH HH                       WW
 *   WW MM  MM   MM   HH      HH HH      HH MMMMMM MMMMMM WW
 *   WW MM  MM   MM   HH      HH HH      HH MMMMMM MMMMMM WW
 *   WW MM  MM MM  MM HHHH  HHHH HHHH  HHHH MM     MM  MM WW
 *   WW MM  MM MM  MM HHHH  HHHH HHHH  HHHH MM     MM  MM WW
 * WW   MMMMMM MM  MM HH  HH  HH HH  HH  HH MMMM   MMMMMM   WW
 * WW   MMMMMM MM  MM HH  HH  HH HH  HH  HH MMMM   MMMMMM   WW
 *   WW MM  MM MMMMMM HH      HH HH      HH MM     MMMM   WW
 *   WW MM  MM MMMMMM HH      HH HH      HH MM     MMMM   WW
 *   WW MM  MM MM  MM HH      HH HH      HH MMMMMM MM  MM WW
 *   WW MM  MM MM  MM HH      HH HH      HH MMMMMM MM  MM WW
 *   WW                       HH HH                       WW
 *   WW                       HH HH                       WW
 *   WWWW                     HH HH                     WWWW
 *   WWWW                     HH HH                     WWWW
 *                            HH HH
 *                            HH HH NNN NNN NNN NNN NNN NNN NNN
 *                            HH HH N N N N N N   N N   N    N
 *                            HH HH NNN NNN N N N N NN  N    N
 *                                  N   NN  N N N N N   N    N
 *                                N N   N N NNN NNN NNN NNN  N
 *
 * FiniteStateMachine.tpp
 *
 *  Created on: Apr 25, 2011
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#ifdef __WarHammer_util_FINITESTATEMACHINE_HPP__

template<typename Context>
WarHammer::util::FiniteStateMachine<Context>::FiniteStateMachine(void)
{
	this->_context = NULL;
	this->_currentState = NULL;
}

template<typename Context>
WarHammer::util::FiniteStateMachine<Context>::FiniteStateMachine(Context* context, WarHammer::util::IState<Context>* initialState)
{
	this->_context = context;
	this->_currentState = initialState;
}

template<typename Context>
WarHammer::util::FiniteStateMachine<Context>::~FiniteStateMachine(void)
{
	delete this->_currentState;
}

template<typename Context>
void WarHammer::util::FiniteStateMachine<Context>::update(void)
{
	if(this->_currentState)
		this->_currentState->execute(this);
}

template<typename Context>
void WarHammer::util::FiniteStateMachine<Context>::changeState(WarHammer::util::IState<Context>* newState)
{
	if(this->_currentState)
	{
		this->_currentState->exit(this);
		delete this->_currentState;
	}

	this->_currentState = newState;
	this->_currentState->enter(this);
}

template<typename Context>
Context* WarHammer::util::FiniteStateMachine<Context>::getContext(void)
{
	return this->_context;
}

template<typename Context>
WarHammer::util::IState<Context>* WarHammer::util::FiniteStateMachine<Context>::getCurrentState(void)
{
	return this->_currentState;
}

#endif
