#include <iostream>
#include <string>

// Product class
class Pizza {
public:
    void setDough(const std::string& dough) {
        this->dough = dough;
    }

    void setSauce(const std::string& sauce) {
        this->sauce = sauce;
    }

    void setTopping(const std::string& topping) {
        this->topping = topping;
    }

    void displayPizza() const {
        std::cout << "Pizza with Dough: " << dough
                  << ", Sauce: " << sauce
                  << ", Topping: " << topping << std::endl;
    }

private:
    std::string dough;
    std::string sauce;
    std::string topping;
};

// Abstract builder class
class PizzaBuilder {
public:
    virtual void buildDough() = 0;
    virtual void buildSauce() = 0;
    virtual void buildTopping() = 0;
    virtual Pizza getPizza() const = 0;
};

// Concrete builder for a specific type of pizza
class HawaiianPizzaBuilder : public PizzaBuilder {
public:
    void buildDough() override {
        pizza.setDough("Pan Dough");
    }

    void buildSauce() override {
        pizza.setSauce("Hawaiian Sauce");
    }

    void buildTopping() override {
        pizza.setTopping("Ham and Pineapple");
    }

    Pizza getPizza() const override {
        return pizza;
    }

private:
    Pizza pizza;
};

// Concrete builder for another type of pizza
class SpicyPizzaBuilder : public PizzaBuilder {
public:
    void buildDough() override {
        pizza.setDough("Thin Dough");
    }

    void buildSauce() override {
        pizza.setSauce("Spicy Tomato Sauce");
    }

    void buildTopping() override {
        pizza.setTopping("Pepperoni and Jalapenos");
    }

    Pizza getPizza() const override {
        return pizza;
    }

private:
    Pizza pizza;
};

// Moja pizza
class KacperDrozdzPizzaBuilder : public PizzaBuilder {
public:
    void buildDough() override {
        pizza.setDough("Thick Dough");  // Changed Dough
    }

    void buildSauce() override {
        pizza.setSauce("Creamy Garlic Sauce");  // Changed Sauce
    }

    void buildTopping() override {
        pizza.setTopping("Chicken, Spinach, and Feta Cheese");  // Changed Topping
    }

    Pizza getPizza() const override {
        return pizza;
    }

private:
    Pizza pizza;
};

// Director class that orchestrates the construction
class Cook {
public:
    void makePizza(PizzaBuilder& builder) {
        builder.buildDough();
        builder.buildSauce();
        builder.buildTopping();
    }
};

int main() {
    Cook cook;

    // Hawaiian Pizza
    HawaiianPizzaBuilder hawaiianBuilder;
    cook.makePizza(hawaiianBuilder);
    Pizza hawaiianPizza = hawaiianBuilder.getPizza();
    std::cout << "Hawaiian Pizza Configuration:" << std::endl;
    hawaiianPizza.displayPizza();

    // Spicy Pizza
    SpicyPizzaBuilder spicyBuilder;
    cook.makePizza(spicyBuilder);
    Pizza spicyPizza = spicyBuilder.getPizza();
    std::cout << "\nSpicy Pizza Configuration:" << std::endl;
    spicyPizza.displayPizza();

    // Pawel Krempa's Pizza
    KacperDrozdzPizzaBuilder KacperDrozdzBuilder;
    cook.makePizza(KacperDrozdzBuilder);
    Pizza KacperDrozdzPizza = KacperDrozdzBuilder.getPizza();
    std::cout << "\nKacper Drozdz Pizza Configuration:" << std::endl;
    KacperDrozdzPizza.displayPizza();

    return 0;
}