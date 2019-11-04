#include "common.h"
#include "id3_read.h"
#include "id3_write.h"

int main(int argc,char **argv)
{
	int flag = 0;
	string title;
	if(argv[1] == NULL)
	{
		cout << "Error: "<<argv[0] << ": Invalid Arguments"<< endl;	
		cout << "Usage: "<<argv[0] << " -h for help"<< endl;
		return 0;
	}
	else if(strcmp(argv[1],"-h") == 0)
	{
		cout << "Help Menu for MP3 Tag Reader and Editor:"<<endl;
		cout <<"\n\n";
		cout << "For viewing the tags- "<<argv[0]<< " -v <.mp3 file>"<<endl;
		cout << "\n\n";
		cout << "For editing the tags- "<<argv[0]<< " -e <.mp3 file> <modifier> <tag>"<<endl;
		cout << "\n\n";
		cout << "Modifier\t\tFunction"<<endl;
		cout << "\t-t\t\tModifies Title Tag"<<endl;
		cout << "\t-a\t\tModifies Artist Tag"<<endl;
		cout << "\t-A\t\tModifies Album Tag"<<endl;
		cout << "\t-y\t\tModifies Year Tag"<<endl;
		cout << "\t-c\t\tModifies Comment Tag"<<endl;
		cout << "\t-g\t\tModifies Genre Tag"<<endl;
		cout << "\n\n";
		cout << "Example : " << argv[0] << " -e sample.mp3 -t \"Changed Title\" "<< endl;
		return 0;
	}
	else if(strcmp(argv[1],"-e") == 0)
	{
		flag = 1;
	}
	else if(strcmp(argv[1],"-v") == 0)
	{
		flag = 0;
	}
	try
	{
		if(check_if_mp3(argv[2]) != true)
			throw 1;
	}
	catch(int val)
	{
		cout << argv[val] << " is not an mp3 file " << endl;
		return 0;
	}
	
	int tag = get_tag(argv[2]);
	id3 *A;
	id3_write *Wr;
	if(tag == ID3v3_0 ||tag == ID3v3_1|| tag == ID3v3_2)
	{
		if(flag && strcmp(argv[3],"-t")==0)
		{
			id3v3_write B(argv[2]);
			Wr=&B;
			Wr->put_title(argv[4]);
		}
		else if(flag == 0 && strcmp(argv[3],"-t")==0)
		{
			id3v3 B(argv[2]);
			A=&B;
			A->get_title();
		}
		if(flag && strcmp(argv[3],"-a")==0)
		{
			id3v3_write B(argv[2]);
			Wr=&B;
			Wr->put_artist(argv[4]);
		}
		else if(flag == 0 && strcmp(argv[3],"-a")==0)
		{
			id3v3 B(argv[2]);
			A=&B;
			A->get_artist();
		}
		if(flag && strcmp(argv[3],"-A")==0)
		{
			id3v3_write B(argv[2]);
			Wr=&B;
			cout << "Hek" << endl;
			Wr->put_album(argv[4]);
		}
		else if(flag == 0 && strcmp(argv[3],"-A")==0)
		{
			id3v3 B(argv[2]);
			A=&B;
			A->get_album();
		}
		if(flag && strcmp(argv[3],"-y")==0)
		{
			id3v3_write B(argv[2]);
			Wr=&B;
			Wr->put_year(argv[4]);
		}
		else if(flag == 0 && strcmp(argv[3],"-y")==0)
		{
			id3v3 B(argv[2]);
			A=&B;
			A->get_year();
		}
		if(flag && strcmp(argv[3],"-g")==0)
		{
			id3v3_write B(argv[2]);
			Wr=&B;
			Wr->put_genre(argv[4]);
		}
		else if(flag == 0 && strcmp(argv[3],"-g")==0)
		{
			id3v3 B(argv[2]);
			A=&B;
			A->get_genre();
		}
		if(flag && strcmp(argv[3],"-c")==0)
		{
			id3v3_write B(argv[2]);
			Wr=&B;
			Wr->put_comments(argv[4]);
		}
		else if(flag == 0 && strcmp(argv[3],"-c")==0)
		{
			id3v3 B(argv[2]);
			A=&B;
			A->get_comments();
		}
	}
	else if(tag == ID3v2_0 ||tag == ID3v2_1|| tag == ID3v2_2)
	{
		id3v2 B(argv[2]);
		A=&B;
		A->get_title();
		A->get_artist();
		A->get_album();
		A->get_year();
		A->get_genre();
		A->get_comments();
	}
	else if(tag == ID3v1)
	{
		if(flag && strcmp(argv[3],"-t")==0)
		{
			id3v1_write B(argv[2]);
			Wr=&B;
			Wr->put_title(argv[4]);
		}
		else if(flag == 0 && strcmp(argv[3],"-t")==0)
		{
			id3v1 B(argv[2]);
			A=&B;
			A->get_title();
		}
		if(flag && strcmp(argv[3],"-a")==0)
		{
			id3v1_write B(argv[2]);
			Wr=&B;
			Wr->put_artist(argv[4]);
		}
		else if(flag == 0 && strcmp(argv[3],"-a")==0)
		{
			id3v1 B(argv[2]);
			A=&B;
			A->get_artist();
		}
		if(flag && strcmp(argv[3],"-A")==0)
		{
			id3v1_write B(argv[2]);
			Wr=&B;
			cout << "Hek" << endl;
			Wr->put_album(argv[4]);
		}
		else if(flag == 0 && strcmp(argv[3],"-A")==0)
		{
			id3v1 B(argv[2]);
			A=&B;
			A->get_album();
		}
		if(flag && strcmp(argv[3],"-y")==0)
		{
			id3v1_write B(argv[2]);
			Wr=&B;
			Wr->put_year(argv[4]);
		}
		else if(flag == 0 && strcmp(argv[3],"-y")==0)
		{
			id3v1 B(argv[2]);
			A=&B;
			A->get_year();
		}
		if(flag && strcmp(argv[3],"-g")==0)
		{
			id3v1_write B(argv[2]);
			Wr=&B;
			Wr->put_genre(argv[4]);
		}
		else if(flag == 0 && strcmp(argv[3],"-g")==0)
		{
			id3v1 B(argv[2]);
			A=&B;
			A->get_genre();
		}
		if(flag && strcmp(argv[3],"-c")==0)
		{
			id3v1_write B(argv[2]);
			Wr=&B;
			Wr->put_comments(argv[4]);
		}
		else if(flag == 0 && strcmp(argv[3],"-c")==0)
		{
			id3v1 B(argv[2]);
			A=&B;
			A->get_comments();
		}
	}
}
