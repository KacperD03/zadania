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

class EbookBuilder {
public:
    virtual void buildTitle() = 0;
    virtual void buildDescription() = 0;
    virtual void buildRating() = 0;
    virtual void buildPurchasedStatus() = 0;
    virtual Ebook getResult() = 0;
};

class ConcreteEbookBuilder : public EbookBuilder {
private:
    Ebook ebook;

public:
    void buildTitle() override {
        ebook.title = "Default Title";
    }

    void buildDescription() override {
        ebook.description = "Default Description";
    }

    void buildRating() override {
        ebook.rating = 0.0;
    }

    void buildPurchasedStatus() override {
        ebook.purchased = false;
    }

    Ebook getResult() override {
        return ebook;
    }
};

class EbookDirector {
public:
    Ebook constructEbook(EbookBuilder& builder) {
        builder.buildTitle();
        builder.buildDescription();
        builder.buildRating();
        builder.buildPurchasedStatus();
        return builder.getResult();
    }
};

int main() {
    EbookDirector ebookDirector;
    ConcreteEbookBuilder ebookBuilder;

    Ebook ebook = ebookDirector.constructEbook(ebookBuilder);

    return 0;
}