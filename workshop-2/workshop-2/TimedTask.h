#ifndef SDDS_TIMEDTASK_H
#define SDDS_TIMEDTASK_H
#include <iostream>
#include <chrono>
#include <string>

namespace sdds {

	const int MAX_OBJECTS = 10;

	class TimedTask {

		unsigned int m_recordNum = 0u;
		std::chrono::steady_clock::time_point m_startTime;
		std::chrono::steady_clock::time_point m_endTime;

		struct {
			std::string m_task;
			std::string m_timeUnit;
			std::chrono::steady_clock::duration m_duration;
		} taskList[MAX_OBJECTS]{};

	public:
		TimedTask();
		virtual ~TimedTask();
		void startClock();
		void stopClock();
		void addTask(const char* taskName);
		friend std::ostream& operator<<(std::ostream& os, const TimedTask& src);

	};


}
#endif // !SDDS_TIMEDTASK_H

