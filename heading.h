#ifndef"HEADING_H"
#define"HEADING_H"
#include <iostream>
#include <string>

class student {
	private:
		int code;
		string name;
		float score;
	public:
		void Addstudent();
		void Deletestudent();
		void Searchstudent();
		void Changestudent();
};

friend void Ranking();
friend void printhomepage();
friend void totalRank();
friend void Average();
friend void Highest();
friend void Lowest();
#endif