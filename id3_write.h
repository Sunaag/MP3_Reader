#ifndef ID3_WRITE_H 
#define ID3_WRITE_H 

namespace first
{
	char buff[4];
}
class id3_write
{
	protected:
		fstream mp3;
		char *file_name;
	public:
		id3_write(void)
		{
		}
		id3_write (const char *file_name)
		{
			this -> file_name = new char[strlen(file_name)+1];
			strcpy(this->file_name,file_name);
			this->mp3.open(file_name,ios::in|ios::out|ios::binary);
		}
		virtual void put_title(char *title)=0;
		virtual void put_artist(char *artist)=0;
		virtual void put_album(char *album)=0;
		virtual void put_year(char *year)=0;
		virtual void put_comments(char *comments)=0;
		virtual void put_genre(char *genre)=0;
		~id3_write(void)
		{
			this->mp3.close();
		}
};
class id3v3_write: public id3_write
{
	public:
		id3v3_write (const char *file_name)
		{
			this -> file_name = new char[strlen(file_name)+1];
			strcpy(this->file_name,file_name);
			this->mp3.open(file_name,ios::in|ios::out|ios::binary);
		}
		void put_title(char *title);
		void put_artist(char *artist);
		void put_album(char *album);
		void put_year(char *year);
		void put_comments(char *comments);
		void put_genre(char *genre);
		~id3v3_write(void)
		{
			this->mp3.close();
		}
};
class id3v2_write : public id3_write
{
	public:
		id3v2_write (const char *file_name)
		{
			this -> file_name = new char[strlen(file_name)+1];
			strcpy(this->file_name,file_name);
			this->mp3.open(file_name,ios::in|ios::out|ios::binary);
		}
		void put_title(char *title)
		{
		}
		void put_artist(char *artist)
		{
		}
		void put_album(char *album)
		{
		}
		void put_year(char *year)
		{
		}
		void put_comments(char *comments)
		{
		}
		void put_genre(char *genre)
		{
		}
		~id3v2_write(void)
		{
			this->mp3.close();
		}
};
class id3v1_write : public id3_write
{
	public:
		id3v1_write (const char *file_name)
		{
			this -> file_name = new char[strlen(file_name)+1];
			strcpy(this->file_name,file_name);
			this->mp3.open(file_name,ios::in|ios::out|ios::binary);
		}
		void put_title(char *title);
		void put_artist(char *artist);
		void put_album(char *album);
		void put_year(char *year);
		void put_comments(char *comments);
		void put_genre(char *genre);
		~id3v1_write(void)
		{
			this->mp3.close();
		}
};

void id3v3_write :: put_title(char *title)
{
	this -> mp3.seekg(0,ios::beg);
	this -> mp3.seekp(0,ios::beg);
	int i=0;
	unsigned int s,res;
	while(this -> mp3.read(first :: buff,4))
	{
		this ->mp3.seekg(i,ios::beg);
		if(strcmp(first::buff,"TIT2") == 0)
		{
			break;
		}
		i++;
	}
	i = 0;
	this -> mp3.seekp(3,ios::cur);
	this -> mp3.read((char *)&s,4);
	res = reverse_byte(&s);
	char *tit = new char[strlen(title) + 1];
	strcpy(tit,title);
	unsigned int len = strlen(tit);
	char null = '\0';
	char r;
	this -> mp3.seekg(2,ios::cur);
	while(res--)
	{
		if(len != 0)
		{
			r = tit[i];
			this -> mp3.write(&r,1);
			len--;
		}
		else
		{
			this -> mp3.write(&null,1);
		}
		i++;
	}
	this -> mp3.close();
}
void id3v3_write :: put_artist(char *title)
{
	this -> mp3.seekg(0,ios::beg);
	this -> mp3.seekp(0,ios::beg);
	int i=0;
	unsigned int s,res;
	while(this -> mp3.read(first :: buff,4))
	{
		this ->mp3.seekg(i,ios::beg);
		if(strcmp(first::buff,"TPE1") == 0)
		{
			break;
		}
		i++;
	}
	i = 0;
	this -> mp3.seekp(3,ios::cur);
	this -> mp3.read((char *)&s,4);
	res = reverse_byte(&s);
	char *tit = new char[strlen(title) + 1];
	strcpy(tit,title);
	unsigned int len = strlen(tit);
	char null = '\0';
	char r;
	this -> mp3.seekg(2,ios::cur);
	while(res--)
	{
		if(len != 0)
		{
			r = tit[i];
			this -> mp3.write(&r,1);
			len--;
		}
		else
		{
			this -> mp3.write(&null,1);
		}
		i++;
	}
	this -> mp3.close();
}
void id3v3_write :: put_album(char *title)
{
	this -> mp3.seekg(0,ios::beg);
	this -> mp3.seekp(0,ios::beg);
	int i=0;
	unsigned int s,res;
	while(this -> mp3.read(first :: buff,4))
	{
		this ->mp3.seekg(i,ios::beg);
		if(strcmp(first::buff,"TALB") == 0)
		{
			break;
		}
		i++;
	}
	i = 0;
	this -> mp3.seekp(3,ios::cur);
	this -> mp3.read((char *)&s,4);
	res = reverse_byte(&s);
	char *tit = new char[strlen(title) + 1];
	strcpy(tit,title);
	unsigned int len = strlen(tit);
	char null = '\0';
	char r;
	this -> mp3.seekg(2,ios::cur);
	while(res--)
	{
		if(len != 0)
		{
			r = tit[i];
			this -> mp3.write(&r,1);
			len--;
		}
		else
		{
			this -> mp3.write(&null,1);
		}
		i++;
	}
	this -> mp3.close();
}
void id3v3_write :: put_genre(char *title)
{
	this -> mp3.seekg(0,ios::beg);
	this -> mp3.seekp(0,ios::beg);
	int i=0;
	unsigned int s,res;
	while(this -> mp3.read(first :: buff,4))
	{
		this ->mp3.seekg(i,ios::beg);
		if(strcmp(first::buff,"TCON") == 0)
		{
			break;
		}
		i++;
	}
	i = 0;
	this -> mp3.seekp(3,ios::cur);
	this -> mp3.read((char *)&s,4);
	res = reverse_byte(&s);
	char *tit = new char[strlen(title) + 1];
	strcpy(tit,title);
	unsigned int len = strlen(tit);
	char null = '\0';
	char r;
	this -> mp3.seekg(2,ios::cur);
	while(res--)
	{
		if(len != 0)
		{
			r = tit[i];
			this -> mp3.write(&r,1);
			len--;
		}
		else
		{
			this -> mp3.write(&null,1);
		}
		i++;
	}
	this -> mp3.close();
}
void id3v3_write :: put_year(char *title)
{
	this -> mp3.seekg(0,ios::beg);
	this -> mp3.seekp(0,ios::beg);
	int i=0;
	unsigned int s,res;
	while(this -> mp3.read(first :: buff,4))
	{
		this ->mp3.seekg(i,ios::beg);
		if(strcmp(first::buff,"TYER") == 0)
		{
			break;
		}
		i++;
	}
	i = 0;
	this -> mp3.seekp(3,ios::cur);
	this -> mp3.read((char *)&s,4);
	res = reverse_byte(&s);
	char *tit = new char[strlen(title) + 1];
	strcpy(tit,title);
	unsigned int len = strlen(tit);
	char null = '\0';
	char r;
	this -> mp3.seekg(2,ios::cur);
	while(res--)
	{
		if(len != 0)
		{
			r = tit[i];
			this -> mp3.write(&r,1);
			len--;
		}
		else
		{
			this -> mp3.write(&null,1);
		}
		i++;
	}
	this -> mp3.close();
}
void id3v3_write :: put_comments(char *title)
{
	this -> mp3.seekg(0,ios::beg);
	this -> mp3.seekp(0,ios::beg);
	int i=0;
	unsigned int s,res;
	while(this -> mp3.read(first :: buff,4))
	{
		this ->mp3.seekg(i,ios::beg);
		if(strcmp(first::buff,"COMM") == 0)
		{
			break;
		}
		i++;
	}
	i = 0;
	this -> mp3.seekp(3,ios::cur);
	this -> mp3.read((char *)&s,4);
	res = reverse_byte(&s);
	char *tit = new char[strlen(title) + 1];
	strcpy(tit,title);
	unsigned int len = strlen(tit);
	char null = '\0';
	char r;
	this -> mp3.seekg(2,ios::cur);
	while(res--)
	{
		if(len != 0)
		{
			r = tit[i];
			this -> mp3.write(&r,1);
			len--;
		}
		else
		{
			this -> mp3.write(&null,1);
		}
		i++;
	}
	this -> mp3.close();
}
void id3v1_write :: put_title(char *title)
{

	this -> mp3.seekp(0,ios::end);
	this -> mp3.seekg(0,ios::end);
	char *buff = new char[strlen(title) + 1];
	strcpy(buff,title);
	long pos = this -> mp3.tellp();
	this -> mp3.seekp(pos - 125);
	this -> mp3.write(buff,30);
}

void id3v1_write :: put_artist(char *artist)
{

	this -> mp3.seekp(0,ios::end);
	this -> mp3.seekg(0,ios::end);
	char *buff = new char[strlen(artist) + 1];
	strcpy(buff,artist);
	long pos = this -> mp3.tellp();
	this -> mp3.seekp(pos - 95);
	this -> mp3.write(buff,30);
}

void id3v1_write :: put_album(char *album)
{

	this -> mp3.seekp(0,ios::end);
	this -> mp3.seekg(0,ios::end);
	char *buff = new char[strlen(album) + 1];
	strcpy(buff,album);
	long pos = this -> mp3.tellp();
	this -> mp3.seekp(pos - 65);
	this -> mp3.write(buff,30);
}
void id3v1_write :: put_year(char *year)
{

	this -> mp3.seekp(0,ios::end);
	this -> mp3.seekg(0,ios::end);
	char *buff = new char[strlen(year) + 1];
	strcpy(buff,year);
	long pos = this -> mp3.tellp();
	this -> mp3.seekp(pos - 35);
	this -> mp3.write(buff,4);
}
void id3v1_write :: put_comments(char *comments)
{

	this -> mp3.seekp(0,ios::end);
	this -> mp3.seekg(0,ios::end);
	char *buff = new char[strlen(comments) + 1];
	strcpy(buff,comments);
	long pos = this -> mp3.tellp();
	this -> mp3.seekp(pos - 31);
	this -> mp3.write(buff,29);
}
void id3v1_write :: put_genre(char *genre)
{

	this -> mp3.seekp(0,ios::end);
	this -> mp3.seekg(0,ios::end);
	char *buff = new char[strlen(genre) + 1];
	strcpy(buff,genre);
	long pos = this -> mp3.tellp();
	this -> mp3.seekp(pos - 1);
	this -> mp3.write(buff,1);
}
#endif
