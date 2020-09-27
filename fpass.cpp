#include<bits/stdc++.h>
using namespace std ;

int main()
{
	fstream f1,f2;
	int current_address,starting_address;
	string label,opcode,operand;
	f1.open("input.txt", ios::in);
	f2.open("SymbolTable.txt", ios::out);
    string str ;
    getline(f1, str) ;
    stringstream ss ;
    ss << str ;
    ss >> label >> opcode >> operand;

	if(strcmp(opcode.c_str(),"START")==0)
	{
		starting_address=atoi(operand.c_str());
		current_address = starting_address;	
	}	

	while(!f1.eof())
	{
        getline(f1, str) ;
        stringstream ss ;
        ss << str ;
        ss >> label >> opcode >> operand ;
		if(strcmp(opcode.c_str(),"HLT")==0)
		{
           cout << endl << "Total memory required " << current_address - starting_address << " bytes" << endl ;
		}
		if(strcmp(label.c_str(),"$")!=0)
		{

			f2 << current_address << "\t" << label.substr(0, label.length()) << endl ;
			cout << current_address << '\t' << label.substr(0, label.length()) << endl ;
		}
		if(strcmp(opcode.c_str(),"MOV") == 0 
			||	strcmp(opcode.c_str(),"SUB") == 0 
			||	strcmp(opcode.c_str(),"ADD") == 0 
			||	strcmp(opcode.c_str(),"INR") == 0 
			||	strcmp(opcode.c_str(),"INX") == 0
			||	strcmp(opcode.c_str(),"DCX") == 0 
			||	strcmp(opcode.c_str(),"CMP") == 0
			||	strcmp(opcode.c_str(),"DCR") == 0 )
		{
			current_address += 1;
		}
		else if(strcmp(opcode.c_str(),"JC") == 0 
			|| strcmp(opcode.c_str(),"JNZ") == 0 
			|| strcmp(opcode.c_str(),"JZ") == 0 
			|| strcmp(opcode.c_str(),"JNC") == 0 
			|| strcmp(opcode.c_str(),"LXI") == 0 )
		{
			current_address+=3;
		}
		else 
		{
			current_address+=2;
		}
	}
	f1.close() ;
    f2.close() ;
    return 0;
    }
