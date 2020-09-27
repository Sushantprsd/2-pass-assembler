#include<bits/stdc++.h>
using namespace std ;


int main()
{
    fstream f1,f2,f3;
	f1.open("input.txt",ios::in);
    int current_address,starting_address ;
	string opcode,label, operand ;
	
	string str ;
    getline(f1, str) ;
    stringstream ss ;
    ss << str ;
    ss >> label >> opcode >> operand ;
	
    cout << "Machine Code" << endl<<endl ;

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
			cout << current_address << "\t" << "76" << endl ;
		    break;
		}

		f2.open("opcode.txt",ios::in);
	    f3.open("SymbolTable.txt",ios::in);
	    bool flag = false;
	    string machine_code,temp_label, temp_address ;
		while(!f3.eof())
		{
			
			getline(f3, str) ;
			stringstream ss ;
			ss << str ;
			ss >> temp_address >> temp_label ;
			if(strcmp(operand.c_str(),temp_label.c_str()) == 0 )
			{
				flag = true;
				break;
			}
		}
		
		int label_address;
		if(flag == true)
		{
			label_address = atoi(temp_address.c_str());
		}
		
		f3.close() ;
		if ( operand.length() <= 4 ) {
			while(!f2.eof())
			{
				string temp_opcode,temp_machine_code,temp_operand;
				getline(f2, str) ;
				stringstream ss ;
				ss << str ;
				ss >> temp_opcode >> temp_operand >> temp_machine_code ;

				if(strcmp(opcode.c_str(),temp_opcode.c_str()) == 0 && (flag == true || strcmp(operand.c_str(),temp_operand.c_str()) == 0) )
				{
					machine_code = "" ;
					for ( int i = 0 ; i < temp_machine_code.length() ; i++ ) {
						machine_code += temp_machine_code[i] ;
					}
					break;
				}
			}
			cout << current_address << "\t" << machine_code ;
			if(flag == true)
			{
				string one = to_string(label_address / 100 );
				string two = to_string(label_address % 100 );
				if(two.length() == 1){
					two = "0"+two;
				}
				current_address++ ;
				cout << endl << current_address << "\t" << one << endl ;
				current_address++ ;
				cout << current_address << "\t" << two << endl ;
				current_address++ ;
			}
			else
			{
				cout << endl ;
				// current_address+=1;
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
			f2.close() ;	
		}else if ( operand.length() == 5 ) {
			while(!f2.eof())
			{
				string temp_opcode,temp_machine_code,temp_operand;
				getline(f2, str) ;
				stringstream ss ;
				ss << str ;
				ss >> temp_opcode >> temp_operand >> temp_machine_code ;
				if(strcmp(opcode.c_str(),temp_opcode.c_str()) == 0 && (flag == true || strcmp(operand.substr(0, 1).c_str(),temp_operand.c_str()) == 0) )
				{
					machine_code = "" ;
					for ( int i = 0 ; i < temp_machine_code.length() ; i++ ) {
						machine_code += temp_machine_code[i] ;
					}
					break;
				}
			}
			f2.close() ;
			cout<<current_address << "\t" << machine_code << endl ;
			current_address++ ;
			cout << current_address << "\t" << operand.substr(2, 2) << endl ;
			current_address++ ;
		}else{
			while(!f2.eof())
			{
				string temp_opcode,temp_machine_code,temp_operand;
				getline(f2, str) ;
				stringstream ss ;
				ss << str ;
				ss >> temp_opcode >> temp_operand >> temp_machine_code ;
				if(strcmp(opcode.c_str(),temp_opcode.c_str()) == 0 && (flag == true || strcmp(operand.substr(0, 1).c_str(),temp_operand.c_str()) == 0) )
				{
					machine_code = "" ;
					for ( int i = 0 ; i < temp_machine_code.length() ; i++ ) {
						machine_code += temp_machine_code[i] ;
					}
					break;
				}
			}
			f2.close() ;
			cout << current_address << "\t" << machine_code << endl ;
			current_address++ ;
			cout << current_address << "\t" << operand.substr(2, 2) << endl ;
			current_address++ ;
			cout << current_address << "\t" << operand.substr(4, 2) << endl ;
			current_address++ ;
		}	
	}
	f1.close() ;
    return 0;
} 


