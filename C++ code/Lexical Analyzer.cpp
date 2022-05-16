#include<iostream>
#include<fstream>
#include<sstream>
#include <queue>
std::queue<std::string> gettoken;
using namespace std;

int token =0;
bool check_alpha(char ch)
{
	if((ch>='a' && ch<='z')||(ch>='A' && ch<='Z'))
	return true;
	else
	return false;
}
bool check_digit(char ch){
	if((ch>='0' && ch<='9'))
	return true;
	else
	return false;
}
bool check_delimiter(char ch)
{
	if(ch==' ' ||ch=='\t' ||ch=='\n')
	return true;
	else
	return false;
	
}
bool check_comment(char ch)
{
	if(ch=='$')
	return true;
	else
	return false;
	
}

bool check_sperator(char ch)
{
	if(ch==';'||ch=='{'||ch=='}'||ch=='('||ch==')'||ch=='<')
	return true;
	else
	return false;
	
}
bool check_operator(char ch)
{
	if(ch=='+'||ch=='-'||ch=='*'||ch=='/')
	return true;
	else
	return false;
	
}
bool check_keyword(string lexeme)
{
		if(lexeme=="integer"|| lexeme=="SSmain"||lexeme=="var"||lexeme=="floop"||lexeme=="wloop"||lexeme=="Type"||lexeme=="getback")
	return true;
	else
	return false;
}
void Lexical_Analyzer(string str){
	
	
	int i=0;

	string lexeme;
	int flag=0;

	int state=0;
	char ch='\0';
	
   ofstream outfile;
   outfile.open("C-output.fas");
	while(str[i]!='\0')
	{
		ch=str[i];
		
		flag=1;
		if(state==3)
		{
			
			
						if(ch=='=')
						{
					
						
						lexeme=lexeme+ch;
						state=0;
					    outfile<<lexeme<<" is an Operator "<<endl;
					     gettoken.push(lexeme);
					    token++;
					    lexeme="";
									
					
				
					     	
						}
						else{

							
						state=0;
					 	outfile<< lexeme <<" is an Operator "<<endl;
				    	 gettoken.push(lexeme);
						token++;
						lexeme="";
			
						
					}
					
					
						
		}
		
		if(state==4)
		{
			
			
						if(ch=='=')
						{
					
						
						lexeme=lexeme+ch;
						state=0;
					    outfile<<lexeme<<" is an Operator "<<endl;
					     gettoken.push(lexeme);
						token++;
						lexeme="";
					
					
				
					     	
						}
						else{

							
						state=0;
					 	outfile<< lexeme <<" is an Operator "<<endl;
				    	 gettoken.push(lexeme);
						lexeme="";
						token++;
						
					}
					
					
						
		}
		if(state==5)
		{
			
			
						if(ch=='=')
						{
					
						
						lexeme=lexeme+ch;
						state=0;
					    outfile<<lexeme<<" is an Operator "<<endl;
					     gettoken.push(lexeme);
						lexeme="";
						token++;
					
				
					     	
						}
						else{

							
						state=0;
					 	outfile<< lexeme <<" is an Operator "<<endl;
				    	 gettoken.push(lexeme);
						lexeme="";
				token++;
						
					}
					
					
						
		}
		
		if(state ==0)
		{
				if(check_alpha(ch))
				{
					state=1;	
				}
				else if(check_digit(ch))
				{
					state=2;	
				}
				
				else if(check_operator(ch))
				{
					state=0;
					 lexeme=ch;
					outfile<<" "<< lexeme <<" is an Operator "<<endl;
					 gettoken.push(lexeme);
					lexeme="";	
					flag=0;
					token++;	
				}
				
				else if(ch=='<')
				{
					state=3;	
					flag=1;
				
					
					
				}
				else if(ch=='>')
				{
					state=4;	
					
				}
					else if(ch=='=')
				{
					state=0;
					if(!(str[i-1]=='>'||str[i-1]=='<'||str[i-1]=='='))
				{
					
					state=5;
				}
				else
				{
					
					lexeme="";	
					flag=0;
				}	
				
				}
				
				else if(check_sperator(ch))
				{
						state=0;
						 lexeme=ch;
					outfile<<" "<< lexeme <<" is a Sperator "<<endl;
					 gettoken.push(lexeme);
					lexeme="";	
					flag=0;	
					token++;
				}
				else if(check_delimiter(ch))
				{
					flag=0;	
				}
				else{
					outfile<"Invalid";
				}
			
		}
		if(state ==1)
		{
				if(!(check_alpha(ch)||check_digit(ch)))
				{
				
				     	state=0;
						if(check_keyword(lexeme))
						{
					      state=0;
					outfile<<" "<< lexeme <<" is a Keyword "<<endl;
					   gettoken.push(lexeme);
					  lexeme="";
					  token++;
						}
						else
						{
					       outfile<<" "<< lexeme <<" is an Identifier "<<endl;
					        gettoken.push(lexeme);
						token++;
						}
						lexeme="";
						
				continue;
				}
		}
		if(state ==2)			
					{
					
						if(!check_digit(ch))
						{
					      state=0;
					    outfile<<" "<< lexeme <<" is a Digit "<<endl;
					     gettoken.push(lexeme);
						token++;
						 lexeme="";
					     
				     	continue;
						}
						
					}

		
	
	
	    	if(flag==1)
	    	lexeme=lexeme+ch;
	    	   
	    
	    		
		i++;
	
	}
	
		
	outfile<<"\n-----------------------";
	outfile<<"\nNo of tokens: "<<token;
		outfile<<"\n-----------------------";
	
	 outfile.close();

}
std::string c_token; 
	

void E()
{
	gettoken.pop();
		if(gettoken.front()==";")
		{
		std::cout<<endl<< gettoken.front()<<" is matched ";
			
		}
	
	
		

		
		
	
	
}
void Type()
{

	gettoken.pop();
		if(gettoken.front()=="<")
		{
				gettoken.pop();
				if(gettoken.front()=="<")
				{
					std::cout<<endl<<"<< is matched ";
					gettoken.pop();
					E();
				}
				
			}
			
			

		}
		
				

	

void P()
{


	if(gettoken.front()=="SSmain") 
	{
		std::cout<<endl<< gettoken.front()<<" is matched ";
	
		gettoken.pop();
		if(gettoken.front()=="(")
		{
			gettoken.pop();
			if(gettoken.front()==")")
			{
			std::cout<<endl<< " << is matched ";
				gettoken.pop();
				
				
		if(gettoken.front()=="Type") 
		{
			std::cout<<endl<< gettoken.front()<<" is matched ";
			Type();
		
	
		}
				
			
		
			}
		}
	}
	

	
}

int main()
{
	 ifstream f("a.txt"); //taking file as inputstream
   string str;
   if(f) {
      ostringstream ss;
      ss << f.rdbuf(); // reading data
      str = ss.str();
   }

	
	
	
	Lexical_Analyzer(str);
	
		
//  while (!gettoken.empty()) {
//        cout << ' ' << gettoken.front()<<"\n";
//        gettoken.pop();
//  }
  	
	P();
		
	return 0;
}
