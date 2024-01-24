#include <iostream>
#include <string>

// Product class
class Computer {
public:
    void setCPU(const std::string& cpu) {
        cpu_ = cpu;
    }

    void setMemory(const std::string& memory) {
        memory_ = memory;
    }

    void setStorage(const std::string& storage) {
        storage_ = storage;
    }

    void display() {
        std::cout << "CPU: " << cpu_ << std::endl;
        std::cout << "Memory: " << memory_ << std::endl;
        std::cout << "Storage: " << storage_ << std::endl;
    }

private:
    std::string cpu_;
    std::string memory_;
    std::string storage_;
};

// Builder interface
class ComputerBuilder {
public:
    virtual void buildCPU(const std::string& cpu) = 0;
    virtual void buildMemory(const std::string& memory) = 0;
    virtual void buildStorage(const std::string& storage) = 0;
    virtual Computer getResult() = 0;
};

// Concrete Builder
class CustomComputerBuilder : public ComputerBuilder {
public:
    CustomComputerBuilder() {
        computer_ = Computer();
    }

    void buildCPU(const std::string& cpu) override {
        computer_.setCPU(cpu);
    }

    void buildMemory(const std::string& memory) override {
        computer_.setMemory(memory);
    }

    void buildStorage(const std::string& storage) override {
        computer_.setStorage(storage);
    }

    Computer getResult() override {
        return computer_;
    }

private:
    Computer computer_;
};

// Director
class ComputerAssembler {
public:
    Computer assembleComputer(ComputerBuilder& builder) {
        builder.buildCPU("intel 3");  // Changed CPU
        builder.buildMemory("512GB");      // Changed Memory
        builder.buildStorage("500GB SSD");  // Changed Storage
        return builder.getResult();
    }
};

int main() {
    CustomComputerBuilder customBuilder;
    ComputerAssembler assembler;
    Computer customComputer = assembler.assembleComputer(customBuilder);
    std::cout << "Custom Computer Configuration:" << std::endl;
    customComputer.display();

    return 0;
}