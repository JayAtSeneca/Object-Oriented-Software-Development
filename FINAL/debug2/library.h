	// library.h
	#ifndef FINAL_LIBRARY_H
	#define FINAL_LIBRARY_H
	#include <algorithm>
	#include <iostream>
	#include <list>
	#include <string>
	#include <vector>
	
	namespace final {
	
	enum MediaType { Book, CompactDisc};
	
	struct Media {
	    std::string title{};
	    std::string publisher{};
	    MediaType type{};
	    unsigned idenifier{};
	
	    Media(const std::string& ti, const std::string& pu, MediaType mt, unsigned id)
	        : title(ti), publisher(pu), type(mt), idenifier(id){};
	};
	
	std::ostream& operator<<(std::ostream& os, const Media& m);
	
	class Organizer{
	    std::string staff{};
	    std::string filter{};
	public:
	    Organizer(std::string fil = "empty") : filter(fil){};
	    void assignStaff(std::string stf) { staff = stf; }
	    std::string getStaff() const { return staff; }
	    void operator()(std::vector<Media>::iterator start, std::vector<Media>::iterator end);
	};
	
	class Library {
	    struct Librarian{
	        std::string name{};
	        bool assigned{};
	    };
	
	    std::vector<Media> material;
	    std::vector<Librarian> staff;
	    Organizer org;
	
	public:
	    Library(){}
	
	    Library(const Library&) = delete;
	    Library(Library&&) = delete;
	    Library& operator=(const Library&) = delete;
	    Library& operator=(Library&&) = delete;
	
	    Library& operator+=(const std::string& name);
	    Library& operator+=(const Media& media);
	    void setOrganizer(Organizer o);
	    void sortMedia() const;
	    void display(std::ostream& os) const;
	};
	
	};
	
	#endif