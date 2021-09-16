#pragma once

class String
{
public:

	bool Initialization(size_t length);
	void Concat(char* str);
	void Copy(char* str);
	void Insert(int index, char* str);
	void Remove(int index, size_t length);
	void OutPut() const;
	void Copy(const String& str);

	String();
	String(const char* str, size_t length);
	String(const String& str);
	String(String&& str);
	~String();

	String& operator= (const String& str);
	String& operator= (String&& str);

	char& operator[] (size_t index);
	char operator[] (size_t index) const;


	char* GetStr() const;
	size_t GetLength() const;

	bool SetStr(const char* str);
	bool SetAge(size_t length);

private:

	char* _str = nullptr;
	size_t _length;

};
