#include <iostream>

using namespace std;

// Imagine a publishing company that markets both book and audio - cassette versions of its works.
// Create a class publication that stores the title and price of a publication.
// From this class derive two classes : i.book, which adds a page countand ii.tape, which adds a playing time in minutes.
// Each of these three classes should have set() and get() functionsand a display() function to display its data.
// Write a main() program to test the bookand tape class by creating instances of them, asking the user to fill in their data and 
// then displaying the data with display().

class publication
{
private:
	string title;
	float price;
public:
	void set(string t, float p)
	{
		title = t;
		price = p;
	}
	void get()
	{
		cout << "Title: " << title << endl;
		cout << "Price: " << price << endl;
	}
	void display()
	{
		cout << "Title: " << title << endl;
		cout << "Price: " << price << endl;
	}
};

class book : public publication
{
private:
	int page_count;
public:
	void set(string t, float p, int pc)
	{
		publication::set(t, p);
		page_count = pc;
	}
	void get()
	{
		publication::get();
		cout << "Page Count: " << page_count << endl;
	}
	void display()
	{
		publication::display();
		cout << "Page Count: " << page_count << endl;
	}
};

class tape : public publication
{
private:
	float playing_time;
public:
	void set(string t, float p, float pt)
	{
		publication::set(t, p);
		playing_time = pt;
	}
	void get()
	{
		publication::get();
		cout << "Playing Time: " << playing_time << endl;
	}
	void display()
	{
		publication::display();
		cout << "Playing Time: " << playing_time << endl;
	}
};

int main()
{
	book b;
	tape t;
	b.set("C++", 100, 1000);
	t.set("C++", 100, 1000);
	b.get();
	t.get();
	b.display();
	t.display();
	return 0;
}