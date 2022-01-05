////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                        //
// CONSTRUCTOR / DESTRUCTOR                                                               //
//                                                                                        //
////////////////////////////////////////////////////////////////////////////////////////////

#include "Tee.h"


Tee::Tee(int number_of_arguments, char **arguments) : number_of_arguments(number_of_arguments),arguments(arguments)

{

    this->read_command();

}; 


Tee::~Tee() { };

////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                        //
//                                   FUNCTIONS                                            //
//                                                                                        //
////////////////////////////////////////////////////////////////////////////////////////////

void Tee::read_command()
{
	/////////////////////////////////////////////////////////////////////////////////////


	if(number_of_arguments==1 || strcmp(arguments[1], "tee") != 0){

	    cout<<"No command entered"<<"\n";

	    return;

	}

	else if(number_of_arguments>=4 && strcmp(arguments[2], "-a") == 0){

	    this->first_file_index = 3;

	}

	else if(number_of_arguments>=3 && strcmp(arguments[2], "-a") != 0){

	    this->first_file_index = 2;
	    this->empty_file();

	}

	else{
		
		this->first_file_index = number_of_arguments;

	}


	this->run();

	/////////////////////////////////////////////////////////////////////////////////////
	return;
};

void Tee::run()
{
	/////////////////////////////////////////////////////////////////////////////////////

	string user_input;
	
	while(getline(cin, user_input)){

		cout<<user_input<<"\n";

		int counter = this->first_file_index;

		while(counter<this->number_of_arguments){
			append_to_file(user_input, this->arguments[counter]);
			++counter;
		}

		
	}

	/////////////////////////////////////////////////////////////////////////////////////
	return;
};

void Tee::empty_file()
{
	/////////////////////////////////////////////////////////////////////////////////////

	int counter = this->first_file_index;

		while(counter<this->number_of_arguments){
			ofstream file;

			file.open(arguments[counter], ios_base::trunc);

			file.close();

			++counter;
		}

	/////////////////////////////////////////////////////////////////////////////////////
	return;
};

void Tee::append_to_file(const string &input, const string &file_name)
{
	/////////////////////////////////////////////////////////////////////////////////////
	
	ofstream file;

	file.open(file_name, ios_base::app);
	file<<input<<"\n";

	file.close();

	/////////////////////////////////////////////////////////////////////////////////////
	return;
};
