#include <iostream>
#include <string>

class Ebook {
public:
    std::string title;
    std::string description;
    float rating;
    bool purchased;

    Ebook() : rating(0.0), purchased(false) {}

    Ebook(const std::string& t, const std::string& d, float r) : title(t), description(d), rating(r), purchased(false) {}
};

class System {
public:
    Ebook recommendedEbooks[5];
    Ebook alphabeticalEbooks[10];
    bool userLoggedIn;

    System() : userLoggedIn(false) {
        initializeRecommendedEbooks();
        initializeAlphabeticalEbooks();
    }

    void initializeRecommendedEbooks() {
        recommendedEbooks[0] = Ebook("Title1", "Description1", 4.5);
        recommendedEbooks[1] = Ebook("Title2", "Description2", 3.8);
        recommendedEbooks[2] = Ebook("Title3", "Description3", 4.2);
        recommendedEbooks[3] = Ebook("Title4", "Description4", 4.0);
        recommendedEbooks[4] = Ebook("Title5", "Description5", 4.7);
    }

    void initializeAlphabeticalEbooks() {
        const std::string titles[] = { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J" };
        float ratings[] = { 4.0, 3.5, 4.2, 3.8, 4.1, 4.5, 3.7, 4.3, 4.6, 3.9 };

        for (int i = 0; i < 10; ++i) {
            alphabeticalEbooks[i] = Ebook(titles[i], "Description" + titles[i], ratings[i]);
        }
    }

    void login() {
        std::cout << "Log in to the system.\n";
        userLoggedIn = true;
    }

    void checkLoginStatus() {
        std::cout << (userLoggedIn ? "User is logged in." : "User is not logged in.") << "\n";
        displayEbookList(userLoggedIn ? recommendedEbooks : alphabeticalEbooks, userLoggedIn ? 5 : 10);
    }

    void displayEbookList(const Ebook ebooks[], int size) {
        std::cout << "Ebook List:\n";
        for (int i = 0; i < size; ++i) {
            std::cout << ebooks[i].title << "\n";
        }
    }

    void selectEbook() {
        std::cout << "Select an ebook.\n";
    }

    void displayEbookDetails(const Ebook& ebook) {
        std::cout << "Ebook Details:\n"
            << "Title: " << ebook.title << "\n"
            << "Description: " << ebook.description << "\n"
            << "Rating: " << ebook.rating << "\n";
    }

    void checkPurchaseStatus(const Ebook& ebook) {
        if (ebook.purchased) {
            std::cout << "You already purchased the ebook. Here is your download link.\n";
        }
        else {
            std::cout << "You have not purchased the ebook.\n";
            std::cout << "Returning to " << (userLoggedIn ? "recommended" : "alphabetical") << " ebook list.\n";
            displayEbookList(userLoggedIn ? recommendedEbooks : alphabeticalEbooks, userLoggedIn ? 5 : 10);
        }
    }
};


