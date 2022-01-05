#ifndef H_TEE
#define H_TEE

////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                        //
// INCLUDES                                                                               //
//                                                                                        //
////////////////////////////////////////////////////////////////////////////////////////////
	
#include <iostream>
#include <fstream>
#include <string.h>
#include <iostream>

using namespace std;



////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                        //
// TEE CLASS                                                                              //
//                                                                                        //
////////////////////////////////////////////////////////////////////////////////////////////


class Tee
{	
	private:

		int first_file_index;
		int number_of_arguments;
		char **arguments;
		
		

	public:
		
		Tee(int number_of_arguments, char **arguments); 
		~Tee();


		// ----------------------------------------------------------------------------------   
		// FUNCTIONS
		// ----------------------------------------------------------------------------------   
        
        void read_command();
		void run();
		void empty_file();
		void append_to_file(const string &input, const string &file_name);
		
};


#endif
