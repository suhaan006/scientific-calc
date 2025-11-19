# Intelligent Library Assistant - Python OOP Project

class Book:
    def __init__(self, book_id, title, author, category):
        self.book_id = book_id
        self.title = title
        self.author = author
        self.category = category
        self.is_available = True

    def display(self):
        status = "Available" if self.is_available else "Issued"
        print(f"{self.book_id} | {self.title} | {self.author} | {self.category} | {status}")


class Library:
    def __init__(self):
        self.books = []

    # Add a new book
    def add_book(self):
        book_id = input("Enter Book ID: ")
        title = input("Enter Title: ")
        author = input("Enter Author: ")
        category = input("Enter Category: ")

        new_book = Book(book_id, title, author, category)
        self.books.append(new_book)
        print("Book added successfully!")

    # Search book using title or author
    def search_book(self):
        key = input("Enter Book Title or Author to search: ").lower()
        found = False

        for book in self.books:
            if key in book.title.lower() or key in book.author.lower():
                book.display()
                found = True

        if not found:
            print("No matching book found.")

    # Issue a book
    def issue_book(self):
        book_id = input("Enter Book ID to issue: ")
        for book in self.books:
            if book.book_id == book_id:
                if book.is_available:
                    book.is_available = False
                    print(f"Book '{book.title}' issued successfully!")
                else:
                    print("Book is already issued.")
                return
        print("Book not found.")

    # Return a book
    def return_book(self):
        book_id = input("Enter Book ID to return: ")
        for book in self.books:
            if book.book_id == book_id:
                if not book.is_available:
                    book.is_available = True
                    print(f"Book '{book.title}' returned successfully!")
                else:
                    print("This book was not issued.")
                return
        print("Book not found.")

    # Show all books
    def show_books(self):
        print("\nBookID | Title | Author | Category | Status")
        print("--------------------------------------------")
        for book in self.books:
            book.display()

    # Simple AI Recommendation based on category
    def recommend_book(self):
        fav = input("Enter your favourite category: ").lower()
        print("\nRecommended Books for you:")
        found = False
        for book in self.books:
            if fav in book.category.lower() and book.is_available:
                book.display()
                found = True
        if not found:
            print("No recommendations available.")


def main():
    library = Library()

    while True:
        print("\n==============================")
        print(" INTELLIGENT LIBRARY ASSISTANT")
        print("==============================")
        print("1. Add Book")
        print("2. Search Book")
        print("3. Issue Book")
        print("4. Return Book")
        print("5. Show All Books")
        print("6. Recommend Books")
        print("7. Exit")

        choice = input("Enter your choice: ")

        if choice == "1":
            library.add_book()
        elif choice == "2":
            library.search_book()
        elif choice == "3":
            library.issue_book()
        elif choice == "4":
            library.return_book()
        elif choice == "5":
            library.show_books()
        elif choice == "6":
            library.recommend_book()
        elif choice == "7":
            print("Thank you for using Intelligent Library Assistant!")
            break
        else:
            print("Invalid choice. Try again.")


main()
