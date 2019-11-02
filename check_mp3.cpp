#include "common.h"

bool check_if_mp3(char *str)
{
	while(*str)
	{
		if(*str == '.')
		{
			if(strcmp(str+1,"mp3") == 0)
				return true;
			else
				return false;
		}
		str++;
	}

}

int get_tag(char *file_name)
{
	ifstream f;
	f.open(file_name,ios::binary);
	f.seekg(0,ios::beg);
	char tag[3];
	f.read(tag,3);
	char version;
	if(strcmp(tag,"ID3") == 0)
	{
		cout << tag << " ";
		f.read(&version,1);
		if(version == 0x03)
		{
			version = 0;
			f.read(&version,1);
			if(version == 0x00)
			{
				cout << "Version 2.3.0"<< endl;
				f.close();
				return ID3v3_0;
			}
			else if(version == 0x01)
			{
				cout << "Version 2.3.1"<< endl;
				f.close();
				return ID3v3_1;
			}
			else 
			{
				cout << "Version 2.3.2"<< endl;
				f.close();
				return ID3v3_2;
			}
		}
		else if(version == 0x02)
		{
			version = 0;
			f.read(&version,1);
			if(version == 0x00)
			{
				cout << "Version 2.2.0"<< endl;
				f.close();
				return ID3v2_0;
			}
			else if(version == 0x01)
			{
				cout << "Version 2.2.1"<< endl;
				f.close();
				return ID3v2_1;
			}
			else 
			{
				cout << "Version 2.2.2"<< endl;
				f.close();
				return ID3v2_2;
			}
		}
	}
	else
	{
		f.seekg(-128,ios::end);
		memset(tag,0,3);
		f.read(tag,3);
		if(strcmp(tag,"TAG") == 0)
		{
			cout << "ID3v1 " << endl;
			f.close();
			return ID3v1;
		}
	}
	f.close();
}

