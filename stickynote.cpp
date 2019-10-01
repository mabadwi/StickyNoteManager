/* In this exercise we want to design a Storyboard. Our version of the Storyboard

 * contains arbitrary many notes (imagine it like putting sticky notes on a board).

 * Every note has a title, a text and a set of tags. E.g.

 * 	- title: "Test Traceplayer"

 * 	- text: "Implement a unit test for the class Traceplayer of the spark core framework."

 * 	- tags: {"unit test", "traceplayer", "testing", "spark core"}

 * 

 * Our Storyboard should enable us to search for notes by title, text and tags.

 * E.g.:

 *      searchByTitle("Test Traceplayer")

 *      searchByTag({"testing", "unit test"})

 *   	searchByText("Implement a unit test for the class Traceplayer of the spark core framework.")

 * For the sake of simplicity we don't want to do any similiarity or prefix matching when

 * searching for a title, tag or text. Only an exact match should give results.

 * 

 * The skeleton code below can be used as a starting point but doesn't have to.

 * The comments "fill in" are placeholders where you definitely have to put in some code when 

 * you use this skeleton code. But this doesn't mean that you shouldn't or can't put code anywhere else.

 * 

 * Also write some simple unit tests to show how you would test the functionality of the Storyboard.

 * Don't use any testing framework. Simple if-statements are sufficient for this exercise.

 * 

 * Hint: Think about performance versus memory tradeoffs in your design, so you can give good 

 *       reasons for your decision. 

 */

#define MAX_Num_ofTags 4
#include <stdio.h>

#include <string.h>
#include <bits/stdc++.h> 
#include <Fileapi.h>
using namespace std; 
int main();
class Storyboard
{

public:
	void delete_line();
		void addNote(){
		//Note Sticky;
		struct NotePad{
			char title[100];
	 		char text[250]; 
	 		char tags[150];
 		}Noteobj;
 		ofstream StickyN("StrickyBoard.txt", ios::app);
 		system("cls");
 		cin.sync();
		cout << "Enter the new Sticky's title: " <<endl;
 		cin.getline(Noteobj.title,sizeof(Noteobj.title));
 		system("cls");
 		cout << "Enter the Sticky's text: " << endl;
 		cin.getline(Noteobj.text,sizeof(Noteobj.text));
 		system("cls");
  
 		cout << "Enter the Sticky's tags: " << endl;
 		cin.getline(Noteobj.tags,sizeof(Noteobj.tags));
 
        StickyN << "Title: " << Noteobj.title << endl << "Text: " << Noteobj.text << endl<< "Tags: " << Noteobj.tags << endl;     
		StickyN.close();
		system ("pause");
		main();
	}

	void deleteNote(){
		ifstream StickyN("StrickyBoard.txt");
		int NumbertoDelete;
		int numStky = 1;
		int num= 1;
		char cline[150];
		string line(cline);
 		system ("CLS");
    	cout << "Entire Board database"<< endl;
    	cout <<"number"<<' ' <<"Title" << ' ' << "Text" << ' ' << "Tags" << endl;
    	cout << "--------------------" << endl;
    	StickyN.getline(cline,150);
    	while(StickyN.getline(cline,150))
		{
			cout << numStky << ' ';
			cout << cline <<endl;
			num++;
			if(num == 4) {
				num = 1;
				numStky++;
				cout<< endl;
			}
		}
		cout<< "--------------------"<<endl;
		StickyN.close();
		cout<<"Enter number of Stick to Delete:"<<endl;
		cin>> NumbertoDelete;
		cout<<endl;
		cin.sync();
		for(int i =(NumbertoDelete*3+1);i>((NumbertoDelete*3)-2);i--){
			
			delete_line("StrickyBoard.txt",i);
			cout<<"test "<< i<<endl;
		}
     	system ("pause");
     	main();
	}

	void searchByTitle(){
		ifstream StickyN("StrickyBoard.txt");
		char sline[150];
		char cline[150];
		string line(cline);
		string Sline(sline);
		int num=1;
		cout<< "Enter Title of Sticky to find: "<<endl;
		cin.sync();
		cin.getline(cline,sizeof(cline));
		line ="Title: ";
		line+=cline;
		while(StickyN.getline(sline,150)){
			Sline = sline;
			if(Sline == line){
				cout<< "Sticky Note is found"<<endl;
				cout<<"-------------------"<<endl;
				cout<<sline<<endl;
				for(int i=0;i<2;i++){
					StickyN.getline(sline,150);
					cout<<sline<<endl;
				}
			}
		}
	StickyN.close();
	system ("pause");
    main();	
	}
	void searchByText(){
		ifstream StickyN("StrickyBoard.txt");
		char sline[150];
		char cline[150];
		string line(cline);
		cout<< "Enter Text of Sticky to find: "<<endl;
		cin.sync();
		cin.getline(cline,sizeof(cline));
		line ="Text: ";
		line+=cline;
		StickyN.getline(sline,150);
		string TitleLine (sline);
		while(StickyN.getline(sline,150)){
			string Sline(sline);
			if(Sline == line){
				cout<< "Sticky Note is found"<<endl;
				cout<<"-------------------"<<endl;
				cout<<TitleLine<<endl;
				cout<<sline<<endl;
				StickyN.getline(sline,150);
				cout<<sline<<endl;
			}
			else{
				TitleLine=sline;
			} 
		}
	StickyN.close();
	system ("pause");
    main();	
	}

	void searchByTag(){
		ifstream StickyN("StrickyBoard.txt");
		char sline[150];
		char cline[150];
		int num = 1;
		string line(cline);
		string Sline;
		cout<< "Enter Tags of Sticky to find: "<<endl;
		cin.sync();
		cin.getline(cline,sizeof(cline));
		line ="Tags: ";
		line+=cline;
		StickyN.getline(sline,150);
		string TitleLine (sline);
		StickyN.getline(sline,150);
		string TextLine (sline);
		while(StickyN.getline(sline,150)){
			//cout<<sline<<endl;
			Sline=sline;
			num ++;
			if(Sline == line){
				cout<< "Sticky Note is found"<<endl;
				cout<<"-------------------"<<endl;
				cout<<TitleLine<<endl;
				cout<<TextLine<<endl;
				cout<<sline<<endl;
			}
			else{
				
				if(num == 2){
				TitleLine=sline;}
				else if(num == 3){
				TextLine=sline;}
				else{
				num =1;
				//cout<<sline<<endl;
				}
				//cout<<TitleLine<<endl;
				//cout<<TextLine<<endl;
			} 
		}
	StickyN.close();
	system ("pause");
    main();
	}
	void quit()
	{
	 system ("CLS");
	 cout << "Thank you for using the Stricky Note database program" << endl;
	 system ("pause");
	 cin.get();
	     } 

private:

	void delete_line(const char *file_name, int n) 
	{ 
	    // open file in read mode or in mode 
	    ifstream is(file_name); 
	  
	    // open file in write mode or out mode 
	    ofstream ofs; 
	    ofs.open("temp.txt", ofstream::out); 
	  
	    // loop getting single characters 
	    char c; 
	    int line_no = 1; 
	    while (is.get(c)) 
	    { 
	        // if a newline character 
	        if (c == '\n') 
	        line_no++; 
	  
	        // file content not to be deleted 
	        if (line_no != n) 
	            ofs << c; 
	    } 
	  
	    // closing output file 
	    ofs.close(); 
	  
	    // closing input file 
	    is.close(); 
	  
	    // remove the original file 
	    bool success1=DeleteFileA(file_name);
		//cout<<"Delete "<<success1<<' '<<endl;
	    // rename the file 
	    bool success2 = rename("temp.txt",file_name);
		//cout<<"Rename "<<success2<<' '<<endl;
		
	}
	


};

int main()
{
	Storyboard Board;

	system ("title Story Board");
	system ("cls");
	system ("color 0F");
	
    int choice;
    cout << "1.Input a new StickyNote" << endl;
    cout << "2.Delete Note" << endl;
    cout << "3.Search By Title" << endl;
    cout << "4.Search By Text" << endl;
    cout << "5.Search By Tags" << endl;
    cout << "6.Exit Program" << endl;
    cin >> choice;
    
	switch (choice){
       case 1:
            Board.addNote();
            break;
       case 2:
            Board.deleteNote();
            break;
       case 3:
            Board.searchByTitle();
            break;
       case 4:
            Board.searchByText();
            break;
        case 5:
            Board.searchByTag();
            break;
	   case 6:
            Board.quit();
            break;
         
       cin.get();
    }
	
}
