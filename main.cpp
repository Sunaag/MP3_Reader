#include "common.h"
#include "id3_class.h"

int main(int argc,char **argv)
{
	try
	{
		if(check_if_mp3(argv[1]) != true)
			throw 1;
	}
	catch(int val)
	{
		cout << argv[val] << " is not an mp3 file " << endl;
		return 0;
	}
	
	int tag = get_tag(argv[1]);
	id3 *A;
	if(tag == ID3v3_0 ||tag == ID3v3_1|| tag == ID3v3_2)
	{
		id3v3 B(argv[1]);
		A=&B;
		A->get_title();
		A->get_artist();
		A->get_album();
		A->get_year();
		A->get_genre();
		A->get_comments();
	}
	else if(tag == ID3v2_0 ||tag == ID3v2_1|| tag == ID3v2_2)
	{
		id3v2 B(argv[1]);
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
		id3v1 B(argv[1]);
		A=&B;
		A->get_all();
	}
}
