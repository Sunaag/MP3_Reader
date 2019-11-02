#ifndef ID3_CLASS_H 
#define ID3_CLASS_H 

unsigned int reverse_byte(void * val);
class id3
{
	protected:
		char tag[4];
		ifstream mp3;
		char *file_name;
	public:
		id3(void)
		{
		}
		id3 (const char *file_name)
		{
			this -> file_name = new char[strlen(file_name)+1];
			strcpy(this->file_name,file_name);
			this->mp3.open(file_name,ios::binary);
		}
		virtual void get_title(void) =0;
		virtual void get_artist(void) =0;
		virtual void get_album(void)=0;
		virtual void get_year(void)=0;
		virtual void get_comments(void)=0;
		virtual void get_genre(void)=0;
		virtual void get_all(void) = 0;
		~id3(void)
		{
			this->mp3.close();
		}
};
class id3v3 : public id3
{
	public:
		id3v3 (const char *file_name)
		{
			this -> file_name = new char[strlen(file_name)+1];
			strcpy(this->file_name,file_name);
			this->mp3.open(file_name,ios::binary);
		}
		void get_title(void);
		void get_artist(void);
		void get_album(void);
		void get_year(void);
		void get_comments(void);
		void get_genre(void);
		void get_all(void)
		{
		}
		~id3v3(void)
		{
			this->mp3.close();
		}
};
class id3v2 : public id3
{
	public:
		id3v2 (const char *file_name)
		{
			this -> file_name = new char[strlen(file_name)+1];
			strcpy(this->file_name,file_name);
			this->mp3.open(file_name,ios::binary);
		}
		void get_title(void);
		void get_artist(void);
		void get_album(void);
		void get_year(void);
		void get_comments(void);
		void get_genre(void);
		void get_all(void)
		{
		}
		~id3v2(void)
		{
			this->mp3.close();
		}
};
class id3v1 : public id3
{
	public:
		id3v1 (const char *file_name)
		{
			this -> file_name = new char[strlen(file_name)+1];
			strcpy(this->file_name,file_name);
			this->mp3.open(file_name,ios::binary);
		}
		void get_title(void)
		{
		}
		void get_artist(void)
		{
		}
		void get_album(void)
		{
		}
		void get_year(void)
		{
		}
		void get_comments(void)
		{
		}
		void get_genre(void)
		{
		}
		void get_all(void);
		~id3v1(void)
		{
			this->mp3.close();
		}
};
void id3v3 :: get_title(void)
{
	this->mp3.seekg(0,ios::beg);
	char buff[4];
	unsigned int s,res;
	int i=0;
	while(this -> mp3.read(buff,4))
	{
		this->mp3.seekg(i,ios::beg);
		if(strcmp(buff,"TIT2") == 0)
		{
			cout << "Title: ";
			break;
		}
		i++;
	}
	this -> mp3.seekg(3,ios::cur);
	this -> mp3.read((char *)&s,4);
	res = reverse_byte(&s);
	//cout << res << endl;
	char r;
	//Move 2 bytes for flags
	this -> mp3.seekg(2,ios::cur);
	while(res--)
	{
		this->mp3.read(&r,1);
		cout << r;
	}
	cout << endl;
}
void id3v3 :: get_artist(void)
{
	this->mp3.seekg(0,ios::beg);
	char buff[4];
	unsigned int s,res;
	int i=0;
	while(this -> mp3.read(buff,4))
	{
		this->mp3.seekg(i,ios::beg);
		if(strcmp(buff,"TPE1") == 0)
		{
			cout << "Artist: ";
			break;
		}
		i++;
	}
	this -> mp3.seekg(3,ios::cur);
	this -> mp3.read((char *)&s,4);
	res = reverse_byte(&s);
	//cout << res << endl;
	char r;
	//Move 2 bytes for flags
	this -> mp3.seekg(2,ios::cur);
	while(res--)
	{
		this->mp3.read(&r,1);
		cout << r;
	}
	cout << endl;
}
void id3v3 :: get_album(void)
{
	this->mp3.seekg(0,ios::beg);
	char buff[4];
	unsigned int s,res;
	int i=0;
	while(this -> mp3.read(buff,4))
	{
		this->mp3.seekg(i,ios::beg);
		if(strcmp(buff,"TALB") == 0)
		{
			cout << "Song/Album: ";
			break;
		}
		i++;
	}
	this -> mp3.seekg(3,ios::cur);
	this -> mp3.read((char *)&s,4);
	res = reverse_byte(&s);
	//cout << res << endl;
	char r;
	//Move 2 bytes for flags
	this -> mp3.seekg(2,ios::cur);
	while(res--)
	{
		this->mp3.read(&r,1);
		cout << r;
	}
	cout << endl;
}
void id3v3 :: get_year(void)
{
	this->mp3.seekg(0,ios::beg);
	char buff[4];
	unsigned int s,res;
	int i=0;
	while(this -> mp3.read(buff,4))
	{
		this->mp3.seekg(i,ios::beg);
		if(strcmp(buff,"TYER") == 0)
		{
			cout << "Year: ";
			break;
		}
		i++;
	}
	//Move 3 bytes to after the tag as i points to next letter after T
	this -> mp3.seekg(3,ios::cur);
	this -> mp3.read((char *)&s,4);
	res = reverse_byte(&s);
	//cout << res << endl;
	//Move 2 bytes for flags
	this -> mp3.seekg(2,ios::cur);
	char r;
	while(res--)
	{
		this->mp3.read(&r,1);
		cout << r ;
	}
	cout << endl;
}
void id3v3 :: get_comments(void)
{
	this->mp3.seekg(0,ios::beg);
	char buff[4];
	unsigned int s,res;
	int i=0;
	while(this -> mp3.read(buff,4))
	{
		this->mp3.seekg(i,ios::beg);
		if(strcmp(buff,"COMM") == 0)
		{
			cout << "Comments: ";
			break;
		}
		i++;
	}
	this -> mp3.seekg(3,ios::cur);
	this -> mp3.read((char *)&s,4);
	res = reverse_byte(&s);
	//cout << res << endl;
	char r;
	//Move 2 bytes for flags
	this -> mp3.seekg(2,ios::cur);
	while(res--)
	{
		this->mp3.read(&r,1);
		cout << r;
	}
	cout << endl;
}
void id3v3 :: get_genre(void)
{
	this->mp3.seekg(0,ios::beg);
	char buff[4];
	unsigned int s,res;
	int i=0;
	while(this -> mp3.read(buff,4))
	{
		this->mp3.seekg(i,ios::beg);
		if(strcmp(buff,"TCON") == 0)
		{
			cout << "Genre: ";
			break;
		}
		i++;
	}
	this -> mp3.seekg(3,ios::cur);
	this -> mp3.read((char *)&s,4);
	res = reverse_byte(&s);
	//cout << res << endl;
	char r;
	//Move 2 bytes for flags
	this -> mp3.seekg(2,ios::cur);
	while(res--)
	{
		this->mp3.read(&r,1);
		cout << r;
	}
	cout << endl;
}
void id3v2 :: get_title(void)
{
	this->mp3.seekg(0,ios::beg);
	char buff[3];
	unsigned int s,res;
	int i=0;
	while(this -> mp3.read(buff,3))
	{
		this->mp3.seekg(i,ios::beg);
		if(strcmp(buff,"TT2") == 0)
		{
			cout << "Title: ";
			break;
		}
		i++;
	}
	this -> mp3.seekg(2,ios::cur);
	this -> mp3.read((char *)&s,3);
	res = reverse_byte(&s);
	//cout << res << endl;
	char r;
	//Move 2 bytes for flags
	this -> mp3.seekg(2,ios::cur);
	while(res--)
	{
		this->mp3.read(&r,1);
		cout << r;
	}
	cout << endl;
}
void id3v2 :: get_artist(void)
{
	this->mp3.seekg(0,ios::beg);
	char buff[3];
	unsigned int s,res;
	int i=0;
	while(this -> mp3.read(buff,3))
	{
		this->mp3.seekg(i,ios::beg);
		if(strcmp(buff,"TP1") == 0)
		{
			cout << "Artist: ";
			break;
		}
		i++;
	}
	this -> mp3.seekg(2,ios::cur);
	this -> mp3.read((char *)&s,3);
	res = reverse_byte(&s);
	//cout << res << endl;
	char r;
	//Move 2 bytes for flags
	this -> mp3.seekg(2,ios::cur);
	while(res--)
	{
		this->mp3.read(&r,1);
		cout << r;
	}
	cout << endl;
}
void id3v2 :: get_album(void)
{
	this->mp3.seekg(0,ios::beg);
	char buff[3];
	unsigned int s,res;
	int i=0;
	while(this -> mp3.read(buff,3))
	{
		this->mp3.seekg(i,ios::beg);
		if(strcmp(buff,"TAL") == 0)
		{
			cout << "Song/Album: ";
			break;
		}
		i++;
	}
	this -> mp3.seekg(2,ios::cur);
	this -> mp3.read((char *)&s,3);
	res = reverse_byte(&s);
	//cout << res << endl;
	char r;
	//Move 2 bytes for flags
	this -> mp3.seekg(2,ios::cur);
	while(res--)
	{
		this->mp3.read(&r,1);
		cout << r;
	}
	cout << endl;
}
void id3v2 :: get_year(void)
{
	this->mp3.seekg(0,ios::beg);
	char buff[3];
	unsigned int s,res;
	int i=0;
	while(this -> mp3.read(buff,3))
	{
		this->mp3.seekg(i,ios::beg);
		if(strcmp(buff,"TYE") == 0)
		{
			cout << "Year: ";
			break;
		}
		i++;
	}
	//Move 2 bytes to after the tag as i points to next letter after T
	this -> mp3.seekg(2,ios::cur);
	this -> mp3.read((char *)&s,3);
	res = reverse_byte(&s);
	//cout << res << endl;
	//Move 2 bytes for flags
	this -> mp3.seekg(2,ios::cur);
	char r;
	while(res--)
	{
		this->mp3.read(&r,1);
		cout << r ;
	}
	cout << endl;
}
void id3v2 :: get_comments(void)
{
	this->mp3.seekg(0,ios::beg);
	char buff[3];
	unsigned int s,res;
	int i=0;
	while(this -> mp3.read(buff,3))
	{
		this->mp3.seekg(i,ios::beg);
		if(strcmp(buff,"COM") == 0)
		{
			cout << "Comments: ";
			break;
		}
		i++;
	}
	this -> mp3.seekg(2,ios::cur);
	this -> mp3.read((char *)&s,3);
	res = reverse_byte(&s);
	//cout << res << endl;
	char r;
	//Move 2 bytes for flags
	this -> mp3.seekg(2,ios::cur);
	while(res--)
	{
		this->mp3.read(&r,1);
		cout << r;
	}
	cout << endl;
}
void id3v2 :: get_genre(void)
{
	this->mp3.seekg(0,ios::beg);
	char buff[3];
	unsigned int s,res;
	int i=0;
	while(this -> mp3.read(buff,3))
	{
		this->mp3.seekg(i,ios::beg);
		if(strcmp(buff,"TCO") == 0)
		{
			cout << "Genre: ";
			break;
		}
		i++;
	}
	this -> mp3.seekg(2,ios::cur);
	this -> mp3.read((char *)&s,3);
	res = reverse_byte(&s);
	//cout << res << endl;
	char r;
	//Move 2 bytes for flags
	this -> mp3.seekg(2,ios::cur);
	while(res--)
	{
		this->mp3.read(&r,1);
		cout << r;
	}
	cout << endl;
}
void id3v1 :: get_all(void)
{
	char tag[4];
	char title[31];
	char artist[31];
	char album[31];
	char year[5];
	char comment[29];
	char track[2];
	char genre[2];
	this->mp3.seekg(-128,ios::end);
	this->mp3.read(tag,3);
	tag[3]='\0';
	cout << tag << endl;
	this->mp3.read(title,30);
	title[30]='\0';
	cout << "Title: ";
	if(title[0] == '\0')
		cout << "Not available " << endl;
	else
		cout << title << endl;
	this->mp3.read(artist,30);
	artist[30]='\0';
	cout << "Artist: ";
	if(artist[0] == '\0')
		cout << "Not available " << endl;
	else
		cout << artist << endl;
	this->mp3.read(album,30);
	album[30] = '\0';
	cout << "Song/Album: ";
	if(album[0] == '\0')
		cout << "Not available " << endl;
	else
		cout << album << endl;
	this->mp3.read(year,4);
	year[4]='\0';
	cout << "Year: ";
	if(year[0] == '\0')
		cout << "Not available " << endl;
	else
		cout << year << endl;
	this->mp3.read(comment,28);
	comment[28] = '\0';
	cout << "Comments: " ;
	if(comment[0] == '\0')
		cout << "Not available " << endl;
	else
		cout << comment << endl;
	this->mp3.read(track,1);
	track[1] = '\0';
	cout << "Track no: " ;
	if(track[0] == '\0')
		cout << "Not available " << endl;
	else
		cout << track << endl; 
	this->mp3.read(genre,1);
	genre[1] = '\0';
	cout << "Genre: ";
	if(genre[0] == '\0')
		cout << "Not available " << endl;
	else
		cout << track << endl; 

}
unsigned int reverse_byte(void *val)
{
	int size = sizeof(int);
	char buff[4] = {0};
	void *ptr = buff;
	int i;
	unsigned int res;
	for(i = size - 1; i>=0; i--)
	{
		buff[i] = *(unsigned char *)val;
		val = (unsigned char *)val + 1;
	}
	res = *(unsigned int *)ptr;
	return res;
}

#endif
