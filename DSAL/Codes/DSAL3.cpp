// Construct a tree to represent a book with chapters, sections, and subsections. Print the nodes and analyze the time
// and space requirements of the method.
// (Tree Construction Method)
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Class to represent a Subsection
class Subsection {
public:
    string name;
    Subsection(string name) {
        this->name = name;
    }
};

// Class to represent a Section
class Section {
public:
    string name;
    vector<Subsection*> subsections;

    Section(string name) {
        this->name = name;
    }

    // Add a Subsection to the section
    void addSubsection(Subsection* subsection) {
        subsections.push_back(subsection);
    }

    // Print subsections
    void printSubsections() {
        for (auto& subsection : subsections) {
            cout << "\t\tSubsection: " << subsection->name << endl;
        }
    }
};

// Class to represent a Chapter
class Chapter {
public:
    string name;
    vector<Section*> sections;

    Chapter(string name) {
        this->name = name;
    }

    // Add a Section to the chapter
    void addSection(Section* section) {
        sections.push_back(section);
    }

    // Print sections
    void printSections() {
        for (auto& section : sections) {
            cout << "\tSection: " << section->name << endl;
            section->printSubsections();  // Print subsections under this section
        }
    }
};

// Class to represent a Book
class Book {
public:
    string title;
    vector<Chapter*> chapters;

    Book(string title) {
        this->title = title;
    }

    // Add a Chapter to the book
    void addChapter(Chapter* chapter) {
        chapters.push_back(chapter);
    }

    // Print the book structure
    void printBook() {
        cout << "Book: " << title << endl;
        for (auto& chapter : chapters) {
            cout << "Chapter: " << chapter->name << endl;
            chapter->printSections();  // Print sections and subsections for each chapter
        }
    }
};

int main() {
    string bookTitle, chapterTitle, sectionTitle, subsectionTitle;
    int numChapters, numSections, numSubsections;

    // Taking input for the Book
    cout << "Enter the title of the book: ";
    getline(cin, bookTitle);

    Book* book = new Book(bookTitle);

    // Taking input for Chapters
    cout << "Enter the number of chapters: ";
    cin >> numChapters;
    cin.ignore();  // To ignore the newline character after the number input

    for (int i = 0; i < numChapters; ++i) {
        cout << "Enter title for Chapter " << (i + 1) << ": ";
        getline(cin, chapterTitle);

        Chapter* chapter = new Chapter(chapterTitle);

        // Taking input for Sections in the Chapter
        cout << "Enter the number of sections in chapter " << (i + 1) << ": ";
        cin >> numSections;
        cin.ignore();

        for (int j = 0; j < numSections; ++j) {
            cout << "Enter title for Section " << (j + 1) << ": ";
            getline(cin, sectionTitle);

            Section* section = new Section(sectionTitle);

            // Taking input for Subsections in the Section
            cout << "Enter the number of subsections in section " << (j + 1) << ": ";
            cin >> numSubsections;
            cin.ignore();

            for (int k = 0; k < numSubsections; ++k) {
                cout << "Enter title for Subsection " << (k + 1) << ": ";
                getline(cin, subsectionTitle);

                Subsection* subsection = new Subsection(subsectionTitle);
                section->addSubsection(subsection);
            }

            chapter->addSection(section);
        }

        book->addChapter(chapter);
    }

    // Print the book structure
    book->printBook();

    // Cleanup memory
    delete book;

    return 0;
}
