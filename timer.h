

#ifndef _timer_h_
#define _timer_h_

#define lock Timer::lck++;
#define unlock if (--Timer::lck == 0 && Timer::waitingContextChange == 1) dispatch();

class Timer {
public:

	static volatile int timeSlice;
	static volatile int requestedContextChange;
	static volatile int waitingContextChange;
	static volatile int lck;

	static void init();
	static void restore();

};

// can't be a part of the class due to its name
void interrupt_timer();

void dispatch();

#endif /* _timer_h_ */
