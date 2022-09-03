#pragma once
class BookStore
{
public:
	int m_nNumber;
	char m_cName[100];
	BookStore(int nNumber, const char cName[]);
	BookStore();
	BookStore(const BookStore& other);
private:
};
BookStore  Max(BookStore A, BookStore B);
BookStore& MaxR(BookStore & A, BookStore & B);
BookStore  MaxR1(BookStore& A, BookStore& B);
BookStore& MaxR2(BookStore A, BookStore B);
const BookStore& MaxRC(const BookStore& A,const BookStore& B);

