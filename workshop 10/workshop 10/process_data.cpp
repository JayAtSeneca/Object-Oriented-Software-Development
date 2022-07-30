// Workshop 9 - Multi-Threading, Thread Class
// process_data.cpp
// 2021/1/5 - Jeevan Pant


#include "process_data.h"
using namespace std::placeholders;

namespace sdds_ws9 {

	void computeAvgFactor(const int* arr, int size, int divisor, double& avg) {
		avg = 0;
		for (int i = 0; i < size; i++) {
			avg += arr[i];
		}
		avg /= divisor;
	}

	void computeVarFactor(const int* arr, int size, int divisor, double avg, double& var) {
		var = 0;
		for (int i = 0; i < size; i++) {
			var += (arr[i] - avg) * (arr[i] - avg);
		}
		var /= divisor;
	}
	ProcessData::operator bool() const {
		return total_items > 0 && data && num_threads>0 && averages && variances && p_indices;
	}

	ProcessData::ProcessData(std::string filename, int n_threads) {  
		// TODO: Open the file whose name was received as parameter and read the content
		//         into variables "total_items" and "data". Don't forget to allocate
		//         memory for "data".
		//       The file is binary and has the format described in the specs.
		std::ifstream file(filename, std::ios::in | std::ios::binary);
		if (file) {
			file.read((char*)&total_items, sizeof (total_items));
			data = new int[total_items];
			for (int i = 0; i < total_items; i++) {
				file.read((char*)&data[i], sizeof(data[i]));
			}
		}



		std::cout << "Item's count in file '"<< filename << "': " << total_items << std::endl;
		std::cout << "  [" << data[0] << ", " << data[1] << ", " << data[2] << ", ... , "
		          << data[total_items - 3] << ", " << data[total_items - 2] << ", "
		          << data[total_items - 1] << "]\n";

		// Following statements initialize the variables added for multi-threaded 
		//   computation
		num_threads = n_threads; 
		averages = new double[num_threads] {};
		variances = new double[num_threads] {};
		p_indices = new int[num_threads+1] {};
		for (int i = 0; i < num_threads+1; i++)
			p_indices[i] = i * (total_items / num_threads);
	}
	ProcessData::~ProcessData() {
		delete[] data;
		delete[] averages;
		delete[] variances;
		delete[] p_indices;
	}

	// TODO Improve operator() function from part-1 for multi-threaded operation. Enhance the  
	//   function logic for the computation of average and variance by running the 
	//   function computeAvgFactor and computeVarFactor in multile threads. 
	// The function divides the data into a number of parts, where the number of parts is 
	//   equal to the number of threads. Use multi-threading to compute average-factor for 
	//   each part of the data by calling the function computeAvgFactor. Add the obtained 
	//   average-factors to compute total average. Use the resulting total average as the 
	//   average value argument for the function computeVarFactor, to compute variance-factors 
	//   for each part of the data. Use multi-threading to compute variance-factor for each 
	//   part of the data. Add computed variance-factors to obtain total variance.
	// Save the data into a file with filename held by the argument fname_target. 
	// Also, read the workshop instruction.
	int ProcessData::operator()(std::string fileName, double& avg, double& var) {
		int retVal = 0;
		std::vector<std::thread> avgThreads;
		std::vector<std::thread> varianceThreads;

		// To compute Average
		for (int i = 0; i < num_threads; i++) {
			avgThreads.push_back(std::thread(std::bind(computeAvgFactor, &data[p_indices[i]], p_indices[1], total_items, std::ref(averages[i]))));
		}
		for (auto& ps : avgThreads) {
			ps.join();
		}
		for (int i = 0; i < num_threads; i++) {
			avg += averages[i];
		}

		// To compute variance
		for (int i = 0; i < num_threads; i++) {
			varianceThreads.push_back(std::thread(std::bind(computeVarFactor, &data[p_indices[i]], p_indices[1], total_items, std::ref(avg), std::ref(variances[i]))));
		}
		for (auto& ps2 : varianceThreads) {
			ps2.join();
		}
		for (int i = 0; i < num_threads; i++) {
			var += variances[i];
		}

		std::ofstream file(fileName, std::ios::out | std::ios::binary);
		if (file) {
			file.write((char*)&total_items, sizeof(total_items));
			for (int i = 0; i < total_items; i++) {
				file.write((char*)&data[i], sizeof(data[i]));
			}
			file.close();
			retVal = 1;
		}
		else {
			throw std::string("ERROR: cannot open file ");
		}
		return retVal;
	}



}