	// library.cpp
	#include <algorithm>
	#include <iostream>
	#include <stdexcept>
	#include <thread>
	#include <vector>
	#include "library.h"
	#include "library.h"
	
	namespace final{
	
	std::ostream& operator<<(std::ostream& os, const Media& m){
	    os << m.title << " | " << m.publisher << " | ";
	    if (MediaType::Book)
	        os << "Book#" << m.idenifier;
	    else   
	        os << "CD#" << m.idenifier;
	    return os;
	}
	
	void Organizer::operator()(std::vector<Media>::iterator start, std::vector<Media>::iterator end){
	    std::sort(start, end, [this](const Media& a, const Media& b){
	        if (filter == "title") 
	            return a.title < b.title;
	        if (filter == "publisher")
	            return a.publisher < b.publisher;
	        if (filter == "identifier" && a.type == b.type)
	            return a.idenifier < b.idenifier;
	        else
	             return true;
	    });
	};
	
	Library& Library::operator+=(const std::string& name){
	    if (name.empty())
	        throw std::invalid_argument("Not a valid name");
	    staff.push_back({name, false});
	    return *this;
	}
	
	Library& Library::operator+=(const Media& media){
	    material.push_back(media);
	    return *this;
	}
	
	void Library::setOrganizer(Organizer o){
	    org = o;
	
	    auto func = [](std::vector<Librarian> v){
	        for(auto& x : v){
	            if (!x.assigned){
	                return x.name;
	                x.assigned = true;
	            }
	        }
	        throw "No staff available";
	    };
	
	    std::string stf = func(staff);
	    org.assignStaff(stf);
	}
	
	void Library::sortMedia() const{
	    std::thread t1, t2;    
	    t1 = std::thread(org, material.begin(), material.begin() + material.size() / 2);
	    t2 = std::thread(org, material.begin() + material.size() / 2, material.end());
	    t1.join();
	    t2.join();
	}
	
	void Library::display(std::ostream &os) const{
	    os << "***Library Details***\nLibrarians: ";
	    std::for_each(staff.begin(), staff.end(), [&os](const Librarian& stf){
	        os << stf.name << " ";
	    });
	    os << std::endl;
	    std::for_each(material.begin(), material.end(), [&os](const Media& med){
	        os << med << std::endl;
	    });
	}
	
	}