#include "GeneratingList.h"
#include "EmpProfile.h"
#include "WritingRecord.h"

using namespace std;

namespace sdds {
	GeneratingList<EmployeeWage> writeRaw(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;
		// TODO: Add your code here to build a list of employees
		//         using raw pointers
		for (size_t i = 0u; i < emp.size(); i++) {
			for (size_t j = 0u; j < sal.size(); j++) {
				if (emp[i].id == sal[j].id) {
					EmployeeWage* ptr = new EmployeeWage(emp[i].name, sal[j].salary);
					try {
						ptr->rangeValidator();
						if (activeEmp.checkLuhn(emp[i].id)) {
							activeEmp += ptr;
							delete ptr;
							ptr = nullptr;
						}
						else {
							throw std::string("Invalid SIN");
						}
					}
					catch (const std::string& msg) {
						delete ptr;
						ptr = nullptr;
						throw msg;
					}
				}
			}
		}
		
		return activeEmp;
	}

	GeneratingList<EmployeeWage> writeSmart(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;
		// TODO: Add your code here to build a list of employees
		//         using smart pointers
		
		for (size_t i = 0u; i < emp.size(); i++) {
			for (size_t j = 0u; j < sal.size(); j++) {
				if (emp[i].id == sal[j].id) {
					std::unique_ptr<EmployeeWage> smtPtr(new EmployeeWage(emp[i].name, sal[j].salary));
					try {
						smtPtr->rangeValidator();
						if (activeEmp.checkLuhn(emp[i].id)) {
							activeEmp += smtPtr;
						}
						else {
							throw std::string("Invalid SIN");
						}
					}
					catch (const std::string& msg) {
						throw msg;
					}
				}
			}
		}


		return activeEmp;
	}
}