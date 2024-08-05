// Структурные шаблоны задание 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <string>
#include <iostream>

class Text {
public:
    virtual void render(const std::string& data) const {
        std::cout << data;
    }
};


class DecoratedText : public Text {
public:
    explicit DecoratedText(Text* text) : text_(text) {}
    Text* text_;
};

class ItalicText : public DecoratedText {
public:
    explicit ItalicText(Text* text) : DecoratedText(text) {}
    void render(const std::string& data)  const {
        std::cout << "<i>";
        text_->render(data);
        std::cout << "</i>";
    }
};

class BoldText : public DecoratedText {
public:
    explicit BoldText(Text* text) : DecoratedText(text) {}
    void render(const std::string& data) const {
        std::cout << "<b>";
        text_->render(data);
        std::cout << "</b>";
    }
};

class Paragraph : public DecoratedText {
public:
    explicit Paragraph(Text* text) : DecoratedText(text) {}
    void render(const std::string& data) const {
        std::cout << "<p>";
        text_->render(data);
        std::cout << "</p>";
    }
};

class Reversed : public DecoratedText {
public:
    explicit Reversed(Text* text) : DecoratedText(text) {}
    void render(const std::string& data) const {
        std::string ReversedData = data;
        std::reverse(ReversedData.begin(), ReversedData.end());
        text_->render(ReversedData);
    }
};

class Link : public DecoratedText {
public:
    explicit Link(Text* text) : DecoratedText(text) {}
    void render(const std::string& link, const std::string& data) const {
        std::cout << "<a href=";
        text_->render(link);
        std::cout << ">";
        text_->render(data);
        std::cout << "</a>";
    }
};

int main() {
    auto Bold_Italic_block = new ItalicText(new BoldText(new Text()));
    Bold_Italic_block->render("Hello world");
    std::cout << std::endl;

    auto Paragraph_block = new Paragraph(new Text());
    Paragraph_block->render("Hello world");
    std::cout << std::endl;

    auto Reversed_block = new Reversed(new Text());
    Reversed_block->render("Hello world");
    std::cout << std::endl;

    auto Link_block = new Link(new Text());
    Link_block->render("netology.ru", "Hello world");
    std::cout << std::endl;
}