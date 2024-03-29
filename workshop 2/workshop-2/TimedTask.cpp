#include "TimedTask.h"
using namespace std;

namespace sdds {

	TimedTask::TimedTask() {}
	TimedTask::~TimedTask() {}

	void TimedTask::startClock() {
		m_startTime = std::chrono::steady_clock::now();
	}
	void TimedTask::stopClock() {
		m_endTime = std::chrono::steady_clock::now();
	}

	void TimedTask::addTask(const char* taskName) {

		if (m_recordNum < MAX_OBJECTS) {
			taskList[m_recordNum].m_task = taskName;
			taskList[m_recordNum].m_timeUnit = "nanoseconds";
			taskList[m_recordNum].m_duration = 
				std::chrono::duration_cast<std::chrono::nanoseconds>(m_endTime - m_startTime);
			m_recordNum++;
		}
	}

	std::ostream& operator<<(std::ostream& os, const TimedTask& src) {
		if (os) {
			os << "--------------------------" << std::endl;
			os << "Execution Times:" << std::endl;
			os << "--------------------------" << std::endl;
			for (unsigned int i = 0u; i < src.m_recordNum; i++) {
				os.width(21);
				os.setf(std::ios::left);
				os << src.taskList[i].m_task << " ";
				os.width(21);
				os.unsetf(std::ios::left);
				os << src.taskList[i].m_duration.count() << " ";
				os << src.taskList[i].m_timeUnit << std::endl;
			}
			os << "--------------------------" << std::endl;
		}
		return os;
	}














}