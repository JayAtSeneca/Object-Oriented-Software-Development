	// main.cpp
	#include <iostream>
	#include <memory>
	#include <string>
	#include "library.h"
	#include "library.h"
	using namespace final;
	
	std::string librarians[] { "James", "", "Yozora", "Eliza", "Mel"};
	
	Media books[]{
	    {"Cats Vol1", "Kitty Books", MediaType::Book, 123},
	    {"Dogs Vol8", "Canine Company", MediaType::Book, 283},
	    {"World of Coffee", "National Geographic", MediaType::Book, 999},
	    {"One Last Kiss", "Novelas Inc.", MediaType::Book, 2},
	};
	Media cds[]{
	    {"Stellar Stellar", "King Label", MediaType::CompactDisc, 44},
	    {"Strings Collection Vol2", "Classical Tunes", MediaType::CompactDisc, 84},
	    {"Sound of Colour (Audio Edition)", "Penguin Books", MediaType::CompactDisc, 12},
	    {"Strings Collecting Tips", "Penguin Books", MediaType::CompactDisc, 2000},
	};
	
	int main(){
	    Library lib1;
	    Library lib2 = lib1;
	    Organizer o1("identifier"), o2("publisher");
	
	    for(auto i = 0; i < 4; ++i)
	        lib1 += books[i];
	    for(auto i = 0; i < 4; ++i)
	        lib2 += cds[i];
	
	    ((lib1 += librarians[0]) += librarians[1]) += librarians[3];
	    (lib2 += librarians[4]) += librarians[2];
	
	    lib1.setOrganizer(o1);
	    lib2.setOrganizer(o2);
	
	    lib1.sortMedia();
	    lib2.sortMedia();
	
	    lib1.display(std::cout);
	    lib2.display(std::cout);
	}